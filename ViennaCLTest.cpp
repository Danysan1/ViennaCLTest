#include "ViennaCLTest.h"

#include <iostream> // std::cin, std::cout
#include <vector> // std::vector
using namespace std;

// http://viennacl.sourceforge.net/doc/manual-operations.html
// http://viennacl.sourceforge.net/doc/manual-algorithms.html#manual-algorithms-eigenvalues
#include <viennacl/linalg/norm_2.hpp>
#include <viennacl/linalg/inner_prod.hpp>
#include <viennacl/linalg/prod.hpp>
#include <viennacl/linalg/direct_solve.hpp>
#include <viennacl/linalg/eig.hpp>
#include <viennacl/linalg/lu.hpp>
using namespace viennacl::linalg;

viennacl::vector<float> leggiVettore(unsigned dimensione){
    // Prepara la dimensione
    while(dimensione == 0){
        cout << "Dimensione vettore? ";
        cin >> dimensione;
    }
    cout << "Creazione vettore di dimensione " << dimensione << endl;

    // Leggi i valori (per la CPU)
    vector<float> vec(dimensione);
    for(unsigned i=0; i<dimensione; i++){
        cout << i << "? ";
        cin >> vec[i];
    }

    // Copia i valori (per la GPU)
    viennacl::vector<float> cl_vec(dimensione);
    viennacl::copy(vec, cl_vec);

    cout << "Vettore: " << cl_vec << endl;
    return cl_vec;
}

viennacl::matrix<float> leggiMatrice(unsigned righe, unsigned colonne){
    // Prepara la dimensione
    if(righe == 0){
        cout << "Numero di righe della matrice? ";
        cin >> righe;
    }
    while(colonne == 0){
        cout << "Numero di colonne della matrice? ";
        cin >> colonne;
    }
    cout << "Creazione matrice " << righe << "x" << colonne << endl;

    // Leggi i valori (per la CPU)
    vector<vector<float> > mat(righe);
    for(unsigned i=0; i<righe; i++){
        mat[i] = vector<float>(colonne);
        for(unsigned j=0; j<colonne; j++){
            cout << i << "," << j << "? ";
            cin >> mat[i][j];
        }
    }

    // Copia i valori (per la GPU)
    viennacl::matrix<float> cl_mat(righe, colonne);
    viennacl::copy(mat, cl_mat);

    cout << "Matrice: " << cl_mat << endl;
    return cl_mat;
}

viennacl::matrix<float> identita(unsigned ordine){
    // Prepara la dimensione
    while(ordine == 0){
        cout << "Ordine matrice? ";
        cin >> ordine;
    }

    // Prepara la matrice (per la CPU)
    vector<vector<float> > mat(ordine);
    for(unsigned i=0; i<ordine; i++){
        mat[i] = vector<float>(ordine);
        for(unsigned j=0; j<ordine; j++){
            mat[i][j] = (i==j);
        }
    }

    // Copia i valori (per la GPU)
    viennacl::matrix<float> cl_mat(ordine, ordine);
    viennacl::copy(mat, cl_mat);
    return cl_mat;
}

void modulo(){
    viennacl::vector<float> vec = leggiVettore(0);

    viennacl::scalar<float> ris = norm_2(vec);
    viennacl::backend::finish();

    cout << "Modulo: " << ris << endl;
}

void prodottoScalare(){
    viennacl::vector<float> vec1 = leggiVettore(0),
            vec2 = leggiVettore(vec1.size());

    viennacl::scalar<float> ris = inner_prod(vec1, vec2);
    viennacl::backend::finish();

    cout << "Prodotto scalare: " << ris << endl;
}

void prodottoMatriceVettore(){
    viennacl::matrix<float> mat = leggiMatrice(0,0);
    viennacl::vector<float> vec = leggiVettore(mat.size2());

    viennacl::vector<float> ris = prod(mat, vec);
    viennacl::backend::finish();

    cout << "Prodotto matrice*vettore: " << ris << endl;
}

void prodottoMatriceMatrice(){
    viennacl::matrix<float> mat1 = leggiMatrice(0,0),
            mat2 = leggiMatrice(mat1.size2(), 0);

    viennacl::matrix<float> ris = prod(mat1, mat2);
    viennacl::backend::finish();

    cout << "Prodotto matriciale: " << ris << endl;
}

void sistemaLineare(){
    viennacl::matrix<float> mat = leggiMatrice(0,0);
    viennacl::vector<float> vec = leggiVettore(mat.size1());

    viennacl::vector<float> ris = solve(mat, vec, upper_tag());
    viennacl::backend::finish();

    cout << "Soluzione: " << ris << endl;
}

// https://sourceforge.net/p/viennacl/mailman/message/35357381/
void inversa(){
    float n;
    cout << "Ordine della matrice? ";
    cin >> n;

    viennacl::matrix<float> mat1 = leggiMatrice(n,n),
            mat2 = identita(n);

    lu_factorize(mat1);
    lu_substitute(mat1, mat2);
    viennacl::backend::finish();

    cout << "Inversa: " << mat2 << endl;
}

void autovettori(){

}
