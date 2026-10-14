/*******************************
* Автор: Решетников Дмитрий    *
* Вариант: 22                  *
* Название: Обработка массивов *
*******************************/

#include <iostream>
using namespace std;

int main(){
  const int MAX_N = 5;
  int F[MAX_N][MAX_N];
  int maxLen = 0;
  int rowNumber = 0;
  int currentLen, rowMaxLen, n;
  

  cout << "size of matrix n (no more than " << MAX_N << "): ";
  cin >> n;

  cout << "Enter the matrix elements:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> F[i][j];
    }
  }

  
  for (int i = 0; i < n; i++) {
    currentLen = 1;
    rowMaxLen = 1;

    for (int j = 1; j < n; j++) {
      if (F[i][j] == F[i][j - 1]) {
        currentLen++;
      }
      else
      {
        if (currentLen > rowMaxLen) {
          rowMaxLen = currentLen;
        }
        currentLen = 1;
      }
    }
    if (currentLen > rowMaxLen) {
      rowMaxLen = currentLen;
    }

  
    cout << "Longest sequence in a row " << i << ": " << rowMaxLen << endl;

    if (rowMaxLen > maxLen) {
      maxLen = rowMaxLen;
      rowNumber = i;
    }
  }

  
  cout << "Initial matrix F:" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << F[i][j] << "\t";
    cout << endl;
  }

  cout << "\nLength of the longest sequence in the matrix: " << maxLen << endl;
  cout << "Row number with the longest sequence: " << rowNumber << endl;

  return 0;
}