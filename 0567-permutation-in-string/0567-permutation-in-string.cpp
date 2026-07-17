class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1f , s2f;
        if(s1.size()>s2.size())
            return false;
        for(int i = 0;i<s1.size();i++)
        {
            s1f[s1[i]]++;
        }
        int l = 0 , r = 0;
        while(r<s2.size())
        {
            s2f[s2[r]]++;
            if(r-l+1 > s1.size())
            {
                s2f[s2[l]]--;
                if(s2f[s2[l]]==0)
                    s2f.erase(s2[l]);
                l++;
            }
            if(r-l+1 == s1.size())
            {
                
                if(s1f == s2f)
                    return true;
                
            }
           
            r++;
        }
        return false;
    }
};