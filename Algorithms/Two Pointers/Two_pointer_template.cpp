class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>m;
    for(auto c:t)m[c]++;

    //counter represents the number of chars of t to be found in s;
    size_t start = 0, end=0, counter = t.size(), minStart=0, minLen = INT_MAX;
    size_t size = s.size();

    //Move to find a valid Window.
    while(end<s.size())
    {
        // If char in s exists in y, decrease counter
        //cout<<start<<" "<<end<<endl;
        if(counter!=0)
        {
            if(m[s[end]]>0) // If this character exists in t also, we can decrease the number of characters to be found in window.
                counter--;


            m[s[end]]--;
            end++;
        }
        // end points to the index next to end of window.
        // When we have found a valid window, move start to find smaller window.

        // m = [- - - - 0 0  0 0 - - - -];
        // -ve numbers are those which do not occur in t or which occur more is s than in t.
        while(counter==0) // Don;t use else because if end points to s.size() in previous if condition, this part will not be executed because while loop will terminate.
        {                 // We can use else if we want to find the longest substring because we don't need to execute this loop when end==n
            if(end-start<minLen)
            {
                minStart = start;
                minLen = end-start;
            }
            m[s[start]]++;
            // Only when a character exists in t, m[s[start]]>0
            if(m[s[start]]>0)
                counter++;
            
            start++;
        }
        //cout<<start<<" "<<end<<" "<<counter<<endl;
    }
    if(minLen!=INT_MAX)
        return s.substr(minStart, minLen);

    return "";
        
    }
};