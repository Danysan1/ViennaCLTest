#include <cstdio>
#include <cctype>
#include "ViennaCLTest.h"

using namespace std;

int main(int argc, char *argv[])
{
    char buffer = 0;
    while(1){
        printf("Comando? (L:lista comandi,  EOF:esci) ");

        do {
            buffer = getchar();
        } while (isspace(buffer));

        switch(buffer){
        case 'L':
        case 'l':
            puts("M: Modulo");
            puts("P: Prodotto scalare");
            puts("Q: Prodotto matrice vettore");
            puts("R: Prodotto matrice matrice");
            puts("S: Sistema lineare");
            puts("I: Inversa");
            puts("A: Autovettori");
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
        case'a':
            autovettori();
            break;

        case EOF:
            putchar('\n');
            return 0;

        default:
            puts("Comando sconosciuto");
            break;
        }

        putchar('\n');
    }
}
