//el vasito repoio 
#include <bits/stdc++.h>
	
#define f(i,a,b) for( int i = a; i < b ; i++ ) 
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
const ll N = 105;
const ll mod = 998244353;
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

//se crea la structura del vertice de cada nodo
struct vertex{
	map <char, int> next, go;
	int p, link; //padre sufix link
	char pch;
	vector <int> leaf; //hijos
	vertex(int p = -1, char pch = -1): p(p), pch(pch), link(-1){}
};

vector <vertex> t; //el vector de los vértices 

void aho_init(){//no olvidar, se inicializa el aho
	t.clear(); t.push_back(vertex());
}

void add_string(string s, int id){
	int v = 0;

	for(char c: s){
		//se recorre el string 
		if(!t[v].next.count(c)){
			//en caso de que no haya aparecido, lo creamos
			t[v].next[c] = t.size();
			t.push_back(vertex(v, c)); //con esto se añade el nuevo nodo, como el ultimo 
		}
		v = t[v].next[c]; //con esto se pasa al siguiente nodo
	}
}

int go(int v, char c);

int get_link(int v){
	if(t[v].link < 0){
		if(!v || !t[v].p) t[v].link = 0; //si estamos en el nodo 0 o sus hijos
		else t[v].link = go(get_link(t[v].p), t[v].pch); //del padre y del valor 	
	}
	return t[v].link;
}

int go(int v, char c){
	if(!t[v].go.count(c)){
		//en caso de que no lo encuentre en el go, hace una recursion
		if(t[v].next.count(c)) t[v].go[c] = t[v].next[c]; // si ya hay c, tonces ese es
		else t[v].go[c] = v == 0 ? 0 : go(get_link(v), c); // si no hay es la recursion
	}

	return t[v].go[c];
}

int main(){
	fastio;
	//se inicia el aho corasick
	aho_init();
	return 0;
}
