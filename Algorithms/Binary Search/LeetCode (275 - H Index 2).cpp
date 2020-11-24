class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Binary seach on the h-index T T T T T F F F F F
        // We are finding first False 
        if(citations.size()==0)
            return 0;
        int n = citations.size();
        int left = 0, right = n+1; // Adding 1 in case we have T T T T T T T {F} // Pseudo False;
        int end = n-1;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            
            int pos = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
            // Pos points to the citation >= mid;
            if(!(end-pos+1>=mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left-1;
    }
};