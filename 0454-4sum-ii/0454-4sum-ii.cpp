class Solution {
public:
    int fourSumCount(vector<int>& A,
                     vector<int>& B,
                     vector<int>& C,
                     vector<int>& D) {

        unordered_map<int, int> mp;

        for (int a : A) {
            for (int b : B) {
                mp[a + b]++;
            }
        }

        int ans = 0;

        for (int c : C) {
            for (int d : D) {
                ans += mp[-(c + d)];
            }
        }

        return ans;
    }
};