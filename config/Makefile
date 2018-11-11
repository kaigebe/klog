CXX=g++
CC=gcc
AR=ar
RM=rm
mem:
	@$(CXX) -c config.cpp
	@$(AR) crv libcfg.a config.o
	@$(CXX) -fPIC -shared -o libcfg.so config.cpp
.PHONY:

clean:
	@${RM} -rf *.a *.so *.out
	


