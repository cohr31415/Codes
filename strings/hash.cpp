#include <bits/stdc++.h>
#define ff first
#define ss second
#define siz(s) (int)s.size() //solo usar esto
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
//v.erase(unique(v.begin(),v.end()),v.end());
typedef long long ll;
const ll N = 2e+6 + 100;
const ll M = 1e+7 + 100;
const ll mod = 1e+9 + 7;
const ll inv = 5e+8 + 4;

using namespace std;

ll arr1[N], arr2[N], pot[N];

void pre(ll p){
    pot[0] = 1; 
    for(ll i = 1; i < N; i++){
        pot[i] = (pot[i - 1] * p)% mod;
    }
    
}

void hash_t(string s, ll* arr){
    for(ll i = 1; i <= siz(s); i++){
        arr[i] = arr[i - 1] + (s[i - 1] - 'a' + 1)* (pot[i - 1]);
        arr[i]%= mod;
    }
}


int main(){
    fastio;
    pre(31); //el valor máximo 
    
    
    return 0;
}
