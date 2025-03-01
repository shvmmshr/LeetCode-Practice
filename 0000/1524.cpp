class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (arr[i] * 1LL);
        }
        int eve = 1, odd = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (pre[i] & 1) {
                ans += eve;
                ans = ans % mod;
                odd++;
                odd = odd % mod;
            } else {
                ans += odd;
                ans = ans % mod;
                eve++;
                eve = eve % mod;
            }
        }
        return ans;
    }
};