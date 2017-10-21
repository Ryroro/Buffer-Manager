#include <iostream>
#include <memory>
#include <string>
#include "BufferManager.h"

Buffer::Buffer(int n) : size(n), next(nullptr), previous(nullptr) {
  char* head = new char[size];
}

int Buffer::put(char c) {
  if ( (loc + 1) == size ) {
    return -1; // indicate that buffer running out of memory
               // send signals to require new buffer
  } else {
    cur++;
    *cur = c;
    loc++;
  }
  return 1;x
}

int Buffer::pop() {
  if ( loc == 0 ) {
    return -1; // the buffer is empty
  } else {
    loc--;
    cur--;
  }
  return 1;
}

Buffer::~Buffer() {
  delete head;
}

BufferManager::BufferManager(int n): incrementSize(n) {
  p = new Buffer(n);
}

void BufferManager::put(char c) {
  if ( p->put(c) == -1 ) {
    allocNewBuffer();
  }
  p->put(c);
}

void BufferManager::pop() {
  if ( p->pop() == -1 ) {
    if ( p->previous == nullptr ) {
      throw std::out_of_range("No char in the buffer");
    } else {
      // NOTE!! fill in the blank to delete the parser later
      p = p->previous;
      p->pop();
    }
  }
}

void BufferManager::allocNewBuffer() {
  p->next = new Buffer(incrementSize); // the next buffer might have other chars
  p = p->next;
}

void BufferManager::destroyBuffer() {
  if ( p->previous == nullptr ) {
  } else {
    p = p->previous;
    delete p;
  }
}

BufferManager::~BufferManager() {
  while ( p->previous != nullptr ) {
    destroyBuffer();
  }
}
