class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
        return 1;
        int res=10;
        int start=9,temp=9;
        for(int i=0;i<n-1;i++)
        {
            start=start*temp;
            res+=start;
            temp--;
        }
        return res;
    }
};