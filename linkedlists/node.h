#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"

class Node {
 public:
  Node();
  Node(Student*);
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);
  ~Node();
 private:
  Student* student;
  Node* next = NULL;
};

#endif
