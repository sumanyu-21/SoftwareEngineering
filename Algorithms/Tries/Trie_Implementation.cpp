# include <iostream>
# include <bits/stdc++.h>
using namespace std;


class TrieNode
{
    public:
    map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode()
    {
        this->endOfWord = false;
    }
};


class Trie
{
    public:
    TrieNode* root;
    Trie()
    {
        this->root = new TrieNode;
    }

    /**
     * Iterative Insertion into the Trie.
     */
    void insert(string s)
    {
        TrieNode* current = root;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            TrieNode* next = current->children[ch];

            if(next==NULL)
            {
                next= new TrieNode;
                current->children[ch] = next;
            }
            current = next;
        }
        current->endOfWord = true;
    }

    /**
     * Recursive Implementation of insert into trie.
     */


    void insertRecursive(TrieNode* current, const string& word, int index)
    {
        if(index==word.length())
        {
            current->endOfWord = true;
            return;
        }
        char ch = word[index];
        TrieNode* next = current->children[ch];

        // If node does not exists in map, then create one and put it into the map.
        if(next==NULL)
        {
            next = new TrieNode;
            current->children[ch] = next;
        }
        insertRecursive(next, word, index+1);
    }

    /** 
     * Iterative Implementation of Search into The Trie
     */

    bool search(string word)
    {
        TrieNode* current = root;
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            TrieNode* next = current->children[ch];
            if(next==NULL)
                return false;
            
            current = next;
        }
        // Return true if current's endOfWord is true else return false.
        return current->endOfWord; 
    }

    /**
     * Recursive Implementation of Search
     */

    bool searchRecursive(TrieNode* current, string word, int index)
    {
        if(index==word.length())
            return current->endOfWord; // Return true of current's endOfWord is true else return false.
        
        char ch = word[index];
        TrieNode* next = current->children[ch];
        if(next==NULL)
            return false;
        
        return searchRecursive(next, word, index+1);
    }
    bool deleteString(string word)
    {
        return delete_(root, word, 0);
    }
    bool delete_(TrieNode* current, string word, int index)
    {
        if(index==word.length())
        {
            // When end of word is reached, only delete if current.endOfWord is true.
            if(!current->endOfWord)
                return false; 

            current->endOfWord = false; 
            // if current has not other children, then return true;

        }
        char ch = word[index];
        TrieNode* next = current->children[ch];
        if(next==NULL)
            return false;
        
        // I can delete current node, if I can delete the next node and the current node->children has only ch
        bool shouldDeleteCurrentNode = delete_(next, word, index+1);

        // If true is returned, then delete the mapping of character and TrieNode refrence from map.
        if(shouldDeleteCurrentNode)
        {
            current->children[ch];
            return current->children.size()==0;
        }
        return false;
    }



};

int main()
{
    Trie ob;
    ob.insert("Hello");
    ob.insert("Shaurya");
    ob.insert("Sumanyu");
    cout<<ob.search("love")<<endl;
    cout<<ob.search("Sumanyu")<<endl;
    cout<<ob.search("Hello")<<endl;
    ob.deleteString("Hello");
    cout<<ob.search("Hello")<<endl;
    return 0;
}