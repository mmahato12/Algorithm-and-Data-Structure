#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <random>
#include <queue>
#include <cstring>
#include <cassert>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define all_(x) x.rbegin(), x.rend()
#define multi_test 1

typedef long long ll;
typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const ll INF = 1e9 + 9;
const ll INF1 = 1e18 + 19;
const ll MAXN = 1e6 + 7;
const ll MAXN1 = 300;
const ll MAXN2 = (1 << 24) + 7;
const ll MOD = 1e9 + 7;
const ll PW = 31;
const ll BLOCK = 317;

void solve();
mt19937_64 mt(1e9 + 7);

signed main() {
    srand('a' + 'l' + 'e' + 'x' + 'X' + '5' + '1' + '2');
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef _DEBUG
#define MAXN 5000
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int q = 1;
    if (multi_test) cin >> q;
    while (q--)  {
        solve();
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------*/

bool pick(int i, vector<int>& v, int l, int r) {
    if (i == l || i == r) return 0;
    return v[i - 1] < v[i] && v[i] > v[i + 1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    int ans = -1, l = -1, r = -1, now = 0;
    for (int i = 1; i + 1 < k; ++i) {
        if (pick(i, v, 0, k - 1)) ++now;
    }

    ans = now + 1, l = 0, r = k - 1;
    for (int i = k; i < n; ++i) {
        if (pick(i - k + 1, v, i - k, i - 1)) --now;
        if (pick(i - 1, v, i - k + 1, i)) ++now;
        if (now + 1 > ans) {
            ans = now + 1;
            l = i - k + 1;
            r = i;
        }
    }

    cout << ans << " " << l + 1 << "\n";
}





//https://codeforces.com/contest/1341/problem/B