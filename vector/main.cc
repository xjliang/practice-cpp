#include "xvector.h"
#include "xvector.cc"
#include "xvector_test.h"
#include "xvector_test.cc"

int main(int argc, const char *argv[]) {

  xj::XVectorTest tests;
  tests.RunTests();

  return EXIT_SUCCESS;
}
