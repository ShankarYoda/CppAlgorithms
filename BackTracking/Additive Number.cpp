class Solution
{
public:
    bool rec(string s, int i, long long a, long long b)
    {
        if (i == s.length())
            return true;

        for (int j = i; j < s.length(); j++)
        {
            long long x = stoll(s.substr(i, j - i + 1));
            if (to_string(x).length() == j - i + 1)
            {
                if (x < a + b)
                    continue;
                else if (x > a + b)
                    break;
                else
                    return rec(s, j + 1, b, x);
            }
            else
                break;
        }
        return false;
    }

    bool isAdditiveNumber(string s)
    {
        bool ans = false;
        int n = s.length();
        long long a, b;
        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = 1; n - i - j >= max(i, j); j++)
            {
                a = stoll(s.substr(0, i));
                b = stoll(s.substr(i, j));
                if (to_string(a).length() + to_string(b).length() == i + j)
                {
                    ans = ans || rec(s, i + j, a, b);
                    if (ans)
                        return true;
                }
            }
        }

        return ans;
    }
};