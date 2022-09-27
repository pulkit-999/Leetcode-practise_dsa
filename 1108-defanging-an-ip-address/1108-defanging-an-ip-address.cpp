class Solution {
public:
    string defangIPaddr(string address) {
        string st="";
        for(int i=0;i<address.size();i++)
        {
            if(address[i]=='.')
            {
                st+="[.]";
            }
            else
                st+=address[i];
        }
        return st;
        
    }
};