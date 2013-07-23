#include <iostream>
#include <stdlib.h>

std::string returnToastedString(bool bun)
{
  if (bun == true) return "toasted";
  else return "non-toasted";
}

std::string returnCheeseString(char cheese)
{
  switch (cheese)
  {
    case '1' : return std::string("swiss");
    case '2' : return std::string("cheddar");
    case '3' : return std::string("american");
  }
}

std::string returnDonenessString(char doneness)
{
  switch(doneness)
  {
    case '1' : return std::string("rare");
    case '2' : return std::string("well done");
    case '3' : return std::string("medium");
  }
}

class Hamburger
{
public:
  void getBun();
  void getPatty();
  virtual void getCheese() {}
  virtual void getBacon() {}
  virtual void serveBurger();
  virtual ~Hamburger() {}
private:
  bool bun;
  char patty;
};

void Hamburger::getBun()
{
  char response = 0;
  std::cout << "Would you like you bun toasted? y/n" << std::endl;
  while (response != 'y' && response != 'n')
  {
    response = std::cin.get();
  }
  if (response == 'y') bun = true;
  else bun = false;
}

void Hamburger::getPatty()
{
  char response = 0;
  std::cout << "How would you like that cooked?" << std::endl;
  std::cout << " 1.  rare" << std::endl;
  std::cout << " 2.  medium" << std::endl;
  std::cout << " 3.  well done" << std::endl;
  while (response < '1' || response > '3')
  {
    response = std::cin.get();
  }
  patty = response; 
}

void Hamburger::serveBurger()
{
  std::cout << "Here is your burger cooked ";
  std::cout << returnDonenessString(patty);
  std::cout << " on a ";
  std::cout << returnToastedString(bun);
  std::cout <<  " bun" << std::endl;
}

class Cheeseburger: public Hamburger {
public:
  void getCheese();
  virtual void getBacon() {}
  virtual void serveBurger();
private:
  char cheese; 
};

void Cheeseburger::getCheese()
{
  char response = 0;
  std::cout << "What kind of cheese would you like?" << std::endl;
  std::cout << " 1.  Cheddar" << std::endl;
  std::cout << " 2.  Swiss" << std::endl;
  std::cout << " 3.  American" << std::endl;
  while (response < '1' || response > '3')
  {
    response = std::cin.get();
  }
  cheese = response; 
}

void Cheeseburger::serveBurger()
{
  Hamburger::serveBurger();
  std::cout << "topped with ";
  std::cout << returnCheeseString(cheese);
  std::cout << " cheese" << std::endl;
}

class Baconcheeseburger: public Cheeseburger
{
public:
  void getBacon();
  void serveBurger();
private:
  int strips;
};

void Baconcheeseburger::getBacon()
{
  char response = 0;
  std::cout << "How many strips of bacon would you like?" << std::endl;
  while (response < '1' || response > '9')
  {
    response = std::cin.get();
  }
  strips = atoi(&response); 
}

void Baconcheeseburger::serveBurger()
{
  Cheeseburger::serveBurger();
  std::cout << "and " << strips << " strips of bacon" << std::endl;
}

class Director
{
public:
  void setBuilder(Hamburger* newBurger)
  {
    this->newBurger = newBurger;
  }

  void buildBurger()
  {
    newBurger->getBun();
    newBurger->getPatty();
    newBurger->getCheese();
    newBurger->getBacon();
  }
private:
  Hamburger* newBurger;
};

int main()
{
  Director director;
  Hamburger *burger;

  char response = 0;
  std::cout << "Welcome to RichBurger - may I take you order?" << std::endl;
  std::cout << "1. - regular hamburger" << std::endl;
  std::cout << "2. - cheeseburger" << std::endl;
  std::cout << "3. - bacon cheeseburger" << std::endl;

  while (response < '1' || response > '3')
  {
    response = std::cin.get();
  }

  if (response == '1' ) burger = new Hamburger(); 
  if (response == '2' ) burger = new Cheeseburger();
  if (response == '3' ) burger = new Baconcheeseburger();
 
  director.setBuilder(burger); 
  director.buildBurger();
  burger->serveBurger();
  delete(burger);
}
