classdef SimpleHydraulicSystemSimulation
  properties
 
    
    #geometry setup
    #Pipe lenghts and effective diameter of valve and pump
    L1
    L2
    Lvalve
    Lpump
    Ltotal

    #Diameter of pipes and effective diameter of valve and pump
    D1
    D2
    Dvalve
    Dpump

    #Perpendicular crosssection area of pipes and effective square of valve and pump
    S1
    S2
    Svalve
    Spump
    Saverage

    #Volume
    V1
    V2
    Vvalve
    Vpump
    Vtotal

    #physical parameters
    p_atm

    #fluid
    rho #density
    mass
    
    #pipe constant
    lambda
    
    #valve constant
    eta
    
    #pump parameters
    s
    delta_P_ref
    Q_max
    
    Q_critical
  end
  
  methods
    function obj = SimpleHydraulicSystemSimulation(
      L1, L2, Lvalve, Lpump, 
      D1, D2, Dvalve, Dpump,
      p_atm,
      rho, lambda, eta, s, delta_P_ref, Q_max, Q_critical)
      
      if nargin == 16
        obj.L1 = L1;
        obj.L2 = L2;
        obj.Lvalve = Lvalve;
        obj.Lpump = Lpump;
      
        obj.D1 = D1;
        obj.D2 = D2;
        obj.Dvalve = Dvalve;
        obj.Dpump = Dpump;
      
        obj.p_atm = p_atm;
        obj.rho = rho;
        obj.lambda = lambda;
        obj.eta = eta;
        obj.s = s;
        obj.delta_P_ref = delta_P_ref;
        obj.Q_max = Q_max;
        
        obj.Q_critical = Q_critical;
      else
        obj.L1 = obj.L2 = 1;
        obj.Lvalve = obj.Lpump = 1;
        obj.D1 = obj.D2 = obj.Dvalve = obj.Dpump = 1;
        
        obj.p_atm = 0;
        obj.rho = obj.lambda = obj.eta = 1;
        obj.s = obj.delta_P_ref = obj.Q_max = 1;
        
        obj.Q_critical = 40;
      endif
      
      #dependent variables
      obj.Ltotal = obj.L1 + obj.L2 + obj.Lvalve + obj.Lpump;
      obj.S1 = pi * obj.D1**2;
      obj.S2 = pi * obj.D2**2;
      obj.Svalve = pi * obj.Dvalve**2;
      obj.Spump = pi * obj.Dpump**2;
      
      obj.V1 = obj.L1 * obj.S1;
      obj.V2 = obj.L2 * obj.S2;
      obj.Vvalve = obj.Lvalve * obj.Svalve;
      obj.Vpump = obj.Lpump * obj.Spump;
      obj.Vtotal = obj.V1 + obj.V2 + obj.Vvalve + obj.Vpump;
      
      #average area of cross section
      obj.Saverage = obj.Vtotal / obj.Ltotal;
      
      #total mass
      obj.mass = obj.rho * obj.Vtotal;
    end
    
    function dp = delta_p_pipe(obj, Q, L, D, S)
      dp = sign(Q).*(obj.lambda*L*Q.^2/2/D/obj.rho/S**2); 
    end
    
    function dp = delta_p_pipe_1(obj, Q)
      dp = obj.delta_p_pipe(Q, obj.L1, obj.D1, obj.S1);
    end
    
    function dp = delta_p_pipe_2(obj, Q)
      dp = obj.delta_p_pipe(Q, obj.L2, obj.D2, obj.S2);
    end
    
    function dp = delta_p_valve(obj, Q)
      dp = sign(Q).*(obj.eta*Q.^2/2/obj.rho/obj.Svalve**2); 
    end
    
    function dp = delta_p_pump(obj, Q)
      dp = obj.s*obj.delta_P_ref*(1 - Q/obj.Q_max); 
    end
    
    function DerQ = flow_rate_derivative(obj, Q)
      DerQ = - obj.Saverage/obj.Ltotal * ( obj.delta_p_pipe_1(Q) 
        + obj.delta_p_pipe_2(Q) + obj.delta_p_valve(Q) - obj.delta_p_pump(Q));
    end
    
    #control points
    function val = p1(obj, Q)
      val = obj.p_atm*ones(size(Q));
    end 
    function val = p2(obj, Q)
      val = obj.p1(Q) - obj.delta_p_valve(Q);
    end 
    function val = p3(obj, Q)
      val = obj.p2(Q) - obj.delta_p_pipe_2(Q);
    end 
    function val = p4(obj, Q)
      val = obj.p1(Q) + obj.delta_p_pipe_1(Q);
    end 
    
    #using Runge-Kutta 4th order method
    function [time, Q_value] = solve(obj, Q0, dt, tmax)
      time = 0:dt:tmax;
      Q_value = zeros(size(time));
      
      index = 1;
      Q_cur = Q_value(1, 1) = Q0;
      for t_cur = time
        
        k1 = dt*obj.flow_rate_derivative(Q_cur);
        k2 = dt*obj.flow_rate_derivative(Q_cur + 0.5*k1);
        k3 = dt*obj.flow_rate_derivative(Q_cur + 0.5*k2);
        k4 = dt*obj.flow_rate_derivative(Q_cur + k3);
        
        Q_cur += (k1 + 2*k2 + 2*k3 + k4)/6.0;
        
        if abs(Q_cur) >= obj.Q_critical
            #system is damaged, there is no flow anymore
            Q_cur = 0;
            break;
        end    
        
        if index > 1
          Q_value(1, index) = Q_cur;
        end
        
        ++index;
      end
    end
  end
end