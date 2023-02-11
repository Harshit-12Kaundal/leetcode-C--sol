    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>>adj[n];
        for(auto it:redEdges){
            adj[it[0]].push_back({it[1],1});
        }
        for(auto it:blueEdges){
            adj[it[0]].push_back({it[1],2});
        }
        int temp=1;
        vector<int>ans(n,-1);
        queue<vector<int>>q;

        q.push({0,0,-1});
        //{start,dist,color}
        while(!q.empty()){

            auto it=q.front();
            q.pop();

            int node=it[0];
            int color=it[2];

            if(ans[node]==-1){
                ans[node]=it[1];
            }

            for(auto &x:adj[node]){
                if(x.first!=-1 &&(color==-1 || x.second!=color)){
                    q.push({x.first,it[1]+1,x.second});

                    x.first=-1;
                }
            }
        }
        return ans;
    }