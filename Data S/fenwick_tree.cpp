//inicializar con update
//el getsum devuelve la suma de [0...pos]
int arr[N];
int bitree[N];
int n;

int getsum(int pos){
    int sum = 0;
    pos++; //ya que el arreglo de bitree empieza en 1
    while(pos > 0){
        sum += bitree[pos];
        pos -= (pos & -pos);
    }
    return sum;
}

//tienes que actualizar el arr antes de update
void update(int pos, int val){
    pos++; //ya que el arreglo de bitree empieza en 1
    while(pos <= n){
        bitree[pos] += val;
        pos += (pos & -pos);
    }
    
}
