#include <iostream>

using namespace std;

struct XORLinkedList
{
  XORLinkedList *address;
  int value;

  XORLinkedList(int value) : value(value), address(nullptr){};
};

auto xorNode(XORLinkedList *a, XORLinkedList *b)
{
  return ((XORLinkedList *)((uintptr_t)a ^ (uintptr_t)b));
}

void addElement(XORLinkedList *root, int value)
{
  XORLinkedList *act = root;
  XORLinkedList *before = nullptr;
  XORLinkedList *next;

  next = xorNode(before, act->address);
  while (next != nullptr)
  {
    before = act;
    act = next;
    next = xorNode(before, act->address);
  }

  auto newNode = new XORLinkedList(value);
  act->address = xorNode(before, newNode);
  newNode->address = xorNode(act, nullptr);
}

void printList(XORLinkedList *root)
{
  XORLinkedList *before = nullptr;
  XORLinkedList *act = root;
  XORLinkedList *temp;

  while (act != nullptr)
  {
    cout << act->value << ' ';
    temp = before;
    before = act;
    act = xorNode(act->address, temp);
  }
  cout << endl;
}

int main()
{
  auto list = new XORLinkedList(1);
  addElement(list, 2);
  addElement(list, 3);
  addElement(list, 4);
  addElement(list, 5);
  addElement(list, 6);
  addElement(list, 7);
  addElement(list, 8);
  printList(list);
  return 0;
}