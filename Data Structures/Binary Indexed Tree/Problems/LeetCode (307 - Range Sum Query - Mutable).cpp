class NumArray {
public:
    vector<int>nums;
    vector<int>bit;
    NumArray(vector<int>& a) {
        
        bit.resize(a.size()+1);
        nums.resize(a.size());
        fill(bit.begin(),bit.end(),0);
        fill(nums.begin(),nums.end(),0);
        for(int i=0;i<a.size();i++)
            update(i,a[i]);
    }
    void print()
    {
        for(int i=1;i<bit.size();i++)
            cout<<bit[i]<<" ";
        cout<<endl;
    }
    
    int getdelta(int i,int val)
    {
        //cout<<"delta "<<i<<" "<<nums[i]<<" "<<val<<endl;
        int delta = val-nums[i];
        nums[i] = val;
        return delta;
    }
    void update(int i, int val) {
        int delta = getdelta(i, val);
        //cout<<"delta: "<<delta<<" "<<nums[i-1]<<endl;
        i=i+1;
        while(i<bit.size())
        {
            bit[i]+=delta;
            i+=(i&(-i));
        }
        //print();
    }
    
    int query(int i)
    {
        
        int ans = 0;
        while(i>0)
        {
            ans+=bit[i];
            i-=(i&(-i));
        }
        //cout<<ans<<endl;
        return ans;
    }
    
    int sumRange(int left, int right) {
        return query(right+1)-query(left);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */