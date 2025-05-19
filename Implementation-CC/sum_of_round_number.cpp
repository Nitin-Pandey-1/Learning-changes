#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<int> round_number(int n)
{
    vector<int> ans;
    int i = 0;
    while (n > 0)
    {
        int digit = n % 10;
        if (digit != 0) {
            ans.push_back(digit * pow(10, i));
        }
        n /= 10;
        i++;
    }
    return ans;
}

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> ans = round_number(n);
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
