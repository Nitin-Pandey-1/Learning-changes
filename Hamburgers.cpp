/* Problem: https://codeforces.com/contest/371/problem/C */
/* STAR PROBLEM */
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

bool possible_burger(ll b, ll sa, ll c, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll r, ll mid) {
    /* 
        total B = b*mid;
        total C = c*mid;
        total sa = sa* mid;
        remaining B = b*mid - nb;
        remaining C = c*mid - nc;
        remaining sa = sa*mid - ns;
        if remaining B > 0 and remaining c >0 and remaining sa >0 r - (remaining B*pb + remaining C*pc + remaining sa*ps) >=0 return true, else return false;
    */

    ll total_ruble = 0;
    if ((b*mid - nb) > 0) total_ruble += ((b*mid - nb)*pb);
    if ((sa*mid - ns) > 0) total_ruble += ((sa*mid - ns)*ps);
    if ((c*mid - nc) > 0) total_ruble += ((c*mid - nc)*pc);

    return (r - total_ruble >=0) ? true: false;
}

ll hamburgers(string s, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll r)
{
    ll b = 0, sa = 0, c = 0;
    for (ll i = 0; i < s.length(); i++) {
        (s[i] == 'B') ? b++: ((s[i] == 'S') ? sa++ : c++);
    }
    ll start = 0, end = 1e13, ans = 0;
    while (start <= end) {
        ll mid = (start + end) / 2;
        if (possible_burger(b, sa, c, nb, ns, nc, pb, ps, pc, r, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;
    cout << hamburgers(s, nb, ns, nc, pb, ps, pc, r) << endl;
    return 0;
}
