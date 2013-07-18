CC=/usr/bin/g++
CFLAGS= -g 

OBJS = abstract_factory \
       builder          \
       factory          \
       object_pool      \
       singleton 

all: $(OBJS)

abstract_factory: abstract_factory.cc
	$(CC) $(CFLAGS) -o abstract_factory abstract_factory.cc

builder: builder.cc
	$(CC) $(CFLAGS) -o builder builder.cc

factory: factory.cc
	$(CC) $(CFLAGS) -o factory factory.cc

object_pool: object_pool.cc
	$(CC) $(CFLAGS) -o object_pool object_pool.cc

singleton: singleton.cc
	$(CC) $(CFLAGS) -o singleton singleton.cc

clean:
	rm $(OBJS) 
