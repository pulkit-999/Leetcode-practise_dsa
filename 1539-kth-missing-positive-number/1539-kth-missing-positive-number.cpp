class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
     vector<int>ans;
        for(int i=1;i<2001;i++)
        {
            if(binary_search(arr.begin(),arr.end(),i)==0)
                ans.push_back(i);
        }
        return ans[k-1];
    }
};