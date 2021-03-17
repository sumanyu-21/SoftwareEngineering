bool contains(const char& c, const string& s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==c)
            return true;
    }
    return false;
}

bool solve(vector<string>& words, string target) {

    vector<vector<int>>dp(target.size()+1,vector<int>((1<<words.size())+1,0));

    dp[0][0] = true;
    for(int j=0;j<words.size();j++)
    {
        dp[0][(1<<j)] = contains(target[0],words[j])?true:false;
        cout<<words[j]<<" "<<dp[0][(1<<j)]<<endl;
    }

    for(int i=0;i<target.size();i++)
    {
        for(int mask=0;mask<(1<<words.size());mask++)
        {
            if(dp[i][mask]==false)
                continue;
            for(int j=0;j<words.size();j++)
            {
                if(mask&(1<<j))
                    continue;
                dp[i+1][mask|(1<<j)] =  dp[i+1][mask|(1<<j)] | (contains(target[i], words[j])==true?true:false);
            }
        }
    }
    /*for(int i=0;i<=target.size();i++)
    {
        for(int mask=0;mask<(1<<words.size());mask++)
            cout<<dp[i][mask]<<" ";
        cout<<endl;
    }*/
    for(int mask=0;mask<(1<<words.size());mask++)
    {
        if(dp[target.size()][mask]==true)
            return true;
    }
    return false;
}