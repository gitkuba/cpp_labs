#include <iostream>
#include <math.h>

using namespace std;

// 1.  Napisz program, który wczytuje ze standardowego wejścia dwie liczby
// (double) i wypisuje ich sumę jeśli obie liczby są mniejsze niż 1000.
int ex1() {
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

// 2. Napisz program, który wczytuje Twoją masę (podaną w kg) i wzrost (podany w cm) i na tej podstawie wylicza
// i wypisuje BMI (czyli m/h2 w kg/m2). Jeśli wyliczona wartość jest mniejsza niż 18.5, program powinien wypisać
// komunikat: 'BMI ponizej normy'. Jeśli wyliczona wartość jest większa niż 25, program
// powinien wypisać komunikat 'BMI powyzej normy'.
int ex2() {
    float mass,height,height_in_m,bmi,height_squared;

    cout << "Podaj masę w kg: ";
    cin >> mass;
    cout << "Podaj wzrost w cm: ";
    cin >> height;

    height_in_m = height / 100;
    height_squared = pow(height_in_m, 2);
    bmi = mass / height_squared;

    cout << "BMI: " << bmi << endl;
    if (bmi < 18.5){
        cout << "Poniżej normy";
    }
    if (bmi > 25){
        cout << "Powyżej normy";
    }
    return 0;
}

// 3. Napisz program wczytujący z klawiatury liczbę całkowitą reprezentującą rok,
// a następnie wypisujący informację o tym, czy jest to rok przestępny, czy nie.
// Wskazówka: Operator reszty z dzielenia to %.
int ex3(){
    int year;
    cout << "Podaj rok: ";
    cin >> year;

    if (year % 4 == 0){
        cout << "rok przestępny";
    } else {
        cout << "rok nieprzestępny";
    }

    return 0;
}

// 4. Napisz program, który wczyta trzy liczby typu int a następnie sprawdzi
// czy stanowią one trójkę pitagorejską, to znaczy czy suma kwadratów dwóch
// mniejszych liczb jest równa kwadratowi liczby największej. Liczby 3, 4 oraz 5
// stanowią taką trójkę. W przypadku podania trójki pitagorejskiej należy wyświetlić
// komunikat: Liczby stanowia trojke pitagorejska., w przeciwnym razie powinien być
// to komunikat: To nie jest trojka pitagorejska. Uwaga: W programie należy założyć,
// że użytkownik wpisze liczby w dowolnej kolejności, np. 5, 3, 4.
int ex4(){
    
}

int main(){
    return ex4();
}
