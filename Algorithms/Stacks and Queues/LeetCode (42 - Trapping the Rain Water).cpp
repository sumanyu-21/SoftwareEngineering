/*class Solution {
public:
        int trap(vector<int>& height) {
        # define a height
        if(height.size()==0)
            return 0;
        stack<int>s;
        int ii = 0;
        
        while(ii<height.size() && height[ii]==0)
            ii++;
        
        // ii points to the first non zero element
        if(ii==height.size())
            return 0;
        
        vector<int>forward(height.size(),-1);
        s.push(ii);
        for(int i=ii+1;i<height.size();i++)
        {
            if(a[i]<a[s.top()])
                s.push(i);
            
            else
            {
                while(!s.empty() && a[i]>=a[s.top()])
                {
                    forward[s.top()] = i;
                    s.pop();
                }
                s.push(i);
            }
        }
        
        stack<int>s2;
        int jj=a.size()-1;
        while(a[jj]==0)
            jj--;
        
        vector<int>backward(height.size(),-1);
        s2.push(jj);
        for(int j =jj-1;j>=0;j--)
        {
            if(a[j]<a[s2.top()])
                s2.push(j);
            
            
            else
            {
                while(!s2.empty() && a[j]>=a[s2.top()])
                {
                    backward[s2.top()] = j;
                    s2.pop();
                }
                s2.push(j);
            }
        }
        
        
        for(int i=0;i<backward.size();i++)
            cout<<backward[i]<<" ";
        cout<<endl;
        
        for(int i=0;i<forward.size();i++)
            cout<<forward[i]<<" ";
        cout<<endl;
        
        
        
        int i = ii; // Starting from first non zero building
        int water = 0;
        while(i<height.size() && forward[i]!=-1)
        {
            int next_biggest = forward[i];
            water+=(next_biggest-i-1)*height[i];
            // Incrementing till the next biggest
            i++;
            while(i<next_biggest)
            {
                water-=height[i];
                // Reducing the answer.
                i++;
            }
            
        }
        int j = jj;
        while(j>i && backward[j]!=-1)
        {
            int before_biggest = backward[j];
            water+=(j-before_biggest-1)*height[j];
            j--;
            while(j>before_biggest)
            {
                water-=height[j];
                j--;
            }
        }
        return water;  
    }
    
};*/


// STack Approach 2
/*class Solution
{
    public:
    int trap(vector<int>& height) {
        stack<int>s;
        if(height.size()==0)
            return 0;
        # define a height
        s.push(0);
        vector<pair<int,int>>ans;
        int water=0;
        for(int i=1;i<height.size();i++)
        {
            if(height[i]>a[s.top()])
            {
                while(!s.empty() && a[i]>a[s.top()])
                {
                    int ir = i;
                    int j = s.top();
                    s.pop();
                    int il = s.empty()?-1:s.top();
                    if(il!=-1)
                        water+=(min(a[ir],a[il])-a[j])*(ir-il-1);
                    //cout<<j<<" "<<ir<<" "<<il<<" "<<water<<endl;
                }
            }
            s.push(i);
        }
        return water;
    }
    
    
};*/

// Best Approach Using 2 Pointers

class Solution
{
    public:
    int trap(vector<int>&height)
    {
        int n = height.size();
        # define a height
        int left=0,right=n-1,maxLeft=0,maxRight=0,water=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                maxLeft = max(maxLeft, height[left]);
                water+=maxLeft-a[left];
                left++;
            }
            else
            {
                maxRight = max(maxRight,height[right]);
                water+=maxRight-a[right];
                right--;
            }
        }
        return water;
    }
};
