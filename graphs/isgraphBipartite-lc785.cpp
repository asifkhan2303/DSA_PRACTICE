class Solution {  // down i have done using dfs and this onr is using bfs-->
public:
    bool bfs(vector<vector<int>> &adj,int u,vector<int> &color,int currColor){
        queue<int> que;
        color[u]=currColor;
        que.push(u);
        while(!que.empty()){
            int t=que.front();
            int colorV=color[t];
            que.pop();
            for(int &v:adj[t]){
                if(color[v]==color[t]){
                    return false;
                }
                if(color[v]==-1){
                    color[v]=1-colorV;
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(graph,i,color,1)){
                    return false;
                }
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int u,vector<int> &color,int currColor){
        color[u]=currColor;
        for(int &v:adj[u]){
            if(color[v]==color[u]){
                return false;
            }
            if(color[v]==-1){
               int colorV=1-color[u];
                if(!dfs(adj,v,color,colorV)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(graph,i,color,1)){
                    return false;
                }
            }
        }
        return true;
    }
};
*/