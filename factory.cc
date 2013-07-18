#include <iostream>
#include <queue>


class Hamburger 
{
public:
  static Hamburger* newBurger(char choice);
  virtual void serve() = 0;
};

class BaconCheeseBurger : public Hamburger 
{
public:
  void serve()
  {
    std::cout << "Here is your Bacon CheeseBurger" << std::endl;
  }
};

class SwissMushroomBurger : public Hamburger 
{
public:
  void serve()
  {
    std::cout << "Here is your Swiss MushroomBurger" << std::endl;
  }
};

class ChiliBurger : public Hamburger 
{
public:
  void serve()
  {
    std::cout << "Here is your ChiliBurger" << std::endl;
  }
};

Hamburger* Hamburger::newBurger(char choice)
{
  switch (choice)
  {
    case '1': return new BaconCheeseBurger;
    case '2': return new SwissMushroomBurger;
    case '3': return new ChiliBurger;
    default: return NULL;
  }
}

int main()
{
  char choice = 0;
  Hamburger* burger;

  std::cout << "Please choose your burger" << std::endl;
  std::cout << "1)  Bacon CheeseBurger" << std::endl;
  std::cout << "2)  Swiss MushroomBurger" << std::endl;
  std::cout << "3)  ChiliBurger" << std::endl;
  std::cout << "4)  Quit" << std::endl;

  while (choice != '4')
  {
    std::cin >> choice;
    if ( choice < '1' || choice > '4')
      std::cout << "Invalid choice - please choose again" << std::endl;
    else 
    {
      if (choice == '4') break;
 
      burger = Hamburger::newBurger(choice);
      burger->serve();
      delete(burger);
    }
  }
}

