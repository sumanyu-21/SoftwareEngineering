class Solution {
public:
    string minWindow(string s, string _t) {
        int n= s.size();
        map<char,int>req;
        for(char ch: _t)
            req[ch]++;
        
        int satisfied = 0;
        int still_required = req.size();
        int first_taken = 0, next_to_take = 0;
        pair<int,int>answer{INT_MAX,0};
        int memo_size=req.size();
        
        while(first_taken<n)
        {
            if(still_required>0)
            {
                // append on the right.
                if(next_to_take == n)
                    break; // We don't have any characters left to take.
                
                if(--req[s[next_to_take++]]==0) // We have satisfied the requirement.
                    still_required--;
            }
            
            else
            {
                ///erase_first;
                if(req[s[first_taken++]]++==0) // If this was 0, then this means it was part of our requirement
                    still_required++;
            }
            if(still_required==0)
            {
                answer = min(answer, make_pair(next_to_take-first_taken, first_taken));
            }
        }
        if(answer.first==INT_MAX){
            return "";
        }
        return s.substr(answer.second,answer.first);     

    }
};