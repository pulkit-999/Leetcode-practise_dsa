class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
       set<int>s;
        for(auto x:candyType)
            s.insert(x);
        int n=candyType.size();
        if(s.size()<=n/2)
            return s.size();
        else
            return n/2;
    }
};