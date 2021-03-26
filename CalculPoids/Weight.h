#pragma once
#include "Globals.h"

#pragma region Calcul Poids
class WEIGHT {
public:
	WEIGHT(string productNumber, int userInput_prdType, int quantity);
	WEIGHT();
	~WEIGHT();
	double getWgt();
	int getBulk();

private:
	//PRESSURE_SCREW* pressScrew;

	double number_wgt;
	string string_wgt;
	string prdNbr;
	int prdType;
	int qty;
	int bulk;

	void choix();



	double headDiam;
	double headHgt;
	double diamNom;
	double bodyLgt;
	double weight;
	//float bulk;

	// VARS FOR CALCUL
	double RHO;
	double VT;			// Volume tête
	double VC;			// Volume corps
	double VTOT;		// Volume total

	void calculBulk();
};