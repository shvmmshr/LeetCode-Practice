class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) { 
            if (nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (nums[j] == 0 && nums[j + 1] != 0) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums;
    }
};

