CC = g++ 
CCFLAGS = -Wno-deprecated -g -O3
OBJ_MAIN = tmp/objects/Mymain.o
OBJ_MY_FUNCTIONS = ../tmp/objects/functionsForAnalysis.o
OBJECTS =  $(OBJ_MAIN) $(OBJ_MY_FUNCTIONS)
ROOTLIB = $(shell $(ROOTSYS)/bin/root-config --cflags --libs)
EXE = tmp/MyAnalysis

MyAnalysis : MyAnalysis.cc $(OBJECTS)
	$(CC) $(CCFLAGS) -o  $(EXE) MyAnalysis.cc $(OBJECTS) $(ROOTLIB)

functionsForAnalysis.o : ../functionsForAnalysis.h ../functionsForAnalysis.cc
	$(CC)  -c ../functionsForAnalysis.cc -o $(OBJ_MY_FUNCTIONS) $(ROOTLIB)

$(OBJ_MAIN) : Mymain.cc
	$(CC) -c Mymain.cc -o $(OBJ_MAIN) $(ROOTLIB)

.PHONY : clean
clean: 
	-rm $(OBJECTS)
