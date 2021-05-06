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
const ll N = 1e+5 + 100;
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

ll bpow(ll a, ll b, ll m){
  if(b == 0) return 1;
  ll a1 = bpow(a, b >> 1, m);
  ll a2 = (a1 * a1) % m;
  if(b&1) return (a2 * a) % m;
  else return a2;
}

bool fermat_prime(ll n, int iter = 1000){
  if(n < 4){
    if(n == 2 or n == 3) return true;
    else return false;
  }

  for(int i = 0; i < iter; i++){
    ll a = random(2, n - 2);
    if(bpow(a, n - 1, n) != 1) return false;
  }
  return true;
}

void solve(){
  long long n0; 
  cin >> n0;
  ll n = n0;
  if(fermat_prime(n)) cout << "YES" << endl;
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
