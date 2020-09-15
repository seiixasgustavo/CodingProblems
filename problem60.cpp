#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int listSum(const vector<int> &list)
{
  int sum = 0;
  for (auto x : list)
  {
    sum += x;
  }
  return sum;
}

bool hasSubset(const vector<int> &list, int index, int sum)
{
  vector<vector<bool>> dp(index + 1, vector<bool>(sum + 1));

  for (int j = 1; j <= sum; j++)
    dp[0][j] = false;
  for (int i = 0; i <= index; i++)
    dp[i][0] = true;

  for (int i = 1; i <= index; i++)
    for (int j = 1; j <= sum; j++)
    {
      if (list[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j] || dp[i][j - list[i - 1]];
    }

  return dp[index][sum];
}

bool canPartition(const vector<int> &list)
{
  int sum = listSum(list);
  return !(sum & 1) && hasSubset(list, list.size(), sum / 2);
}

int main()
{
  vector<int> list{2, 4, 8};
  vector<int> list2{15, 5, 20, 10, 35, 15, 10};
  cout << (canPartition(list2) == true ? "true" : "false") << endl;
  return 0;
}

// Solving using recursion
// bool hasSubsetWithRecursion(const vector<int> &list, int index, int sum)
// {
//   if (sum == 0)
//     return true;
//   if (index == 0)
//     return false;
//   if (list[index] > sum)
//     return hasSubsetWithRecursion(list, index - 1, sum);
//   return hasSubsetWithRecursion(list, index - 1, sum - list[index]) || hasSubsetWithRecursion(list, index - 1, sum);
// }

// bool hasSubset2(const vector<int> &list)
// {
//   int sum = listSum(list);
//   if (sum % 2 == 1)
//     return false;
//   return hasSubsetWithRecursion(list, list.size() - 1, sum / 2);
// }