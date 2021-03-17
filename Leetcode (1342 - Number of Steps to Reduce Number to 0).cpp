class Solution {
public:
    int numberOfSteps (int num) {
        
        int ans = 0;
        while(num>0)
        {
            
            if(num&1)
            {
                if(num==1)
                    ans+=1;
                else
                    ans+=2;
            }
            else
                ans+=1;
            num>>=1;
        }
        return ans;
    }
};