#include <iostream>

using namespace std;

struct UnivalTree
{
  bool value;
  UnivalTree *left;
  UnivalTree *right;

  UnivalTree(bool value) : value(value), left(nullptr), right(nullptr){};
  UnivalTree(bool value, UnivalTree *left, UnivalTree *right) : value(value), left(left), right(right){};
};

int univalTree(UnivalTree *root)
{
  // Basic Cases
  if (root == nullptr)
    return 0;
  if (root->right == nullptr && root->left == nullptr)
    return 1;

  // Single Child Tree
  if (root->left == nullptr)
  {
    if (root->right->value == root->value)
      return 1 + univalTree(root->right);
    return univalTree(root->right);
  }
  if (root->right == nullptr)
  {
    if (root->left->value == root->value)
      return 1 + univalTree(root->left);
    return univalTree(root->left);
  }

  // Two Children Tree
  if (root->right->value == root->left->value && root->left->value == root->value)
    return 1 + univalTree(root->left) + univalTree(root->right);
  return univalTree(root->left) + univalTree(root->right);
}

int main()
{
  auto res = univalTree(new UnivalTree(false, new UnivalTree(true), new UnivalTree(true)));
  cout << res << endl;
}