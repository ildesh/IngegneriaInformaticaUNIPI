#include <iostream>
using namespace std;

int main() {
    cout << "ES 1" << endl;

    int n;
    cout << "Inserisci un intero positivo: ";
    cin >> n;
    while(n <= 0) {
        cout << "Errore! L'intero non e' positivo!" << endl;
        cin >> n;
    }
    cout << "L'intero positivo inserito e': " << n << endl;

    cout << "-----------------------------" << endl;
    cout << "ES 2" << endl;

    int a;
    int numPos = 0;
    float somma = 0;
    cout << "Inserisci dieci interi: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << "Intero no. " << i << endl;
        cin >> a;
        if(a > 0) {
            somma += a;
            numPos++;
        }
    }
    float media = (somma / numPos);
    cout << "Media positivi:  " << media << endl;
    cout << "----------------------------" << endl;
    cout << "ES 3" << endl;

    int numAst;
    cout << "Base quadrato: " << endl;
    cin >> numAst;
    cout << "Stampo quadrato di base " << numAst << endl;
    for(int i = 0; i < numAst; i++) {
        for(int j = 0; j < numAst; j++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Stampo quadrato vuoto di base " << numAst << endl;

    for (int i = 0; i < numAst; i++) {
        for(int j = 0; j < numAst; j++ ) {
            if(i != 0 && i != numAst - 1 && j != 0 && j != numAst - 1) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << endl;
    }

    cout << "---------------------------" << endl;
    cout << "ES 4" << endl;

    /* Una bitmask (maschera di bit) è semplicemente un numero binario che usi per
       accendere, spegnere o controllare specifici bit in un altro numero usando
       operazioni bit a bit.
    Le operazioni più comuni:
        - & (AND): puoi azzerare dei bit.
        - | (OR): puoi accendere dei bit.
        - ^ (XOR): puoi invertire dei bit.
        - ~ (NOT): puoi invertire tutti i bit.
*/

    unsigned int e;
    cout << "Inserisci un numero n (posizione del bit): ";
    cin >> e;

    // Genera la maschera M1 ( maschera a 16 bit (peso dell'unsigned short int)
    // in cui viene posizionato nella poszione n il valore 1)
    unsigned short int M1 = 1 << e;
    cout << "Maschera M1 in base 10: " << M1 << endl;
    cout << "Maschera M1 in base 16: " << hex << M1 << dec << endl;

    // Genera la maschera M2 ( l'opposto di M1)
    unsigned short int M2 = ~M1;
    cout << "Maschera M2 in base 10: " << M2 << endl;
    cout << "Maschera M2 in base 16: " << hex << M2 << dec << endl; // HEX per convertirlo in esadecimale

    cout << "----------------------------" << endl;
    cout << "ES 5" << endl;

    unsigned int p; // peso 32 bit
    cout << "Inserisci un numero senza segno: ";
    cin >> p;
    for(int i = 31; i >= 0; i--) {
        if(p & (1 << i)) {
            cout << "1";
        }
        else {
            cout << "0";
        }

        if (i % 4 == 0) cout << " "; // metto lo spazio ogni 4 bit per leggere
                                     //  meglio il numero convertito
    }
    cout << endl;

    cout << "---------------------------" << endl;
    cout << "ES 6" << endl;

    int q;
    int ris = 1;
    cout << "Inserisci un numero: ";
    cin >> q;
    while(q < 0) {
        cout << "Errore! L'intero non e' positivo!";
        cin >> q;
    }
    for(int i = 1; i <= q; i++) {
        ris = ris * i; // moltiplica a ogni passo
    }

    cout << "Il fattoriale di " << q << "e' " << ris;
    return 0;
}
