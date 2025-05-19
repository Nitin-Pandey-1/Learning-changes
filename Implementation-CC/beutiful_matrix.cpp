#include <iostream>
#include <cmath>
using namespace std;

#define beutiful_matrix(a, b) (abs(2-a) + abs(2-b))

int main() {
  int element;
  int matrix[5][5];
  int row1 = 0, coloumn1 = 0;

  for (int i= 0; i<5; i++) {
    for (int j = 0; j<5; j++) {
      cin >> element;
      matrix[i][j] = element;
      if (element) {
        row1 = i, coloumn1 = j;
      }
    }
  }

  cout << beutiful_matrix(row1, coloumn1)<<endl;
  return 0;
}
