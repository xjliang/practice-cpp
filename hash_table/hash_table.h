#ifndef PROJECT_HASH_TABLE_H
#define PROJECT_HASH_TABLE_H

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include "hash_object.h"

namespace xj {

class HashTable{
 public:
  explicit HashTable(const int size);
  ~HashTable();
  // no copy of this object
  HashTable(const HashTable&) = delete;
  HashTable& operator=(const HashTable&) = delete;
  
  int hash(const std::string& key) const;
  
  // Inserts the given object to the hash table. If key exists, update the value.
  void insert(const HashObject* obj);
  
  // Returns true if the specified key exists in the hash table.
  bool exist(const std::string& key) const;
  
  // Returns the value associated with the specifed key, NULL if not present.
  const std::string get(const std::string& key) const;
  
  // Removes the value associated with the specified key from the hash table.
  void remove(const std::string& key);
  
  // Outputs the content of the hash table.
  void dump() const;
  
 private:
  int size_;
  HashObject* data_;
};
  
} // namespace xj


#endif // !PROJECT_HASH_TABLE_H