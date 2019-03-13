//Solution to the codeforces round #564
//https://codeforces.com/contest/1136/standings/friends/true
//
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define sz size
#define ss second
#define pb push_back
#define mp make_pair
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
//#define mod 1000000007
typedef long long ll;
typedef long double ld;
const ll minf = 1e9 + 5;
const ld ep = 2.71828182845904523536;
const int EPS=1e-9;
//const ld pi=acos(-1.0);
const int N = (520);

using namespace std;

int ma[N][N], me[N][N];
vector <int> xd[2*N];
vector <int> xd2[2*N];
int main(){
	fastio;
	int n ,m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> ma[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> me[i][j];
		}
	}
	
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			xd[i + j].push_back(ma[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			xd2[i + j].push_back(me[i][j]);
		}
	}
	bool bo = true;
	for(int i = 0; i < 2*N; i++){
		sor(xd[i]);
		sor(xd2[i]);
		int l = xd[i].size();
		for(int j = 0; j < l; j++){
			if(xd[i][j] != xd2[i][j]) bo = false;
		}
		if(!bo) break;
	}


	if(bo) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	

	return 0;


}
