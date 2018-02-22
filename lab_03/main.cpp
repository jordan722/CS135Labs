#include <iostream>

#include "funcs.h"

int main()
{
  std::cout << "This main is the real program\n";
  std::cout << "hello world\n" ;

  cout << east_storage("07/22/2016") << endl;
  cout << mineast() << endl;
  cout << maxeast() << endl;
  cout << compare("09/13/2016","09/17/2016") << endl;
  cout << reverse_order("09/13/2016","09/17/2016") << endl;

  return 0;
}
