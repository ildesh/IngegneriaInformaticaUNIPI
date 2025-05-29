#include <iostream>
using namespace std;
const int N = 3;

int somma_diag(const int mat[][3]) {
    int somma = 0;
    for(int i = 0; i < N; i++) {
            somma = somma + mat[i][i];
            if (i != N - 1 - i) {
                somma = somma + mat[i][N-1-i];
            }
    }
    return somma;
}

void componenti_negative(const int* vett, int n, int*& negativi, int& n_negativi) {
    n_negativi = 0;
    for (int i = 0; i < n; ++i) {
        if (vett[i] < 0)
            ++n_negativi;
    }

    negativi = new int[n_negativi];

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (vett[i] < 0)
            negativi[j++] = vett[i];
    }
}

int* crea_serpente(int r, int c) {
    int* matrice = new int[r*c];
    int valore = 1;

    for(int i = 0; i < r; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < c; j++) {
                matrice[i * c + j] = valore++;
            }
        }
        else {
            // Riga dispari: da destra a sinistra
            for (int j = c - 1; j >= 0; j--) {
                matrice[i * c + j] = valore++;
            }
        }
    }
    return matrice;
}

int** trasposta(const int* matr, int n) {
    // Matrice statica per i valori trasposti
    static int tr[N][N];

    // Array statico di puntatori a riga
    static int* righe[N];

    // Inizializza i puntatori a riga
    for (int i = 0; i < n; i++) {
        righe[i] = tr[i];
    }

    // Esegue la trasposizione
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tr[j][i] = matr[i * n + j];
        }
    }

    return righe;
}

void multMatVect(const int mat[3][3],const int vett[3], int vettRis[3]) {
    for(int i = 0; i < 3; i++) {
        vettRis[i] = 0;
        for (int j = 0; j < 3; j++) {
            vettRis[i] += mat[i][j] * vett[j];
        }
    }

}

int main() {
    cout << "ES 1" << endl;
    int mat[N][N];
    cout << "Inserisci 9 interi" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
    int somma = somma_diag(mat);
    cout << "La somma degli elementi sulla diagonale princ. e sec. e': " << somma << endl;

    cout << "---------------------" << endl;
    cout << "ES 2" << endl;
    int vett[] = {11, -22, 4, -3, 18, -1};
    int n = sizeof(vett) / sizeof(vett[0]);
    cout << "Vettore di partenza (con componenti sia positive che negative):" << endl;
    for(int i = 0; i < n; i++) {
        cout <<  vett[i] << " ";
    }
    cout << endl;
    int* negativi = nullptr;
    int n_negativi = 0;
    componenti_negative(vett,n,negativi,n_negativi);
    cout << "Ecco il nuovo vettore (solo componenti negative):" << endl;
    for(int i = 0; i < n_negativi; i++) {
        cout << negativi[i] << " ";
    }
    cout << endl;
    delete[] negativi;
    cout << "Ora che non mi serve piu', posso deallocarlo dallo Heap" << endl;

    cout << "---------------------" << endl;
    cout << "ES 3" << endl;
    int r,c;
    cout << "Inserisci N: ";
    cin >> r;
    cout << "Inserisci M: ";
    cin >> c;

    int *ris = crea_serpente(r,c);

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << ris[i * c + j] << "\t";
        }
        cout << endl;
    }
    delete[] ris;


    cout << "---------------------" << endl;
    cout << "ES 4" << endl;
    int matr[N][N] ;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << "Elemento [ " << i << " ]" << "[ " << j << " ]: ";
            cin >> matr[i][j];
        }
    }
    cout << "Matrice di partenza: " << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }

    int **risultato = trasposta(*matr, N);
    cout << endl;
    cout << "Matrice trasposta: " << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << risultato[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "---------------------" << endl;
    cout << "ES 5" << endl;
    int matrice[3][3];
    int vettore[3];
    cout << "Inserisci i 9 elementi della matrice: " << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> matrice[i][j];
        }
    }

    cout << "Inserisci i 3 della colonna vettore: " << endl;
    for(int i = 0; i < 3; i++) {
        cin >> vettore[i];
        cout << endl;
    }

    int risMolt[3];

    multMatVect(matrice,vettore,risMolt);

    for(int i = 0; i < 3; i++) {
        cout << risMolt[i] << " ";
        cout << endl;
    }

    return 0;
}
