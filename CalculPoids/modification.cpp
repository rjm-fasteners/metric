// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include "PRIX.h"
#include "Poids.h"
#include "Threading.h"
#include "CalculPoids.h"
#include "PrdSpecsAndTitle.h"
#include "Body.h"

#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
string directoryName = "";
string startProduct = "";
string endProduct = "";

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

using namespace std;

string tag = "\"";
string photo;
string photo2;					// yet optional
string photo3;					// yet optional
string photo4;					// yet optional
int reponse;
float bulk;						// to be removed
char choix;

/*****Fonction qui change la virgule pour un point*****/
string comaToDot(std::string prix) {
	std::replace(prix.begin(), prix.end(), ',', '.');
	return prix;
}

/*****Fonction qui change le point pour une virgule*****/
string dotToComa(std::string text) {
	std::replace(text.begin(), text.end(), '.', ',');
	return text;
}

/*****Fonction qui change la virgule pour un point et convertie la string en float*****/
float toFloat(std::string prix) {
	prix = comaToDot(prix);
	return std::atof(prix.c_str());
}

string _ratio(float prix1, float dernierCoutant, int reponse) {
	string result = "";
	if (reponse == 10)
	{
		if (prix1 <= dernierCoutant * 2.2)
		{
			result = "-----Prix 1 INFERIEUR a 55%-----> ";
		}
		else if (prix1 >= dernierCoutant * 2.5)
		{
			result = "-----Prix 1 SUPERIEUR a 60%-----> ";
		}
	}
	else if (reponse == 4 || reponse == 5)
	{
		if (prix1 <= dernierCoutant * 4)
		{
			result = "-----Prix 1 INFERIEUR a 75%-----> ";
		}
		else if (prix1 >= dernierCoutant * 4.8)
		{
			result = "-----Prix 1 SUPERIEUR a 79%-----> ";
		}
	}
	else
	{
		if (prix1 <= dernierCoutant * 7.05)
		{
			result = "-----Prix 1 INFERIEUR a 86%-----> ";
		}
		else if (prix1 >= dernierCoutant * 8.8)
		{
			result = "-----Prix 1 SUPERIEUR a 88,5%-----> ";
		}

	}
	return result;
}


