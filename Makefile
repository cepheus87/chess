EXEC = main
CO = g++

HEADER= functions.h chesspieceFunc.h

LIBS = 

FUNCTIONS= 
CFLAGS = -Wall 


%.o: %.cpp $(HEADER)
	$(CO) $(CFLAGS) -c $<


all: $(EXEC).o $(HEADER) $(FUNCTIONS)
	$(CO) $(CFLAGS) functions.cpp chesspieceFunc.cpp $(LIBS) $(FUNCTIONS) $(EXEC).o -o $(EXEC).exe 

clean:
	rm -f *.o *~ $(EXEC).exe
