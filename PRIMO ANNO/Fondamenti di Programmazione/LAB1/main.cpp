#include <iostream>
using namespace std;

int main() {
    int num1,num2;
    cout << "ES 1" << endl;
    cout << "inserisci i due numeri (il secondo numero inserito deve essere > 0): " << endl;
    cin >> num1 >> num2;

    while(num2 == 0) {
        cout << "Hai inserito 0 come secondo numero, riprova: ";
        cin >> num2;
    }
    int ris = num1 / num2;
    int resto = num1 % num2;

    cout << "ris: " << ris << endl;
    cout << "resto: " << resto << endl;

    cout << "-----------------" << endl;

    cout << "ES 2" << endl;

    float x, a, b;
    cout << "Inserisci i valori x, a e b" << endl;
    cin >> x >> a >> b;

    float y = a*x + b;

    cout << "Ris: " << y << endl;

    cout << "-----------------" << endl;

    cout << "ES 3" << endl;

    int a1,b1;

    cout << "Inserisci i valori a e b" << endl;
    cin >> a1 >> b1;

    while (a1 == 0 || b1 == 0) {
        if (a1 == 0){
            cout << "Il valore di a inserito è pari a 0, riprova: " << endl;
            cin >>  a1;
        }
        else if (b1 == 0) {
            cout << "Il valore di b inserito è pari a 0, riprova: " << endl;
            cin >>  b1;
        }
    }

    float x1 = - (float(b1) / a1);
    cout << "Ris: " << x1 << endl;
    return 0;
}
