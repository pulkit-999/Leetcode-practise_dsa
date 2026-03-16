class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999)
        return 0;
        else if (n<1e6)
        return n-999;
        else if (n<1e9)
        return ((n-1e6)*2+(1e6-999+1));
        else if (n<1e12)
        return ((n-1e9)*3+(1e9-1e6)*2+(1e6-999+2));
        else if (n<1e15)
        return ((n-1e12)*4+(1e12-1e9)*3+(1e9-1e6)*2+(1e6-999+3));
        else if (n==1e15)
        return ((n-1e12)*4+(1e12-1e9)*3+(1e9-1e6)*2+(1e6-999+3)+1);
        return 0;

    }
};