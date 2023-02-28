//
// Created by Tran Giang on 2/17/23.
//
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int min_diff_in_BST(TreeNode* root){
    int dist = 1000001;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left){
            q.push(curr->left);
            dist = min(abs(curr->left->val-curr->val), dist);
        }
        if(curr->right){
            q.push(curr->right);
            dist = min(abs(curr->right->val-curr->val), dist);
        }
    }
    return dist;
}

void solve(){
    TreeNode t1(4);
    TreeNode t21(2);
    TreeNode t22(6);
    TreeNode t31(1);
    TreeNode t32(3);
    t1.left = &t21;
    t1.right = &t22;
    t21.left = &t31;
    t21.right = &t32;
    int res = min_diff_in_BST(&t1);
    cout << res << endl;
}