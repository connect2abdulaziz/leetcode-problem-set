#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (const int & a: nums)
            if (a != val) nums[k++] = a;
        return k;
    }
};