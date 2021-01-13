//https://codeforces.com/problemset/problem/154/C
//need double hash 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define siz(s) (ll)s.size() //solo
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
//v.erase(unique(v.begin(),v.end()),v.end());
typedef long long ll;
const ll N = 1e+6 + 100;
const ll M = 1e+7 + 100;
const ll mod = 1e+9 + 7;
const ll mod2 = 1e+9 + 9;
const ll inv = 5e+8 + 4;

using namespace std;

ll pot[N], pot2[N], hash_t[N], hash_t2[N];
vector <ll > adj[N];
map <pair<ll, ll>, ll> ma;
ll tot = 0, tot2 = 0;

void pre(){
    pot[0] = 1;
    for(ll i = 1; i < N; i++){
        pot[i] = (pot[i - 1] * 3) % mod;
    }
    pot2[0] = 1;
    for(ll i = 1; i < N; i++){
        pot2[i] = (pot2[i - 1] * 3) % mod2;
    }
    
    
}

void solve(){
    ll n, m; cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        tot += pot[i];
        tot %= mod;
        tot2 += pot2[i];
        tot2 %= mod;
    }
    for(ll i = 1; i <= n; i++) hash_t[i] = tot, hash_t2[i] = tot2;
    
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
        
        hash_t[a] += pot[b];
        hash_t[a] %= mod;
        hash_t[b] += pot[a];
        hash_t[b] %= mod;
        
        hash_t2[a] += pot2[b];
        hash_t2[a] %= mod2;
        hash_t2[b] += pot2[a];
        hash_t2[b] %= mod2;
    }
    for(ll i = 1; i <= n; i++) ma[{hash_t[i], hash_t2[i]}]++;
    
    ll ans = 0;
    
    for(auto x: ma){
        ans += (x.ss * x.ss - x.ss) / 2;
    }
    
    for(ll u = 1; u <= n; u++){
        for(auto v: adj[u]){
            //edge u--v
            if(v > u) continue;
            ll curr_u = hash_t[u] + pot[u];
            curr_u %= mod; 
            if(curr_u < 0) curr_u += mod;
            ll curr_v = hash_t[v] + pot[v];
            curr_v %= mod; 
            if(curr_v < 0) curr_v += mod;
            
            ll curr_u2 = hash_t2[u] + pot2[u];
            curr_u2 %= mod2; 
            if(curr_u2 < 0) curr_u2 += mod2;
            ll curr_v2 = hash_t2[v] + pot2[v];
            curr_v2 %= mod2; 
            if(curr_v2 < 0) curr_v2 += mod2;
            
            if(curr_u == curr_v and curr_u2 == curr_v2) ans++;
        }
    }
    

    cout << ans << endl;
    
    
}

int main(){
    fastio;
    pre();
    ll t = 1;
    //cin >> t;
    
    while(t--) solve();
    
    return 0;
}
