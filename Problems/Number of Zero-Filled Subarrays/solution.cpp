//
// Created by sourena khanzadeh on 2023-03-22.
//

#include <vector>
/**
 * Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
 */
class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        long long res = 0;
        for (int i =0; i<nums.size(); i++){
            if(nums[i] != 0)
                continue;
            int j = i;
            int k = 1;
            while(j > nums.size() && nums[j] == 0){
                res += k;
                j++;
                i++;
                k++;
            }
        }
        return res;
    }
};