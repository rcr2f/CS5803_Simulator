#export SYSTEMC_HOME=/usr/local/systemc231/
#g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o sim hello.cpp -lsystemc -lm

DESIGN := CDC_Sim

CXX := g++
TARGET_ARCH := linux64


CC_FILES := $(shell find . -name "*.cpp" -type f)
OBJECTS := $(subst .cc,.o,$(CC_FILES))
OBJECT := ./instruction.cpp ./main.cpp

SYSTEMC_HOME := /usr/local/systemc-2.3.1



INC := -I. -I$(SYSTEMC_HOME)/include
LIBDIR := -L. -L$(SYSTEMC_HOME)/lib-$(TARGET_ARCH)
LIBS := -lsystemc -lm


CDC_Sim_target:  $(OBJECT) $(SYSTEMC_HOME)/lib-$(TARGET_ARCH)/libsystemc.a
	$(CXX) $(INC) $(LIBDIR) -Wl,-rpath=$(SYSTEMC_HOME)/lib-$(TARGET_ARCH) -o $(DESIGN) $(OBJECT) $(LIBS)


