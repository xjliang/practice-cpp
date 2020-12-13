#include "hash_table.h"

namespace xj {

HashTable::HashTable(const int size)
    : size_(size), data_(new HashObject[size]) {
  assert(data_);
  
  for (int i = 0; i < size_; i++) {
    data_[i].set_key(HashObject::get_null_key());
  }
}

HashTable::~HashTable() {
  delete[] data_;
}

int HashTable::hash(const std::string& key) const {
  int hash = 0;
  int key_length = static_cast<int>(key.size());
  for (int i = 0; i < key_length; i++) {
    hash = hash * 31 + key[i];
  }
  return abs(hash % size_);
}

bool HashTable::exist(const std::string& key) const {
  int index = hash(key);
  const int orig_index = index;
  bool found = false;
  
  while (data_[index].key() != HashObject::get_null_key()) {
    if (data_[index].key() == key) {
      found = true;
      break;
    }
    index = (index + 1) % size_;
    if (index == orig_index) {
      break;
    }
  }
  
  return found;
}

void HashTable::insert(const HashObject* obj) {
  if (obj == nullptr) {
    return;
  }

  int index = hash(obj->key());
  const int orig_index = index;
  int dummy_index = -1;
  
  bool found = false;
  while (data_[index].key() != HashObject::get_null_key()) {
    if (data_[index].key() == obj->key()) {
      found = true;
      break;
    } else if (data_[index].key() == HashObject::get_dummy_key()) {
      dummy_index = index;
    }
    index = (index + 1) % size_;
    if (index == orig_index) {
      return;
    }
  }
  
  if (!found && dummy_index != -1) {
    index = dummy_index;
  }
  
  data_[index].set_key(obj->key());
  data_[index].set_value(obj->value());
}

void HashTable::dump() const {
  for (int i = 0; i < size_; i++) {
    std::cout << i << ": " << data_[i].key()
                   << ":" << data_[i].value() << std::endl;
  }
}

void HashTable::remove(const std::string& key) {
  int index = hash(key);
  const int orig_index = index;
  
  while (data_[index].key() != HashObject::get_null_key()) {
    if (data_[index].key() == key) {
      data_[index].set_key(HashObject::get_dummy_key());
      data_[index].set_value("");
      break;
    }
    index = (index + 1) % size_;
    if (index == orig_index) {
      break;
    }
  }
}

const std::string HashTable::get(const std::string& key) const {
  int index = hash(key);
  const int orig_index = index;
  
  while (data_[index].key() != HashObject::get_null_key()) {
    if (data_[index].key() == key) {
      return data_[index].value();
    }
    index = (index + 1) % size_;
    if (index == orig_index) {
      break;
    }
  }
  
  return nullptr;
}
    
} // namespace xj
