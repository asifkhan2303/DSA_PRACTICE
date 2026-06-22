class Solution {
public:
    // void dfs(int u,vector<vector<int>> &adj,vector<bool>&vis){
    //     vis[u]=true;
    //     for(int &ngbr:adj[u]){
    //         if(!vis[ngbr]){
    //             dfs(ngbr,adj,vis);
    //         }
    //     }
    // }
    void bfs(int u,vector<vector<int>> &adj,vector<bool> &vis){
        queue<int> que;
        vis[u]=true;
        que.push(u);
        while(!que.empty()){
            int t=que.front();
            que.pop();
            for(int &ngbr:adj[t]){
                if(!vis[ngbr]){
                    vis[ngbr]=true;
                    que.push(ngbr);
                }
                
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    continue;
                }
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                //dfs(i,adj,vis);
                bfs(i,adj,vis);
                res++;
            }
        }
        return res;
    }
};