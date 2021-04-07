#pragma once

class WEIGHT_AND_BULK {
public:
	WEIGHT_AND_BULK(int userInput_prdType, int quantity);
	WEIGHT_AND_BULK();
	~WEIGHT_AND_BULK();
	double getWgt();
	int getBulk();

private:
	double headDiam;
	double headHgt;
	double diamNom;
	double bodyLgt;
	double weight;
	int prdType;
	int qty;
	int bulk;

	// VARS FOR CALCUL
	double RHO;			// Densit� acier (kg/m�)
	double VT;			// Volume t�te
	double VC;			// Volume corps
	double VTOT;		// Volume total

	void choix();
	void calculWeight();
	void calculBulk();
};