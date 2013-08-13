#include <iostream>

class ArithmeticFunction
{
public:
  virtual float perform_function(float a, float b) = 0;
  virtual ~ArithmeticFunction() {}
};

class Calculator
{
public:
  enum FunctionType {dummy, add, subtract, multiply, divide};
  float calculate(float a, float b);
  void set_function(int choice);
  Calculator()
  {
    function = NULL;
  }
  ~Calculator()
  {
    if (function == NULL)
      delete function;
  }
private: 
  ArithmeticFunction *function;
};
class Multiply: public ArithmeticFunction
{
public:
  float perform_function(float a, float b)
  {
    return a * b;
  }
};

class Divide: public ArithmeticFunction
{
public:
  float perform_function(float a, float b)
  {
    return a / b;
  }
};

class Subtract: public ArithmeticFunction
{
public:
  float perform_function(float a, float b)
  {
    return a - b;
  }
};

class Add: public ArithmeticFunction
{
public:
  float perform_function(float a, float b)
  {
    return a + b;
  }
};

float Calculator::calculate(float a, float b)
{
  return function->perform_function(a,b);
}

void Calculator::set_function(int choice)
{
  if (function == NULL) delete function;

  switch (choice)
  {
    case add: function = new Add(); break;
    case subtract: function = new Subtract(); break;
    case divide: function = new Divide(); break;
    case multiply: function = new Multiply(); break;
  }
}

int main()
{
  Calculator calculator;
  int choice;
  std::cout << "0) Exit, 1) Add, 2) Subtract, 3) Divide, 4) Multiply" << std::endl;
  std::cin >> choice;
  while (choice)
  {
    calculator.set_function(choice);
    std::cout << "4 (function) 3 = " << calculator.calculate(4,3) << std::endl;
    std::cout << "0) Exit, 1) Add, 2) Subtract, 3) Divide, 4) Multiply" << std::endl;
    std::cin >> choice;
  } 
  return 0;
}
