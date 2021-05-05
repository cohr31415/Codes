//https://www.spoj.com/problems/PON/
//ACCEPTED

#include <bits/stdc++.h>
//v.erase(unique(v.begin(),v.end()),v.end());
#define ff first
#define ss second
#define pb push_back
#define sz(v) (ll)v.size()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long double ld;
typedef __int128 ll;
const ll N = 1e+4 + 100;
const ll INF = 1e+18;
const ll mod = 1e+9 + 7;
const ld EPS = 1e-9;
const ll MAXN = 1<<20;
 
using namespace std;
 
const ld DINF = numeric_limits<ld>::infinity(); // que mrd será esto xd
 
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b){ return uniform_int_distribution<ll> (a, b) (rng); }

ll v[12] = {2, 3, 5, 7, 11, 13, 17, 18, 23, 29, 31, 37};


ll bpow(ll a, ll b, ll m){
  if(b == 0) return 1LL;
  ll a1 = bpow(a, b >> 1, m);
  ll a2 = (a1 * a1) % m;
  if(b&1) return (a2 * a) % m;
  else return a2;
}

bool check_c(ll n, ll a, ll d, ll s){
  //if(__gcd(n, a) != 1) return false;
  ll x = bpow(a, d, n);

  if(x == 1 or x == n - 1) return false;
  for(int r = 1; r < s; r++){
    x = (x * x) % n;
    if(x == n - 1) return false; 
  }
  return true;
}

bool miller_rabin(ll n, ll iter){
  if(n < 4){
    if(n == 2 or n == 3) return true;
    else return false;
  }

  ll s = 0;
  ll d = n - 1;
  while(!(d&1)){
    d >>= 1;
    s++;
  }

  for(int i = 0; i < iter; i++){
    ll a = v[i];
    if(a > n - 2) continue;
    if(check_c(n, a, d, s)) {return false;}
  }

  return true;
}



void solve(){

  long long n1; cin >> n1;
  ll n = n1;
  

  if(miller_rabin(n, 12)) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  
}
 
 
int main(){

  int t = 1;
  cin >> t;

  for(int i = 1; i <= t; i++){
    solve();
      
  }

  return 0;
}
