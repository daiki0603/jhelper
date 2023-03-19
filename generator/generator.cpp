#include <bits/stdc++.h>

// the number of stress cases
static constexpr int kStressIterations = 0;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// lower latin
std::string random_string(int len) {
    std::string res;
    while (len--) {
        int r = rng() % 26;
        res += char('a' + r);
    }
    return res;
}

// generate random input
void generateTest(std::ostream& test) {
    using namespace std;
    int n = 50;
    int k = 50;
    test << n << " " << k << '\n';
    for (int i = 0; i < n; ++i) {
        test << random_string(n) << '\n';
    }
}

// naive solution
void naive_solver(std::istream& in, std::ostream& out) {
    using namespace std;
    int n, k; in >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) in >> s[i];
    sort(s.begin(), s.end(), [&](string s1, string s2) {
        return s1 + s2 <= s2 + s1;
    });
    vector<vector<string>> dp(n, vector<string> (k + 1, "{"));
    dp[n - 1][0] = "";
    dp[n - 1][1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i + 1][j];
            if (j > 0) dp[i][j] = min(dp[i][j], s[i] + dp[i + 1][j - 1]);
        }
    }
    out << dp[0][k] << '\n';
    return;
}
