#include "encoded.h"
#include <iostream>

int main(int argc, char* argv[]) {
  Protected<int> x = protect(3);
  Protected<int> y = protect(4);
  Protected<int> z = x + y;
  z += protect(5);
  z *= protect(3);
  z /= protect(3);
  std::cout << z << std::endl;
  std::cout << z.value << std::endl;
  std::cout << "not z " << !z 
	    << " not not z " << !!z 
	    << " not not not z " << !!!z
	    << std::endl;
  std::cout << (z && z) 
	    << (z && !z) 
	    << (protect(0) && protect(0)) 
	    << (protect((unsigned int)0 ) && protect((unsigned int)1))
	    << std::endl;
  for (int i = 0; i < 12; ++i) {
    std::cout << std::dec << protect(i) << "/" << ~(protect(i)) << std::dec << std::endl;
  }
  return 0;
}

