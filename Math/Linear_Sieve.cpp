int prime[N]; // el menor divisor primo
vector <int> p; // guarda los primos 

void linear_sieve(int n) { // criba en o(n)
  assert(n < N);
  for(int i = 1; i <= n; i++) prime[i] = i;

  for(int i = 2; i <= n; i++){
    if(prime[i] == i) p.push_back(i);
    for(int j = 0; j < p.size() and i * p[j] <= n; j++){
      prime[i * p[j]] = p[j];
      if(i % p[j] == 0) break;
    }
  }
}
