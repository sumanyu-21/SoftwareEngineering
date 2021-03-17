class TreeAncestor {
public:
    vector<vector<int>>sparse;
    int max_depth;
    TreeAncestor(int n, vector<int>& parent) {
        sparse.resize(n);
        max_depth=log2(n)+1;
        for(int i=0;i<n;i++)
        {
            sparse[i].resize(log2(n)+1);
            fill(sparse[i].begin(),sparse[i].end(),-1);
            sparse[i][0]=parent[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int k=1;k<max_depth;k++)
            {
                sparse[i][k] = sparse[i][k-1]!=-1?sparse[sparse[i][k-1]][k-1]:-1;
            }
        }
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<max_depth;j++)
                cout<<sparse[i][j]<<" ";
            cout<<endl;
        }*/
    }
    
    int getKthAncestor(int node, int k) {
        int i=0;
        while(k>0)
        {
            if(k&1)
                node=sparse[node][i];
            k>>=1;
            i++;
            if(node==-1)
                return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */