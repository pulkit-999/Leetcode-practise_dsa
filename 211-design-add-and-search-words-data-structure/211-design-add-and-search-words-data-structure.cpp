struct Node
{
  Node *links[26];
    bool flag=false;
    
    void put(char ch,Node* node)
    {
        links[(ch-'a')]=node;
    }
    Node *get(char ch)
    {
        return (links[(ch-'a')]);
    }
                bool containskey(char ch)
                {
                    return (links[(ch-'a')])==NULL;
                }
                void isset()
                {
                    flag=true;
                    
                }
                bool isend()
                {
                    return flag;
                }
};
class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word)
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
        node->isset();
    }
    
    bool search1(Node* node,string word)
    {
        
        for(int i=0;i<word.size();i++)
        {
            if(word[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(node->links[j]!=NULL)
                    {
                        if(search1(node->links[j],word.substr(i+1))){ //imp
                            return true;
                        }
                    }
                }
                return false;
                }
            
            if(node->containskey(word[i]))
            {
              return false;
            }
            node=node->get(word[i]);
        }
    
          return node->isend();
    }
    bool search(string word)
    {
           Node* node = root;
        return search1(node,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */