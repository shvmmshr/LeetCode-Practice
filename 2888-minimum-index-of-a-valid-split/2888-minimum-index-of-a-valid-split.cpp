class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int n=nums.size();
        int cnt=0, xM=0;
        for(int x: nums){
            if (cnt==0) xM=x;
            cnt+=(x==xM)?1:-1;
        }
        //Count maxF
        int maxF=count(nums.begin(), nums.end(), xM);
        // find the valid split
        int cntxM=0;
        for(int i=0; i<n; i++){
            cntxM+=nums[i]==xM;
            if (cntxM*2>(i+1) && ((maxF-cntxM)*2>(n-i-1)))
                return i;
        }
        return -1;
    }
};