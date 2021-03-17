//Iterating over the start of the interval;
/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length();
        int end = 0; // Initially start and end inclusive
        set<int>inside; // COntains elements in [start, end];
        inside.insert(s[0]);
        int answer = 0;
        for(int start = 0;start<n;start++)
        {
            // If we can expand end by 1 and we don't have a character already in the set
            while(end+1<n && !inside.count(s[end+1]))
            {
                inside.insert(s[++end]);
            }
            
            //end now points to the longest substring without repeating characters.
            answer = max(answer, end-start+1);
            
            // Now erase the first character of the window;
            inside.erase(s[start]);
        }
        
        return answer;
    }
};*/

// Iterating over the end of the interval and pull start to the right;
/*
class Solution{
    public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int start = 0;// Initially start and end inclusive
        set<int>inside;
        int answer = 0;
        for(int end=0;end<n;++end)
        {
            if(inside.count(s[end])) // If inside has already such a character
            {
                // Start Pulling start
                while(true)
                {
                    inside.erase(s[start++]);
                    if(s[start-1]==s[end])
                        break;
                }                    
            }
            inside.insert(s[end]);
            answer = max(answer, end-start+1);
        }
        return answer;
    }
    
};*/

// Solution Using template
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int>m;
        
        int maxLen=0, start=0, end=0;
        while(end<s.size())
        {
            cout<<"1) "<<" "<<start<<" "<<end<<" "<<m[s[end]]<<endl;
            if(m[s[end]]==0)
            {
                m[s[end]]++;
                end++;
            }
            //End points to the next character outside the window.
            else // We can use else if we want to find the longest substring because we don't need to execute this loop when end==n
            {
                while(s[end]!=s[start])
                {
                    m[s[start]]--;
                    start++;
                }
                m[s[start]]--;
                start++;
            }
            maxLen=max(maxLen,end-start);
            //cout<<"2) "<<start<<" "<<end<<" "<<m[s[end]]<<endl;
            
        }
        return maxLen;
        //abcabcbb
    }
};
