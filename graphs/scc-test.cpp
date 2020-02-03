// SPOJ
// CAPCITY - Capital City
// cp algorithms
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
    vector <int> order, component, color;
    // se usa para inicializar los grafos con n vértices y m aristas
    void init(int n, int m){
        adj.clear(); adj_i.clear(); order.clear();
        color.assign(n + 1, 0);
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
    void dfs2(int u, int col){
        used[u] = true;
        component.push_back(u);
        color[u] = col;
        for(auto x: adj_i[u]){
            if(!used[x]) dfs2(x, col);
        }
    }
    //resuelve el scc y en color te guarda el color en el que guarda
    int go(int n, int m){
        for(int i = 1; i <= n; i++){
            if(!used[i]) dfs1(i);
        }
        limpiar(n, m);
        int col = 1;
        for(int i = 0; i < n; i++){
            int u = order[n - i - 1];
            if(!used[u]) {
                dfs2(u, col);
                col++; 
            }
        }
        return col - 1;
    }
} F;
 
vector <pair <int, int>> aristas;
vector <int> xd[N], aea, resp;
int tot[N];
int vis[N];

void dfs(int u, int p){
    vis[u] = true;
    tot[u] = 1;
    for(auto x: xd[u]){
        if(x == p) continue;
        dfs(x, u);
        if(!vis[x]) tot[u] += tot[x];
    }
}

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    //se leen las aristas
    F.init(n, m);
    F.limpiar(n, m);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        F.adj[a].push_back(b);
        F.adj_i[b].push_back(a);
        aristas.push_back({a, b});
    }
    int n2 = F.go(n, m);
    //for(int i = 1; i <= 4; i++) trace(F.color[i]);
    //trace(n2);
    //listo todos están 
    
    for(auto x: aristas){
        int a = F.color[x.ff], b = F.color[x.ss];
        if(a == b) continue;
        xd[a].push_back(b);
        //trace(a, b);
    }

    for(int i = 0; i < N; i++) {sort(xd[i].begin(), xd[i].end()); xd[i].erase(unique(xd[i].begin(),xd[i].end()),xd[i].end());}
    
    int cant = 0;
    for(int i = 1; i <= n2; i++){
        if(xd[i].size() == 0) cant++;
    }

    //trace(uwu);
    if(cant == 1){
        int answer = -1;
        for(int i = 1; i <= n2; i++){
            if(xd[i].size() == 0) answer = i;
        }
        //trace(answer);
        for(int i = 1; i <= n; i++){
            if(F.color[i] == answer) resp.push_back(i);
        }

        cout << resp.size() << endl;
        for(auto x: resp) cout << x << " ";
    }
    else{
        cout << 0 << endl;
    }

    return 0;
 
}
