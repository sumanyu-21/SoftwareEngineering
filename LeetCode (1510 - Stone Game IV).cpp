class Solution {
public:
    
    vector<int>calculate_squares(int n)
    {
        vector<int>squares;
        int i=1;
        while(i*i<=n)
        {
            squares.push_back(i*i);
            i+=1;
        }
        return squares;
        
    }
    bool winnerSquareGame(int n) {
        vector<int>squares = calculate_squares(n);
        const int win=1, loose=0;
        vector<int>dp(n+1,-1);
        dp[0] = loose;
        for(int i=1;i<=n;i++)
        {
            dp[i] = loose;
            for(int sq:squares)
            {
                if(sq>i)
                    break;
                if(dp[i-sq]==loose)
                {
                    dp[i] = win;
                    break;
                }
            }
        }
        return dp[n];
    }
};