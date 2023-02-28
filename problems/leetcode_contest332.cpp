//
// Created by Tran Giang on 2/28/23.
//
#include "utils.cpp"
#include <iostream>
#include <math.h>
using namespace std;

long long count(vector<int>& nums, int value){
    int n = nums.size();
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int j = n-1;
        while(i < j && nums[i]+nums[j] > value){ --j;}
        res += (j-i);
    }
    return res;
}

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    return count(nums, upper) - count(nums, lower-1);
}

long long findTheArrayConcVal(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = n-1;
    long res = 0;
    while(left < right){
        int num_digit = log10(nums[right]);
        long sum = nums[left]*pow(10, num_digit+1) + nums[right];
        res += sum;
        ++left;
        --right;
    }
    if(n%2 != 0){
        res += nums[n/2];
    }
    return res;
}

void solvep(){
    string s;
    getline(cin, s);
    vector<string> arr = split_string(s);
    vector<int> nums;
    for(auto a: arr){
        nums.push_back(stoi(a));
    }
    int lower, upper;
    cin >> lower;
    cin >> upper;
    int res = countFairPairs(nums, lower, upper);

    cout << res << endl;
}