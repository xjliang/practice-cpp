#include "xvector_test.h"
#include <iostream>
#include <cassert>

namespace xj {

void XVectorTest::RunTests() const {
  printf(">>> Testing Size()...\n");
  TestSize();
  printf(">>> Testing Empty()...\n");
  TestEmpty();
  printf(">>> Testing Capacity()...\n");
  TestCapacity();
  printf(">>> Testing At()...\n");
  TestAt();
  printf(">>> Testing PopBack()...\n");
  TestPop();
  printf(">>> Testing Insert()...\n");
  TestInsert();
  printf(">>> Testing Remove()...\n");
  TestRemove();
  printf(">>> Testing Find()...\n");
  TestFind();
  printf("<<< All tests passed.\n");
};

void XVectorTest::TestSize() const {
  xj::XVector tester(3);
  assert(tester.size() == 0);

  int items_to_add = 5;
  for (int i = 0; i < items_to_add; ++i) {
    tester.PushBack(i + 1);
  }
  assert(tester.size() == items_to_add);
}

void XVectorTest::TestEmpty() const {
  xj::XVector tester(3);
  assert(tester.empty());
}

void XVectorTest::TestCapacity() const {
  xj::XVector tester(4);

  // test increasing size
  assert(tester.capacity() == xj::kMinCapacity);
  for (int i = 0; i < 17; ++i) {
    tester.PushBack(i + 1);
  }
  assert(tester.capacity() == xj::kMinCapacity * 2);
  for (int j = 0; j < 20; ++j) {
    tester.PushBack(j + 1);
  }
  assert(tester.capacity() == xj::kMinCapacity * 4);

  // test decreasing size
  for (int k = 0; k < 30; ++k) {
    tester.PopBack();
  }
  assert(tester.capacity() == xj::kMinCapacity * 2);

  for (int k = 0; k < 7; ++k) {
    tester.PopBack();
  }
  assert(tester.capacity() == xj::kMinCapacity);
}

void XVectorTest::TestAt() const {
  xj::XVector tester(3);
  tester.PushBack(4);
  tester.PushBack(9);
  tester.PushBack(12);
  assert(tester.At(0) == 4);
  assert(tester.At(1) == 9);
  assert(tester.At(2) == 12);
}

void XVectorTest::TestPop() const {
  xj::XVector tester(1);
  tester.PushBack(3);

  int popped = tester.PopBack();
  assert(popped == 3);
  tester.PushBack(9);
  tester.PushBack(8);

  assert(tester.size() == 2);
  int popped2 = tester.PopBack();
  assert(popped2 == 8);
  assert(tester.size() == 1);
}

void XVectorTest::TestInsert() const {
  xj::XVector tester(3);
  tester.PushBack(5);
  tester.PushBack(7);
  tester.PushBack(9);
  tester.Insert(0, 4);
  assert(tester.At(0) == 4);
  assert(tester.At(1) == 5);
  assert(tester.At(2) == 7);
  assert(tester.At(3) == 9);
  tester.Insert(3, 8);
  assert(tester.At(3) == 8);
  assert(tester.At(4) == 9);
}

void XVectorTest::TestRemove() const {
  xj::XVector tester(5);
  tester.PushBack(50);
  tester.PushBack(2);
  tester.PushBack(50);
  tester.PushBack(4);
  tester.PushBack(50);
  tester.Remove(2);
  assert(tester.size() == 4);
  assert(tester.At(1) == 2);
  assert(tester.At(2) == 4);
}

void XVectorTest::TestFind() const {
  xj::XVector tester(3);
  tester.PushBack(4);
  tester.PushBack(7);
  tester.PushBack(11);
  assert(tester.Find(5) == -1);
  assert(tester.Find(4) == 0);
  assert(tester.Find(7) == 1);
  assert(tester.Find(11) == 2);
}

}  // namespace xj
