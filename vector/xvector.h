// Copyright 2020
// License
// Author: xjliang
// This is the header file for vector

#ifndef PRACTICE_CPP_XVECTOR_H_
#define PRACTICE_CPP_XVECTOR_H_

#include <memory> // shared_ptr
#include <exception>

namespace xj {

  static const int kMinCapacity = 16;
  static const int kGrowthFactor = 2;
  static const int kShrinkFactor = 4;

class XVector {

 public:
  XVector(int capacity);
  XVector(const XVector& other) = default;
  ~XVector();

  // Returns the number of items sotred in the vector.
  int size() const { return size_; }

  // Test whether vector is empty
  bool empty() const { return size_ == 0; }

  // Returns the capacity of the vector.
  int capacity() const { return capacity_; }

  // Prints out public information about the vector.
  void Dump() const;

  // Returns the value sotred at the given index
  int At(int index) const;

  // Appends the given value to the end of the vector.
  void PushBack(int value);

  // Returns the last item in the vector, and removes it.
  int PopBack();

  // Inserts the given value at the given index, shifting
  // current and trailing items to the right.
  void Insert(int index, int value);

  // Deletes item at index, shifting all trailing items left.
  void Remove(int index);

  // Searches for value and returns the first index with that value,
  // -1 if not found.
  int Find(int value) const;

 private:
  /// Safety check used only from At().
  void RangeCheck(int n) const {
    if (n >= this->size()) {
      throw std::out_of_range("vector::_M_range_check: __n ");
    }
  }

  // Increases the capacity_of the vector.
  void Grow();

  // Decreases the capacity_of the vector.
  void Shrink();

  // Checks to see if resizing is required for the given capacity
  // and grows or shrinks the vector as need.
  void ResizeForSize(int capacity);

  // Determines the capacity for the vector.
  int DetermineCapacity(int capacity);

 private:
  // The actual capacity that can be accommodated before resize is required
  int capacity_{kMinCapacity};

  // The number of items currently stored
  int size_{0};

  // The storage where ints are stored
  std::unique_ptr<int[]> data_;
};

} // namespace xj

#endif // PRACTICE_CPP_XVECTOR_H_
