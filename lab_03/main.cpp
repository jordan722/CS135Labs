#include <iostream>

#include "funcs.h"

int main()
{
  std::cout << "This main is the real program\n";
  std::cout << "hello world\n" ;
  double min;

  min = mineast();
  std::cout << "Minimum east is " << min << std::endl;

  return 0;
}
