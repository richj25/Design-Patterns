#include <iostream>
#define ArrayLength 10


class Visitor
{
public:
	virtual void visit(int ele) = 0;

};

class SumVisitor : public Visitor
{
public:
	SumVisitor();

	void visit(int ele);

	int value();

private:
	int total;
};

SumVisitor::SumVisitor()
{
	total = 0;
}

void SumVisitor::visit(int ele)
{
	total += ele;
}

int SumVisitor::value()
{
	return total;
}

class Visitable
{
public:
	void accept(Visitor &v);
};

class ArrayVisitable : public Visitable
{
public:
	ArrayVisitable();
	void accept(Visitor &v);
	static int length;

private:
	int data[ArrayLength];
};

int ArrayVisitable::length = ArrayLength;

ArrayVisitable::ArrayVisitable()
{
	for (int i = 0; i < length; i++)
	{
		data[i] = i;
	}
}

void ArrayVisitable::accept(Visitor &v)
{
	for (int i = 0; i < length; i++)
	{
		v.visit(data[i]);
	}
}

int main(void)
{
	ArrayVisitable array;
	SumVisitor visitor;

	array.accept(visitor);

	std::cout << "Total is " << visitor.value() << std::endl;

}
