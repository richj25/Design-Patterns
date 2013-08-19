#include <iostream>

class Hamburger
{
public:
  virtual ~Hamburger() {}
  virtual void serve() = 0;
};

class WendysBurger : public Hamburger
{
public:
  void serve()
  {
    std::cout << "Wendys hamburger" << std::endl;
  }
};

class McdonaldsBurger : public Hamburger
{
public:
  void serve()
  {
    std::cout << "McDonalds hamburger" << std::endl;
  }
};

class BurgerkingBurger : public Hamburger
{
public:
  void serve()
  {
    std::cout << "BurgerKing hamburger" << std::endl;
  }
};

class BurgerFactory
{
public:
  virtual ~BurgerFactory() {}
  virtual Hamburger* get_burger() = 0;
};

class McDonalds : public BurgerFactory
{
public:
  Hamburger* get_burger()
  {
    return new McdonaldsBurger;
  }
};

class Wendys : public BurgerFactory
{
public:
  Hamburger* get_burger()
  {
    return new WendysBurger;
  }
};

class BurgerKing : public BurgerFactory
{
public:
  Hamburger* get_burger()
  {
    return new BurgerkingBurger;
  }
};

int main()
{
  BurgerFactory *factory;
  char choice;
  Hamburger *burger;

  std::cout << "Where should we eat today?" << std::endl;
  std::cout << "1) McDonalds" << std::endl;
  std::cout << "2) Wendys" << std::endl;
  std::cout << "3) BurgerKing" << std::endl;
  
  std::cin >> choice;

  switch (choice)
  {
     case '1' : 
       factory = new McDonalds;
       break;
     case '2' : 
       factory = new Wendys;
       break;
     case '3' : 
       factory = new BurgerKing;
       break;
     default:
       factory = new McDonalds;
       std::cout << "Whatever. We're going to McDonalds" << std::endl;
  } 
 
  burger = factory->get_burger();
  burger->serve(); 
  delete(burger);
  delete(factory);
}
