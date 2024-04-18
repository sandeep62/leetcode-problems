class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid){
        int rows=grid.size(),cols=grid[0].size(),ans=0;
        int up,down,left,right;
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]==1)
                {
                    if(r==0){
                        up=1;
                    }
                    else{
                        up=grid[r-1][c]==0;
                    }
                    if(c==0){
                        left=1;
                    }
                    else{
                        left=grid[r][c-1]==0;
                    }
                    if(r==rows-1){
                        down=1;
                    }else{
                        down=grid[r+1][c]==0;
                    }
                    if(c==cols-1){
                        right=1;
                    }else{
                        right=grid[r][c+1]==0;
                    }
                    ans+=up+left+right+down;
                }
            }
        }
        return ans;
    }
};