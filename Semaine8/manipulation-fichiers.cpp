#include <stdexcept>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "manipulation-fichiers.h"

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** affiche les notes contenues dans un fichier après les avoir
 *  multipliées par deux.
 *  Format: chaque ligne doit être de la forme "<nom> <note>"
 *  @param nomFichier le nom du fichier
 **/
void afficheNotes(string nomFichier) {
    ifstream fluxFichier;
    fluxFichier.open(nomFichier);
    string nom;
    int noteSur10;
    while ( fluxFichier >> nom and fluxFichier >> noteSur10) {
        cout << nom << " " << 2 * noteSur10 << endl;
    }
    fluxFichier.close();
}

void mystere(string nomFichier) {
    ifstream fichier;
    fichier.open(nomFichier);
    string t;
    int n;
    while ( fichier >> t and fichier >> n ) {
        cout << t << " " << 2 * n << endl;
    }
    fichier.close();
}
/** compte le nombre de caractères d'un fichier
 *  @param nomFichier le nom du fichier
 *  @return le nombre de caractères contenus dans le fichier
 */
int mystereEpais(string zut) {
    ifstream bla;
    bla.open(zut);
    int foo = 0;
    char y;
    while ( bla >> y ) {
        foo++;
    }
    bla.close();
    return foo;
}

float moyenne(string nomFichier) {
    ifstream varFichier;
    varFichier.open(nomFichier);
    string temp;
    int note;
    int somme = 0;
    int nb = 0;
    while ( varFichier >> temp and varFichier >> note ) {
        somme = somme + note;
        nb = nb + 1;
    }
    varFichier.close();
    return somme / nb;
}

vector<int> lit_notes(string nomFichier) {
    ifstream fichier;
    fichier.open(nomFichier);
    vector<int> notes;
    string temp;
    int note;
    while ( fichier >> temp and fichier >> note ) {
        notes.push_back(note);
    }
    fichier.close();
    return notes;
}

int word_count(string nomFichier) {
    ifstream fichier;
    fichier.open(nomFichier);
    int nbr = 0;
    string temp;
    while ( fichier >> temp ) {
        nbr = nbr + 1;
    }
    fichier.close();
    return nbr;
}

int line_count(string nomFichier) {
    ifstream fichier;
    fichier.open(nomFichier);
    string ligne;
    int compteur = 0;
    while ( getline(fichier, ligne) ) {
        compteur = compteur + 1;
    }
    fichier.close();
    return compteur;
}

void cat(string nomFichier) {
    ifstream fichier;
    fichier.open(nomFichier);
    string ligne;
    while ( getline(fichier,ligne) ) {
        cout << ligne << endl;
    }
    fichier.close();
}

void copy(string source, string destination) {
    ifstream fichierS;
    fichierS.open(source);
    ofstream fichierD;
    fichierD.open(destination);
    string ligne;
    while ( getline(fichierS, ligne) ) {
        fichierD << ligne << endl;
    }
    fichierS.close();
    fichierD.close();
}

int main() {
    cout << "-- cat fichier-test --" << endl;
    cat("truc.txt");

    cout << "-- mystere --" << endl;
    mystere("truc.txt");

    cout << "-- Tests --" << endl;
    ASSERT( mystereEpais("truc.txt") == 65 );
    ASSERT( moyenne("truc.txt") == 3 );
    ASSERT( lit_notes("truc.txt") == vector<int>( {4,2,3,2,1,5,5,4,4,5} ) );
    ASSERT( word_count("truc.txt") == 20 );
    ASSERT( line_count("truc.txt") == 10 );

    cout << "-- copy --" << endl;
    copy("truc.txt", "truc-copy.txt");
    cout << "-- cat truc-copy --" << endl;
    cat("truc-copy.txt");

    cout << "-- afficheNotes ---" << endl ;
    afficheNotes("truc.txt");
    return 0;
}
