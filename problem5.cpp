#include <iostream>

using namespace std;

template <typename T>
using choice = function<T(T, T)>;
template <typename T>
using makeChoice = function<T(choice<T>)>;

template <typename T>
makeChoice<T> cons(T a, T b)
{
  auto p = [ a, b ](auto c) -> auto
  {
    return c(a, b);
  };
  return p;
}

template <typename T>
T car(makeChoice<T> f)
{
  auto left = [](T a, T b) {
    return a;
  };
  return f(left);
}

template <typename T>
T cdr(makeChoice<T> f)
{
  auto right = [](T a, T b) {
    return b;
  };
  return f(right);
}

int main()
{
  auto x = car(cons(2, 3));
  auto y = cdr(cons('a', 'b'));
  cout << x << ' ' << y << endl;
  return 0;
}