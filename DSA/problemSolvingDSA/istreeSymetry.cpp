#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        bool value=true;
        while((!q1.empty())&&(!q2.empty()))
        {
            TreeNode * c1=q1.front();
            TreeNode * c2=q2.front();
            q1.pop();
            q2.pop();
            if(c1==nullptr&&c2==nullptr)
            {
                continue;
            }
            if(c1==nullptr||c2==nullptr)
                return false;
        

            if(c1->val != c2->val)
                return false;
            
            if(c1->left||c2->left)
            {
                q1.push(c1->left);
                q2.push(c2->left);
            }
            if(c1->right||c2->right)
            {
                q1.push(c1->right);
                q2.push(c2->right);
            }
        }

        return value;
    }
};