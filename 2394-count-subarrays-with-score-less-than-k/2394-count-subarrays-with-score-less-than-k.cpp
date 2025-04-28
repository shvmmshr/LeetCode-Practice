class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0, part_sum = 0;
        for (int right = 0, left = 0; right < nums.size(); right++) {
            part_sum += nums[right];
            while (part_sum * (right - left + 1) >= k && left <= right) {
                part_sum -= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};