#include <iostream>
#include <string>

class Burger
{
public:
	Burger();
	virtual ~Burger();
	virtual void serve() { std::cout << "Here is a " << description << std::endl; }
	virtual std::string getDescription() { return description; }

private:
	std::string description;
};

Burger::Burger()
{
	description = "burger";
}

Burger::~Burger()
{
}

class DecoratedBurger : public Burger
{
public:
	DecoratedBurger(Burger *burger, std::string addOn);
	virtual ~DecoratedBurger();
	void serve() { std::cout << "Here is a " << description << std::endl; }
	virtual std::string getDescription() { return this->description; }

private:
	Burger* m_burger;
	std::string description;
};

DecoratedBurger::DecoratedBurger(Burger* burger, std::string addOn)
{
	this->description = burger->getDescription() + " with " + addOn;
	m_burger = burger;
}

DecoratedBurger::~DecoratedBurger()
{
	delete m_burger;
}

int main()
{
	Burger* burger = new Burger();

	burger->serve();

	burger = new DecoratedBurger(burger, "cheese");

	burger->serve();

	burger = new DecoratedBurger(burger, "onions");

	burger->serve();

	std::cout << "Deleting the first burger" << std::endl;
	delete burger;

	burger = new DecoratedBurger(new DecoratedBurger(new Burger(), "cheese"), "onions");

	burger->serve();

	delete burger;
}
