#pragma once

class WEIGHT {
public:
	WEIGHT(int userInput_prdType, int quantity);
	WEIGHT();
	~WEIGHT();
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
	double RHO;			// Densité acier (kg/m³)
	double VT;			// Volume tête
	double VC;			// Volume corps
	double VTOT;		// Volume total

	void choix();
	void calculBulk();
	void pressureScrew();
};