class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>> &vis){
        vis[i][j]=true;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        for(int d=0;d<4;d++){
            int x_=i+dr[d];
            int y_=j+dc[d];
            if(x_>=0 && x_<n && y_>=0 && y_<m && !vis[x_][y_] && grid[x_][y_]=='1'){
                dfs(grid,x_,y_,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,i,j,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};