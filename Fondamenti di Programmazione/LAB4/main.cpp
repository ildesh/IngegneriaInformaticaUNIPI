#include <iostream>
using namespace std;

int main()
{
    // ES 1
    cout << "ES 1:" << endl;
    int n;
    cout << "Lato? ";
    cin >> n;
    while (n < 0) {
        cout << "Lato? ";
        cin >> n;
    }

    cout << "Triangolo rettangolo: " << endl;
    for(int riga = 0; riga <= n; riga++) {
        for(int colonna = 0; colonna < riga; colonna++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << "Triangolo rettangolo rovesciato: " << endl;
    for (int i = 0; i < n; i++) {
        // Spazi
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        // Asterischi
        for (int k = 0; k < n - i; k++) {
            cout << "*";
        }
        cout << endl;
    }

    // -----------------------------------------
    // ES 2
    cout << "-----------------------" << endl;
    cout << "ES 2:" << endl;

        int a;
    cout << "Inserire n dispari: ";
    cin >> a;
    while(a % 2 == 0) {
        cout << "Inserire n dispari: ";
        cin >> a;
    }

    int altezza = (a + 1) / 2; // Numero di righe

    for (int i = 0; i < altezza; i++) {
        // Spazi a sinistra
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }

        // Asterischi (decrescono di 2 ogni riga)
        for (int k = 0; k < a - 2 * i; k++) {
            cout << "* ";
        }

        cout << endl;
    }

    // -----------------------------------------
    // ES 3
    cout << "-----------------------" << endl;
    cout << "ES 3:" << endl;

    int e;
    cout << "ordine della tavola: ";
    do {
        cin >> e;
    }while(e <= 0);

    for (int i = 1; i <= e; i++) {
        for (int j = 1; j <= e; j++) {
            cout << i * j;
            if (j < e) cout << " ";
        }
        cout << endl;
    }

    // -----------------------------------------
    // ES 4
    cout << "-----------------------" << endl;
    cout << "ES 4:" << endl;
    int scelta;
    int num1, num2, num3;
    while(true) {
        cout << "Menu operazioni" << endl;
        cout << "1: minimo di tre interi" << endl << "2: massimo di tre interi" << endl << "3: media di tre interi" << endl << "0: esci" << endl << endl << "Scelta?";
        do {
            cin >> scelta;
        }while(scelta <0 || scelta >3);
        switch(scelta) {
            case 0:
                return 0;

            case 1: {
                cout << "Inserisci tre interi:" << endl;
                cin >> num1 >> num2 >> num3;
                int min = num1;
                if(num2 < min && num2 < num3) {
                    min = num2;
                }
                else if(num3 < min && num3 < num2) {
                    min = num3;
                }
                cout << "Stampo il minimo: " << min << endl;
                break;
            }
            case 2:{
                cout << "Inserisci tre interi:" << endl;
                cin >> num1 >> num2 >> num3;
                int max = num1;
                if(num2 > max && num2 > num3) {
                    max = num2;
                }
                else if(num3 > max && num3 > num2) {
                    max = num3;
                }
                cout << "Stampo il massimo: " << max << endl;
                break;
            }
            case 3:{
                cout << "Inserisci tre interi:" << endl;
                cin >> num1 >> num2 >> num3;
                float media = float(num1 + num2 + num3) / 3;
                cout << "Stampo la media: " << media << endl;
                break;
            }

            default:
                return 0;
        }
    }




    return 0;
}
