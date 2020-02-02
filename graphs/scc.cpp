//aea ctmr
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
//v.erase(unique(v.begin(),v.end()),v.end());
#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PI 3.14159265358979323846
 
typedef long double ld;
typedef long long ll;
const ll N = 100500;
const ll mod = 1e9 + 7;
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
 
struct SCC{
    vector <vector<int>> adj, adj_i;
    vector <bool> used;
    vector <int> order, component;
    // se usa para inicializar los grafos con n vértices y m aristas
    void init(int n, int m){
        vector <int> zero; zero.clear();
        for(int i = 0; i <= n; i++){
            adj.push_back(zero);
            adj_i.push_back(zero);
        }
        
    }
    // para limpiar los usados
    void limpiar(int n, int m){used.assign(n + 1, false);}
    // primer dfs,para calcular los exit time
    void dfs1(int u){
        used[u] = true;
        for(auto x: adj[u]){
            if(!used[x]) dfs1(x);
        }
        order.push_back(u);
    }
    
    // segundo dfs, se tiene que recorrer de reversa, y hacer dfs
    // y todos los que salen son componente, que se guarda en component
    // notar que en cada iteración, component se tiene que limpiar
    void dfs2(int u){
        used[u] = true;
        component.push_back(u);
        for(auto x: adj_i[u]){
            if(!used[x]) dfs2(x);
        }
    }
} F;
 
int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    //se leen las aristas
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        F.adj[a].push_back(b);
        F.adj_i[b].push_back(a);
    }
    return 0;
 
}
