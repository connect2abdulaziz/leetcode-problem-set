#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num;
        copy(nums1.begin(), nums1.begin() + m, back_inserter(num));
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
            if (num[i] < nums2[j])
                nums1[k++] = num[i++];
            else
                nums1[k++] = nums2[j++];
        while (i < m)
            nums1[k++] = num[i++];
        while (j < n)
            nums1[k++] = nums2[j++];
    }
};
//2nd method
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        reverse(nums1.begin(), nums1.end());
        reverse(nums1.end() - m, nums1.end());
        int i = nums1.size() - m, j = 0, k = 0;
        while (i < nums1.size() && j < n)
            if (nums1[i] < nums2[j])
                nums1[k++] = nums1[i++];
            else
                nums1[k++] = nums2[j++];
        while (j < n)
            nums1[k++] = nums2[j++];
    }
};