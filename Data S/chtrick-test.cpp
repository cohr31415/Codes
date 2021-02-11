// https://codeforces.com/contest/1083/problem/E
// por el problema en especifico, pendientes ordenadas 
// y queries ordenadas
#include <bits/stdc++.h>
//v.erase(unique(v.begin(),v.end()),v.end());
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef double ld;
typedef long long ll;
const ll N = 1e+6 + 1500;
const ll M = 3e+7 + 10;
const ll P = 31;
const ll mod = 1e+9 + 7 ;

using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);}
#else
#define trace(...)
#endif

struct line{
    ll m, h;
    line(){}
    line(ll m, ll h) : m(m), h(h){}
    //comparando las rectas mx + h
};

deque <line> v;
ll dp[N];
vector <pair<pair <ll, ll>, ll>> xd;

inline ll eval(ll x, line a){
    return a.m * x + a.h;
}

inline ld in(line a, line b){
    return (1.0 * (a.h - b.h)) / (b.m - a.m);
}

void insert(line x){
    while(v.size() >= 2 and in(x, v[0]) >= in(v[0], v[1])) v.pop_front();
    v.push_front(x);
}

ll query(ll x){
    while(v.size() >= 2 and eval(x, v[v.size() - 2]) >= eval(x, v.back())) v.pop_back();
    return eval(x, v.back());
}

void solve(){
    ll n; cin >> n;
    
    for(int i = 0; i < n; i++){
        ll x, y, a; cin >> x >> y >> a;
        xd.push_back({{x, y}, a});
    }
    
    sort(xd.begin(), xd.end());
    
    insert(line{0, 0});
    ll ans = 0;
    for(int i = 0; i < n; i++){
        dp[i] = query(xd[i].ff.ss) + xd[i].ff.ff * xd[i].ff.ss - xd[i].ss;
        insert(line{-xd[i].ff.ff, dp[i]});
        ans = max(ans, dp[i]);
    }
    
    cout << ans << endl;

}

int main(){
    fastio;
    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
    return 0;
}
