//devuelve el gcd entre a y b
//cumple que a * x + b * y = gcd(a, b)

ll gcd(ll a, ll b, ll *x, ll *y){
  if(b == 0){
    *x = 1;
    *y = 0;
    return a;
  }
  ll g = gcd(b, a % b, &x1, &y1);
  *x = y1;
  *y = x1 - (a / b) * y1;
  return g;
}

ll lcm(ll a, ll b){
  ll x, y;
  ll g = gcd(a, b, &x, &y);
  return (a * b) / g;
}
