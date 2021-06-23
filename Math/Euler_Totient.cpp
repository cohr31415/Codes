ll p[N];

//primera forma
ll phi(ll n){
  ll ans = n;

  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      while(n / i == 0) n /= i;
      ans -= ans / i; 
    }
  }

  if(n > 1) ans = ans - n;
  return ans;
}

//segunda forma desde el 1 hasta el n 
ll phi_to_n(ll n){
  p[0] = 0;
  p[1] = 1;

  for(int i = 2; i <= n; i++){
    p[i] = i;
  }

  for(int i = 2; i <= n; i++){
    if(p[i] == i){
      for(int j = i; j <= n; j += i) p[j] -= p[j] / i;
    }
  }
}
