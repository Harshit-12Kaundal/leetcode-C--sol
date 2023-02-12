    int f(int ind,int s,int prev,vector<vector<int>>&adj){
    long long int ans=0;
        int cnt=1;
        for(auto it: adj[ind]){
            if(it!=prev){
                cnt+= f(it,s,ind,adj);
            }
        }
        if(ind!=0){
            ans+=((cnt+s-1)/s);
        }
        return cnt;
    } 
    long long minimumFuelCost(vector<vector<int>>& roads, int seats){
        int n=roads.size();
        vector<vector<int>>adj(n+1);
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        f(0,seats,-1,adj);
        return ans;
    }