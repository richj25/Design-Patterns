#include <iostream>
#include <stdlib.h>


class Interface {
public:
  virtual ~Interface() {}
  virtual void serve() = 0;
};

template<class T>
class Adapter : public Interface
{
public:
  Adapter(T *object, void(T:: *method)())
  {
    this->object = object;
    this->method = method;
  }

  ~Adapter()
  {
    delete(object);
  }

  void serve()
  {
    (object->*method)();
  }

private:
  T *object;
  void(T:: *method)();
};


class WendysBurger 
{
public:
  void wendysServe()
  {
    std::cout << "Here is you Wendys hamburger" << std::endl;
  }
};

class BurgerkingBurger 
{
public:
  void burgerkingServe()
  {
    std::cout << "Here is your BurgerKing hamburger" << std::endl;
  }
};

class McdonaldsBurger 
{
public:
  void mcdonaldsServe()
  {
    std::cout << "Here is your McDonalds hamburger" << std::endl;
  }
};

Interface  **initialize()
{
  Interface **array = new Interface*[3];
  array[0] = new Adapter<McdonaldsBurger> (new McdonaldsBurger(), &McdonaldsBurger::mcdonaldsServe); 
  array[1] = new Adapter<WendysBurger> (new WendysBurger(), &WendysBurger::wendysServe); 
  array[2] = new Adapter<BurgerkingBurger> (new BurgerkingBurger(), &BurgerkingBurger::burgerkingServe); 
  return array;
}


int main()
{
  Interface **burgers = initialize();
  char choice;

  std::cout << "Where should we eat today>" << std::endl;
  std::cout << "1) McDonalds" << std::endl;
  std::cout << "2) Wendys" << std::endl;
  std::cout << "3) BurgerKing" << std::endl;
  std::cout << "4) I'm skipping lunch today" << std::endl;

  std::cin >> choice;

  while (choice < '1' || choice > '4')
  {
    std::cout << "Not a valid choice - please choose again" << std::endl;
    std::cin >> choice;
  }

  if (choice == '4') exit(0);

  std::cout << "choice is " << atoi(&choice) << std::endl;
  burgers[atoi(&choice)-1]->serve();
}
