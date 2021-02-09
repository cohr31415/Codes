// inicializa con init(0, 1, n, arreglo)
// update de suma de [l ,r) 
// query de suma de [l, r)
int st[4 * N], lazy[4 * N];
int a[N];
int n;

inline int op(int a, int b){ return a + b;}

void init(int k, int s, int e, int* a){ // inicializa con init(1, 0, n, a)
    lazy[k] = 0; // valor neutro del lazy
    if(s + 1 == e){
        st[k] = a[s];
        return; // no olvidar return
    }
    int mid = (s + e)/2;
    init(2 * k, s, mid, a); init(2 * k + 1, mid, e, a);
    st[k] = op(st[2 * k], st[2 * k + 1]); // no olvidar la operacion
}

void push(int k, int s, int e){ //pushea los errores
    if(lazy[k] == 0) return; // elemento neutro
    st[k] += (lazy[k] * (e - s)); //+= ya que es suma
    if(s + 1 < e){
        lazy[2 * k] += lazy[k]; // += ya que es suma
        lazy[2 * k + 1] += lazy[k];
    }
    lazy[k] = 0; //elemento neutro
}

void upd(int k, int s, int e, int l, int r, int v){ // se usa con upd(1, 0, n, l, r, v)
    push(k, s, e);
    if(e <= l || s >= r) return; // caso nulo 
    if(s >= l && e <= r){
        lazy[k] += v;
        push(k, s, e); //no entiendo este push 
        return; //no olvidar el return
    }
    int mid = (s + e) / 2;
    upd(2 * k, s, mid, l, r, v);
    upd(2 * k + 1, mid, e, l, r, v);
    
    st[k] = op(st[2 * k], st[2 * k + 1]); // no olvidar la operacion
}

int query(int k, int s, int e, int l, int r){ // se usa com query(1, 0, n, l, r)
    if(e <= l || s >= r) return 0; //caso nulo 
    push(k, s, e);
    if(s >= l && e <= r) return st[k];
    int mid = (s + e) / 2;
    return op(query(2 * k, s, mid, l , r), query(2 * k + 1, mid, e, l, r));
}
