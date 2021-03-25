#pragma once
#include "WeightCalculators.h"
#include "Globals.h"
#include <iostream>

WEIGHT_CALCULATORS::WEIGHT_CALCULATORS(string productNumber, int userInput_prdType, int quantity) {
	this->prdNbr = productNumber;
	this->prdType = userInput_prdType;
	this->qty = quantity;
	weight = 0;
	number_wgt = 0;
	text = "";




	// VARS FOR CALCUL
	headDiam = stod(title_headDiam);
	headHgt = stod(title_headHeight);
	diamNom = title_diamNom;
	bodyLgt = stod(title_length);
	RHO = 7.8;		// kg/m³

	separation();
	choix();
	calculBulk();
}

WEIGHT_CALCULATORS::WEIGHT_CALCULATORS() { }

WEIGHT_CALCULATORS::~WEIGHT_CALCULATORS() { }

// Returns the weight (stored as kilograms) as grams
inline double WEIGHT_CALCULATORS::getWgt() { return number_wgt * 1000; }

// If 0 remains from modulo 10 of qty, means it's not needed to round up.
// Otherwise, calculate (10 - remain) and add that to the qty so it is rounded up to nearest 10.
inline int WEIGHT_CALCULATORS::getBulk() { return (qty % 10 == 0) ? qty : (qty + (10 - (qty % 10))); }

inline void WEIGHT_CALCULATORS::separation() {
	stringstream ss(prdNbr);
	for (int j = 0; j < 2; j++) getline(ss, souschaine[j], '-');

	for (int j = 2; j < souschaine[1].length(); j++) text += souschaine[1][j];

	if (souschaine[1][1] == '0') {
		if (text[0] != '0' && text[0] != '1' && text[0] != '2')
			text[0] = '0';
	}
}

inline void WEIGHT_CALCULATORS::choix() {
	if (prdType == 6) {
		pressureScrew();
		/*pressScrew = new WEIGHT_CALCULATORS(prdNbr, qty);
		qty = pressScrew->getqty();
		number_wgt = pressScrew->getWgt();*/
	}
}

inline void WEIGHT_CALCULATORS::calculBulk() {
	VT = ((M_PI * pow(headDiam, 2)) / 4) * headHgt;
	VC = ((M_PI * pow(diamNom, 2)) / 4) * bodyLgt;
	VTOT = (VT + VC) / 1000000;

	weight = VTOT * RHO;
	if (qty) weight *= qty;
	qty = 18 / weight; // Arrondir à la dizaine
}

inline void WEIGHT_CALCULATORS::pressureScrew() {
	calculBulk();
}