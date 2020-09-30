// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include "PRIX.h"
#include "Poids.h"
#include "Threading.h"
#include "CalculPoids.h"
#include "Title.h"
#include "Body.h"


using namespace std;

string tag = "\"";
string photo;
string photo2;					// yet optional
string photo3;					// yet optional
string photo4;					// yet optional
int reponse;
float bulk;						// to be removed
int Met_Int;
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

string ratio(float prix1, float dernierCoutant, int reponse) {
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
			while (!Product.eof())
			{
				string produit[65];
				string calculatedRatio = "";


				for (int i = 0; i < 60; i++)
				{
					getline(Product, produit[i], ';');
					//cout << i << " : " << produit[i] << endl;
				}

				float prix1 = toFloat(produit[9]);
				float prix4 = toFloat(produit[39]);
				float dernierCoutant = toFloat(produit[10]);

				/*******Valide si prix à zéro******/
				if (produit[39] == "0,0000" || produit[39] == "0.0000")
				{
					cout << "-----Pas de prix pour ce produit!-----> ";
				}

				if (choix == 'A' || choix == 'a')
				{
					if (prix4 < dernierCoutant * 1.99)
					{
						cout << m << " : " << produit[0] << " Prix 4 INFERIEUR a 50%" << endl;
						m++;
					}
				}

				/******Validation que le ratio est de 85.75% à 86%******/

				float prix1 = toFloat(produit[9]);
				float dernierCoutant = toFloat(produit[10]);

				if (prix1 < dernierCoutant * 7.05)
				{
					cout << "-----Ratio inferieur a 86%-----> ";
				}

				cout << 0 << " : " << produit[0] << endl;

				if (reponse == 7)
				{
					string texte;

					texte = produit[4];

					TITRE title;
					string titre = "";
					TexteATranscrire1[0] = produit[0];
					title.constructeur(produit[0], bulk, reponse, tag);
					titre = title.getTitre();
					tag = title.getTag();


					TexteATranscrire1[5] = "Unity";
					TexteATranscrire1[6] = "1";


					TexteATranscrire1[1] = "\"" + titre + "\"";
					TexteATranscrire1[2] = body(produit[2], produit[0], reponse, tag, Met_Int);
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
				else if (reponse == 9)
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
					title.constructeur(produit[0], bulk, reponse, tag);
					titre = title.getTitre();
					tag = title.getTag();
					TexteATranscrire1[6] = "50";
					bulk = 200;
					TexteATranscrire1[1] = "\"" + titre + "\"";
					TexteATranscrire1[2] = body(produit[2], produit[0], reponse, tag, Met_Int);
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
				else
				{
					string texte;
					CALCUL_POIDS calcul;
					float rlg = 0;
					if (produit[0][0] == 'R' && produit[0][1] == 'L' && produit[0][2] == 'G') {
						rlg = produit[0][4] + produit[0][5];
						//rlg = stof(produit[0]);
					}
					calcul.constructeur(produit[0], bulk, 'c', reponse, rlg);
					bulk = calcul.getBulk();
					texte = calcul.getPoids();

					TITRE title;
					string titre = "";
					TexteATranscrire1[0] = produit[0];
					title.constructeur(produit[0], bulk, reponse, tag);
					titre = title.getTitre();
					tag = title.getTag();

					TexteATranscrire1[1] = "\"" + titre + "\"";
					TexteATranscrire1[2] = body(produit[2], produit[0], reponse, tag, Met_Int);
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
					//calcul.constructeur(produit[0], bulk, 'b', reponse,rlg);
					//bulk = calcul.getBulk();
					//texte = calcul.getPoids();

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
					calcul.constructeur(produit[0], bulk, 'c', reponse,rlg);
					bulk = calcul.getBulk();
					texte = calcul.getPoids();

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
			}
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
};

int main()
{
	cout << "Debut : " << endl;
	cout << "	1 - Boulon \n	2 - Ecrou \n	3 - Rondelle \n	4 - Equerre \n	5 - Tige Filte \n	6 - Vis \n	7 - Autre \n	8 - Ancrage \n	9 - Goupille \n";
	cin >> reponse;
	PRIX prix;

	cout << "	1 - Metric \n	2 - Inch \n";
	cin >> Met_Int;

	cout << endl << "En cours ..." << endl << endl;
	ouverture(prix);


	cout << "Fin";
}