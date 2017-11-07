#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    srand(time(NULL)); // Start rand.
    cout << "Bonjour.\nCeci fabrique des textures tuilables rectangulaires. " << endl;
    cout << "Une nouvelle image pour chaque fois, en remplacement." << endl;
    cout << "Internationnalisation future probable. (Je sais : anglais langue mondiale... etc...)" << endl;
    cout << "Le format est PGM (Netpbm gris ASCII : https://fr.wikipedia.org/wiki/Portable_pixmap)." << endl;
    cout << "Vous pouvez utiliser un logiciel de type GIMP pour les couleurs et la conversion. (https://www.gimp.org/)" << endl;
    // Par défaut :
    const int FULLWHITE = 256; // From 1 (included) to 65536 (included).
    if ((FULLWHITE>65536 )||(FULLWHITE<1 )){// ( Norme du fichier ).
cerr << "Erreur de fichier !";

;
    }
    int X=16; // Colonnes
    int Y=7; // Lignes // 70 caractères MAX par ligne.
    bool GTend=true; // Ne pas recommencer.
    do {
        // Début du fichier :
        int PixFin=0;
        string const nomFichier("GenTex.pgm"); // input ?
        ofstream myfile;
        myfile.open (nomFichier.c_str()); // .c_str() because not "GenTex.pgm".
        myfile << "P2\n";
        myfile << "# GenTextur\n";
        myfile << X ;
        string separator = " ";
        myfile << separator;
        myfile << Y;
        myfile << "\n";
        myfile << FULLWHITE;
        myfile << "\n";
        // Si pas de ligne de commande.
// input X (que nombre) 1 à 32k.
// input Y (que nombre) 1 à 32k.
// input nom.
        for (int i=0; i<X; i++) {
            for (int j=0; j<Y; j++) {
                // formule avec rand.
                PixFin= rand()%FULLWHITE;

                myfile << PixFin;
                if (j<Y -1) {
                    myfile << " "; // Pas en fin de ligne.
                    }
                }
            if (i<X -1) {
                myfile << "\n";  // Pas en fin de fichier.
                }
            }
        myfile.close();
        // input end?
        }
    while (!GTend);
    cout << "Au revoir." << endl;
    return 0;
    }
