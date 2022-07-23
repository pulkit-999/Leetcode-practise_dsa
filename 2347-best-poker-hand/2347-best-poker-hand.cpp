class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) 
    {
     unordered_map<int,int> m;
        set<char>s;
       // int c=count(suits.begin(),suits.end(),suits[0]);
        for(int i=0;i<5;i++)
        {
            s.insert(suits[i]);   
        }
        int n=5;
        int maxi=0;
        for(int i=0;i<5;i++)
        {
            m[ranks[i]]++;
            maxi=max(maxi,m[ranks[i]]);
        }
        // cout<<maxi;
        if(s.size()==1)
            return "Flush";
        if(maxi==2)
            return "Pair";
        if(maxi>=3)
            return "Three of a Kind";
        return "High Card";
    }
};