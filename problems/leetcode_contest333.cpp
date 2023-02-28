//
// Created by Tran Giang on 2/27/23.
//
#include "utils.cpp"
#include <iostream>
#include <map>

using namespace std;
vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int, int> map;
    for(auto nums: nums1){
         int id = nums[0];
         int val = nums[1];
         if(!map.count(id)){
             map[id] = val;
         }
    }
    for(auto nums: nums2){
        int id = nums[0];
        int val = nums[1];
        if(!map.count(id)){
            map[id] = val;
        }else{
            map[id] += val;
        }
    }
    vector<vector<int>> res;
    for(auto &it : map){
        vector<int> temp {it.first, it.second};
        res.push_back(temp);
    }
    return res;
}

int minOperations(int n) {
    int res = 0;
    while(n > 0){
        if((n%3) == 3){
            n++;
            res++;
        }else{
            res += n&1;
            n = n >> 1;
        }
    }
    return res;
}

