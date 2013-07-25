#include <iostream>
#include <stdlib.h>

class Hamburger
{
public:
  virtual void serve() = 0;
  virtual ~Hamburger() {}
};

class McdonaldsBurger : public Hamburger
{
public:
  void serve() { std::cout << "Here is your McDonalds hamburger" << std::endl; }
};

class WendysBurger : public Hamburger
{
public:
  void serve() { std::cout << "Here is your Wendys hamburger" << std::endl; }
};

class BurgerkingBurger : public Hamburger
{
public:
  void serve() { std::cout << "Here is your BurgerKing hamburger" << std::endl; }
};

class Restaurant
{
public:
  virtual void serve() = 0;
  virtual ~Restaurant() {}
};

class Mcdonalds : public Restaurant
{
public:
  Mcdonalds()
  {
    impl = new McdonaldsBurger();
  }
  ~Mcdonalds()
  {
    delete(impl);
  }
  void serve() { impl->serve(); }
private:
  Hamburger *impl;
};

class Wendys : public Restaurant
{
public:
  Wendys()
  {
    impl = new WendysBurger();
  }
  ~Wendys()
  {
    delete(impl);
  }
  void serve() { impl->serve(); }
private:
  Hamburger *impl;
};

class Burgerking : public Restaurant
{
public:
  Burgerking()
  {
    impl = new BurgerkingBurger();
  }
  ~Burgerking()
  {
    delete(impl);
  }
  void serve() { impl->serve(); }
private:
  Hamburger *impl;
};

int main()
{
  char choice;

  Restaurant *restaurant[3];
  restaurant[0] = new Mcdonalds();
  restaurant[1] = new Wendys();
  restaurant[2] = new Burgerking();

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

  if (choice == '4') exit(0);

  restaurant[atoi(&choice)-1]->serve();

  delete(restaurant[0]);
  delete(restaurant[1]);
  delete(restaurant[2]);
}
