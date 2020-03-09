function PolynomialEvaluator
    input Real A[:];
    input Real x := 1.0;
    output Real result;
  protected
    Real xpower;//local variable
  
algorithm
  result := 0;
  xpower := 1;
  
  for i in 1:size(A, 1) loop
    result := result + A[i]*xpower; 
    xpower := xpower*x;
  end for;

end PolynomialEvaluator;
