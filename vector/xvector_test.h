#ifndef PROJECT_XVECTOR_TEST_H
#define PROJECT_XVECTOR_TEST_H

#include "xvector.h"

namespace xj {

class XVectorTest {
 public:
  void RunTests() const;
  void TestSize() const;
  // Tests increases and decreases in capacity based on number of items stored.
  void TestCapacity() const;
  void TestEmpty() const;
  void TestAt() const;
  void TestPop() const;
  void TestInsert() const;
  void TestRemove() const;
  void TestFind() const;
};

} // namespace xj

#endif // PROJECT_XVECTOR_TEST_H
