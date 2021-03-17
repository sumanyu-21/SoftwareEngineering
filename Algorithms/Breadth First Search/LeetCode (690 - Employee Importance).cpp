/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int go(vector<Employee*>& employees, int idx, unordered_map<int, int>&location)
    {
        if(employees[idx]->subordinates.size()==0)
        {
            return employees[idx]->importance;
        }
        
        int ans = employees[idx]->importance;
        for(int i=0;i<employees[idx]->subordinates.size();i++)
        {
            ans+=go(employees, location[employees[idx]->subordinates[i]], location);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> location;
        for(int i=0;i<employees.size();i++)
            location[employees[i]->id] = i;
        
        int idx = location[id];
        int ans = go(employees, idx, location);
        cout<<ans;
        return ans;
        
    }
};