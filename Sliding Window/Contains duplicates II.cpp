// Contains Duplicate II 

// Description
// You are given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k, otherwise return false.

// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true

// Example 2:
// Input: nums = [2,1,2], k = 1
// Output: false

// approach: Sliding Window 
// Hash Set
// Intuition
// We only need to check for duplicates within a sliding window of size k. Using a hash set, we maintain exactly the elements in the current window. If a new element already exists in the set, we found a duplicate within distance k. We slide the window by removing the leftmost element when the window exceeds size k.

// Algorithm
// Create an empty hash set to represent the sliding window.
// Use two pointers L and R, with R iterating through the array.
// If the window size R - L exceeds k, remove nums[L] from the set and increment L.
// If nums[R] is already in the set, return true.
// Add nums[R] to the set.
// If no duplicate is found, return false.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int L = 0;

        for (int R = 0; R < nums.size(); R++) {
            if (R - L > k) {
                window.erase(nums[L]);
                L++;
            }
            if (window.find(nums[R]) != window.end()) {
                return true;
            }
            window.insert(nums[R]);
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;

    Solution solution;
    bool result = solution.containsNearbyDuplicate(nums, k);
    cout << (result ? "true" : "false");
    return 0;
}
