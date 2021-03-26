#pragma once

#pragma region Calcul Poids
class CALCUL_POIDS {
public:
	CALCUL_POIDS(string productNumber, int userInput_prdType, int quantity);
	CALCUL_POIDS();
	~CALCUL_POIDS();
	double getWgt();
	int getBulk();

private:
	BOULON boulon;
	ECROU ecrou;
	WASHER washer;
	//PRESSURE_SCREW* pressScrew;

	double number_wgt;
	string string_wgt;
	string prdNbr;
	int prdType;
	int qty;
	int bulk;

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

inline double CALCUL_POIDS::getWgt() { return number_wgt; }

// If 0 remains from modulo 10 of bulk, means it's not needed to round up.
// Otherwise, calculate (10 - remain) and add that to the bulk so it is rounded up to nearest 10.
inline int CALCUL_POIDS::getBulk() { return (bulk % 10 == 0) ? bulk : (bulk + (10 - (bulk % 10))); }

inline void CALCUL_POIDS::choix() {
	if (prdType == 1 || prdType == 5) {
		boulon.constructeur(prdNbr, qty);
		qty = boulon.getbulk();
		number_wgt = boulon.getpoid();
	}
	else if (prdType == 2) {
		ecrou.constructeur(prdNbr, qty);
		qty = ecrou.getbulk();
		number_wgt = ecrou.getpoid();
	}
	else if (prdType == 3) {
		//washer.constructeur(numproduit, bulk, rlg);
		qty = washer.getbulk();
		number_wgt = washer.getpoid();
	}
	else if (prdType == 4) number_wgt = 0;
	else if (prdType == 6) {
		//pressScrew = new PRESSURE_SCREW(prdNbr, qty);
		//bulk = pressScrew->getBulk();
		//number_wgt = pressScrew->getWgt();
	}
}
#pragma endregion