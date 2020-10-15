#include <iostream>

using namespace std;

string longestPath(string x)
{
  return x;
}

int main()
{
  string x = "dir/n/tsubdir1/n/t/tfile1.ext/n/t/tsubsubdir1/n/tsubdir2/n/t/tsubsubdir2/n/t/t/tfile2.ext";
  cout << longestPath(x) << endl;
}