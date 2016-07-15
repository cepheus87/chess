EXEC = main
CO = g++

HEADER= functions.h 

CFLAGS = -Wall 


#%.o: %.cpp $(HEADER)
#	$(CO) $(CFLAGS) -c $<


all: $(EXEC).o $(HEADER) $(FUNCTIONS)
	$(CO) $(CFLAGS) functions.cpp $(EXEC).o -o $(EXEC).exe 

clean:
	rm -f *.o *~ $(EXEC).exe
