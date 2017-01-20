#source file
#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
  
#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET  := shtvm
  
#compile and lib parameter
#编译参数
CC      := g++
LINK 	:= g++
LIBS    := -L. -L../lib/ `pkg-config --libs gtk+-2.0 gthread-2.0`
INCLUDE := -I. -I../include/ -I../xpp/ `pkg-config --cflags gtk+-2.0 gthread-2.0`
LINKCFLAGS += -lpthread -lBnrCtlL32 $(INCLUDE) $(LIBS) -lstdc++
CFLAGS  := -g $(INCLUDE)
  
#i think you should do anything here
#下面的基本上不需要做任何改动了
.PHONY : everything objs clean veryclean rebuild
  
everything : $(TARGET)
  
all : $(TARGET)
  
objs : $(OBJS)
	
rebuild: clean everything
                
clean :
	rm -fr *.so
	rm -fr *.o
	rm -fr $(TARGET)
    
$(TARGET) : $(OBJS)
	$(LINK)  -o $@ $(OBJS) $(LDFLAGS) $(LIBS) $(LINKCFLAGS)

$(OBJS):%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
