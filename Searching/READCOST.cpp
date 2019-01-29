//https://www.codechef.com/problems/READCOST

#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ull;
typedef long double ld;

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define full(a) a.begin(),a.end()
#define mem(a,x) memset(a,x,sizeof(a))

const int MAXN= 1e5+5;
const int MOD = 1e9+7;

using namespace std;

int main() {
    while(true) {
        ll n,m,x;
        cin >> n >> m >> x;
        if(n == 0 && m == 0 && x == 0) break;
        ll prev = 0;
        ll total = 0;
        for(ll amount = 0; amount <= 1000; amount++) {
            ll low = prev + 1;
            ll high = m, ans = -1;
            while(low <= high) {
                ll mid = low + (high - low)/2;
                ll val = x + mid * n;
                ll gonnaPay = (val - n)/m;
                if(gonnaPay > amount) {
                    high = mid - 1;
                }
                else {
                    ans = mid;
                    low = mid + 1;
                }
            }
            if(ans == -1) {
                continue;
            }
            total+=(amount*(ans-prev));
            cout<<total<<" "<<ans<<" "<<amount<<"\n";
            if(ans == m) {
                break;
            }
            prev = ans;
        }
        cout << total << endl;
    }
}