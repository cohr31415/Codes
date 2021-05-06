//Primera forma
typedef vector <vector <int>> Matrix;

Matrix operator +(Matrix m1, Matrix m2) { // suma
  // misma dimension
  assert(m1.size() == m2.size());
  assert(m1[0].size() == m2[0].size());
  
  Matrix m3(m1.size(), vector <int>(m1[0].size(), 0));
  for(int i = 0; i < m1.size(); i++){
    for(int j = 0; j < m1[0].size(); i++){
      m3[i][j] = (m1[i][j] + m2[i][j]) % mod;
    }
  }

  return m3;
}

Matrix operator -(Matrix m1, Matrix m2) { // resta
  // misma dimension
  assert(m1.size() == m2.size());
  assert(m1[0].size() == m2[0].size());
  
  Matrix m3(m1.size(), vector <int>(m1[0].size(), 0));
  for(int i = 0; i < m1.size(); i++){
    for(int j = 0; j < m1[0].size(); i++){
      m3[i][j] = (m1[i][j] - m2[i][j] + mod) % mod;
    }
  }

  return m3;
}

Matrix operator * (Matrix m1, Matrix m2) { // producto
  // para que se multipliquen
  assert(m1[0].size() == m2.size());
  Matrix m3(m1.size(), vector <int>(m2[0].size(), 0));

  for(int i = 0; i < m1.size(); i++){
    for(int j = 0; j < m2[0].size(); j++){
      for(int k = 0; k < m1[0].size(); k++){
        m3[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }

  return m3;
}

Matrix bp(Matrix m1, int n) { // exponenciacion de matrices
  //matrix cuadrada
  assert(m1.size() == m1[0].size());
  Matrix m3(m1.size(), vector <int>(m1.size(), 0));
  if(n == 0){
    for(int i = 0; i < m3.size(); i++) m3[i][i] = 1;
    return m3;
  }

  m3 = bp(m1, n >> 1);
  Matrix m4 = m3 * m3;
  if(n&1) return m4 * m1;
  else return m4;
}

pair <int, int> fib2(int n) { // devuelve f(n), f(n + 1)
  Matrix m3(2, vector <int>(2, 0));
  m3[0][1] = 1;
  m3[1][0] = 1;
  m3[1][1] = 1;
  Matrix m4 = bp(m3, n);

  return {m4[0][1], m4[1][1]};
}

//Segunda forma

pair <int, int> fib1(int n) { // devuelve f(n), f(n + 1)
  if(n == 0) return {0, 1};

  pair <int, int> p = fib1(n >> 1);
  int c = (p.ff * (2 * p.ss - p.ff)) % mod;
  int d = (p.ff * p.ff + p.ss * p.ss) % mod;

  if(n&1) return {d, (c + d) % mod};
  else return {c, d};
} 

int fib(int n) { //devuelve f(n)
  return fib2(n).ff;
}
