class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < rowIndex + 1; i++)
        {
            vector<int> level(i);
            level[0] = 1;
            ans.push_back(level);
            for (int j = 1; j < i; j++)
            {
                if (j == 0)
                    ans[i][j] = 1;
                else
                    ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            ans[i].push_back(1);
        }
        return ans[rowIndex];
    }
};