// Te wheel_factorization te devuelve todos los factores primos

typedef N = 1e+5 + 100;

void linear_sieve(){ // o(n)
  for(int i = 1; i < N; i++) primes[i] = i;
  for(int i = 2; i < N; i++){
    if(primes[i] == i) p.push_back(i);
    for(int j = 0; j < p.size() and p[j] * i < N; j++){
      primes[p[j] * i] = p[j];
      if(i % p[j] == 0) break;
    }
  }
}

vector <int> wheel_factorization(int n){
  vector <int> divi; divi.clear();
  while(n != 1){
    int a = primes[n];
    while(n % a == 0) divi.push_back(a), n /= a;
  }
  return divi;
}
