class Solution {
public:
    bool isPowerOfThree(int n) {
        int num=n;
        int count=0;
        while(num%3==0 &&num>1)
        {
            num=num/3;
            count++;
        }
        int p=pow(3,count);
       return(p==n);
    }
    
};