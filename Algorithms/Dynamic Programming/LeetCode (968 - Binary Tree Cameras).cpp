/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// DP Solution
struct triplet
{
    int camera, covered, not_covered;
};

class Solution {
    
    triplet dfs (TreeNode* current)
    {
        if(current==NULL)
        {
            triplet t;
            t.camera = 99999;
            t.covered = 0;
            t.not_covered = 0;
            return t;
        }
        
        triplet t1 = dfs(current->left);
        triplet t2 = dfs(current->right);
        
        triplet t3;
       
        t3.camera = min(t1.camera, min(t1.covered, t1.not_covered)) + min(t2.camera, min(t2.covered, t2.not_covered)) + 1;
        
        t3.covered = min(min(t2.camera, t2.covered) + t1.camera, min(t1.camera, t1.covered) + t2.camera); // Atleast one of the child should have camera
        
        t3.not_covered = t1.covered + t2.covered;
        
        return t3;
        
    }
public:
    int minCameraCover(TreeNode* root) {
        triplet t = dfs(root);
        cout<<t.camera<<" "<<t.covered<<" "<<t.not_covered<<endl;
        return min(t.camera,t.covered);
    }
};


// Greedy Solution.
/*class Solution
{
    public:
    int cnt = 0;
    const int UNCOVERED = 0, COVERED = 1, CAMERA_INSTALLED = 2;
    
    int dfs(TreeNode* current)
    {
        if(current==NULL)
             return 1;
         
        int left = dfs(current->left);
        int right = dfs(current->right);
        
        if(left==UNCOVERED || right==UNCOVERED)
        {
            cnt++;
            return CAMERA_INSTALLED;
        }
        
        if(left==CAMERA_INSTALLED || right==CAMERA_INSTALLED)
        {
            return COVERED;
        }
        else
            return UNCOVERED;
    }
     int minCameraCover(TreeNode* root) {
        if(dfs(root)==0)
            cnt++;
         return cnt;
     }
    
    
};*/

