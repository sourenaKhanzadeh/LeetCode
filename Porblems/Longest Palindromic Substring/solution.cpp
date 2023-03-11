//
// Created by sourena khanzadeh on 2023-03-11.
//
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string res = "";
        int max_len = 0;
        for(int i=0; i<s.size(); i++) {
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            if(max_len < r - l - 1) {
                res = s.substr(l + 1, r - l - 1);
                max_len = r - l - 1;
            }

            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            if(max_len < r - l - 1) {
                res = s.substr(l + 1, r - l - 1);
                max_len = r - l - 1;
            }
        }
        return res;
    }
};