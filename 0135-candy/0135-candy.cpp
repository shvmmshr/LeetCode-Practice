class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        vector<int>candy(n,1);
        for(int i=1;i<n;i++){
            if(rating[i]>rating[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(rating[i]>rating[i+1]){
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }
        return accumulate(candy.begin(),candy.end(),0);
    }
};