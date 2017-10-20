#include <iostream>
#include <memory>
#include <string>

class Buffer {  
 public:
  char* p; // keeps track of where you are in the current buffer
  Buffer() = default;
  Buffer(int);
  void put(char);
  ~Buffer();
  
 private:
  int size;
  int loc; // mark location of the current buffer
  char* head;
  Buffer* next;
  Buffer* previous;
};

class BufferManager {
 public:
  BufferManager() = default;
  BufferManager(int n);
  void put(char c);
  void allocNewBuffer();

 private:
  int incrementSize;
  Buffer* p; // current buffer
  Buffer* head;
  Buffer* tail;
};
