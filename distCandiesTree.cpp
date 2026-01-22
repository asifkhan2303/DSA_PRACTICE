#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int solve(TreeNode *root, int &moves)
{
    if (!root)
        return 0;
    int l = solve(root->left, moves);
    int r = solve(root->right, moves);
    moves += abs(l) + abs(r);
    return (l + r + root->val) - 1;
}

int distributeCoins(TreeNode *root)
{
    int moves = 0;
    solve(root, moves);
    return moves;
}

int main()
{
    int n;
    cin >> n;

    if (n == 0)
        return 0;

    queue<TreeNode *> q;
    int x;
    cin >> x;

    TreeNode *root = new TreeNode(x);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n)
    {
        TreeNode *cur = q.front();
        q.pop();

        cin >> x;
        if (x != -1)
        {
            cur->left = new TreeNode(x);
            q.push(cur->left);
        }
        i++;

        if (i >= n)
            break;

        cin >> x;
        if (x != -1)
        {
            cur->right = new TreeNode(x);
            q.push(cur->right);
        }
        i++;
    }

    cout << distributeCoins(root);
    return 0;
}
