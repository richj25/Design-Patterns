#include <iostream>
#include <stdlib.h>

class Hamburger
{
public:
  virtual Hamburger* clone() = 0;
  virtual ~Hamburger() {}
  virtual void serve() = 0; 
};

class Mcdonalds : public Hamburger
{
public:
  Hamburger* clone() { return new Mcdonalds;}
  void serve() {std::cout << "Here is your McDonalds hamurger" << std::endl;} 
};

class Wendys : public Hamburger
{
public:
  Hamburger* clone() { return new Wendys;}
  void serve() {std::cout << "Here is your Wendys hamurger" << std::endl;} 
};

class Burgerking : public Hamburger
{
public:
  Hamburger* clone() { return new Burgerking;}
  void serve() {std::cout << "Here is your BurgerKing hamurger" << std::endl;} 
};

class BurgerFactory
{
public:
  static Hamburger* make_burger(int choice)
  {
    return burger_prototypes[choice]->clone();
  }
private:
  static Hamburger* burger_prototypes[4];
};

Hamburger* BurgerFactory::burger_prototypes[] = {
  NULL, new Mcdonalds, new Wendys, new Burgerking
};

int main()
{
  char choice;
  Hamburger *burger;

  std::cout << "Where should we eat today?" << std::endl;
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

  std::cout << "Choice = " << choice << std::endl;
  if (choice == '4') exit(0);

  burger = BurgerFactory::make_burger(atoi(&choice)); 

  burger->serve();

  delete(burger);
}


