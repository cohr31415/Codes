//https://www.spoj.com/problems/NHAY/
#include <bits/stdc++.h>
#define ff first
#define ss second
#define siz(s) (int)s.size()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
//v.erase(unique(v.begin(),v.end()),v.end());
typedef long long ll;
const ll N = 2e+6 + 100;
const ll M = 1e+7 + 100;
const ll mod = 1e+9 + 7;
const ll inv = 5e+8 + 4;

using namespace std;

ll arr1[N], arr2[N], pot[N], i_pot[N];

ll bpow(ll a, ll b){
    if(b==0) return 1;
    ll a1 = bpow(a, b/2);
    ll a2 = (a1 * a1)%mod;
    if(b&1) return (a2*a)%mod;
    else return a2;
}

void pre(ll p){
    pot[0] = 1; 
    for(ll i = 1; i < N; i++){
        pot[i] = (pot[i - 1] * p)% mod;
    }
    
}

void hash_t(string s, ll* arr){
    for(ll i = 1; i <= s.size(); i++){
        arr[i] = arr[i - 1] + (s[i - 1] - 'a' + 1)* (pot[i - 1]);
        arr[i]%= mod;
    }
}

void solve(ll n){
    string s; cin >> s;
    string s1; cin >> s1;
    
    hash_t(s, arr1);
    hash_t(s1, arr2);
    int cont = 0;
    for(ll i = 1; i <= siz(s1) - siz(s) + 1; i++){
        ll curr = arr2[i + s.size() - 1] - arr2[i - 1];
        curr %= mod;
        if(curr < 0) curr += mod;
        ll curr2 = arr1[s.size()] * pot[i - 1];
        curr2 %= mod;
        if(curr2 < 0) curr2 += mod;

        if(curr == curr2) cont++, cout << i - 1 << endl;
    }
    if(!cont) cout << endl;
}

int main(){
    fastio;
    pre(31);
    ll t; 
    t = 1;
    //cin >> t;
    
    while(cin >> t) solve(t);
    
    return 0;
}
