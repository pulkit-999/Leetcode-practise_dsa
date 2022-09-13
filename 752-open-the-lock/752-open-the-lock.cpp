class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
{
        unordered_set<string>s(deadends.begin(),deadends.end());
        unordered_set<string>vis;
        queue<pair<string,int>>q;
        if(s.find("0000")==s.end())
        {
        q.push({"0000",0});
        vis.insert("0000");
        }
        else
            return -1;
        
        if (target=="0000")
            return 0;
        // if(s.find(target)!=s.end());
        //     return -1;
        while(!q.empty())
        {
            string k=q.front().first;
            int counts=q.front().second;
            if(k==target)
                return q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                string t1,t2;
                t1=k.substr(0,i)+to_string((k[i]-'0'+1)%10)+k.substr(i+1);
                    t2=k.substr(0,i)+to_string((k[i]-'0'-1+10)%10)+k.substr(i+1);
                if(vis.find(t1)==vis.end() && s.find(t1)==s.end())
                {
                    q.push({t1,counts+1});
                    vis.insert(t1);
                }
                if(vis.find(t2)==vis.end() && s.find(t2)==s.end())
                {
                    q.push({t2,counts+1});
                    vis.insert(t2);
                }
            }
        }
        
        return -1;
    }
};