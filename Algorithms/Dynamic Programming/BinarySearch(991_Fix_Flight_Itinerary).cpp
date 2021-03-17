
int diff(const string& a, const string& b)
{
    int cnt=0;
    for(int i=0;i<3;i++)
        cnt+=(a[i]!=b[i]);

    return cnt;
}
int solve(vector<string>& itinerary, vector<vector<string>>& edges) {
    int n = itinerary.size();
    int m = edges.size();
    vector<string>names;
    // https://stackoverflow.com/questions/15176104/c11-range-based-loop-get-item-by-value-or-reference-to-const
    for(vector<string>& edge :edges)
    {
        names.push_back(edge[0]);
        names.push_back(edge[1]);
    }
    // We could have used set also to handle this instead of vector.
    // Remove Repititions. However, even if we dont do that, everything will be fine.
    sort(names.begin(), names.end());
    names.resize(unique(names.begin(), names.end()) - names.begin());
    /*for(string s:names)
        cout<<s<<endl;*/
    
    
    int k = names.size();

    auto get_id = [&](const string& s){
        return lower_bound(names.begin(), names.end(), s) - names.begin();
    };

    vector<vector<int>>out_edges(k);
    for(vector<string>&edge :edges)
    {
        out_edges[get_id(edge[0])].push_back(get_id(edge[1]));
    }
    vector<vector<int>>dp(n+1,vector<int>(k, INT_MAX/2));
    // Initialise somehow? Yet don't know that. Will see later

    for(int s_id=0;s_id<k;s_id++)
    {
        dp[1][s_id] = diff(itinerary[0], names[s_id]);
    }
    for(int i=1;i<n;i++)
    {
        for(int s_id = 0;s_id<k;s_id++)
        {
            // i can change to something such that there is an edge from s_id to i. We can iterate over all strings in names and check if there is an edge. Or iterate over strings which has an edge from s_id;
            
            for(int new_s: out_edges[s_id])
            {
                //dp[i][s_id] -> dp[i+1][new_s];
                //dp[i+1][new_s] = min(dp[i+1][new_s], dp[i][s_id] + ????);
                // ???-> We need to find the number of character changes.
                dp[i+1][new_s] = min(dp[i+1][new_s], dp[i][s_id] + diff(itinerary[i], names[new_s]));
            }
        }
    }
    int ans = INT_MAX;
    //dp[n][] = ??
    for(int s_id=0;s_id<k;s_id++)
        ans = min(ans, dp[n][s_id]);
     
    return ans;
}