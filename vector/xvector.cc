#include "xvector.h"

#include <iostream>
#include <cstdio>

namespace xj {

  XVector::XVector(int capacity) : size_(0) {
    if (capacity == 0) {
      printf("Cannot make vector of that size.\n");
      // TODO: handle this
      exit(EXIT_FAILURE);
    }

    int actual_capacity = DetermineCapacity(capacity);
    capacity_ = actual_capacity;
    data_ = std::unique_ptr<int[]>(new int[actual_capacity]);
  }

  XVector::~XVector() { }

  // Increases the capacity_of the vector.
  void XVector::Grow() {
    int old_capacity = capacity_;
    int new_capacity = DetermineCapacity(old_capacity);

    if (old_capacity != new_capacity) {
      std::unique_ptr<int[]> new_data(new int[new_capacity]);

      for (int i = 0; i < size_; i++) {
        new_data[i] = data_[i];
      }

      data_ = std::move(new_data);
      capacity_ = new_capacity;
    }
  }

  // Decreases the capacity_of the vector.
  void XVector::Shrink() {
    int old_capacity = capacity_;
    int new_capacity = old_capacity / 2;

    if (new_capacity < kMinCapacity) {
      new_capacity = kMinCapacity;
    }

    // this block is same to Grow()
    if (old_capacity != new_capacity) {
      std::unique_ptr<int[]> new_data(new int[new_capacity]);

      for (int i = 0; i < size_; i++) {
        new_data[i] = data_[i];
      }

      data_ = std::move(new_data);
      capacity_ = new_capacity;
    }
  }

  void XVector::ResizeForSize(int candinate_size) {
    if (capacity_ < candinate_size) {
      // grow
      Grow();
    } else if (capacity_ > candinate_size) {
      // shrink
      if (size_ < capacity_ / kShrinkFactor) {
        Shrink();
      }
    }
  }

  // Determines the capacity for the vector.
  int XVector::DetermineCapacity(int capacity) {
    int actual_capacity = kMinCapacity;

    while (capacity > actual_capacity / kGrowthFactor) {
      actual_capacity *= kGrowthFactor;
    }

    return actual_capacity;
  }

  // Prints out public information about the vector.
  void XVector::Dump() const {
    printf("size: %d\ncapacity: %d\nitems:\n", size_, capacity_);
    for (int i = 0; i < size_; i++) {
      printf("%d: %d\n", i, data_[i]);
    }
  }

  // Returns the value sotred at the given index
  int XVector::At(int index) const {
    RangeCheck(index);
    return data_[index];
  }

  // Appends the given value to the end of the vector.
  void XVector::PushBack(int value) {
    ResizeForSize(size_ + 1);

    data_[size_] = value;
    ++size_;
  }

  // Returns the last item in the vector, and removes it.
  int XVector::PopBack() {
    if (size_ == 0) {
      printf("Nothing to pop.\n");
      exit(EXIT_FAILURE);
    }

    ResizeForSize(size_ - 1);

    int value = data_[size_ - 1];
    --size_;
    return value;
  }

  // Inserts the given value at the given index, shifting
  // current and trailing items to the right.
  void XVector::Insert(int index, int value) {
    RangeCheck(index);

    ResizeForSize(size_ + 1);

    // shift items to the right
    for (int i = size_; i > index; i--) {
      data_[i] = data_[i - 1];
    }

    // insert item
    data_[index] = value;
    ++size_;
  }

  // Deletes item at index, shifting all trailing items left.
  void XVector::Remove(int index) {
    RangeCheck(index);

    ResizeForSize(size_ - 1);

    // shift items to the right
    for (int i = index; i < size_ - 1; i++) {
      data_[i] = data_[i + 1];
    }

    --size_;
  }

  // Searches for value and returns the first index with that value,
  // -1 if not found.
  int XVector::Find(int value) const {
    int found_index = -1;

    for (int i = 0; i < size_; i++) {
      if (data_[i] == value) {
        found_index = i;
        break;
      }
    }

    return found_index;
  }

} // namespace xj
