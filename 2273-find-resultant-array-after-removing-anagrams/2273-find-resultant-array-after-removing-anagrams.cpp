class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
   vector<string>ans;  
        set<string>s;
        for(int i=0;i<words.size();i++)
        {
            string k=words[i];
            sort(k.begin(),k.end());
            int n=s.size();
              s.insert(k);
            if(s.size()>1)
            {
                s.clear();
                s.insert(k);
                ans.push_back(words[i]);
            }
            if(s.size()!=n)
            {
                  ans.push_back(words[i]);
            }
        }
       
        return ans;
    }
};