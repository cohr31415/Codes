//se inicializa con init(arreglo)
//se modifica p = pos, v = val
int st[2 * N];
int a[N];
int n;

inline int op(int a, int b){ return a + b;}

void init(int* a){ //inicia
    for(int i = 0; i < n; i++) st[i + n] = a[i]; //arreglo original
    for(int i = n - 1; i > 0; i--) st[i] = op(st[i << 1], st[(i << 1) | 1]);
}

void update(int p, int v){ //modifica
    st[p += n] = v;
    for(p; p > 1; p >>= 1) st[p >> 1] = op(st[p], st[p^1]);
}

int query(int l, int r){ //query de [l, r)
    int ans = 0; //valor neutral
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) ans = op(ans, st[l++]);
        if(r & 1) ans = op(ans, st[--r]);
    }
    return ans; //rspuesta
}
