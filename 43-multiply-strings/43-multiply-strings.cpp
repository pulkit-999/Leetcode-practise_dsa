class Solution {
public:
    string multiply(string num1, string num2)
    {
        int m=num1.size();
        int n=num2.size();
        int ans[m+n];
        memset(ans,0,sizeof(ans));
        if(num1=="0"||num2=="0")
            return "0";
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=mul+ans[i+j+1];
                ans[i+j]+=sum/10;
                ans[i+j+1]=sum%10;
            }
        }
        string s="";
        for(auto x:ans)
        {
            if(s.size()!=0||x!=0)
            {
                s=s+(to_string(x));
            }
        }
        return s;
		// int i = 0;
		// while (i < m+n && ans[i] == 0) i++;
		// while (i < m+n) s.push_back(ans[i++] + '0');
		// return s;
    }
};