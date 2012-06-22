/*
Author:  Weixian Zhou, ideazwx@gmail.com
Date:    June 21, 2012
Problem: Add Binary
Difficulty: easy
Source:  http://www.leetcode.com/onlinejudge
Notes:
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
*/
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i, j;
        int carry;
        int count;
        string result;

        i = a.length() - 1;
        j = b.length() - 1;
        carry = 0;

        while (i >= 0 && j >= 0) {
            count = 0;
            if (carry == 1) count++;
            if (a[i] == '1') count++;
            if (b[j] == '1') count++;

            if (count == 0) {
                carry = 0;
                result = "0" + result;
            }
            else if (count == 1) {
                carry = 0;
                result = "1" + result;
            }
            else if (count == 2) {
                carry = 1;
                result = "0" + result;
            }
            else {
                carry = 1;
                result = "1" + result;
            }
            i--;
            j--;
        }

        while (i >= 0) {
            count = 0;
            if (a[i] == '1') count++;
            if (carry == 1) count++;
            if (count == 0) {
                carry = 0;
                result = "0" + result;
            }
            else if (count == 1) {
                carry = 0;
                result = "1" + result;
            }
            else{
                carry = 1;
                result = "0" + result;
            }
            i--;
        }
        while (j >= 0) {
            count = 0;
            if (b[j] == '1') count++;
            if (carry == 1) count++;
            if (count == 0) {
                carry = 0;
                result = "0" + result;
            }
            else if (count == 1) {
                carry = 0;
                result = "1" + result;
            }
            else{
                carry = 1;
                result = "0" + result;
            }
            j--;
        }

        if (carry) {
            result = "1" + result;
        }
        return result;
    }
};



