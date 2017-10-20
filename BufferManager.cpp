#include <iostream>
#include <memory>
#include <string>
#include "BufferManager.h"

Buffer::Buffer(int n) : size(n), next(nullptr), previous(nullptr) {
  char* head = new char[size];
}

int Buffer::put(char c) {
  *p = c;
  if ( (loc -1) == size )
    return -1;
  return 1;
}
  
void Buffer::~Buffer() {
  if (next != nullptr && previous != nullptr) {
      next->previous = previous;
      previous->next = next;
    } else if (next == nullptr) {
      previous->next = nullptr;
    } else {
      next->previous = nullptr;
    }
    delete head;
}

void Buffer::put(char c) {
  if ( p->put(c) \== -1 ) {
    allocNewBuffer();
  }
}
  
void Buffer::allocNewBuffer() {
  p->next = new Buffer(incrementSize); // the next buffer might have other chars
}
