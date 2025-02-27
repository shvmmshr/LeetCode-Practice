class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        multiset<int> dp(arr.begin(),arr.end());
        int ans = 0;
        int now_len = 2;
        for(int i =0; i < arr.size();i++){
            for(int j = i+1; j < arr.size();j++){
                int first = arr[i];
                int second = arr[j];
                while(dp.find(first + second) != dp.end()){
                    int temp = first+second;
                    first = second;
                    second = temp;
                    now_len++;
                }
                ans = std::max(now_len, ans);
                now_len = 2;
            }
        }
        if(ans !=2) return ans;
        return 0;
    }
};