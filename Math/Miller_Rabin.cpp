//para llamar si un numero es primo es miller_rabin(n, 12)
typedef __int128 ll; //en el caso de numeros grandes

ll v[12] = {2, 3, 5, 7, 11, 13, 17, 18, 23, 29, 31, 37};

//bpow
ll bpow(ll a, ll b, ll m){
  if(b == 0) return 1LL;
  ll a1 = bpow(a, b >> 1, m);
  ll a2 = (a1 * a1) % m;
  if(b&1) return (a2 * a) % m;
  else return a2;
}

//true si n es compuesto
bool check_c(ll n, ll a, ll d, ll s){
  //if(__gcd(n, a) != 1) return false;
  ll x = bpow(a, d, n);

  if(x == 1 or x == n - 1) return false;
  for(int r = 1; r < s; r++){
    x = (x * x) % n;
    if(x == n - 1) return false; 
  }
  return true;
}

//true si n es priimo
bool miller_rabin(ll n, ll iter){
  if(n < 4){
    if(n == 2 or n == 3) return true;
    else return false;
  }

  ll s = 0;
  ll d = n - 1;
  while(!(d&1)){
    d >>= 1;
    s++;
  }

  for(int i = 0; i < iter; i++){
    ll a = v[i];
    if(a > n - 2) continue;
    if(check_c(n, a, d, s)) {return false;}
  }

  return true;
}
