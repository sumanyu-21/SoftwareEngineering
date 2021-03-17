class Solution {
public:
    vector<vector<string>>ans;
    vector<int>distance;
    
    int bfs(vector<vector<int>>&adjList, vector<string>&wordList, int endWord, int beginWord)
    {
        distance.resize(adjList.size());
        fill(distance.begin(),distance.end(),INT_MAX);
        queue<int>q;
        q.push(beginWord);
        distance[beginWord] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v:adjList[u])
            {
                if(distance[v]==INT_MAX && distance[v]>distance[u]+1)
                {
                    distance[v] = distance[u]+1;
                    q.push(v);
                }
            }
        }
        
        return distance[endWord];
    }
    
    // FInding all valid strings using recursion.
    void find_all_strings(vector<vector<int>>&adjList, int i, int cnt, string &endWord, vector<string>&wordList, vector<string>&valid_path)
    {
        //valid_path.push_back(wordList[i]); 
        if(cnt==0)
        {
            if(wordList[i]==endWord)
                ans.push_back(valid_path);
            return;
        }
        
        for(int v:adjList[i])
        {
            if(distance[v]!=distance[i]+1)
                continue;
            valid_path.push_back(wordList[v]);
            find_all_strings(adjList, v, cnt-1, endWord, wordList,valid_path);  
            valid_path.pop_back();
        }
        //valid_path.pop_back();
        return;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>exists;
        for(int i=0;i<wordList.size();i++)
            exists[wordList[i]] = i;
        
        
        if(exists.find(endWord)==exists.end())
            return {};
        
        if(exists.find(beginWord)==exists.end())
            wordList.push_back(beginWord);
        
        vector<vector<int>>adjList;
        adjList.resize(wordList.size());
        for(int i=0;i<wordList.size();i++)
        {
            string word = wordList[i];
            for(int j =0;j<word.size();j++)
            {
                for(char c_new='a';c_new<='z';c_new++)
                {
                    if(c_new==word[j])
                        continue;
                    string string_new = word;
                    string_new[j] = c_new;
                   
                    if(exists.find(string_new)!=exists.end())
                    {
                        adjList[i].push_back(exists[string_new]);
                    }
                }
            }
            //cout<<adjList[i].size()<<endl;
        }
        /*for(int i=0;i<adjList.size();i++)
        {
            cout<<wordList[i]<<" : ";
            for(int j=0;j<adjList[i].size();j++)
                cout<<wordList[adjList[i][j]]<<" ";
            cout<<endl;
        }*/
        int beginWord_idx = exists.find(beginWord)!=exists.end()?exists[beginWord]:adjList.size()-1;
        int min_distance = bfs(adjList, wordList, exists[endWord], beginWord_idx);
        //cout<<min_distance<<endl;
        if(min_distance==INT_MAX)
            return {};
        
        vector<string>valid_path;
        valid_path.push_back(beginWord);
        find_all_strings(adjList, beginWord_idx, min_distance, endWord, wordList, valid_path);
        //return {{}};
        return ans;
    }
};
