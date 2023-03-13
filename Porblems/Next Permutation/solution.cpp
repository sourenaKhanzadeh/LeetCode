//
// Created by sourena khanzadeh on 2023-03-12.
//


#include <algorithm>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};