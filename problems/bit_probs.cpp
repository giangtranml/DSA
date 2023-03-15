//
// Created by Tran Giang on 3/1/23.
//
#include <iostream>
#include <math.h>
using namespace std;
int countSetBits(int n){
    if(n <= 1){ return 1;}
    int x = log2(n);
    return x*(1<<(x-1)) + 1 + (n-(1<<x)+1) + countSetBits(n-(1<<x));
}

int maxConsecutiveOnes(int N)
{
    // code here
    int bit_len = log2(N);
    int longest = 1;
    for(int i = 0; i <= bit_len; i++){
        int x = 1<<i;
        cout << ((x^(x-1))&N);
        longest = max(longest, (x^(x-1))&N);
    }
    while(longest & 1 != 0){
        longest >>= 1;
    }
    return longest;
}