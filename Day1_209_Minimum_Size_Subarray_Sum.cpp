#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void pushStart(int & sum, int & target, int & s, vector<int>& nums){
        while(sum >= target){
            sum -= nums[s++];
        } 
        sum += nums[--s];
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int sum = 0, s = 0, e = 0;
        while(e< nums.size() && sum< target){
            sum += nums[e++];
        }
        if (sum < target)
            return 0;
        if (sum >= target){
            pushStart(sum, target, s, nums);
        }
        while(e< nums.size()){
            sum += nums[e++];
            sum -= nums[s++];
            if (sum >= target){
                pushStart(sum, target, s, nums);
            }
        }
        return e-s;
    }
};