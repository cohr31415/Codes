// recordar ordenarlos antes de usar
// en este problema como las querys estan ordenadas decrecientemente, 
// se puede hacer en O(1)
struct line{
    ll m, h;
    line(){}
    line(ll m, ll h) : m(m), h(h){}
    //comparando las rectas mx + h
};

deque <line> v;
ll dp[N];
vector <pair<pair <ll, ll>, ll>> xd;

inline ll eval(ll x, line a){ // evalua x en la linea a
    return a.m * x + a.h;
}

inline ld in(line a, line b){ // el punto de interseccion entre la linea a y linea b
    return (1.0 * (a.h - b.h)) / (b.m - a.m);
}

void insert(line x){ // añadir una linea
    while(v.size() >= 2 and in(x, v[0]) >= in(v[0], v[1])) v.pop_front();
    v.push_front(x);
}

ll query(ll x){ // respuesta al evaluar en x
    while(v.size() >= 2 and eval(x, v[v.size() - 2]) >= eval(x, v.back())) v.pop_back();
    return eval(x, v.back());
}
