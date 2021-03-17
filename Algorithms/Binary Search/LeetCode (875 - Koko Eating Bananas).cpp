class Solution {
public:
    bool valid(vector<int>&a, const int& K, const int& H)
    {
        int remaining = H;
        int curr = 0;
        while(remaining>=0 && curr<a.size())
        {
            remaining-=a[curr]/K;
            if(a[curr]%K!=0)
                remaining-=1;
            curr++;
        }
        if(remaining<0)
            return false;
        return true;
    }
    int minEatingSpeed(vector<int>& a, int H) {
        int n = a.size();
        int left = 1, right = a[max_element(a.begin(), a.end()) - a.begin()];
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(valid(a, mid, H))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};