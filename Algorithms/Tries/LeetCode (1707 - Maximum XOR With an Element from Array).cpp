class TrieNode
{
    public:
    TrieNode* left;
    TrieNode* right;
    int smallest;
    bool endOfNumber;
    int x;
    TrieNode()
    {
        this->left = nullptr;
        this->right = nullptr;
        this->smallest = INT_MAX;
        this->endOfNumber = false;
        this->x = INT_MAX;
        
    }
    
};

class Trie
{
    
    public:
    TrieNode* root;
    Trie()
    {
        this->root = new TrieNode;
    }
    
    void insert(int x)
    {
        TrieNode* current = root;
        for(int i=29;i>=0;i--)
        {
            TrieNode* next;
            if(x&(1<<i))
                next = current->right;
            else
                next = current->left;
            
            if(next==nullptr)
            {
                next = new TrieNode;
                if(x&(1<<i))
                    current->right = next;
                else
                    current->left = next;
                
            }
            current = next;
        }
        current->endOfNumber = true;
        current->x = x;
        
    }
    
    int findMin(TrieNode* current)
    {
        if(current==NULL)
        {
            return INT_MAX;
        }
        
        current->smallest = min(current->x, min(findMin(current->left), findMin(current->right)));
        return current->smallest;
    }
    
    bool search(int x)
    {
        TrieNode* current = root;
        for(int i=29;i>=0;i--)
        {
            TrieNode* next = current;
            if(x&(1<<i))
                next = current->right;
            else
                next = current->left;
            if(next==nullptr)
                return false;
            current = next;
        }
        return current->endOfNumber;
    }
    
    void print(TrieNode* current)
    {
        if(current==NULL)
            return;
        cout<<current->left<<" "<<current->right<<" "<<current->x<<" "<<current->smallest<<" "<<current->endOfNumber<<endl;
        print(current->left);
        print(current->right); 
    }
    
    int query(int x, int not_to_exceed)
    {
        TrieNode* current = root;
        int ans = 0;
        for(int i=29;i>=0;i--)
        {
            if(x&(1<<i)) // If this bit is equal to 1
            {
                //cout<<i<<" : this bit is 1"<<endl;
                if(current->left!=NULL && current->left->smallest<=not_to_exceed)
                {
                    current = current->left;
                    //cout<<"going_left "<<current->smallest<<" "<<current->x<<endl;
                }
        
                else 
                {
                    current = current->right;
                    //cout<<"going right "<<current->smallest<<" "<<current->x<<endl;
                }
            }
            else
            {
                //cout<<i<<" : this bit is 0"<<endl;
                if(current->right!=NULL && current->right->smallest<=not_to_exceed)
                {
                    current = current->right;
                    //cout<<"going right "<<current->smallest<<" "<<current->x<<endl;
                }
                else
                {
                    current = current->left;
                    //cout<<"going_left "<<current->smallest<<" "<<current->x<<endl;
                }
            }
            if(current==NULL || current->smallest>not_to_exceed) // In case, we have were only able to reach a NULL state or we somehow, both the left and right minimum exceeds the not_to_exceed, then break.
                break;
        }
        
        if(current==NULL || current->endOfNumber==false)// Here, I should have used some falg variable, but this also works.
            return -1;
        
        else
        {
            
            return current->x^x;
        }
    }
    
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        Trie ob;
        for(int i=0;i<nums.size();i++)
            ob.insert(nums[i]);
        
        ob.findMin(ob.root);
        vector<int>ans;
        for(auto q:queries)
        {
            int not_to_exceed = q[1];
            int x = q[0];
            ans.push_back(ob.query(x,not_to_exceed));
        }
        return ans;
    }
};