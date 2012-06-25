/*
Author:  Weixian Zhou, ideazwx@gmail.com
Date:    June 22, 2012
Problem: Anagrams
Difficulty: easy
Source:  http://www.leetcode.com/onlinejudge
Notes:
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.

Solution:
sort every string in alphabetical order and create a mapping from the original
string to the sorted string. Then traverse the sorted string array to get the
mapping orignal result strings.
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

class Solution {
public:
     vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, vector<string> > dict;

        if (strs.size() == 0) {
            return result;
        }

        for (size_t i = 0; i < strs.size(); i++) {
            string sorted(strs[i]);
            sort(sorted.begin(), sorted.end());
            dict[sorted].push_back(strs[i]);
        }

        map<string, vector<string> >::iterator it;
        for (it = dict.begin(); it != dict.end(); it++) {
            if (it->second.size() > 1) {
                for (size_t i = 0; i < it->second.size(); i++) {
                    result.push_back(it->second[i]);
                }
            }
        }

        return result;
    }
};

