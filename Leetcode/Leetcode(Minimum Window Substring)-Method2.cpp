bool check(unordered_map<char,int>& given, unordered_map<char,int>& window)
{
	for(pair p:given)
	{
		if(window[p.first]<p.second)
			return false;
	}
	return true;
}


class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();
        unordered_map<char, int>given;
        unordered_map<char, int>window;
        for(auto ch:t)
            given[ch]++;

        int start = 0;
        int end = 0;
        int ans_id1=0, ans_id2=INT_MAX;
        bool flag = false;
        int count_existing = 0;
        for(int start=0;start<n;start++)
        {
            if(end<start)
                end++;


            while(end<n)
            {
                if(given.find(s[end])!=given.end())
                {
                    window[s[end]]++;
                    if(window[s[end]]==given[s[end]])
                        count_existing++;
                }

                if(count_existing==given.size())//if(check(given, window)) // If true, then all the elements are present in window.
                {
                    cout<<start<<" "<<end<<endl;
                    if(ans_id2-ans_id1>end-start)
                    {
                        //cout<<ans_id1<<" "<<ans_id2<<endl;
                        ans_id1 = start;
                        ans_id2 = end;
                        flag=true;
                    }
                    if(window.find(s[end])!=window.end())
                    {
                        window[s[end]]--;
                        if(window[s[end]]<given[s[end]])
                            count_existing--;
                    }
                    break;
                }


                end++;
            }
            /*for(auto p:window)
                cout<<p.first<<":"<<p.second<<"   ";
            cout<<endl;*/
            if(window.find(s[start])!=window.end())
            {
                window[s[start]]--;
                if(given.find(s[start])!=given.end() && window[s[start]]<given[s[start]] && s[start]!=s[end]) // Here we are checking if s[start]!=s[end] because we might have already decreased the count_existing when we breaked out of while loop.
                    count_existing--;
            }   
            //cout<<count_existing<<endl;
            //start++;
        }
        /*string ans = s.substr(ans_id1, ans_id2-ans_id1+1);
        cout<<ans<<endl;*/
        if(flag)
        {
            string ans  = s.substr(ans_id1, ans_id2-ans_id1+1);
            return ans;
        }
        else
            return "";
        
    }
};