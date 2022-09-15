class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        int n=changed.size();
        
        unordered_map<int,int>m;
        if(n%2!=0)
            return ans;
        for(int i=0;i<changed.size();i++)
        {
            m[changed[i]]++;
        }
        sort(changed.begin(),changed.end());
        
        for(int i=0;i<changed.size();i++)
        {
            if(changed[i]==0 && m[changed[i]]>=2)
            {
                m[changed[i]]-=2;
                ans.push_back(changed[i]);
            }
            else if (changed[i]>0 && m[changed[i]] && m[changed[i]*2]) 
            {
                m[changed[i]]-=1;
                m[changed[i]*2]-=1;
                ans.push_back(changed[i]);
            }
        }
        if( ans.size()==n/2)
        {
            return ans;
        }
        else
        {
            ans.clear();
        return ans;
        }   
    }
};