#include <iostream>
using namespace std;

const int N_INTERI = 10;
const int N_INTERI2 = 6;

bool pari(int* vett) {
  int somma = 0;
  for(int i = 0; i < N_INTERI; i++) {
    somma += vett[i];
  }
  if(somma % 2 == 0) {
    return true;
  }
  return false;
}

void concatena(const int* v1, const int* v2, int n1, int n2, int* v3) {
  int grandezza_vett = n1 + n2;

  for(int i = 0; i < grandezza_vett; i++) {
    if(i < n1) {
      v3[i] = v1[i];
    }
    else {
      v3[i] = v2[i - n1];
    }
  }
}

void ruotaVettore(int* vettore, int passi, int* nuovoVett) {
  for(int i = 0; i < N_INTERI2; i++) {
    nuovoVett[(i + passi) % N_INTERI2] = vettore[i];
  }
}

bool palindroma(const char* array, int grandezzaArray) {
  for (int i = 0; i < grandezzaArray / 2; i++) {
    if(array[i] != array[grandezzaArray - 1 - i]) {
      return false;
    }
  }
  return true;
}

const char* my_strchr(const char* str, char carattere) {
  while(*str != '\0') {
    if(*str == carattere) {
      return str;
    }
    str++;
  }
  return nullptr;
}

int contaParole(const char* str) {
  int contatore = 0;
  bool inParola = false;

  while(*str != '\0') {
    if(*str != ' ' && !inParola) {
      inParola = true;
      contatore++;
    }
    else if(*str == ' ') {
      inParola = false;
    }
    str++;
  }
  return contatore;
}

int main() {
  int vettore1[N_INTERI];

  cout << "ES 1" << endl;
  cout << "Inserisci 10 elementi dell'array: " << endl;

  for (int i = 0; i < N_INTERI; i++) {
    cout << "Elemento [ " << i + 1 << " ]: ";
    cin >> vettore1[i];
  }
  bool risultato = pari(vettore1);

  if (risultato) {
    cout << "La somma degli interi inseriti e' PARI" << endl;
  }
  else {
    cout << "La somma degli interi inseriti e' DISPARI" << endl;
  }

  cout << "-------------------------" << endl;
  cout << "ES 2" << endl;

  int grandezza2 = 2, grandezza3 = 3;
  int vettore2[grandezza2] = {2, 6};
  int vettore3[grandezza3] = {3, 15, 4};
  int vettore_ris[grandezza2 + grandezza3];

  concatena(vettore2,vettore3,grandezza2,grandezza3,vettore_ris);
  cout << "v3: ";
  for(int i = 0; i < grandezza2 + grandezza3; i++) {
    cout << vettore_ris[i] << " ";
  }
  cout << endl;

  cout << "-------------------------" << endl;
  cout << "ES 3" << endl;

  int vettore4[N_INTERI2];
  cout << "Inserire gli elementi del vettore: " << endl;
  for(int i = 0; i < N_INTERI2; i++) {
    cin >> vettore4[i];
  }
  int k;
  cout << "Inserire un numero di passi di rotazione: ";
  cin >> k;
  int vettNuovo[N_INTERI2];
  ruotaVettore(vettore4, k, vettNuovo);

  for(int i = 0; i < N_INTERI2; i++) {
   cout << vettNuovo[i] << " ";
  }
  cout << endl;

  cout << "-------------------------" << endl;
  cout << "ES 4" << endl;

  int grandezza = 0;
  char array[40];
  cout << "Inserisci una parola: ";
  cin >> array;
  while(array[grandezza] != '\0') {
    grandezza++;
  }

  if(palindroma(array,grandezza)) {
    cout << "La parola e' PALINDROMA" << endl;
  }
  else {
    cout << "La parola NON e' PALINDROMA" << endl;
  }

  cout << "-------------------------" << endl;
  cout << "ES 5" << endl;

  const char* str = "Fondamenti di Programmazione";
  char carattereRicercato = 'd';

  const char* ritorno = my_strchr(str,carattereRicercato);

  cout << "C-stringa: \"" << str << "\"\n";
  cout << "Carattere: '" << carattereRicercato << "'\n";

  if(ritorno != nullptr){
    cout << "Il carattere si trova in posizione: " << ritorno - str << endl;
  }
  else {
    cout << "Il carattere non e' stato trovato " << endl;
  }

  cout << "-------------------------" << endl;
  cout << "ES 6" << endl;
  const char *Cstringa1 = "Lorem ipsum dolor     sit amet";
  const char *Cstringa2 = "    Lorem ipsum   dolor    sit amet    ";
  int paroleContate1 = contaParole(Cstringa1);
  int paroleContate2 = contaParole(Cstringa2);

  cout << "Numero di parole della prima C-stringa: " << paroleContate1 << endl;
  cout << "Numero di parole della seconda C-stringa: " << paroleContate2 << endl;
  return 0;
}


