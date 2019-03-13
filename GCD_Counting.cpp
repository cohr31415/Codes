//This is the Educational Codeforces Round 58
//https://codeforces.com/contest/1101/problem/D
//This solution contains a lot of comments due the debug's part 
//
#include <bits/stdc++.h>
#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define fs first
#define sz size
#define sc second
#define pb push_back
#define mp make_pair
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const ll minf = 1e+18;
const int N = 200005;
const ld ep = 2.71828182845904523536;
 

using namespace std;

//vector <ld> dist;
vector <int> xd[N];
vector <int> adj[N];
vector <int> valor;
map <int,int> m[N];
map <int,int>::iterator it;
int padre[N];
bool vis[N];
bool visfeik[N];
bool visited[N];
int maxi = 1;
int n;

void useless(){
	//primero se ve los divisores primos
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			for(int j = i; j < N; j+=i) {
				vis[j] = true;
				xd[j].push_back(i);
			}
		}
	}
	//ahora se mapea para cada valor del vector xd y mas webadas :v
	for(int i = 1; i <= n; i++){
		int l = xd[valor[i]].size();
		for(int j = 0; j < l; j++){
			m[i][xd[valor[i]][j]] = 1;
		}
	}
	for(int i = 0; i < N; i++) {padre[i] = -1;}
}

void dfsfeik(int u){
	//cout << u << endl;
	visfeik[u] = true;
	int l = adj[u].size();

	for(int i = 0; i < l; i++){
		int v = adj[u][i];
		if(!visfeik[v]){
			//cout << v << " asdasd" << endl; 
			//int v = adj[u][i];
			//padre[v] = v;
			dfsfeik(v);
			padre[v] = u;
		}
	}
}

void dfs(int u){
	//int ward = u;
	visited[u] = true;
	int l = adj[u].size();

	
	int len = xd[valor[u]].size();
	//cout << "asdasd   " << u << " " << len<<endl;
	for(int i = 0; i < l; i++){
		if(!visited[adj[u][i]]) dfs(adj[u][i]);
	}
	for(int j = 0; j < len; j++){
		//este es el primo que debemos buscar xd
		int pri = xd[valor[u]][j];
		int maxi1 = 0;
		int maxi2 = 0;
		for(int i = 0; i < l; i++){
			int v = adj[u][i];

			if(v != padre[u]){
				
				//veremos todos sus primos
				it = m[v].find(pri);

				if(it != m[v].end()){
					//m[u][pri] = max(m[u][pri], m[v][pri] + 1);
					if(m[v][pri] >= maxi1 and m[v][pri] >= maxi2){maxi2 = maxi1; maxi1 = m[v][pri];}
					else if(m[v][pri] < maxi1 and m[v][pri] >=maxi2){maxi2 = m[v][pri];}

				}

			}

		}
		m[u][pri] = maxi1 + 1;
		//cout << u << " " << pri << " " << maxi1 << " " <<maxi2 <<endl; 
		maxi = max(maxi, maxi1 + maxi2 + 1);
	}

}

int main(){
	fastio;
	int n;
	bool tr = false;
	cin >> n;
	
	//cout<<xd[2].size()<<endl;
	valor.push_back(-1);
	//cout<<xd[n].size()<<endl;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a != 1) tr = true;
		valor.push_back(a);
	}
	//cout<<valor[1]<<endl;

	//if(!tr) {cout<< 0 << endl; return 0;}

	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	useless();
	if(!tr) {cout<< 0 << endl; return 0;}
	//primero veremos quienes son los padres de cada webda :V
	dfsfeik(1);
	dfs(1);
	for(int i = 1; i <= n; i++){
		//cout << i << " " << padre[i] << endl;
	}	

	/*
	int l;
	cout <<"-asdasdasd ";
	cin >> l;
	for(int i=0;i<xd[l].size();i++) cout << xd[l][i] << endl;
	*/
	cout << maxi <<endl;
	return 0;
}
