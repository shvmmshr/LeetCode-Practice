class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        // Create DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take max from either previous row or column
                }
            }
        }

        // Now build the shortest common supersequence
        string result = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            // If characters are the same, add to the result
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) { // Move in the direction of larger dp value
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }

        // If there are any remaining characters in str1
        while (i > 0) {
            result += str1[i - 1];
            i--;
        }

        // If there are any remaining characters in str2
        while (j > 0) {
            result += str2[j - 1];
            j--;
        }

        // Since we added characters in reverse order, reverse the result before returning
        reverse(result.begin(), result.end());
        return result;
    }
};