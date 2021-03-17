/*class Solution {
public:
    string reformatNumber(string s) {
        string t;
        for(int i=0;i<s.length();i++)
        {

            if(s[i]!='-' && s[i]!=' ')
                 t.push_back(s[i]);
        }
        string ans;
        for(int i=0;i<t.size();i++)
        {
            cout<<i<<endl;
            if(i!=0)
                ans.push_back('-');
            if(t.size()-1-i+1==2)
            {
                ans.push_back(t[i]);
                ans.push_back(t[i+1]);
                //ans.append('-');
                i+=1;
            }
            else if(t.size()-1-i+1==3)
            {
                string temp = t.substr(i, 3);
                ans+=temp;
                //ans.append('-');
                i+=2;
            }
            else if(t.size()-1-i+1==4)
            {
                ans.push_back(t[i]);
                ans.push_back(t[i+1]);
                ans.push_back('-');
                ans.push_back(t[i+2]);
                ans.push_back(t[i+3]);
                i+=3;
            }
            else
            {
                //cout<<i<<endl;
                ans.push_back(t[i]);
                ans.push_back(t[i+1]);
                ans.push_back(t[i+2]);
                i+=2;
            }
            cout<<i<<" "<<ans<<endl;
            //cout<<i<<endl;
        }
        return ans;
        
    }
};*/

class Solution{
    public:
    string reformatNumber(string number)
    {
        string all;
        for(char c: number)
        {
            if(isdigit(c))
                all.push_back(c);
        }
        cout<<all<<endl;
        string answer;
        int n = all.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && i%3==0)
                answer+="-";
            answer.push_back(all[i]);
        }
        if(n%3==1 && n>=4)
        {
            swap(answer.end()[-2], answer.end()[-3]);
        }
        
        return answer;
    }
};