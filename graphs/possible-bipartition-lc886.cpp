class Solution {  // using dfs-->
public:
    bool dfs(vector<vector<int>>&adj,int u,vector<int> &color,int currColor){
        color[u]=currColor;
        for(int &v:adj[u]){
            if(color[v]==color[u]){
                return false;
            }
            if(color[v]==-1){
                int colorV=1-currColor;
                if(!dfs(adj,v,color,colorV)){
                    return false;
                }
            }
        }
        return true;
    } 
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto &edge:dislikes){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!dfs(adj,i,color,1)){
                    return false;
                }
            }
        }
        return true;
    }
};

/*  using bfs-->
class Solution {
public:
    bool bfs(vector<vector<int>> &adj,int u,vector<int>&color,int currColor){
        queue<int> que;
        que.push(u);
        color[u]=currColor;
        while(!que.empty()){
            int t=que.front();
            que.pop();
            for(int &v:adj[t]){
                if(color[v]==color[t]){
                    return false;
                }
                if(color[v]==-1){
                    color[v]=1-color[t];
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto &edge:dislikes){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bfs(adj,i,color,1)){
                    return false;
                }
            }
        }
        return true;
    }
};
*/