#include <iostream>
using namespace std;
#include <cmath>

int main() {
    int a;
    cout << "ES 1" << endl;
    cout << "Inserisci il numero a: ";
    cin >> a;

    if (a % 2 == 0 && a % 4 != 0) {
        cout << "Multiplo di 2 ma non di 4" << endl;
    }
    else {
        cout << "Condizione non soddisfatta" << endl;
    }

    cout << "-------------------" << endl;

    cout << "ES 2" << endl;
    int x,y,z;
    int max;
    cout << "Inserisci i numeri x,y e z" << endl;
    cin >> x >> y >> z;

    max = x;

    if (y > max) {
        max = y;
    }
    else if (z > max) {
        max = z;
    }

    cout << "Il massimo e': " << max << endl;

    cout << "-------------------" << endl;

    cout << "ES 3" << endl;

    char c;
    cout << "Inserisci un carattere: ";
    cin >> c;
    if(c >= 'a' && c <= 'z') {
        cout << "Lettera minuscola" << endl;
    }
    else if (c >= 'A' && c <= 'Z') {
        cout << "Lettera maiuscola" << endl;
    }
    else if(c >= 0 && c <= 9) {
        cout << "Cifra decimale" << endl;
    }

    cout << "-------------------" << endl;

        cout << "ES 4" << endl;

        int a1,b1,c1;

        cout << "Inserisci il numero a,b,c" << endl;

        cin >> a1 >> b1 >> c1;


        if(a == 0 && b1 == 0) {
            cout << "Equazione Degenere";
            return 0;
        }
        if(a == 0) {
            while(b1 == 0) {
                cout << "Inserisci il valore di b1" << endl;
                cin >> b1;
            }
            float x = -(float(c1) / b1);
            cout << "Ris x1 = " << x << endl;
            return 0;
        }
        int discrim = (b1*b1) - 4*(a1*c1);
        if (discrim < 0) {
            cout << "Soluzioni immaginarie" << endl;
            return 0;
        }
        double x1 = (-b1 + sqrt(discrim)) / (2*a1);
        double x2 = (-b1 - sqrt(discrim)) / (2*a1);

        cout << "Ris x1 = " << x1 << endl;
        cout << "Ris x2 = " << x2 << endl;

        return 0;
    }
