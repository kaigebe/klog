######################################
#Author: Kai.Ge
#Time:   2018/11/18
######################################

CXX=g++
CC=gcc
AR=ar crv
RM=rm -rf
CP=cp
MV=mv

#debug enable
DBG_ENABLE = 0

#source file path
SRC_PATH := .

#Target exec file 
TARGET := api

#get all source file
SRCS  += $(wildcard $(SRC_PATH)/*.cpp)

#all .o base on .cpp
OBJS := $(SRCS:.cpp=.o)

#need libs 
LIBS := mem

#header path
INCLUDE_PATH := ../include

#lib Path
LIB_PATH := ~/disk/workspace/KLog/lib

#debuf enbale
ifeq (1,$(DBG_ENABLE))
	CFLAGS += -D_DEBUG -O0 -g -DEBUG=1
endif

#get all include path
CFLAGS += $(foreach dir,$(INCLUDE_PATH),-I$(dir))

#get all lib path 
LDFLAGS += $(foreach lib,$(LIB_PATH),-L$(lib))

#get all libs
LDFLAGS += $(foreach lib,$(LIBS),-l$(lib))

all: clean build

build:
	$(CXX) -c $(SRCS) $(CFLAGS)
	$(AR) lib$(TARGET).a $(OBJS)
	$(CXX) -fPIC -shared -o lib$(TARGET).so $(SRCS) $(CFLAGS)
	$(CP) lib$(TARGET).a ../lib
	$(CP) lib$(TARGET).so ../lib
	$(MV) $(OBJS) ../Target
#	$(CXX) -c mem.cpp
#	$(AR) crv libmem.a mem.o
#	$(CXX) -fPIC -shared -o libmem.so mem.cpp
#	$(CP) libmem.a ../lib
#	$(CP) libmem.so ../lib
#	$(MV) mem.o ../Target
.PHONY:

clean:
	${RM} *.a *.so *.out *.o
	


