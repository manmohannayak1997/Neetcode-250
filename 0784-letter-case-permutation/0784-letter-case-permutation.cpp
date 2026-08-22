class Solution {
public:

    void solve(string s, int index, vector<string>& ans) {

        if (index == s.size()) {
            ans.push_back(s);
            return;
        }

        if (isalpha(s[index])) {

            // Lowercase
            s[index] = tolower(s[index]);
            solve(s, index + 1, ans);

            // Uppercase
            s[index] = toupper(s[index]);
            solve(s, index + 1, ans);

        } else {

            // Digit
            solve(s, index + 1, ans);
        }
    }

    vector<string> letterCasePermutation(string s) {

        vector<string> ans;

        solve(s, 0, ans);

        return ans;
    }
};