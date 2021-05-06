typedef __int128 ll;

ll bpow(ll a, ll b, ll m){
  if(b == 0) return 1;
  ll a1 = bpow(a, b >> 1, m);
  ll a2 = (a1 * a1) % m;
  if(b&1) return (a2 * a) % m;
  else return a2;
}

bool fermat_prime(ll n, int iter = 1000){
  if(n < 4){
    if(n == 2 or n == 3) return true;
    else return false;
  }

  for(int i = 0; i < iter; i++){
    ll a = random(2, n - 2);
    if(bpow(a, n - 1, n) != 1) return false;
  }
  return true;
}
