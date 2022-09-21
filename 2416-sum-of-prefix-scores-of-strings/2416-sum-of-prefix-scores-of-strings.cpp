struct Node{
    
   Node* links[26];
    int cp=0;
    int ew=0;
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    bool containskey(char ch)
    {
        return links[ch-'a']==NULL;
    }
    void incpre()
    {
        cp++;
    }
     void incend()
    {
        ew++;
    }
    int prefix()
    {
        return cp;
    }
    bool isend()
    {
        return ew;
    }
    
};





class Solution {
    public :Node*root;
    Solution(){
        root=new Node();
    }
public:
    void insert(string &word)
{
        Node *node=root;
    for(int i=0;i<word.size();i++)
    {
        if(node->containskey(word[i]))
        {
            node->put(word[i],new Node());
          
        }
        node=node->get(word[i]);
          node->incpre();
    }
        node->incend();
}
    int  count(string &word)
{
        int sum=0;
        Node *node=root;
    for(int i=0;i<word.size();i++)
    {
        if(node->containskey(word[i]))
        {
            break;
        }
        else{
        node=node->get(word[i]);
          sum+=node->prefix();
            }
          
    }
      
        return sum;
}
    
    vector<int> sumPrefixScores(vector<string>& words) 
    {
            
        vector<int>v;
        for(auto it:words)
            insert(it);
        int sum=0;
        for(int i=0;i<words.size();i++)
        {
            sum=count(words[i]);
            v.push_back(sum);
        }
        return v;
        
    }
};