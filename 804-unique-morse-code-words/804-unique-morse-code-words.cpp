class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
    string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        //map<char,string>m;
        int i=0;
        unordered_set<string>s;
        // for(char ch='a';ch<='z';ch++)
        // {
        //     m[ch]=arr[i];
        //     i++;
        // }
        string res="";
        for(int i=0;i<words.size();i++)
        {
            res="";
            string k=words[i];
            for(int j=0;j<k.size();j++)
            {
                res=res+arr[k[j]-'a'];
                          }
            if(res!="")
            s.insert(res);
        }
        return s.size();
    }
};