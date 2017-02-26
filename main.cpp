#include <iostream>
#include "ViennaCLTest.h"

using namespace std;

int main(int argc, char *argv[])
{
    char buffer = 0;
    while((cout << "Comando? (L:lista comandi,  EOF:esci) ") && (cin >> buffer)){
        cout << endl;

        switch(buffer){
        case 'L':
        case 'l':
            cout << "M: Modulo" << endl
                 << "P: Prodotto scalare" << endl
                 << "Q: Prodotto matrice vettore" << endl
                 << "R: Prodotto matrice matrice" << endl
                 << "S: Sistema lineare" << endl
                 << "I: Inversa" << endl
                 << "A: Autovettori" << endl;
            break;

        case 'M':
        case 'm':
            modulo();
            break;

        case 'P':
        case 'p':
            prodottoScalare();
            break;

        case 'Q':
        case 'q':
            prodottoMatriceVettore();
            break;

        case 'R':
        case 'r':
            prodottoMatriceMatrice();
            break;

        case 'S':
        case 's':
            sistemaLineare();
            break;

        case 'I':
        case 'i':
            inversa();
            break;

        case 'A':
        case 'a':
            autovettori();
            break;

        case 'X':
        case 'x':
            stressTest();
            break;

        default:
            cout << "Comando sconosciuto: " << buffer << endl;
            break;
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}
