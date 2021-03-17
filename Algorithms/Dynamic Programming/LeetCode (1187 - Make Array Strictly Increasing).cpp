//O(n^3) Solution
/*int dp[2005][2005];
class Solution {
public:
    int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
        
        const int INF = 1e9+5;
        dp[0][B.size()] = 0;
        for(int v1=0;v1<B.size();v1++)
            dp[0][v1] = 1;
        
        //cout<<"working"<<endl;
        for(int i=1;i<A.size();i++)
        {
            for(int v1=0;v1<=B.size();v1++)
                dp[i][v1] = INF;
            
            for(int v1=0;v1<=B.size();v1++)
            {
                for(int v0=0;v0<=B.size();v0++)
                {
                    int value0 = (v0==B.size()?A[i-1]:B[v0]);
                    int value1 = (v1==B.size()?A[i]:B[v1]);
                    
                    if(value0<value1)
                        dp[i][v1] = min(dp[i][v1], dp[i-1][v0] + (v1==B.size()?0:1));
                }
            }
        }
        int ans = INF;
        for(int v1=0;v1<=B.size();v1++)
            ans = min(ans, dp[A.size()-1][v1]);
        
        if(ans==INF)
            return -1;
        return ans;
        
    }
};*/

//O(n^2) solution
int dp[2005][2005];
class Solution {
public:
    int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
        sort(B.begin(),B.end());
        B.resize(unique(B.begin(),B.end()) - B.begin());
        
        const int INF = 1e9+5;
        dp[0][B.size()] = 0;
        for(int v1=0;v1<B.size();v1++)
            dp[0][v1] = 1;
        
        //cout<<"working"<<endl; 
        for(int i=1;i<A.size();i++)
        {
            for(int v1=0;v1<=B.size();v1++)
                dp[i][v1] = INF;
            
            for(int v0=0;v0<=B.size();v0++)
            {
                vector<int>indices;
                if(v0==B.size())// Check Everything
                {
                    for(int v1=0;v1<=B.size();v1++)
                    {
                        int value0 = (v0==B.size()?A[i-1]:B[v0]);
                        int value1 = (v1==B.size()?A[i]:B[v1]);

                        if(value0<value1)
                            dp[i][v1] = min(dp[i][v1], dp[i-1][v0] + (v1==B.size()?0:1));
                    }
                }
                else
                {
                    for(int v1:{(int)B.size(), v0+1})
                    {
                        // Possiblity that next element is not changed.
                    // Not all the elements from V0+1 till the end, only consider rhe next element because it will give the longest subsequennce.
                        int value0 = (v0==B.size()?A[i-1]:B[v0]);
                        int value1 = (v1==B.size()?A[i]:B[v1]);

                        if(value0<value1)
                            dp[i][v1] = min(dp[i][v1], dp[i-1][v0] + (v1==B.size()?0:1));
                    }
                        
                }
                
            }
        }
        int ans = INF;
        for(int v1=0;v1<=B.size();v1++)
            ans = min(ans, dp[A.size()-1][v1]);
        
        if(ans==INF)
            return -1;
        return ans;
        
    }
};