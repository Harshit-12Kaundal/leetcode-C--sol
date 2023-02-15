vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int carry=0;
        int n=num.size();
        int i=n-1;

        while(i>=0 || k>0 || carry>0){
            int sum=carry;
            if(k>0){
                int rem=k%10;
                sum+=rem;
                k=k/10;
            }
            if(i>=0){
                sum+=num[i];
                i--;
            }
            carry=sum/10;
            ans.push_back(sum%10);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }