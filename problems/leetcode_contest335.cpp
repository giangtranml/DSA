//
// Created by Tran Giang on 3/5/23.
//
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include "utils.cpp"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void bfs(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        // Visit the current node
        cout << node->val << " ";
        // Add the left child to the queue
        if (node->left != NULL) {
            q.push(node->left);
        }
        // Add the right child to the queue
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
}

long long kthLargestLevelSum(TreeNode* root, int k) {
    map<int, long long> treemap;
    treemap[1] = root->val;
    queue<pair<int, TreeNode*>> q;
    pair<int, TreeNode*> t1(1, root);
    q.push(t1);
    while (!q.empty()) {
        pair<int, TreeNode*> pair_tree = q.front();
        int depth = pair_tree.first;
        TreeNode* node = pair_tree.second;
        q.pop();
        // Visit the current node
        cout << node->val << " ";
        // Add the left child to the queue
        if (node->left != NULL) {
            int child_depth = depth + 1;
            if(!treemap.count(child_depth)){
                treemap[child_depth] = 0;
            }
            treemap[child_depth] += node->left->val;
            pair<int, TreeNode*> pair_child(child_depth, node->left);
            q.push(pair_child);

        }
        // Add the right child to the queue
        if (node->right != NULL) {
            int child_depth = depth + 1;
            if(!treemap.count(child_depth)){
                treemap[child_depth] = 0;
            }
            treemap[child_depth] += node->right->val;
            pair<int, TreeNode*> pair_child(child_depth, node->right);
            q.push(pair_child);
        }
    }
    vector<long long> sums;
    for(auto [key, val]: treemap){
        sums.push_back(val);
    }
    sort(sums.rbegin(), sums.rend());
    return sums[k-1];
}

unsigned long long GCD(unsigned long long a, unsigned long long b){
    /* Greatest Common Divisor: finds multiplication of common prime factors.
     * E.g:
     *  30: 2x3x5
     *  15: 3x5
     *  => GCD(30, 15) = 3x5
     *  24: 2x2x2x3
     *  10: 2x5
     *  => GCD(24, 10) = 2
     *  --------------
     *  GCD(a, b) = a           if b = 0
     *            = GCD(b, a%b) if b > 0
    */
    return (b==0) ? a : GCD(b, a%b);
}

int findValidSplit(vector<int>& nums) {
    vector<unsigned long long> prefix_prod;
    int n = nums.size();
    prefix_prod.push_back(nums[0]);
    for (int i = 1; i < n; ++i) {
        prefix_prod.push_back(nums[i]*prefix_prod[i-1]);
    }
    cout << "----" << endl;
    print_1d_vector(prefix_prod);
    int res = -1;
    unsigned long long total_prod = prefix_prod[n-1];
    for (int i = 0; i < n-1; ++i) {
        unsigned long long gcd = GCD(prefix_prod[i], total_prod/prefix_prod[i]);
        cout << gcd << endl;
        if(gcd == 1){
            res = i;
            break;
        }
    }
    return res;
}

void solvep(){
    string s;
    getline(cin, s);

    vector<string> arr_s = split_string(s);
    vector<int> nums;
    for(auto str: arr_s){
        nums.push_back(stoi(str));
    }
    int res = findValidSplit(nums);
    cout << res << endl;
}