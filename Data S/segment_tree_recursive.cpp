// se inicializa con init(1, 0, n, arreglo)
int st[4 * N];
int a[N];
int n;

inline int op(int a, int b){ return a + b;} // la operación, se puede cambiar a struct

void init(int k, int s, int e, int* a){ // para inicializar init(1, 0, n, a)
    if(s + 1 == e){
        st[k] = a[s];
        return; // no olvidar return
    }
    int mid = (s + e)/2;
    init(2 * k, s, mid, a); init(2 * k + 1, mid, e, a);
    st[k] = op(st[2 * k], st[2 * k + 1]); // no olvidar la operacion 
}
// para actualizar el valor de p a v
void upd(int k, int s, int e, int p, int v){ // upd(1, 0, n, p, v)
    if(s + 1 == e){
        st[k] = v;    
        return; // no olvidar return
    }
    int mid = (s + e) / 2;
    if(mid > p) upd(2 * k, s, mid, p, v);
    else upd(2 * k + 1, mid, e, p, v);
    
    st[k] = op(st[2 * k], st[2 * k + 1]); // no olivdar la operacion
}
// para obtener la query de [l, r)
int query(int k, int s, int e, int l, int r){ // query(1, 0, n, l, r)
    if(e <= l || s >= r) return 0;
    if(s >= l && e <= r) return st[k];
    int mid = (s + e) / 2;
    return op(query(2 * k, s, mid, l , r), query(2 * k + 1, mid, e, l, r));
}
