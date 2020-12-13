#include "hash_table_tests.h"

void run_all_tests() {
  test_insert_exist();
  test_probing();
  test_get();
  test_remove();
  std::cout << "All tests passed.\n";
}

void test_insert_exist() {
  xj::HashTable states(100);
  
  xj::HashObject tx;
  tx.set_key("Texas");
  tx.set_value("Austin");
  
  states.insert(&tx);
  
  assert(states.exist("Texas"));
}

void test_probing() {
  // setting high load to force collisions
  xj::HashTable states(8);
  
  xj::HashObject tx;
  tx.set_key("Texas");
  tx.set_value("Austin");
  
  xj::HashObject ca;
  ca.set_key("California");
  ca.set_value("Sacramento");
  
  xj::HashObject nm;
  nm.set_key("New Mexico");
  nm.set_value("Santa Fe");  
  
  xj::HashObject fl;
  fl.set_key("Florida");
  fl.set_value("Tallahassee");
  
  xj::HashObject oregon;
  oregon.set_key("Oregon");
  oregon.set_value("Salem");
  
  xj::HashObject wa;
  wa.set_key("Washington");
  wa.set_value("Olympia");
  
  xj::HashObject ut;
  ut.set_key("Utah");
  ut.set_value("Salt Lake City");
  
  xj::HashObject ny;
  ny.set_key("New York");
  ny.set_value("Albany");
  
  xj::HashObject mn;
  mn.set_key("Minnesota");
  mn.set_value("St. Paul");
  
  states.insert(&tx); // 1
  states.insert(&ca); // 0
  states.insert(&nm);
  states.insert(&fl);
  states.insert(&oregon);
  states.insert(&wa);
  states.insert(&ut);
  states.insert(&ny);
  states.insert(&mn);
  
  //  Texas:1
  //  California:0
  //  New Mexico:5
  //  Florida:5
  //  Oregon:4
  //  Washington:0
  //  Utah:6
  //  New York:7
  //  Minnesota:6
  
  states.dump();
  //  0: California:Sacramento
  //  1: Texas:Austin
  //  2: Washington:Olympia
  //  3: New York:Albany
  //  4: Oregon:Salem
  //  5: New Mexico:Santa Fe
  //  6: Florida:Tallahassee
  //  7: Utah:Salt Lake City
  
  assert(states.exist("California"));
  assert(states.exist("New Mexico"));
  assert(states.exist("Florida"));
  assert(!states.exist("Minnesota")); // no room
}

void test_get() {
  xj::HashTable states(8);
  
  xj::HashObject tx;
  tx.set_key("Texas");
  tx.set_value("Austin");
  
  states.insert(&tx);
  
  assert(states.get("Texas") == "Austin");
}

void test_remove() {
  xj::HashTable states(8);
  
  xj::HashObject tx;
  tx.set_key("Texas");
  tx.set_value("Austin");
  
  states.insert(&tx);
  
  assert(states.exist("Texas"));
  
  states.remove("Texas");
  
  assert(!states.exist("Texas"));
}