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
        //set<char>given;
        unordered_map<char,int>given;
        unordered_map<char, int>window;
        for(auto ch:t)
            given[ch]++;//given.insert(ch);

        int start = 0;
        int end = 0;
        int ans_id1=0, ans_id2=INT_MAX;
        bool flag = false;
        for(int start=0;start<n;start++)
        {
            if(end<start)
                end++;


            while(end<n)
            {
                window[s[end]]++;
                /*set<int>intersect;
                set_intersection(given.begin(), given.end(), window.begin(),window.end(),intersect.begin())*/
                //check(given, window);
                if(check(given, window)) // If true, then all the elements are present in window.
                {
                    //cout<<start<<" "<<end<<endl;
                    if(ans_id2-ans_id1>end-start)
                    {
                        //cout<<ans_id1<<" "<<ans_id2<<endl;
                        ans_id1 = start;
                        ans_id2 = end;
                        flag=true;
                    }
                    window[s[end]]--;
                    break;
                }


                end++;
            }
            /*for(auto p:window)
                cout<<p.first<<":"<<p.second<<"   ";
            cout<<endl;*/
            window[s[start]]--;
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
