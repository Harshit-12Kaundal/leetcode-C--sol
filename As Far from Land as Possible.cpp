class Solution {
    int r[4]={-1,0,1,0};
    int c[4]={0,1,0,-1};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        if(q.empty()|| q.size()==n*n){
            return -1;
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;

            for(int i=0;i<4;i++){
                int nr=x+r[i];
                int nc=y+c[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n && dp[nr][nc]==-1){
                    dp[nr][nc]=dp[x][y]+1;
                    q.push({nr,nc});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};