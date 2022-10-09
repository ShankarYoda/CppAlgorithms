/* 0-1 Knapsack Problem  - Bottom Up Approach */

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define fast                    \
    cin.sync_with_stdio(false); \
    cin.tie(NULL);              \
    cout.tie(NULL);

int dp[1001][10001];

int knapsack(int n, int wt[], int val[], int W)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] <= W)
        return dp[n][W] = max(val[n - 1] + knapsack(n - 1, wt, val, W - wt[n - 1]), knapsack(n - 1, wt, val, W));
    else
        return dp[n][W] = knapsack(n - 1, wt, val, W);
}
signed main()
{
    fast;
    int n = 3;
    int wt[3] = {10, 20, 30};
    int val[3] = {60, 100, 120};
    int W = 50;
    //memonization
    memset(dp, -1, sizeof(dp));
    cout << knapsack(n, wt, val, W);
    return 0;
}
