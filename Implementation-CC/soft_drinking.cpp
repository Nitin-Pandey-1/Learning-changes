#include <iostream>
#include <cmath>

using namespace std;

#define soft_drinking(n,k,l,c,d,p,nl,np) (min(((k*l)/nl), min(c*d, (p/np)))/n)

int main() {
  int n, k, l, c, d, p, nl, np;
  cin >>n >> k >> l >>c >> d >> p >>nl >>np;
  cout <<soft_drinking(n, k, l, c, d, p, nl, np) <<endl;
  return 0;
}
