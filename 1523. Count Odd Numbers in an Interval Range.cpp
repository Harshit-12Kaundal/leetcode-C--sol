//iterator
int countOdds(int low, int high) {
    int ans=0;
    while(low<=high){
        if(low%2!=0){
            ans++;
        }
        low++;
    }
    return ans;
}


//Recursion

int countOdds(int low, int high) {
    if(low%2!=0)return countOdds(low-1,high);
    if(high%2!=0)return countOdds(low,high+1);
    return (high-low)/2;
}