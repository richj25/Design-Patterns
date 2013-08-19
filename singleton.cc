#include <iostream>
#include <atomic>

using std::cout;
using std::endl;

class StaticSingle {
public:
  static StaticSingle& get_instance()
  {
    static StaticSingle single(0,0);
    return single;
  }

private:
  StaticSingle(int m, int n): count1(m), count2(n){}
  StaticSingle(const StaticSingle& single);
  StaticSingle& operator=(const StaticSingle& rhs);
  int count1, count2;
};


class NewSingle {
public:
  static NewSingle& get_instance(int x, int y);
  ~NewSingle();
  std::atomic<int> x;
  std::atomic<int> y;

private:
  NewSingle(int x, int y);
  NewSingle(const NewSingle& single);
  NewSingle& operator=(const NewSingle& rhs);
  static NewSingle* instance;
};

NewSingle* NewSingle::instance = NULL;

NewSingle::NewSingle(int x, int y): x(x), y(y)
{
  cout << "NewSingle constructor" << endl;
}

NewSingle::~NewSingle()
{
  cout << "NewSingle destructor" << endl;
  instance = NULL;
}

NewSingle& NewSingle::get_instance(int x, int y)
{
  if (instance == NULL) instance = new NewSingle(x,y);
  return *instance;
}

int main()
{
  StaticSingle& single1 = StaticSingle::get_instance();
  StaticSingle& single2 = StaticSingle::get_instance();

  cout << "Address of single1 = " << &single1 << endl;
  cout << "Address of single2 = " << &single2 << endl;

  NewSingle& single3 = NewSingle::get_instance(2,3);
  NewSingle& single4 = NewSingle::get_instance(4,5);

  cout << "Address of single3 = " << &single3 << endl;
  cout << "Address of single4 = " << &single4 << endl;
  cout << "single3: x member = " << single3.x << endl;
  cout << "single3: y member = " << single3.y << endl;
  cout << "single4: x member = " << single4.x << endl;
  cout << "single4: y member = " << single4.y << endl;

  delete(&single3);

  NewSingle& single5 = NewSingle::get_instance(4,5);

  cout << "Address of single5 = " << &single5 << endl;
  cout << "single5: x member = " << single5.x << endl;
  cout << "single5: y member = " << single5.y << endl;

  delete(&single5);
}
