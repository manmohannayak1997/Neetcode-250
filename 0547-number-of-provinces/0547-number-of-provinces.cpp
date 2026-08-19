class Solution {
    private:
    void dfs(vector<vector<int>> & isConnected , int n , int src , vector<bool> &visited){
        visited[src] = true;
        for(int i = 0;i<n;i++){
            if(!visited[i] && isConnected[src][i]==1)
            {
                dfs(isConnected,n,i,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0,n = isConnected.size();
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                 res++;
                 dfs(isConnected,n,i,visited);
            }
               
        }
        return res;
    }
};