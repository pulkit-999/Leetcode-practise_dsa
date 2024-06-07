class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream s(sentence);
        unordered_map<string,int>m;
        for(auto x:dictionary)
        m[x]++;
        string ans;
        string t;
        while(getline(s,t,' '))
        {
            string temp;
            bool flag=0;
            for(int i=0;i<t.size();i++)
            {
                temp+=t[i];
                if(m.count(temp))
                {
                    flag=1;
                    ans+=temp;
                    ans+=' ';
                    break;
                }

            }
            if(flag==0)
            {
                ans+=t;
                ans+=' ';
            }
        }
        ans.pop_back();
        return ans;
    }
};