Medium:
1.Two Sum II Input Array Is Sorted Problem Link
Description
Given an array of integers numbers that is sorted in non-decreasing order.
Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
There will always be exactly one valid solution.
Your solution must use O(1) additional space.
Example 1:
Input: numbers = [1,2,3,4], target = 3
Output: [1,2]
Explanation:
The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, index1 = 1, index2 = 2. We return [1, 2] 
Algorithm
² Initialize two pointers:
² l = 0 (start)
² r = len(numbers) - 1 (end)
² While l < r:
² Compute curSum = numbers[l] + numbers[r].
² If curSum > target, move r left to reduce the sum.
² If curSum < target, move l right to increase the sum.
² If curSum == target, return [l + 1, r + 1].
² If no pair matches the target, return an empty list.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int curSum = numbers[l] + numbers[r];

            if (curSum > target) {
                r--;
            } else if (curSum < target) {
                l++;
            } else {
                return { l + 1, r + 1 };
            }
        }
        return {};
    }
};

2. 3Sum - Explanation
Problem Link
Description
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
The output should not contain any duplicate triplets. You may return the output and the triplets in any order.
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
Algorithm
² Sort the array to handle duplicates and enable two-pointer logic.
² Loop through the array using index i:
² Let a = nums[i].
² If a > 0, break (all remaining numbers are positive).
² Skip duplicate values for the first number.
² Set two pointers:
² l = i + 1
² r = len(nums) - 1
² While l < r:
² Compute threeSum = a + nums[l] + nums[r].
² If threeSum > 0, move r left.
² If threeSum < 0, move l right.
² If threeSum == 0:
² Add the triplet to the result.
² Move both pointers inward.
² Skip duplicates at the left pointer.
² Return the list of all valid triplets.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
				  while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                   }

                }
            }
        }
        return res;
    }
};

3.4Sum - Explanation
Problem Link
Description
You are given an integer array nums of size n, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
• 0 <= a, b, c, d < n
• a, b, c, and d are distinct.
• nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Note: [1,0,3,2] and [3,0,1,2] are considered as same quadruplets.
Example 1:
Input: nums = [3,2,3,-3,1,0], target = 3
Output: [[-3,0,3,3],[-3,1,2,3]]
Example 2:
Input: nums = [1,-1,1,-1,1,-1], target = 2
Output: [[-1,1,1,1]]



Algorithm
² Sort the array.
² Iterate i from 0 to n, skipping duplicates.
² For each i, iterate j from i + 1 to n, skipping duplicates.
² Use two pointers: left = j + 1 and right = n - 1.
² While left < right:
² If sum equals target, add quadruplet and move both pointers while skipping duplicates.
² If sum is less than target, increment left.
² If sum is greater than target, decrement right.
² Return the result list.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

