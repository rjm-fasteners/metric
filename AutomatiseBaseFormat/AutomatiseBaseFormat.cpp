// AutomatiseBaseFormat.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
using namespace std;
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    string deleteline;
    string line;

    ifstream read;
    read.open("Format de base.csv");
    fstream temp;
    temp.open("temp.csv");

    if (read.is_open()) {
        std::string line;
        while (getline(read, line)) {
            if ((!line.find("Vis Mauricie inc.;;;;;;;;;;") || !line.find(";;;;;;;;;;") || !line.find("Analyse de l’inventaire") || !line.find("Imprim") || !line.find("N° produit;;") || !line.find(";;;;;;7 – Prix Quantité;0;;0,0000;") || !line.find(";;;;;;;;Page")))
                temp << "";
            else if (!line.empty())
                temp << line;
            cout << line << endl;
        }
        if (read.eof())
        {
            read.seekg(EOF);
            temp.unget();
            //char a = temp.seekp(temp.end);

        }
    }
    else {
        std::cerr << "Error: coudn't open file\n";
        /* additional handle */
    }
    read.close();
    temp.close();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
