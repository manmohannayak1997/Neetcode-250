class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vector<int>>;

    vvi ans;
    vi curr;
    vector<bool> used;

    void bt(vi& nums) {

        // A complete permutation is formed
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Skip duplicate at the same recursion level
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            // Choose
            curr.push_back(nums[i]);
            used[i] = true;

            // Explore
            bt(nums);

            // Undo
            used[i] = false;
            curr.pop_back();
        }
    }

    vvi permuteUnique(vi& nums) {

        sort(nums.begin(), nums.end());

        used.resize(nums.size(), false);

        bt(nums);

        return ans;
    }
};