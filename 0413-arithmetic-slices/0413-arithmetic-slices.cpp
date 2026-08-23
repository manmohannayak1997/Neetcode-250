// 5. DP Definition

// Let:

// dp[i]

// represent:

// The number of arithmetic slices that end at index i.

// Now compare:

// nums[i] - nums[i-1]

// with:

// nums[i-1] - nums[i-2]

// If they are equal:

// nums[i] - nums[i-1]
// ==
// nums[i-1] - nums[i-2]

// then the sequence ending at i is arithmetic.

// Recurrence
// dp[i] = dp[i-1] + 1

// Why +1?

// Suppose:

// nums = [1,2,3,4,5]

// At i = 3:

// [1,2,3,4]

// The arithmetic slices ending at index 3 are:

// [2,3,4]
// [1,2,3,4]

// So:

// dp[3] = 2

// And at i = 4:

// dp[4] = dp[3] + 1
//       = 3

// The three slices ending at 5 are:

// [3,4,5]
// [2,3,4,5]
// [1,2,3,4,5]
// 6. C++ DP Solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {


        int n = nums.size();


        if (n < 3)
            return 0;


        vector<int> dp(n, 0);


        int ans = 0;


        for (int i = 2; i < n; i++) {


            if (nums[i] - nums[i - 1] ==
                nums[i - 1] - nums[i - 2]) {


                dp[i] = dp[i - 1] + 1;


                ans += dp[i];
            }
        }


        return ans;
    }
};