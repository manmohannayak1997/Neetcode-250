Trapping Rain Water 
Problem Link
Description
You are given an array of non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.
Return the maximum area of water that can be trapped between the bars.
Example 1:

Input: height = [0,2,0,3,1,0,1,3,2,1]
Output: 9


Brute force Approach:
Prefix & Suffix Arrays
Intuition
Instead of recomputing the tallest bar to the left and right for every index, we can precompute these values once.
We build two arrays:
• leftMax[i] = tallest bar from the start up to index i
• rightMax[i] = tallest bar from the end up to index i
Once we have these, the trapped water at position i is simply:
min(leftMax[i], rightMax[i]) - height[i]
This removes the repeated work from the brute-force approach and makes the solution more efficient and easier to understand.
Algorithm
Ø If the array is empty, return 0.
Ø Create two arrays:
Ø leftMax of size n
Ø rightMax of size n
Ø Fill leftMax:
Ø leftMax[0] = height[0]
Ø For each i from 1 to n - 1,
leftMax[i] = max(leftMax[i - 1], height[i])
Ø Fill rightMax:
Ø rightMax[n - 1] = height[n - 1]
Ø For each i from n - 2 down to 0,
rightMax[i] = max(rightMax[i + 1], height[i])
Ø Compute trapped water:
Ø For each index i, add min(leftMax[i], rightMax[i]) - height[i] to the result.
Ø Return the total trapped water.

Optimized solution:
Two Pointers
Intuition
Water at any position depends on the shorter wall between the left and right sides.
So if the left wall is shorter, the right wall can't help us—water is limited by the left side.
That means we safely move the left pointer inward and calculate how much water can be trapped there.
Similarly, if the right wall is shorter, we move the right pointer left.
As we move the pointers, we keep track of the highest wall seen so far on each side (leftMax and rightMax).
The water at each position is simply:
max wall on that side – height at that position
Algorithm

Ø Set two pointers:
Ø l at the start
Ø r at the end
Track leftMax and rightMax as the tallest walls seen.
Ø While l < r:
Ø If leftMax < rightMax:
Ø Move l right.
Ø Update leftMax.
Ø Add leftMax - height[l] to the result.
Ø Else:
Ø Move r left.
Ø Update rightMax.
Ø Add rightMax - height[r] to the result.
Ø Return the total trapped water.

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};


