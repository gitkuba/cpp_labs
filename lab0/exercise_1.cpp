//
// 1.  Napisz program, który wczytuje ze standardowego wejścia dwie liczby
// (double) i wypisuje ich sumę jeśli obie liczby są mniejsze niż 1000.
//

#include <iostream>

using namespace std;

int main() {
    cout << "Podaj dwie liczby typu double: ";
    double n,m;
    cin >> n;
    cin >> m;
    if (n >= 1000 or m >= 1000){
        cout << "Liczby muszą być mniejsze od 1000!";
        return 0;
    }
    cout << n + m << endl;
    return 0;
}
