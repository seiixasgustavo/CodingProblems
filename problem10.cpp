#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

template <typename T>
void scheduler(T f, int n)
{
  this_thread::sleep_for(chrono::milliseconds(n));
  f();
}

int main()
{
  scheduler(([]() -> void { cout << "Hello\n"; }), 5000);
  return 0;
}