// Fiz o teste unitário em c++
// A função que tinha que ser feita pelo exercício está em 
// C puro.

#include <iostream>
#include <vector>

typedef std::vector<int> Stack;

Stack *stackNew(void)
{
  return new Stack;
}

void stackFree(Stack *p)
{
  delete p;
}

void stackPush(Stack *p, int elem)
{
  p->push_back(elem);
}

int stackPop(Stack *p)
{
  int ret = p->back();
  p->pop_back();
  return ret;
}

int stackEmpty(Stack *p)
{
  return !p->size();
}

void print(Stack *p)
{
    std::cout << "[ ";
    for(int x : *p) {
        std::cout << x << ' ';
    }
    std::cout << "]\n";
}

extern "C" {

  void stackRemoveEven(Stack *p) {
    Stack *temp = stackNew();
    
    while(!stackEmpty(p)){
      int elem = stackPop(p);
      if ((elem &0x01)){
        stackPush(temp, elem);
      }
    }
    
    while(!stackEmpty(temp)){
      stackPush(p, stackPop(temp));
    }

    stackFree(temp);
  }

}

int main() {

  int i;
  Stack *p = stackNew();
  for(i = 0; i<10; i++){
    stackPush(p, i);
  }
  print(p);
  stackRemoveEven(p);
  print(p);  
} 