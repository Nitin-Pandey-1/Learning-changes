#include <iostream>
#include <cmath>

using namespace std;

int min_dist(int x1, int x2, int x3)
{
    return min((abs(x1 - ((x1 + x2 + x3)/3)) + abs(x2 - ((x1 + x2 + x3)/3)) + abs(x3 - ((x1 + x2 + x3)/3))),
               min((abs(x1 - x2) + abs(x3 - x2)),
               min((abs(x2 - x1) + abs(x3 - x1)),
               (abs(x1 - x3) + abs(x2 - x3)))));
}

int main()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    cout << min_dist(x1, x2, x3) << endl;
    return 0;
}
