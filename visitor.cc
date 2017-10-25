#include <iostream>
#include <list>
#include <vector>

#define DataLength 10


class Visitor
{
public:
	virtual void visit(int ele) = 0;

};

class AverageVisitor : public Visitor
{
public:
	AverageVisitor();

	void visit(int ele);

	float value();

	void clear();

private:
	int numberOfElements;
	int total;
};

AverageVisitor::AverageVisitor()
{
	numberOfElements = 0;
	total = 0;
}

void AverageVisitor::visit(int ele)
{
	total += ele;
	numberOfElements++;
}

float AverageVisitor::value()
{
	return (float)total/(float)numberOfElements;
}

void AverageVisitor::clear()
{
	total = 0;
	numberOfElements = 0;
}

class SumVisitor : public Visitor
{
public:
	SumVisitor();

	void visit(int ele);

	int value();

	void clear();

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

void SumVisitor::clear()
{
	total = 0;
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


private:
	std::vector<int> data;
};

ArrayVisitable::ArrayVisitable()
{
	for (int i = 0; i < DataLength; i++)
	{
		data.push_back(i);
	}
}

void ArrayVisitable::accept(Visitor &v)
{
	for (std::vector<int>::iterator iter = data.begin(); iter != data.end(); iter++)
	{
		v.visit(*iter);
	}
}

class ListVisitable : public Visitable
{
public:
	ListVisitable();
	void accept(Visitor &v);

private:
	std::list<int> data;
};

ListVisitable::ListVisitable()
{
	for (int i = 0; i < DataLength; i++)
	{
		data.push_back(i);
	}
}

void ListVisitable::accept(Visitor &v)
{
	for (std::list<int>::iterator iter = data.begin(); iter != data.end(); iter++)
	{
		v.visit(*iter);
	}
}

int main(void)
{
	ArrayVisitable array;
	ListVisitable list;
	SumVisitor sum;
	AverageVisitor average;

	array.accept(sum);
	std::cout << "Total is " << sum.value() << std::endl;

	sum.clear();

	list.accept(sum);
	std::cout << "Total is " << sum.value() << std::endl;

	array.accept(average);
	std::cout << "Average is " << average.value() << std::endl;

	average.clear();

	list.accept(average);
	std::cout << "Average is " << average.value() << std::endl;
}
