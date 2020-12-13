#ifndef PROJECT_HASH_OBJECT_H
#define PROJECT_HASH_OBJECT_H

#include <string>

namespace xj {

class HashObject {
 public:
  HashObject() {}
  ~HashObject() {}
  
  // no copy of this object
  HashObject(const HashObject&) = delete;
  HashObject& operator=(const HashObject&) = delete;
  
  std::string key() { return key_; }
  std::string value()  { return value_; }
  const std::string& key() const { return key_; }
  const std::string& value() const { return value_; }
  
  void set_as_dummy() {
    key_ = get_dummy_key();
    value_ = "";
  }
  
  void set_key(const std::string& key) {
    key_ = key;
  }
  void set_value(const std::string& value) {
    value_ = value;
  }
  
  static const std::string get_dummy_key() {
    return "<Dummy>";
  }
  static const std::string get_null_key() {
    return "<Null>";
  }
  
 private:
  std::string key_;
  std::string value_;
};

} // namespace xj

#endif // !PROJECT_HASH_OBJECT_H