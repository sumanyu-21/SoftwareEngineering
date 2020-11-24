# include <bits/stdc++.h>
# include <cstdlib>
/*class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto itr = std::lower_bound(arr.begin(), arr.end(), x);
        int n = arr.size();
        
        vector<int>ans;
        ans.reserve(k);
        if(itr==arr.end())
            itr--;
        
        if(itr!=arr.end())
        {
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
            int i = itr - arr.begin();
            int j = i+1;
            int count = 0;
            while(i>=0 && count<=k)
            {
                //cout<<arr[i] - x<<" "<<i<<endl;
                pq.push(make_pair(abs(arr[i] - x), arr[i]));
                count++;
                i--;
            }
            count = 0;
            while(j<n && count<=k)
            {
                pq.push({abs(arr[j] - x), arr[j]});
                count++;
                j++;
            }
            
            count = 0;
           
            while(count<k)
            {
                ans.push_back(pq.top().second);
                pq.pop();
                count++;
            }
            sort(ans.begin(), ans.end());
            //return ans;
        } 
        return ans;
    }
};*/
// _ w _ _ _ _ _ _ i _ _ _ _ _
// F F F T T T T T T

bool better(int i, int j, int x, int n, vector<int>&a)
{
    if(j==n)
        return true;
    return abs(a[i] - x) <= abs(a[j] - x);
}
class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n = a.size();
        int i = lower_bound(a.begin(), a.end(), x) - a.begin();
        // Let's point i to the closest element. In case 2 elements are closest, then we will point to the smaller element.
        if(i==n || (i!=0 && x-a[i-1]<= a[i]-x))
            i--;
        
        
        // We want to now take some elements from the right and some elements from the right.
        // Binary search on the position of the first taken element .  
        int left = max(i-k+1, 0), right = min(i, n-k);
        while(left<right)
        {
            int mid = left + (right - left)/2;
            int then_last_element = mid + k - 1;
            if(better(mid, then_last_element+1, x, n,a))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            } 
        }
        return vector<int>(a.begin() + left, a.begin() + left+k);
    }
};