class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<char>s;
      for(int i=0;i<num.size();i++)
      {
        while(s.size() and s.top()>num[i] and k>0)
        {
            s.pop();
            k--;
        }
        s.push(num[i]);
        }
      string ans="";
      if(s.empty())
      return "0";

      while(k>0)
      {
        k--;
        s.pop();
      }
       while(s.size())
      {
        ans+=s.top();
        s.pop();
      }
    //   ans.erase(0, ans.find_first_not_of('0'));
    while(ans.size()!=0 and ans.back()=='0' )
    ans.pop_back();
    reverse(ans.begin(),ans.end());
     
     if(ans.empty())
     return "0";
      return ans;
    }
};