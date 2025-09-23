#include <iostream>
using namespace std;

void raddoppia(int &a) {
    cout << "Dentro raddoppia(): Indirizzo di a: " << &a << endl;
    cout << "Dentro raddoppia(): a: " << a << endl;
    a = a * 2;
    cout << "Dentro raddoppia(): a: " << a << endl;
}

int restituisciTriplo(int *e) {
    return (*e) * 3;
}

int f_puntatori2(int *l) {
    cout << "Dentro f_puntatori2(): Valore puntatore : " << l << endl;
    cout << "Dentro f_puntatori2(): Valore oggetto puntato: " << *l << endl;
    if((*l) % 2 == 0) {
        return (*l) * (*l);
    }
    if((*l) % 3 == 0) {
        return (*l) * (*l) * (*l);
    }
    return *l;
}

void inizializzaP(int **i) {
    *i = nullptr;
}

double calcolaStatistiche(int a, int b, int c, int& minimo, int& massimo) {
    // Calcolo minimo e massimo
    minimo = a;
    if (b < minimo) minimo = b;
    if (c < minimo) minimo = c;

    massimo = a;
    if (b > massimo) massimo = b;
    if (c > massimo) massimo = c;

    // Calcolo media come double
    return (a + b + c) / 3.0;
}

bool restituisciPrimoValorePari(int a, int b, int c, int &ValorePari) {
    if(a % 2 == 0) {
        ValorePari = a;
        return true;
    }
    if(b % 2 == 0) {
        ValorePari = b;
        return true;
    }
    if(c % 2 == 0) {
        ValorePari = c;
        return true;
    }
    return false;
}

int main() {
    cout << "ES 1" << endl;
    int n;
    cout << "Numero: ";
    cin >> n;
    cout << "Indirizzo di n: " << &n << endl;
    raddoppia(n);
    cout << "Nuovo valore di n: " << n << endl;

    cout << "--------------------------------" << endl;
    cout << "ES 2" << endl;
    int f;
    cout << "Numero: ";
    cin >> f;
    int triplo  = restituisciTriplo(&f);
    cout << "Il triplo del valore inserito e': " << triplo << endl;


    cout << "--------------------------------" << endl;
    cout << "ES 3" << endl;
    int a;
    cout << "Numero: ";
    cin >> a;
    cout << "Indirizzo di n: " << &a << endl;
    int ritorno = f_puntatori2(&a);
    cout << "Il risultato e': " << ritorno << endl;

    cout << "--------------------------------" << endl;
    cout << "ES 4" << endl;
    int k;
    cin >> k;
    int *p;
    cout << "p non inizializzato: " << hex << p << endl;
    p = &k;
    cout << "p punta a k: " << hex << p << endl;
    cout <<"Valore di k: " << hex <<  k << endl;
    inizializzaP(&p);
    cout << "p inizializzato a nullptr: " << hex << p << endl;

    cout << "--------------------------------" << endl;
    cout << "ES 5" << endl;
    int x,y,z;
    cout << "Inserisci tre interi:" << endl;
    cin >> x >> y >> z;
    int minVal, maxVal;

    double media = calcolaStatistiche(x,y,z,minVal,maxVal);
    cout << "Il minimo e': " << minVal << endl;
    cout << "Il massimo e': " << maxVal << endl;
    cout << "La media e': " << media << endl;

    cout << "--------------------------------" << endl;
    cout << "ES 6" << endl;
    int r,g,h;
    cout << "Inserisci 3 interi: " << endl;
    cin >> r >> g >> h;
    int pari;
    bool ris = restituisciPrimoValorePari(r,g,h,pari);
    if(ris) {
        cout << "Il primo numero apri della sequenza e': " << pari;
    }
    else {
        cout << "Nessun numero pari presente nella sequenza inserita";
    }
    return 0;
}