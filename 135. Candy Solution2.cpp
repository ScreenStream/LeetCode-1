uclass Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            if (ratings[i + 1] > ratings[i])
                dp[i + 1] = dp[i] + 1;
        }
        
        for (int i = n - 1; i; --i) {
            if (ratings[i - 1] > ratings[i] && dp[i - 1] <= dp[i])
                dp[i - 1] = dp[i] + 1;
        }
        
        int res = 0;
        for (auto x : dp)
            res += x;
        return res;
    }
};
