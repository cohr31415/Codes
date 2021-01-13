//https://codeforces.com/contest/126/problem/B
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

int kmp[N], kmp2[N];

void solve(){
    string s; cin >> s;
    int n = s.size();
    
    kmp[0] = 0;
    
    for(int i = 1; i < n; i++){
        int j = kmp[i - 1];
        while(j > 0 and s[j] != s[i]) j = kmp[j - 1];
        if(s[j] == s[i]) j++;
        kmp[i] = j;
    }
    
    int maxi = 0;
    //for(int i = 1; i < n; i++) cout << kmp[i] << endl;
    for(int i = 1; i < n - 1; i++) maxi = max(maxi, kmp[i]);
    int ans = kmp[n - 1];
    while(ans > maxi) ans = kmp[ans - 1];
    
    if(!ans) cout << "Just a legend" << endl;
    else{
        for(int i = 0; i < ans; i++) cout << s[i]; cout << endl;
    }
}


int main(){
    fastio;
    //pre(31); //el valor máximo 
    int t = 1;
    //cin >> t;
    
    while(t--) solve();
    
    return 0;
}
