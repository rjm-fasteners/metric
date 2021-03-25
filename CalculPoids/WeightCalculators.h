#ifndef H__WEIGHT_CALCULATORS__H
#define H__WEIGHT_CALCULATORS__H
#include "Globals.h"

# define M_PI 3.14159265358979323846		/* Pi */

class WEIGHT_CALCULATORS {
public:
	WEIGHT_CALCULATORS(string productNumber, int userInput_prdType, int quantity);
	WEIGHT_CALCULATORS();
	~WEIGHT_CALCULATORS();
	double getWgt();
	int getBulk();

private:
	string souschaine[2];
	string text;
	string prdNbr;
	double headDiam;
	double headHgt;
	double diamNom;
	double bodyLgt;
	double weight;



	double number_wgt;
	string string_wgt;
	int prdType;
	int qty;




	// VARS FOR CALCUL
	double RHO;
	double VT;			// Volume tête
	double VC;			// Volume corps
	double VTOT;		// Volume total

	int bulk;

	void choix();
	void separation();
	void calculBulk();



	void pressureScrew();





	string title_headHeight;
	string title_length;
};

#endif