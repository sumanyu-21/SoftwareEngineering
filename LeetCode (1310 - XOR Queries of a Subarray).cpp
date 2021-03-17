
// Using prefix sums. Time Complexity(N*bits + Q*bits)
/*class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int N_bits = 30;
        vector<vector<int>>prefix(n, vector<int>(N_bits,0));
        
        for(int i=0;i<n;i++)
        {
            for(int bit=0;bit<N_bits;bit++)
            {
                prefix[i][bit] = (i>=1?prefix[i-1][bit]:0);
                if(arr[i]&(1<<bit))
                {
                    prefix[i][bit]+=1;
                }
            }
        }
    
        vector<int>ans;
        for(int q=0;q<queries.size();q++)
        {
            int l = queries[q][0];
            int r = queries[q][1];
            
            int res = 0;
            for(int bit=0;bit<N_bits;bit++)
            {
                int n_set_bits = prefix[r][bit] - (l-1>=0?prefix[l-1][bit]:0);
                if(n_set_bits&1)
                    res+=(1<<bit);
                   
                
            }
            ans.push_back(res);
        }
        return ans;
    }
};*/


// Using Segment Trees. Time Complexity (N*logN + Q*logN)

/*class SegmentTree
{
    
    
    public:
    int n;
    vector<int>low, high; // Tells us the range each index in segment tree is responsible for.
    vector<int>arr; 
    vector<int>s_t; // Segment Tree
    vector<int>d_t; // Propagation Tree
    SegmentTree(int n, vector<int>&arr)
    {
        this->n = n;
        low.resize(4*n+1);
        high.resize(4*n+1);
        this->arr = arr;
        s_t.resize(4*n+1);
        
        init(0, 0, n-1);
    }
    
    void init(int i, int a, int b)
    {
        low[i] = a, high[i] = b;
        if(a==b)
        {
            s_t[i] = arr[a];
            return;
        }
        
        int mid = (a+b)/2;
        init(2*i+1, a, mid); // For this case, a<=b; Not to worry but this.
        init(2*i+2, mid+1, b); // For this mid+1>b only when a==b. However we handled this in return statement. Not to worry about this too.
        s_t[i] = s_t[2*i+1]^s_t[2*i+2];
    }
    
    int query(int i, int a, int b)
    {
        if(b<low[i] || high[i]<a)
            return 0;
        if(a<=low[i] && high[i]<=b)
            return s_t[i];
        
        // Parital Overlap;
        int query_left = query(2*i+1, a, b);
        int query_right = query(2*i+2, a, b);
        return query_left^query_right;
    }
    
  
    
};

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        SegmentTree ob(arr.size(), arr);
        vector<int>ans;
        for(auto q:queries)
        {
            
            int result = ob.query(0, q[0], q[1]);
            ans.push_back(result);
        }
        return ans;
    }
};
*/

// Using better way of using prefix approach;

class Solution{
    public:
    vector<int>xorQueries(vector<int>&arr, vector<vector<int>>&queries)
    {
        int n = arr.size();
        vector<int>prefXor(n);
        for(int i=0;i<n;i++)
        {
            prefXor[i] = (arr[i] ^ (i==0?0:prefXor[i-1]));
        }
        vector<int>ans;
        for(auto q:queries)
        {
            int L = q[0];
            int R = q[1];
            ans.push_back(prefXor[R] ^ (L-1>=0?prefXor[L-1]:0));
        }
        return ans;
    }
};