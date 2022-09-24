class Solution {
public:
    void reverseString(vector<char>& s) 
    {
     stack<char>st;
        for(auto x:s)
        {
            st.push(x);
        }
        s.clear();
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
    }
};