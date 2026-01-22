#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};*/

class Solution {
  public:
    void solve(Node* root,int sum,int curr,vector<int> &temp,vector<vector<int>> &result){
        if(!root){
            return;
        }
        // add value of key to out current sum
        curr=curr+root->key;
        // add key to our temp vector
        temp.push_back(root->key);
        // check if curr sum == required sum add temp to result. and then move ahead because there are negative no and there may be new paths in the very existing temp.
        if(curr==sum){
            result.push_back(temp);
        }
        // traverse left tree
        solve(root->left,sum,curr,temp,result);
        // traverse right tree
        solve(root->right,sum,curr,temp,result);
        // while returning remove the key that was added at last.
        temp.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(root,sum,0,temp,result);
        return result;
    }
};

