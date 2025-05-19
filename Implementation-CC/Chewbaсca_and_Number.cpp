#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

#define MIN(a, b) (a>=b) ? b:a

ll chewbacca(ll x) {
  ll digit = 0;
  ll res = 0;
  ll power = 1;
  while(x>0) {
    digit = x%10;
    digit = MIN(digit, 9-digit);
    res += digit*power;
    x /=10;
    power *= 10;
  }
  if (!digit) {
    res += 9*(power/10);
  }
  return res;
}

int main() {
  ll x;
  cin >> x;
  cout << chewbacca(x)<<endl;
  return 0;
}
