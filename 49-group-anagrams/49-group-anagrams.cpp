class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<string>res;
        vector<vector<string>>ans;
        map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string k=strs[i];
            sort(k.begin(),k.end());
            m[k].push_back(strs[i]);
        }
        for(auto x:m)
        {
          
            ans.push_back(x.second);
            
        }
        return ans;
    }
};