function Sum
    input Real arg1;
    input Real arg2;
    output Real result;
  protected
    Real p = PolynomialEvaluator({1, 2, 3, 4}, 21);
algorithm
  result := arg1 + arg2;
end Sum;
