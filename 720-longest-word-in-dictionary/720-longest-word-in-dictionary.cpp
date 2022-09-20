struct Node{
    Node *links[26];
    bool flag=false;
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return (links[ch-'a']);
    }
    bool containskey(char ch)
    {
        return links[ch-'a']==NULL;
    }
    void setend()
    {
        flag=true;
    }
    bool isend()
    {
        return flag;
    }
};
class Trie{
   private: Node* root;
  public:  
     Trie()
     {
         root=new Node();
     }
    void insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containskey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setend();
    }
    bool check(string &word)
    {
         Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containskey(word[i]))
            {
                return false;
                
            }
            else{
                node=node->get(word[i]);
            }
            if(node->isend()==false)
                return false;
        }
        return true;
    }
};
class Solution 
{
   public: Node* root;
  public:  
    string longestWord(vector<string>& words) 
    {
        Trie ob;
         Node* node=root;
        for(auto &it:words)
        {
            ob.insert(it);
        }
        string maxi="";
        for(auto &it:words)
        {
            if(ob.check(it))
            {
                if(it.length()>maxi.size())
                {
                    maxi=it;
                }
                else if(it.length()==maxi.length() && it<maxi)
                {
                    maxi=it;
                }
            }
        }
        return maxi;
    }
};