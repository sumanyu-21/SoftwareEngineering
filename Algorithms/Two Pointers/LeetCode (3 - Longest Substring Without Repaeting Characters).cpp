/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        
        int start = 0;
        int end = 0;
        set<int>inside;
        
        inside.insert(s[0]);
        int ans = 0;
        while(start<n && end<n)
        {
            
            while(end+1<n && !inside.count(s[end+1])) /// end +1 character is yet not present in window.
            {
                inside.insert(s[end+1]);
                end++;
                
            }
            
            // If character is present, then remove the start character
            cout<<start<<" "<<end<<endl;
            inside.erase(s[start]);
            ans = max(ans, end-start+1);
            start++;
            
        }
        return ans;
        
    }
};*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        
        int i=0, j=0;
        int ans = 0;
        unordered_map<char, int>last_pos;
        while(j<s.length())
        {
            if(last_pos.find(s[j])==last_pos.end() || last_pos[s[j]]<i)
            {
                last_pos[s[j]] = j;
                ans = max(ans, j-i+1);
                //cout<<ans<<endl;

            }
            else
            {
                // We have found a repeating character.
                i = last_pos[s[j]]+1; // Start from this new position.
                last_pos[s[j]] = j;
                ans = max(ans , j-i+1);
                //cout<<ans<<endl;
                
            }
            j+=1;
        }
        
        //cout<<ans<<endl;
        return ans;
        
    }
};