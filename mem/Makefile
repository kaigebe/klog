CXX=g++
CC=gcc
AR=ar
RM=rm
mem:
	@$(CXX) -c mem.cpp
	@$(AR) crv libmem.a mem.o
	@$(CXX) -fPIC -shared -o libmem.so mem.cpp
.PHONY:

clean:
	@${RM} -rf *.a *.so *.out
	


