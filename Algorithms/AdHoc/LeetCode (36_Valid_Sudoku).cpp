class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int>row_map;
        map<char, int>column_map;
        map<char, int>box_map;
        
        for(int i=0;i<board.size();i++)
        {
            row_map.clear();
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                {
                    row_map[board[i][j]]+=1;
                    if(row_map[board[i][j]]>1)
                        return false;
                }
                
            }
        }
        cout<<"done"<<endl;
        
        for(int j=0;j<board[0].size();j++)
        {
            column_map.clear();
            for(int i=0;i<board.size();i++)
            {
                if(board[i][j]!='.')
                {
                    column_map[board[i][j]]+=1;
                    if(column_map[board[i][j]]>1)
                        return false;
                }
            }
        }
        
        cout<<"done"<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                box_map.clear();
                for(int k=3*i;k<3*(i+1);k++)
                {
                    for(int l=3*j;l<3*(j+1);l++)
                    {
                        if(board[k][l]!='.')
                        {
                            box_map[board[k][l]]+=1;
                            if(box_map[board[k][l]]>1)
                                return false;
                        }
                    }
                    
                }
                
            }
        }
        return true;
        
    }
};