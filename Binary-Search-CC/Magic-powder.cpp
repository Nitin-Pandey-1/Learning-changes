/* Problem: https://codeforces.com/contest/670/problem/D1 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

bool valid_number(ll n, ll k, vector<ll> a, vector<ll> b, ll mid) {
  /*
    total ingrediants = {a1*mid, a2*mid, a3*mid ..... }
    remaining ingrediants = {a1*mid-b1, a2*mid-b2, a3*mid-b3 .....}
    if (any remaining ingrediants > 0) add it up in total_req
    if (k-total_req > 0) true: false;
  */
  ll total_req = 0;
  for (ll i = 0; i < n; i++) {
    if ((a[i]*mid - b[i]) > 0) {
      total_req += (a[i]*mid - b[i]);
    }
  }
  return ((k - total_req) >= 0) ? true: false;
}

ll magic_powder(ll n, ll k, vector<ll> a, vector<ll> b) {
  ll start = 0, end = 1e13;
  ll ans = 0;
  while(start <= end) {
    ll mid = (start + end)/2;
    // Mid is the number of cookies which can be made from ingrediants
    if (valid_number(n, k, a, b, mid)) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

int main() {
  ll n, k;
  cin >> n >> k;
  vector <ll> a, b;
  ll n_copy = n;
  while (n_copy -- ){
    ll ai;
    cin >> ai;
    a.push_back(ai);
  }
  n_copy = n;
  while (n_copy -- ){
    ll bi;
    cin >> bi;
    b.push_back(bi);
  }

  cout << magic_powder(n, k, a, b) <<endl;

  return 0;
}
