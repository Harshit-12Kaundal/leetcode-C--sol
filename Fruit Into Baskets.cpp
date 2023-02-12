    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int ans=INT_MIN;
        while(j<n){
            mp[fruits[j]]++;
            while(mp.size()>2){
                if(--mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                    
                }i++;
            }
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;    
    }