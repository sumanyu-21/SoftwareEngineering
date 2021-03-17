/*class Solution {
public:
    //vector<string>ans;
    bool valid(string s)
    {
        //cout<<"here"<<endl;
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(st.empty())
                    return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        
        return false;
    }
    void generate(string &s, int n, vector<string>&ans)
    {
        if(s.size()==2*n)
        {
            //cout<<s<<endl;
            if(valid(s))
                ans.push_back(s);
            return;
        }
        s.push_back('(');
        generate(s, n, ans);
        s.pop_back();
        s.push_back(')');
        generate(s,n,ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>ans;
        generate(s, n, ans);
        return ans;
        
    }
};*/

// Method - II --> will generate duplicates also, because ()()  ()(()) is same as ()  ()()(())
/*class Solution
{
    public:
    vector<string> generateParenthesis(int n)
    {
        if(n==0)
        {
            return {""};
        }
        if(n==1)
        {
            return {"()"};
        }
        
        vector<string>ans;
        for(string s: generateParenthesis(n-1)){
            ans.push_back("(" +s + ")");
        }
        
        for(int n1=1;n1<n;n1++)
        {
            int n2 = n-n1;
            vector<string>A = generateParenthesis(n1);
            vector<string>B = generateParenthesis(n2);
            for(string s1:A)
            {
                for(string s2:B)
                {
                    ans.push_back(s1 + s2);
                }
            }
        }
        return ans;
        
    }
};
*/

// Taking care of that

class Solution
{
    public:
    vector<string> generateParenthesis(int n)
    {
        if(n==0)
        {
            return {""};
        }
        vector<string>ans;        
        for(int n1=1;n1<=n;n1++)
        {
            int n2 = n-n1;
            vector<string>A = generateParenthesis(n1-1);
            vector<string>B = generateParenthesis(n2);
            for(string s1:A)
            {
                for(string s2:B)
                {
                    ans.push_back("(" + s1 + ")" + s2);
                }
            }
        }
        return ans;
    }
};

// Another way using balance

/*class Solution
{
    public:
    void rec(string s, int n, int balance, vector<string>& ans)
    {
        if(balance>n-s.length())
        {
            return;
        }
        if(s.length()==n)
        {
            if(balance==0)
                ans.push_back(s);
            return;
        }
        
        rec(s + "(", n, balance+1, ans);
        if(balance>=1) // If 0 or negative, there's no point in doing this.
            rec(s+")", n, balance-1, ans);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string>ans;
        rec("", 2*n, 0, ans);
        return ans;
    }
};*/