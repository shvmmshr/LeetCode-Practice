class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        multiset<int> dp(arr.begin(),arr.end());
        int res = 0;
        int len = 2;
        for(int i =0; i < arr.size();i++){
            for(int j = i+1; j < arr.size();j++){
                int first = arr[i];
                int second = arr[j];
                while(dp.find(first + second) != dp.end()){
                    int temp = first+second;
                    first = second;
                    second = temp;
                    len++;
                }
                res = std::max(len, res);
                len = 2;
            }
        }
        if(res !=2) return ans;
        return 0;
    }
};