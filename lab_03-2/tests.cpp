#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"



TEST_CASE("Testing Min"){
  CHECK(mineast()==49.34);

}


TEST_CASE("Testing Max"){
  CHECK(maxeast()==81.0);

}

TEST_CASE("Testing East Storage"){
  CHECK(east_storage("07/22/2016"));
  CHECK(east_storage("13/99/2016") == 0.0);
  CHECK(east_storage("")==0.0);

}

TEST_CASE("Testing East Storage"){
  std::string test_one = compare("09/13/2016","09/17/2016");
  CHECK(test_one == "09/13/2016 East\n09/14/2016 East\n09/15/2016 Equal\n09/16/2016 West\n09/17/2016 West\n");


}
