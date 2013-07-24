#include <iostream>

class Socket 
{
public:
  Socket(float size) {this->size = size;}
  void printsize() {std::cout << "I am a " << size << " inch socket" << std::endl;}
  void turn() {std::cout << "The socket is turning" << std::endl;}
private:
  float size;
};

class Rachet
{
public:
  Rachet(float size) { this->size = size;}
  virtual ~Rachet() {}
  void printsize() {std::cout << "I am a " << size << " inch rachet" << std::endl;} 
  void turn();
private:
  float size;
};

class Adapter: public Rachet
{
public:
  Socket *s;
  Adapter(Socket *s, float rachetSize) :  Rachet(rachetSize)
  {
    s = s;
  }
  void turn()
  {
    std::cout << "The adapter is turning" << std::endl;
    s->turn();
  }
};

void Rachet::turn()
{
  std::cout << "I'm turning the rachet" << std::endl;
  //((Adapter *)this)->turn(); 
  Adapter * adapt;
  adapt = dynamic_cast<Adapter *>(this);
  if (adapt != NULL) 
    adapt->turn();
  else
    std::cout << "There is no adapter attached" << std::endl;
}

int main()
{
  Socket *sock = new Socket(0.25);
  sock->printsize();

  Adapter *adapt = new Adapter(sock,0.5);
  adapt->printsize();

  Rachet *rachet = adapt;

  rachet->turn();

  delete(adapt);
  delete(sock);
}
