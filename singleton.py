#!/usr/bin/python

import time
import datetime

class Singleton:
    """ A python singleton """

    class __impl:
        """the actual singleton implementation """
        def __init__(self):
            """ Save a timestamp of when created """
            self.ts = datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S')

        def return_id(self):
            return id(self)

        def return_timestamp(self):
            return(self.ts)

    __instance = None

    def __init__(self):
        if Singleton.__instance is None:
            Singleton.__instance = Singleton.__impl();

    def return_timestamp(self):
        return self.__instance.return_timestamp()


s1 = Singleton()
print id(s1), s1.return_timestamp()

time.sleep(5)

s2 = Singleton()
print id(s2), s2.return_timestamp()

print "Different id but same timestamp"

