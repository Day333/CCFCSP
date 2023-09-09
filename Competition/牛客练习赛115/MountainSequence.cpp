#include <iostream>
#include <map>
#define MOD 998244353
typedef long long ll;

void solve()
{
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    int maxx = -1;
    for (int t = 1; t <= n; t++)
    {
        int a;
        std::cin >> a;
        mp[a]++;
        maxx = std::max(maxx, a);
    }
    ll ans = 1;
    for (auto t : mp)
    {
        if (t.first == maxx)
            continue;
        ans = (ans * (t.second + 1)) % MOD;
    }
    std::cout << ans << std::endl;
}

int main()
{
    int TT;
    std::cin >> TT;
    while (TT--)
    {
        solve();
    }
    return 0;
}