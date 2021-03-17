/*class Solution {
    
public:
    
    bool possible(vector<int>&jobs, int k, int mid)
    {
        int n = jobs.size();
        const int INF = INT_MAX;
        int dp[k+1][1<<n][n+1];
        
        for(int worker=0;worker<=k;worker++)
        {
            for(int mask=0;mask<(1<<n);mask++)
            {
                for(int job_id=0;job_id<=n;job_id++)
                    dp[worker][mask][job_id]=INF;
            }
        }
        
        dp[0][0][0] = 0;
        
        for(int worker=0;worker<k;worker++)
        {
            for(int mask=0;mask<(1<<n);mask++)
            {
                for(int job_id=0;job_id<n;job_id++)
                {
                    
                    // Give this job to the current worker;
                   
                    int sum_so_far = dp[worker][mask][job_id];
                    if(sum_so_far==INF)
                        continue;
                    if(sum_so_far + jobs[job_id]<=mid && !(mask&(1<<job_id)))
                    {
                        int &s2 = dp[worker][mask|(1<<job_id)][job_id+1];
                        s2 = min(s2, sum_so_far+jobs[job_id]);
                    }
                    

                    // Don'd give it to this worker.
                    int &s2 = dp[worker][mask][job_id+1];
                    s2 = min(s2, sum_so_far);
                    
                }
                if(dp[worker][mask][n]!=INF) // I am able to assign jobs to kth worker in a valid way.
                    dp[worker+1][mask][0] = 0; // We are able to assign this configuration(mask) and we can set the initial state of next worker as 0;
            }
        }
        
        if(dp[k][(1<<n)-1][0]==0)// All groups are considered until k-1 and all jobs have been assigned and when we begin assigining for group K+1, we are again job_id = 1. If this is not INF(infact==0), then we know we have found valid assigning with at most time for eaxh worker as 'mid';
            return true;
        return false;
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        
        
        int left = 0, right = accumulate(jobs.begin(),jobs.end(),0);
        while(left<right)
        {
            int mid = left +(right-left)/2;
            if(possible(jobs, k, mid))
                right = mid;
            else
                left = mid+1;
                
        }
        return left;
    }
};*/


class Solution{
    public:
    int minimumTimeRequired(vector<int>& jobs, int k)
    {
        int n = jobs.size();
        vector<int>dp((1<<12),INT_MAX);
        vector<int>amt(1<<12);
        
        for(int mask=0;mask<(1<<n);mask++)
        {
            amt[mask] = 0;
            for(int i=0;i<n;i++)
            {
                if(mask&(1<<i))
                    amt[mask]+=jobs[i];
            }
        }
    
    
        dp[0] = 0;
        for(int i=1;i<=k;i++)
        {
            // mask represents the final configuration after ith assignment;
            for(int mask = (1<<n)-1;mask>=0;mask--)
            {

                 //Iterating over submasks ie, we reached the current mask from this submask.
                int other = mask; // Other represents the assignment for the kth group.
                while(true)
                {
                    dp[mask] = min(dp[mask], max(dp[mask^other], amt[other]));// Mask^other removes bits which are set in other. Basically mask^other represents the previous configuration. Then we added assignments for kth group and reached the configuration denoted by mask.
                    if(other==0) break;
                    other = (other-1)&mask;
                    
                }

            }
        }
        return dp[(1<<n)-1];
    }
    
};