#pragma once

#pragma region Calcul Poids
class CALCUL_POIDS {
public:
	CALCUL_POIDS(string productNumber, int userInput_prdType, int quantity);
	CALCUL_POIDS();
	~CALCUL_POIDS();
	string getPoids();

private:
	BOULON boulon;
	ECROU ecrou;
	WASHER washer;
	PressureScrew* pressScrew;

	double number_wgt;
	string string_wgt;
	string prdNbr;
	float bulk, poidsProduit;
	int prdType;
	int qty;

	void choix();
};

CALCUL_POIDS::CALCUL_POIDS(string productNumber, int userInput_prdType, int quantity) {
	this->prdNbr = productNumber;
	this->prdType = userInput_prdType;
	this->qty = quantity;

	number_wgt = 0;

	choix();
}

CALCUL_POIDS::CALCUL_POIDS() { }

CALCUL_POIDS::~CALCUL_POIDS() { }

inline string CALCUL_POIDS::getPoids() { return string_wgt; }

inline void CALCUL_POIDS::choix() {
	if (prdType == 1 || prdType == 5) {
		boulon.constructeur(prdNbr, bulk);
		bulk = boulon.getbulk();
		number_wgt = boulon.getpoid();
	}
	else if (prdType == 2) {
		ecrou.constructeur(prdNbr, bulk);
		bulk = ecrou.getbulk();
		number_wgt = ecrou.getpoid();
	}
	else if (prdType == 3) {
		//washer.constructeur(numproduit, bulk, rlg);
		bulk = washer.getbulk();
		number_wgt = washer.getpoid();
	}
	else if (prdType == 4) number_wgt = 0;
	else if (prdType == 6) {
		pressScrew = new PressureScrew(prdNbr, bulk);
		bulk = pressScrew->getBulk();
		number_wgt = pressScrew->getPoids();
	}
}
#pragma endregion