#export SYSTEMC_HOME=/usr/local/systemc231/
# 				g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux -o CDC_Sim main.cpp -lsystemc -lm

DESIGN := CDC_Sim

CXX := g++
TARGET_ARCH := linux64

.SUFFIXES: .o .cc

CC_FILES := $(shell find . -name "*.cpp" -type f)
OBJECTS := $(subst .cc,.o,$(CC_FILES))

SYSTEMC_PATH := /usr/local/systemc-2.3.1

INC := -I. -I$(SYSTEMC_PATH)/include
LIBDIR := -L$(SYSTEMC_PATH)/lib-$(TARGET_ARCH)
LIBS := -lsystemc -lm


CDC_Sim_target:  $(OBJECTS) $(SYSTEMC_PATH)/lib-$(TARGET_ARCH)/libsystemc.a
	$(CXX) $(INC) $(LIBDIR) -o $(DESIGN) $(OBJECTS) $(LIBS)

.cc.o :
	$(CXX) $(INC) -Werror -c -o $@ $<

