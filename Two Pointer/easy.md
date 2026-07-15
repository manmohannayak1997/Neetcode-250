EASY

1.Valid Palindrome
Problem Link
Description
Given a string s, return true if it is a palindrome, otherwise return false.
A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).
Example 1:
Input: s = "Was it a car or a cat I saw?"
Output: true
Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.
Example 2:
Input: s = "tab a cat"
Output: false

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            while (l < r && !alphaNum(s[l])) {
                l++;
            }
            while (r > l && !alphaNum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++; r--;
        }
        return true;
    }

    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};


2.Valid Palindrome II - Explanation
Problem Link
Description
You are given a string s, return true if the s can be a palindrome after deleting at most one character from it.
A palindrome is a string that reads the same forward and backward.
Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).
Example 1:
Input: s = "aca"
Output: true
Explanation: "aca" is already a palindrome.
Example 2:
Input: s = "abbadc"
Output: false
Explanation: "abbadc" is not a palindrome and can't be made a palindrome after deleting at most one character.
Example 3:
Input: s = "abbda"
Output: true



class Solution {
public:
    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return isPal(s, l + 1, r) ||
                       isPal(s, l, r - 1);
            }
        }

        return true;
    }
};

3.Merge Strings Alternately - Explanation
Problem Link
Description
You are given two strings, word1 and word2. Construct a new string by merging them in alternating order, starting with word1 — take one character from word1, then one from word2, and repeat this process.
If one string is longer than the other, append the remaining characters from the longer string to the end of the merged result.
Return the final merged string.
Example 1:
Input: word1 = "abc", word2 = "xyz"
Output: "axbycz"
Example 2:
Input: word1 = "ab", word2 = "abbxxc"
Output: "aabbbxxc"

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string res;
        for (int i = 0; i < n || i < m; i++) {
            if (i < n) {
                res += word1[i];
            }
            if (i < m) {
                res += word2[i];
            }
        }
        return res;
    }
};


4.Merge Sorted Array - Explanation
Problem Link
Description
You are given two integer arrays nums1 and nums2, both sorted in non-decreasing order, along with two integers m and n, where:
• m is the number of valid elements in nums1,
• n is the number of elements in nums2.
The array nums1 has a total length of (m+n), with the first m elements containing the values to be merged, and the last n elements set to 0 as placeholders.
Your task is to merge the two arrays such that the final merged array is also sorted in non-decreasing order and stored entirely within nums1.
You must modify nums1 in-place and do not return anything from the function.
Example 1:
Input: nums1 = [10,20,20,40,0,0], m = 4, nums2 = [1,2], n = 2
Output: [1,2,10,20,20,40]
Example 2:
Input: nums1 = [0,0], m = 0, nums2 = [1,2], n = 2
Output: [1,2]

#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // Pointers for the end of valid elements in nums1 and nums2
        int i = m - 1; 
        int j = n - 1;
        // Pointer for the very end of nums1 (where the next largest element goes)
        int k = m + n - 1;
        
        // Merge from right to left
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // If there are remaining elements in nums2, copy them over.
        // (If there are remaining elements in nums1, they are already in place!)
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};


5.Remove Duplicates From Sorted Array - Explanation
Problem Link
Description
You are given an integer array nums sorted in non-decreasing order. Your task is to remove duplicates from nums in-place so that each element appears only once.
After removing the duplicates, return the number of unique elements, denoted as k, such that the first k elements of nums contain the unique elements.
Note:
• The order of the unique elements should remain the same as in the original array.
• It is not necessary to consider elements beyond the first k positions of the array.
• To be accepted, the first k elements of nums must contain all the unique elements.
Return k as the final result.
Example 1:
Input: nums = [1,1,2,3,4]
Output: [1,2,3,4]
Explanation: You should return k = 4 as we have four unique elements.
Example 2:
Input: nums = [2,10,10,30,30,30]
Output: [2,10,30]
Explanation: You should return k = 3 as we have three unique elements.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        for (int r = 1; r < nums.size(); r++) {
            if (nums[r] != nums[r - 1]) {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};
