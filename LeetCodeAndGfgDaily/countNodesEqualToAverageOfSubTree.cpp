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
    pair<int, int> sumCnt(TreeNode* root, int &cnt){
        if(root == NULL){
            return {0,0};
        }

        pair<int,int> left = sumCnt(root->left, cnt);
        pair<int,int> right = sumCnt(root->right, cnt);

        int sumL = left.first, cntL = left.second;
        int sumR = right.first, cntR = right.second;

        if((sumL + sumR + root->val)/(cntL + cntR + 1) == root->val) cnt++;
        return {sumL + sumR + root->val, cntL + cntR + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        sumCnt(root, cnt);
        return cnt;
    }
};