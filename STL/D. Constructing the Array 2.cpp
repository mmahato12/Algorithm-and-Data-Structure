#include<bits/stdc++.h>

#define deb(x) cout << #x << " -> " << x << el 
#define db double
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define unmap unordered_map
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define sclu(x) scanf("%llu", &x)
#define scd(x) scanf("%lf", &x)
#define scld(x) scanf("%Lf", &x)
#define pass cout<<"pass\n"
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define vec vector
#define el "\n"
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define cj "Case #" << tc << ": "
#define f(i,x,y) for(int i=x;i<y;++i)
#define ff(i,x,y) for(int i=x;i<=y;++i)
#define mem(x) memset(x, 0, sizeof(x))
#define mems(x,y) memset(x, y, sizeof(x))
#define MOD 1000000007
#define MAX 200005

using namespace std;

int n, k;

void solve(int tc) {
	cin >> n;
	vi ans(n);

	auto comp = [](pii a, pii b) -> bool {
		int l = a.S - a.F;
		int r = b.S - b.F;

		if(l == r) {
			return a.F > b.F;
		}

		return l < r;
	};

	priority_queue<pii, vector<pii>, decltype(comp)> q(comp);
	q.push({ 0, n - 1 });

	int s = 0;
	while(!q.empty()) {
		pii st = q.top();
		q.pop();

		if(st.F > st.S) continue;

		// cout << "l, r -> " << st.F << ", " << st.S << el;

		int mid = (st.F + st.S) / 2;
		ans[mid] = ++s;

		q.push({ st.F, mid - 1 });
		q.push({ mid + 1, st.S });
	}

	for(int s: ans) cout << s << " ";
	cout << el;
}

int main() {
	int tt = 1;
	sc(tt);
	for(int i = 1; i <= tt; ++i) {
		solve(i);
	}
 	
	return 0;
}