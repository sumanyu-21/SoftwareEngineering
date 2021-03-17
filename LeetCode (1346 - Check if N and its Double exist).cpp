class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        set<int>s;
        for(int x:arr)
        {
            if(s.count(2*x) || (x%2 ==0 && s.count(x/2)))
                return true;
            s.insert(x);
        }
        return false;
    }
};

// We can also solve it using 2 pointers after sorting the array.