void ouverture(PRIX prix)
{
	if (toupper(choix) == 'D') int i = TabCategorie(100, "");
	else {
		string FILENAME = "produit.txt"; 
		fstream Product;
		Product.open(FILENAME, ios::in);

		fstream finish;
		FILENAME = "finish.txt";
		finish.open(FILENAME, ios::out | ios::trunc);
		const int nbrOfHeaders = 20;
		int m = 0;

		string TexteATranscrire1[nbrOfHeaders]{ "","","","","","Quantity","Unity","","","shopify","continue","manual","","VRAI","VRAI","","1","FAUX","lg","" }; // si on remet les bulk changer UNITY pour BULK
		string TexteATranscrire2[nbrOfHeaders]{ "","","","","","","","","","","continue","manual","","VRAI","VRAI","","","","lg","" }; //ligne 2 pour petite quantité
		string TexteATranscrire3[nbrOfHeaders]{ "","","","","","Quantity","manual","","","shopify","continue","manual","","VRAI","VRAI","","","FAUX","lg","" }; // si on remet les bulk changer UNITY pour BULK
		string TexteATranscrire4[nbrOfHeaders]{ "","","","","","","","","","","","","","","","","2","","","" }; //2e image

		string TexteATranscrire5[nbrOfHeaders]{ "","","","","","Color","White Painted Head [100 units]","","","shopify","continue","manual","","VRAI","VRAI","","3","FAUX","lg","" }; //au 100 variante couleur blanche
		string TexteATranscrire6[nbrOfHeaders]{ "","","","","","Color","White Painted Head [1000 units]","","","shopify","continue","manual","","VRAI","VRAI","","","FAUX","lg","" }; //au 1000 variante couleur blanche
		string TexteATranscrire7[nbrOfHeaders]{ "","","","","","Color","Black Painted Head [100 units]","","","shopify","continue","manual","","VRAI","VRAI","","4","FAUX","lg","" }; //au 100 variante couleur blanche
		string TexteATranscrire8[nbrOfHeaders]{ "","","","","","Color","Black Painted Head [1000 units]","","","shopify","continue","manual","","VRAI","VRAI","","","FAUX","lg","" }; //au 1000 variante couleur blanche

		if (finish.is_open())
		{

			finish << "Handle;Title;Body (HTML);Tags;Published;Option1 Name;Option1 Value;Variant SKU;Variant Grams;Variant Inventory Tracker;Variant Inventory Policy;Variant Fulfillment Service;Variant Price;Variant Requires Shipping;Variant Taxable;Image Src;Gift Card;Variant Weight Unit;Cost per item" << endl;

			if (Product.is_open())
			{
				string productname[100] = { "" };
				int cpt = 0;

				while (!Product.eof())
				{
					string produit[65];
					string produitCategorie[25];
					string calculatedRatio = "";

					if (toupper(choix) == 'A' || toupper(choix) == 'B' || toupper(choix) == 'E')
					{
						for (int i = 0; i < 60; i++)
						{
							getline(Product, produit[i], ';');
							//cout << i << " : " << produit[i] << endl;
						}
					}
					/***************Si recherche de catégorie (option C) est sélectionnée on rempli une autre variable car il n'y a pas le même nombre de valeurs***************/
					else
					{
						for (int i = 0; i < 24; i++)
						{
							getline(Product, produitCategorie[i], ';');
							//cout << i << " : " << produit[i] << endl;
						}
					}

					float prix1 = toFloat(produit[9]);
					float prix4 = toFloat(produit[39]);
					float dernierCoutant = toFloat(produit[10]);

					/*******Valide si prix à zéro******/
					if (produit[39] == "0,0000" || produit[39] == "0.0000")
					{
						cout << "-----Pas de prix pour ce produit!-----> ";
					}

					/******Validation que le ratio est de 85.75% à 86%******/
					if (prix1 < dernierCoutant * 7.05)
					{
						cout << "-----Ratio inferieur a 86%-----> ";
					}

					/*************** Valide si le prix 4 est inférieure à 50% ***************/
					if (toupper(choix) == 'A')
					{
						if (prix4 < dernierCoutant * 1.99)
						{
							cout << m << " : " << produit[0] << " Prix 4 INFERIEUR a 50%" << endl;
							m++;
						}
					}

					/***************** Validation de présence de catégorie ******************/
					else if (toupper(choix) == 'C')
					{
						int categoryFound = 0;
						categoryFound = TabCategorie(20, produitCategorie[0]);
						if (categoryFound == 1)
						{
							cout << "Categorie " << produitCategorie[0] << " est PRESENTE" << endl;
						}
						else
						{
							cout << "Categorie " << produitCategorie[0] << " MANQUANTE **********" << endl;
						}
					}

					/****************** Importation sélection B implicite *******************/
					else {
						/*if (reponse == 6)
						{
							string texte;

							texte = produit[4];

							TITRE title;
							string titre = "";
							TexteATranscrire1[0] = produit[0];
							title.constructeur(produit[0], reponse, tag);
							titre = title.getTitre();
							tag = title.getTag();


							TexteATranscrire1[5] = "Unity";
							TexteATranscrire1[6] = "1";


							TexteATranscrire1[1] = "\"" + titre + "\"";
							TexteATranscrire1[2] = body(produit[2], produit[0], reponse, tag);
							TexteATranscrire1[7] = produit[0];

							texte = dotToComa(texte);

							TexteATranscrire1[8] = texte;

							TexteATranscrire1[12] = produit[9];


							TexteATranscrire1[15] = photo;
							TexteATranscrire1[18] = produit[10];

							tag += "\"";
							TexteATranscrire1[3] = tag;


							for (int j = 0; j < 19; j++)
							{
								finish << TexteATranscrire1[j] << ";";
							}
							finish << endl;

							tag = "\"";
							photo = "";
							qte = 0;
							bulk = 0;
						}
						else */
							if (reponse == 9)
						{

							string texte;

							texte = produit[4];
							float poids = stof(texte);
							poids = poids * 50;
							stringstream ss;
							ss << poids;
							texte = ss.str();

							TITRE title;
							string titre = "";
							TexteATranscrire1[0] = produit[0];
							title.constructeur(produit[0], reponse, tag);
							titre = title.getTitre();
							tag = title.getTag();
							TexteATranscrire1[6] = "50";
							bulk = 200;
							TexteATranscrire1[1] = "\"" + titre + "\"";
							TexteATranscrire1[2] = body(produit[2], produit[0], reponse, tag);
							TexteATranscrire1[7] = produit[0];

							texte = dotToComa(texte);

							TexteATranscrire1[8] = texte;

							prix.constructeur(produit[39], 'b', bulk);

							texte = prix.getPrice();

							texte = dotToComa(texte);

							TexteATranscrire1[12] = texte;

							TexteATranscrire1[15] = photo;
							TexteATranscrire1[18] = produit[10];


							texte = produit[4];

							TexteATranscrire1[0] = produit[0];
							TexteATranscrire1[7] = produit[0];

							poids = stof(texte);

							if (poids < 1)
							{
								poids = 1;
								stringstream ss1;
								ss1 << poids;
								texte = ss1.str();
							}

							comaToDot(texte);

							TexteATranscrire1[8] = texte;

							TexteATranscrire1[12] = produit[9];
							TexteATranscrire1[18] = produit[10];


							tag += "\"";
							TexteATranscrire1[3] = tag;

							tag = "\"";
							photo = "";
							qte = 0;
							bulk = 0;
							for (int j = 0; j < 19; j++)
							{
								finish << TexteATranscrire1[j] << ";";
							}
							finish << endl;
							for (int j = 0; j < 19; j++)
							{
								finish << TexteATranscrire1[j] << ";";
							}
							finish << endl;
						}
						// LISTING PRODUCTS IF REPONSE == 10
						else if (reponse == 10)
						{
							// String variable isn't useful (creating a new string just for that wouldn't be good idea)
							TexteATranscrire1[2] = body("0", "0", 0, "0");
						}

						/* Boulon, Ecrou, Rondelle, Vis pression */
						else if (reponse == 1 || reponse == 2 || reponse == 3 || (reponse == 6 && produit[0][1] == 'P'))
						{
							calculatedRatio = _ratio(prix1, dernierCoutant, reponse);
							cout << produit[0] << calculatedRatio << endl;

							string texte = produit[4];
							CALCUL_POIDS* calcul;
							float rlg = 0;

							// Extrait les deux premiers chiffres de la deuxieme souschaine(souschaine[1]) du numéro du produit
							// Permet de connaître le diamètre nominal et agir en fonction de celui-là pour les bulk sizes
							string souschaine[3];
							stringstream ss(produit[0]);
							for (int j = 0; j < 3; j++) getline(ss, souschaine[j], '-');
							int diamNom = ((souschaine[1][0] - 48) * 10) + ((souschaine[1][1] - 48));

							// Instead of awful code repetition, making variables to make the code flexible
							// bulkA is considered as the unity option
							int bulkB = 0, bulkC = 0;

							/***** Si diamètre nominal <= M6 (moins que 1/4") */
							if (diamNom <= 6) { bulkB = 100; bulkC = 1200; }

							// M7 Vendu seulement à l'unité, c'est donc le seul pour lequel on ne fait pas les bulk B et C (prix 3 et 4)
							/***** Si diamètre nominal == M7 (1/4") */
							if (diamNom == 7) { bulkB = 0; bulkC = 0; }

							/***** Si diamètre nominal == M8 ou M9 (5/16" ou 0.354") */
							else if (diamNom == 8 || diamNom == 9) { bulkB = 100; bulkC = 1000; }

							/***** Si diamètre nominal == M10 (3/8") */
							else if (diamNom == 10) { bulkB = 100; bulkC = 500; }

							/***** Si diamètre nominal == M11 (7/16") */
							else if (diamNom == 11) { bulkB = 50; bulkC = 350; }

							/***** Si diamètre nominal == M12 (1/2") */
							else if (diamNom == 12) { bulkB = 50; bulkC = 250; }

							/***** Si diamètre nominal == M14 (9/16") */
							else if (diamNom == 14) { bulkB = 25; bulkC = 200; }

							/***** Si diamètre nominal == M16 (5/8") */
							else if (diamNom == 16) { bulkB = 25; bulkC = 150; }

							/***** Si diamètre nominal == M18 ou M20 (11/16" ou 3/4") */
							else if (diamNom == 18 || diamNom == 20) { bulkB = 25; bulkC = 100; }

							/***** Si diamètre nominal == M22 (7/8") */
							else if (diamNom == 22) { bulkB = 25; bulkC = 75; }

							/***** Si diamètre nominal >= M24 (1") */
							else if (diamNom >= 24) { bulkB = 10; bulkC = 30; }

#pragma region Prix par 1
							TITRE title;
							string titre = "";
							title.constructeur(produit[0], reponse, tag);
							titre = title.getTitre();
							tag = title.getTag();

							TexteATranscrire1[1] = "\"" + titre + "[Bulk Size: " + to_string(bulkC) + "]\"";
							TexteATranscrire1[2] = body(produit[2], produit[0], reponse, tag);

							calcul = new CALCUL_POIDS(produit[0], 'a', reponse, rlg, 1);
							texte = calcul->getPoids();

							TexteATranscrire1[0] = produit[0];
							TexteATranscrire1[7] = produit[0];

							texte = dotToComa(texte);

							TexteATranscrire1[8] = texte;

							TexteATranscrire1[12] = produit[9]; // prix 1
							TexteATranscrire1[19] = produit[10];
							TexteATranscrire1[16] = "";
#pragma endregion

							if (bulkB != 0 && bulkC != 0) {
#pragma region Prix par bulkB
								calcul = new CALCUL_POIDS(produit[0], 'b', reponse, rlg, bulkB);
								texte = calcul->getPoids();

								TexteATranscrire2[0] = produit[0];
								TexteATranscrire2[6] = to_string(bulkB);
								TexteATranscrire2[7] = produit[0];

								texte = dotToComa(texte);

								TexteATranscrire2[8] = texte;

								prix.constructeur(produit[29], 'b', bulkB); //prix 3
								texte = prix.getPrice();
								texte = dotToComa(texte);

								TexteATranscrire2[12] = texte;
								TexteATranscrire2[18] = produit[10];
#pragma endregion

#pragma region Prix par bulkC
								calcul = new CALCUL_POIDS(produit[0], 'b', reponse, rlg, bulkC);
								texte = calcul->getPoids();

								TexteATranscrire3[0] = produit[0];
								TexteATranscrire3[6] = "Bulk [" + to_string(bulkC) + "]";
								TexteATranscrire3[7] = produit[0];

								texte = dotToComa(texte);

								TexteATranscrire3[8] = texte;

								prix.constructeur(produit[39], 'b', bulkC); //prix 4
								texte = prix.getPrice();
								texte = dotToComa(texte);

								TexteATranscrire3[12] = texte;
								TexteATranscrire3[16] = "1";
								TexteATranscrire3[15] = photo;
								TexteATranscrire3[18] = produit[10];
#pragma endregion
							}

							tag += "\"";
							TexteATranscrire1[3] = tag;

							tag = "\"";
							photo = "";
							qte = 0;

							for (int j = 0; j < nbrOfHeaders; j++) finish << TexteATranscrire1[j] << ";";
							finish << endl;
							
							for (int j = 0; j < nbrOfHeaders; j++) finish << TexteATranscrire2[j] << ";";
							finish << endl;
							
							for (int j = 0; j < nbrOfHeaders; j++) finish << TexteATranscrire3[j] << ";";
							finish << endl;
							
							if (TexteATranscrire4[15] != "") {
								for (int j = 0; j < nbrOfHeaders; j++) finish << TexteATranscrire4[j] << ";";
							}
							finish << endl;
						}

						else {
							string texte;
							CALCUL_POIDS* calcul;
							float rlg = 0;
							if (produit[0][0] == 'R' && produit[0][1] == 'L' && produit[0][2] == 'G') {
								rlg = produit[0][4] + produit[0][5];
								//rlg = stof(produit[0]);
							}
							calcul = new CALCUL_POIDS(produit[0], bulk, 'c', reponse, rlg);
							bulk = calcul->getBulk();
							texte = calcul->getPoids();

							TITRE title;
							string titre = "";
							TexteATranscrire1[0] = produit[0];
							title.constructeur(produit[0], reponse, tag);
							titre = title.getTitre();
							tag = title.getTag();

							TexteATranscrire1[1] = "\"" + titre + "\"";
							TexteATranscrire1[2] = body(produit[2], produit[0], reponse, tag);
							TexteATranscrire1[7] = produit[0];

							texte = dotToComa(texte);

							TexteATranscrire1[8] = texte;

							prix.constructeur(produit[39], 'c', bulk);

							texte = prix.getPrice();
							texte = dotToComa(texte);

							TexteATranscrire1[12] = texte;

							TexteATranscrire1[15] = photo;
							TexteATranscrire1[18] = produit[10];

							/*****Petite quantité, 2e section de prix et quantité****/
							//calcul = new CALCUL_POIDS(produit[0], bulk, 'b', reponse,rlg);
							//bulk = calcul.getBulk();
							//texte = calcul->getPoids();

							//TexteATranscrire2[0] = produit[0];
							//TexteATranscrire2[6] = to_string(qte);
							//TexteATranscrire2[7] = produit[0];

							//for (int i = 0; i < texte.length(); i++)
							//{
							//	if (texte[i] == '.')
							//	{
							//		texte[i] = ',';
							//	}
							//}
							//TexteATranscrire2[8] = texte;

							//prix.constructeur(produit[29], 'b', bulk);
							//texte = prix.getPrice();
							//for (int i = 0; i < texte.length(); i++)
							//{
							//	if (texte[i] == '.')
							//	{
							//		texte[i] = ',';
							//	}
							//}
							//TexteATranscrire2[12] = texte;
							//TexteATranscrire2[18] = produit[10];



							/***** Ancienne qte unitaire *****
							calcul = new CALCUL_POIDS(produit[0], bulk, 'c', reponse,rlg);
							bulk = calcul.getBulk();
							texte = calcul->getPoids();

							TexteATranscrire3[0] = produit[0];
							TexteATranscrire3[7] = produit[0];

							for (int i = 0; i < texte.length(); i++)
							{
								if (texte[i] == '.')
								{
									texte[i] = ',';
								}
							}
							TexteATranscrire3[8] = texte;

							TexteATranscrire3[12] = produit[9];
							TexteATranscrire3[18] = produit[10];*/


							tag += "\"";
							TexteATranscrire1[3] = tag;

							tag = "\"";
							photo = "";
							qte = 0;
							bulk = 0;

							if (produit[0][0] == 'E' && produit[0][1] == 'A' || ((produit[0][0] == 'T') && (produit[0][1] == 'I')))
							{
								TexteATranscrire1[5] = "Unity";
								TexteATranscrire1[6] = "1";
								TexteATranscrire1[12] = produit[9];

								//TexteATranscrire1[8] = TexteATranscrire3[8];

								for (int j = 0; j < 19; j++)
								{
									finish << TexteATranscrire1[j] << ";";
								}
								finish << endl;
							}
							else
							{
								for (int j = 0; j < 19; j++)
								{
									finish << TexteATranscrire1[j] << ";";
								}
								finish << endl;
								for (int j = 0; j < 19; j++)
								{
									//	finish << TexteATranscrire2[j] << ";";
								}
								finish << endl;
								for (int j = 0; j < 19; j++)
								{
									//	finish << TexteATranscrire3[j] << ";";
								}
								finish << endl;
							}
						}

						productname[cpt] = produit[0];
						cpt++;
					}

				}

				/* TRIAGE TECH DRAWS */
				if (toupper(choix) == 'E') {
					/* Le triage va supprimer les fichiers .step pour lesquels aucun produit n'existe */
					#pragma region Triage pour les dessins techniques
						string filename[5000] = { "" };
						string filenameFormatted[5000] = { "" };

						cpt = 0;
						try
						{
							for (auto& p : fs::directory_iterator(directoryName)) {
								filename[cpt] = p.path().string();
								filenameFormatted[cpt] = p.path().string();
								filenameFormatted[cpt].erase(0, filenameFormatted[cpt].find("\\") + 1);
								filenameFormatted[cpt].erase(filenameFormatted[cpt].find("."));
								cpt++;
							}
						}
						catch (const std::exception&) { }

						/*
						int a = 0;
						while(a < filenameFormatted->size()){
							if (startProduct != filenameFormatted[a])
								filenameFormatted[a] = "";
							else
								break;
							a++;
						}
						while (a < filenameFormatted->size()) {
							if (endProduct == filenameFormatted[a])
								break;
							a++;
						}
						while (a < filenameFormatted->size()) {
							filenameFormatted[a] = "";
							a++;
						}*/

						int filesCount = cpt;

					#pragma region Lowering all characters
						/* Lowering product names */
						for (std::string& s : productname)
							for (char& c : s)
								c = std::tolower(static_cast<unsigned char>(c));

						/* Lowering file names */
						for (std::string& s : filenameFormatted)
							for (char& c : s)
								c = std::tolower(static_cast<unsigned char>(c));
					#pragma endregion

						cout << endl;
						bool found = false;
						cpt = 0;
						int missingCount = 0;
						for (string prd : productname) {
							if (!prd.empty()) {
								found = false;
								for (string flnm : filenameFormatted) {
									if (flnm == prd)
										found = true;
								}
								if (!found) {
									cout << "Missing files for " << prd << endl;
									missingCount++;
								}
								cpt++;
							}
						}

						int productsCount = cpt;

						found = false;
						cpt = 0;
						int deletedCount = 0;
						for (string flnm : filenameFormatted) {
							if (!flnm.empty()) {
								found = false;
								for (string prd : productname) {
									if (flnm == prd)
										found = true;
								}
								if (!found) {
									remove(filename[cpt].c_str());
									deletedCount++;
								}
								cpt++;
							}
						}

						double fpp = (filesCount - deletedCount);
						fpp /= (productsCount - missingCount);
						cout << endl << "|----------------------------------SORTING REPORT----------------------------------|";
						cout << endl << "There were a total of " << filesCount << " files.";
						cout << endl << deletedCount << " files were deleted because they didn't match any product." << endl;
						cout << endl << "There are " << productsCount << " products.";
						cout << endl << "There are " << missingCount << " products that don't have a file (see detail above)." << endl;
						cout << endl << "Matched a total of " << productsCount - missingCount << " products." << endl;
						cout << endl << "Summary : " << productsCount - missingCount << " products for " << filesCount - deletedCount << " files. " << fpp << " files per products (FPP)." << endl;
						cout << endl << "! " << "If FPP is not an integer, a product must be missing one of it's " << ceil(fpp) << " files." << " !" << endl;
						cout << "|----------------------------------------------------------------------------------|" << endl;
					}

					cout << endl;
					#pragma endregion
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier product." << endl;
			}

		}
		else
		{
			cout << "ERREUR: Impossible d'ouvrir le fichier finish." << endl;
		}

		Product.close();
		finish.close();
	}
};

