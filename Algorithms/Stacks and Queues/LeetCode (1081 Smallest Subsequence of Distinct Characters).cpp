//Time Complexity O(A*A*(N+A))--> O(NA^2 + A^3) where A is alphabet size.
/*class Solution {
public:
    string smallestSubsequence(string s) {
    
        vector<bool>at_all(26);
        for(char c:s)
            at_all[c-'a'] = true;
        
        // Check if We can Take this character next;
        const int n = s.length();
        int start = 0;
        string subsequence;
        while(at_all!=vector<bool>(26,false))
        {
            for(char first='a'; first<='z';first++)
            {
                if(!at_all[first-'a'])
                    continue;
                
                int i=start;

                // Get the first occurence of the character 'first'
                while(s[i]!=first)
                    i++;

                vector<bool>in_suffix(26);
                // TO the right of me, do all other characters exist?
                for(int j=i;j<n;j++)
                {
                    in_suffix[s[j]-'a'] = true;
                }

                bool ok = true;
                for(int z=0;z<26;z++)
                {
                    if(at_all[z] && !in_suffix[z])
                        ok = false;
                }
                if(!ok)
                    continue;
                subsequence+=first;
                at_all[first-'a'] = false; // Pretend this character does not exist in the string. We will never use the first character again.
                start = i+1;
                break; // Break if we have found the best character.
            }
        }
        return subsequence;
        
    }
};*/

// Time Complexity-->O(A*A*(A+A)) + O(AN) = O(AN)
/*class Solution {
public:
    string smallestSubsequence(string s) {
    
        const int n = s.length();
        int next_occurence[n+1][26];
        for(int c=0;c<26;c++)
            next_occurence[n][c] = n;// It doesn't matter what we have here. Our for loop will never execute in this case. When we do start = i+1, we know that all the remaining characters exist on the right side.
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int c=0;c<26;c++)
                next_occurence[i][c] = next_occurence[i+1][c];
            next_occurence[i][s[i]-'a'] = i;
        }
        
        vector<bool>at_all(26);
        for(char c:s)
            at_all[c-'a'] = true;
        
        // Check if We can Take this character next;
        
        int start = 0;
        string subsequence;
        while(at_all!=vector<bool>(26,false))
        {
            for(char first='a'; first<='z';first++)
            {
                if(!at_all[first-'a'])
                    continue;
                
                int i=next_occurence[start][first-'a'];

                // Get the first occurence of the character 'first'
                //while(s[i]!=first)
                //    i++;

                vector<bool>in_suffix(26);
                // TO the right of me, do all other characters exist?
                for(int j=i;j<n;j++)
                {
                    in_suffix[s[j]-'a'] = true;
                }
                // Removing this for loop as well.
                for(int z=0;z<26;z++)
                    if(next_occurence[i][z]!=n)
                        in_suffix[z] = true;

                bool ok = true;
                for(int z=0;z<26;z++)
                {
                    if(at_all[z] && !in_suffix[z])
                        ok = false;
                }
                if(!ok)
                    continue;
                subsequence+=first;
                at_all[first-'a'] = false; // Pretend this character does not exist in the string. We will never use the first character again.
                start = i+1;
                break; // Break if we have found the best character.
            }
        }
        return subsequence;
        
    }
};*/

class Solution
{
    public:
     string smallestSubsequence(string s) {
         vector<int>last(26);
         for(int i=0;i<s.length();i++)
            last[s[i]-'a'] = i;
         //cout<<"here"<<endl;
         vector<bool>seen(26,false);
         stack<char>st;
         for(int i=0;i<s.length();i++)
         {
             if(seen[s[i]-'a'])
                 continue;
             while(!st.empty() && st.top()>s[i] && last[st.top()-'a']>i)
             {
                 seen[st.top()-'a'] = false;
                 st.pop();
             }
             st.push(s[i]);
             seen[s[i]-'a'] = true;
             
            
         }
         string subsequence;
         while(!st.empty())
         {
             subsequence+=st.top();
             st.pop();
         }
         reverse(subsequence.begin(),subsequence.end());
         return subsequence;
     }
    
};