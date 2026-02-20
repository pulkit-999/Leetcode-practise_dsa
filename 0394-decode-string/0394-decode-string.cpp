class Solution {
public:
    string decodeString(string s) {
        stack<string>s1;
        stack<string>s2;
       string ss="";
        for(int i=0;i<s.size();i++)
        {
            string num="";
            bool flag=false;
            while((s[i]-'0'>=0 and s[i]-'0'<=9))
            {
                num+=s[i];
                i++;
                flag=true;
            }
            if(flag)
            s1.push(num);
            if(s[i]==']')
            {
                string tempp="";
                while(s2.size() and s2.top()!="[")
                {
                    tempp=s2.top()+tempp;
                    s2.pop();
                }
                s2.pop();
                int k=stoi(s1.top());
                s1.pop();
                while(k--)
                {
                    ss+=tempp;
                }
                s2.push(ss);
            }
            else
            s2.push(std::string(1,s[i]));
            ss="";
        }
        while(s2.size())
        {
            cout<<s2.top()<<endl;
            ss=s2.top()+ss;
            s2.pop();
        }
        return ss;
    }
};