class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> counter(121);
        for (int age : ages) ++counter[age];
        int res = 0;
        for (int i = 1; i < 121; ++i)
        {
            int n1 = counter[i];
            for (int j = 1; j < 121; ++j)
            {
                int n2 = counter[j];
                if (check(i, j))
                {
                    res += (n1 * n2);
                    if (i == j) res -= n2;
                }
            }
        }
        return res;
    }

    bool check(int a, int b) {
        return (0.5 * a + 7 < b) && (a >= b) && (a >= 100 || b <= 100);
    }
};