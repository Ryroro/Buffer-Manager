#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

// This library allows user to use buffer link list to manage
// chars.
//
// Buffer is the basic unit of the buffer link list. Buffer
// unit is responsible for pushing chars, popping chars. It
// also holds information of the previous buffer and the next
// buffer. It is not responsible for the management of multiple
// buffer
//
// Buffer Manager is responsible for managing the buffers,
// including creating new buffer, destroying buffer.
//
// The user is responsible for the destroy of the buffer
// manager
//


#include <iostream>
#include <memory>
#include <string>


class Buffer {
  friend class BufferManager;
 public:
  char* cur; // keeps track of where you are in the current buffer
  Buffer() = default;
  Buffer(int);
  int put(char);
  int pop();
  ~Buffer();
  
 private:
  int size;
  int loc; // mark location of the current buffer
  char* head; // mark the current pointer in the buffer
  Buffer* next;
  Buffer* previous;
};

class BufferManager {
 public:
  BufferManager() = default;
  BufferManager(int n);
  void put(char c);
  void pop();
  void allocNewBuffer();
  void destroyBuffer();
  ~BufferManager();

 private:
  int incrementSize;
  Buffer* p; // current buffer
  Buffer* head;
  Buffer* tail;
};

#endif
