class LRUCache {
public:
   
    class Node{
        public:
         int key,val;
        Node*next,*prev;
        Node(int _key,int _val)
    {
        key=_key;
        val=_val;
    }
    };
    Node*head=new Node(-1,-1);
     Node*tail=new Node(-1,-1);
    int size;
    unordered_map<int,Node*>m;
    LRUCache(int capacity) 
    {
        size=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void add(Node*newnode)
    {
        Node*temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(Node*delnode)
    {
         Node*delp=delnode->prev;
        Node*deln=delnode->next;
        delp->next=deln;
        deln->prev=delp;
    }
    
    int get(int key) 
    {
        if(m.find(key)!=m.end())
        {
            Node*a=m[key];
            m.erase(key);
            int res=a->val;
                deletenode(a);
            add(a);
            m[key]=head->next;
            return res;
        }
            return -1;
    }
    
    void put(int key, int value) 
    {
        if(m.find(key)!=m.end())
        {
            Node*b=m[key];
            m.erase(key);
            deletenode(b);
        }
        if(m.size()==size)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        add(new Node(key,value));
            m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */