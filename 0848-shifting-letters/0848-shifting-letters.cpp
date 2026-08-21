class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int sum = 0;
        for(auto i:shifts){
            sum+=i;
        }
        int i = 0;
        for(auto ch:s){
            s[i] = 'a' + (ch-'a'+sum)%26;
            cout<<s[i]<<"-";
            sum-=shifts[i++];
        }  
        return s;   
    }
};