class Solution {
public:
    string reverseWords(string s)
    {
     string ans;
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
          if(s[i]==' ')
          {
              while(!st.empty())
              {
                  ans.push_back(st.top());
                  st.pop();
              }
              ans.push_back(' ');
              
          }
            else 
            {
                st.push(s[i]);
            }
    }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
            
        }
        return ans;
    }
};