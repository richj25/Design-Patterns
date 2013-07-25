CC=/usr/bin/g++
CFLAGS= -g 

OBJS = abstract_factory      \
       adapter               \
       bridge                \
       builder               \
       external_polymorphism \
       factory               \
       object_pool           \
       prototype             \
       singleton 

all: $(OBJS)

abstract_factory: abstract_factory.cc
	$(CC) $(CFLAGS) -o abstract_factory abstract_factory.cc

adapter: adapter.cc
	$(CC) $(CFLAGS) -o adapter adapter.cc

bridge: bridge.cc
	$(CC) $(CFLAGS) -o bridge bridge.cc

builder: builder.cc
	$(CC) $(CFLAGS) -o builder builder.cc

external_polymorphism: external_polymorphism.cc
	$(CC) $(CFLAGS) -o external_polymorphism external_polymorphism.cc

factory: factory.cc
	$(CC) $(CFLAGS) -o factory factory.cc

object_pool: object_pool.cc
	$(CC) $(CFLAGS) -o object_pool object_pool.cc

prototype: prototype.cc
	$(CC) $(CFLAGS) -o prototype prototype.cc

singleton: singleton.cc
	$(CC) $(CFLAGS) -o singleton singleton.cc

clean:
	rm $(OBJS) 
