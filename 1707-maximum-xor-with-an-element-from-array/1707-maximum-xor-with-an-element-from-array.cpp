struct Node{
    Node* links[2];
    void put(int bit ,Node *node)
    {
        links[bit]=node;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    bool containskey(int bit)
    {
        return links[bit]==NULL;
    }
};
class Trie{
    public:Node*root;
    Trie()
    {
        root=new Node();
    }
  public:
    void insert(int num)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containskey(bit))
            {
                node->put(bit,new Node());
            }
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
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
    {
        Trie ob;
        int maxi=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>q;
        for(int i=0;i<queries.size();i++)
        {
            q.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(q.begin(),q.end());
        int k=queries.size();
        vector<int>ans(k,0);
   int ind=0;
       for(int i=0;i<k;i++)
        {
            int a=q[i].first;
           int b=q[i].second.first;
           int c=q[i].second.second;
           while(ind<n&& nums[ind]<=a)
           {
               ob.insert(nums[ind]);
               ind++;
           }
           if(ind==0)
               ans[c]=-1;
           else
               ans[c]=ob.maxii(b);
            
        }
        return ans;
    }
};