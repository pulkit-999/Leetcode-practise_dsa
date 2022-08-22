class Solution {
public:
    bool isPowerOfFour(int n) 
    {
     int num=n;
        int count=0;
        while(num%4==0 &&num>1)
        {
            num=num/4;
            count++;
        }
        int p=pow(4,count);
       return(p==n);
    }
};