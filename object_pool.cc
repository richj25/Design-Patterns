#include <iostream>
#include <stack>

class Plate
{
  bool clean;
public:
  void clean_plate()
  {
    clean = true;
  }
  void use_plate()
  {
    clean = false;
  }
  Plate() 
  {
    clean = true;
  }
};

class StackOfPlates
{
  std::stack<Plate*> stack;
  StackOfPlates() {}
  StackOfPlates(const StackOfPlates& single);
  StackOfPlates& operator=(const StackOfPlates& rhs);
public:
  static StackOfPlates& get_instance()
  {
    static StackOfPlates s;
    return s;
  }

  Plate* get_plate()
  {
    if (stack.empty())
    {
      return new(Plate);
    }
    Plate *plate = stack.top();
    stack.pop();
    return plate;
  } 

  void return_plate(Plate *plate)
  {
    plate->clean_plate();
    stack.push(plate); 
  }
};


int main()
{
  std::stack<Plate*> inuse;
  Plate *plate;

  StackOfPlates& stackOfPlates = StackOfPlates::get_instance();

  for (int i = 0; i < 10; i++)
  {
    plate = stackOfPlates.get_plate();
    plate->use_plate();
    inuse.push(plate);  
  }

  while (!inuse.empty())
  {
    plate = inuse.top();
    inuse.pop();
    stackOfPlates.return_plate(plate);
  }

  for (int i = 0; i < 15; i++)
  {
    plate = stackOfPlates.get_plate();
    plate->use_plate();
    inuse.push(plate);  
  }

  while (!inuse.empty())
  {
    delete(inuse.top());
    inuse.pop();
  }
}
