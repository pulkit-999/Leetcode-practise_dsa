class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int pigs=0;
        int c=minutesToTest/minutesToDie;
        while(pow(c+1,pigs)<buckets)
        {
            pigs++;
        }
        return pigs;
    }
};