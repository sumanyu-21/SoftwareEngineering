class Solution {
public:
    string removeDuplicateLetters(string s) {
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