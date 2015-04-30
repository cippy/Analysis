CC = g++ 
CCFLAGS = -Wno-deprecated -g -O3
INCLUDE = -I$(HOME)/Analysis/include
OBJ_MAIN = tmp/objects/main.o
OBJ_MY_FUNCTIONS = tmp/objects/functionsForAnalysis.o
OBJ_MY_CLASSES = tmp/objects/myClasses.o
OBJECTS =  $(OBJ_MAIN) $(OBJ_MY_FUNCTIONS) $(OBJ_MY_CLASSES)
ROOTLIB = $(shell $(ROOTSYS)/bin/root-config --cflags --libs)
EXE = tmp/Analysis
HEADER = $(HOME)/Analysis/include

Analysis : Analysis.cc $(OBJECTS)
	$(CC) $(CCFLAGS) -o  $(EXE) Analysis.cc $(OBJECTS) $(ROOTLIB) $(INCLUDE)

#Analysis.cc : $(OBJECTS)
#	$(CC) $(CCFLAGS) -o $(EXE) Analysis.cc $(OBJECTS) $(ROOTLIB)

$(OBJ_MY_FUNCTIONS) : $(HEADER)/functionsForAnalysis.h functionsForAnalysis.cc
	$(CC) -c functionsForAnalysis.cc -o $(OBJ_MY_FUNCTIONS) $(ROOTLIB) $(INCLUDE)

$(OBJ_MY_CLASSES) : $(HEADER)/myClasses.h myClasses.cc
	$(CC) -c myClasses.cc -o $(OBJ_MY_CLASSES) $(ROOTLIB) $(INCLUDE)

#functionsForAnalysis.cc : functionsForAnalysis.h
#	$(CC) -c functionsForAnalysis.cc -o $(OBJ_MY_FUNCTIONS) $(ROOTLIB)

$(OBJ_MAIN) : main.cc
	$(CC) -c main.cc -o $(OBJ_MAIN) $(ROOTLIB) $(INCLUDE)

.PHONY : clean
clean: 
	-rm $(OBJECTS)