void devAccel() {
	// Choix de l'action
	choix = 'B';

	// Choix du produit
	reponse = 6;
}

int main()
{
	cout << "Faites un choix... " << endl << endl;

	/* Activate only to accelerate development */
	bool dev = true;

	if (dev) {
		devAccel();
	}
	else {
		do {
			cout << "A) Calcul de ratio inferieur a 50% \nB) Importation \nC) Validation de categorie \nD) Listing des categories \nE) Importation et triage des dessins techniques \nChoix : ";
			cin >> choix;
			cout << endl;
		} while (toupper(choix) != 'A' && toupper(choix) != 'B' && toupper(choix) != 'C' && toupper(choix) != 'D' && toupper(choix) != 'E');

		if (toupper(choix) == 'B' || toupper(choix) == 'E') {
			do {
				cout << "	1 - Boulon \n	2 - Ecrou \n	3 - Rondelle \n	4 - Equerre(NOT WORKING) \n	5 - Tige \n	6 - Vis \n	22 - Liste des produits	\n";
				cin >> reponse;
			} while (reponse < 1 || (reponse > 6 && reponse != 22));
		}

		/// TODO NEED TO COMPLETE THE PATH
		if (toupper(choix) == 'E')
		{
			cout << "** FACULTATIF | BETA **" << endl;
			cout << "Veuillez entrer le nom du dossier contenant les dessins techniques a trier : ";
			cin >> directoryName;
		}

		/// TODO NEED TO COMPLETE THE PATH (reponse=100 isnt used anywhere else...)
		if (toupper(choix) == 'D') reponse = 100;
	}


	PRIX prix;

	cout << endl << "En cours ..." << endl << endl;
	ouverture(prix);


	cout << "Fin" << endl;
}

