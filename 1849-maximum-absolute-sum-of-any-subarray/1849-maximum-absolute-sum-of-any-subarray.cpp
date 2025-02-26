class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        int n=nums.size(),i=0;
        while(i<n){
            sum+=nums[i];
            maxi=max((sum),maxi);
            if(sum<0){
                sum=0;
            }
            i++;
        }
       i=0,sum=0;
       int mini=INT_MAX;
        while(i<n){
            sum+=nums[i];
            mini=min((sum),mini);
            if(sum>0){
                sum=0;
            }
            i++;
        }
        return max(abs(maxi),abs(mini));
    }
};