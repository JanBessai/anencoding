CXX = clang++
ACXX = ag++
LDFLAGS = -lgmp -lgmpxx
ACXXFLAGS = 
CXXFLAGS = -O3 -std=c++0x

all : anencode

anencode : lut.o main.o
	$(ACXX) $(ACXXFLAGS) $(LDFLAGS) main.o lut.o -o anencode

lut.o : lut.cpp
	$(CXX) $(CXXFLAGS) -c lut.cpp -o lut.o

%.o : %.cpp
	$(ACXX) $(ACXXFLAGS) -c $< -o $@

clean :
	rm -f *.o anencode

.PHONY : clean
