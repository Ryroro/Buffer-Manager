#include <iostream>
#include "BufferManager.cpp"
using namespace std;

int main() {
  BufferManager* bufferManager = new BufferManager(10);
  const char *p = "hello, world\n it is nice to meet you";
  while (*p != '\0') {
    bufferManager->put(*p);
    p++;
  }
  return 0;


}
  
