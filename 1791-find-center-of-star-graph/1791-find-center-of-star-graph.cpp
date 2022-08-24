class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0],b=edges[0][1];
        if(a==edges[1][0]) return a;
        else if(b==edges[1][0]) return b;
        else if(b==edges[1][1]) return b;
        else if(a==edges[1][1]) return a;
        return 1;}
};