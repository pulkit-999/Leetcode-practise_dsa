struct Node{
    Node *links[2];
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
        bool containskey(int bit)
        {
        return (links[bit]==NULL);
        }
};
class Trie{
    public: Node*root;
    Trie()
    {
        root=new Node();
    }
     void insert(int num)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containskey(bit))
                node->put(bit,new Node());
            node=node->get(bit);
        }
    }
    int maxii(int num)
    {
          Node* node=root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containskey(1-bit))
            {
                node=node->get(bit);
            }
            else
            {
                maxi=maxi |(1<<i);
                node=node->get(1-bit);
            }
        }
        return maxi;
    }
};
class Solution {
   // Node*root;
   //  public :Solution ()
   //  {
   //      root=new Node;
   //  }
public:
   
    int findMaximumXOR(vector<int>& nums) {
        Trie ob;
        for(auto &it:nums)
        {
            ob.insert(it);
        }
        int maxi=0;
        for(auto &it:nums)
        {
            maxi=max(maxi,ob.maxii(it));
        }
        return maxi;
    }
};