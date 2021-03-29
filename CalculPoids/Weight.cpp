#pragma once
#include "Globals.h"
#include "Weight.h"

WEIGHT::WEIGHT(int userInput_prdType, int quantity) {
	this->prdType = userInput_prdType;
	this->qty = quantity;
	weight = 0;

	// VARS FOR CALCUL
	headDiam = stod(global_headDiam);
	headHgt = stod(global_headHeight);
	diamNom = global_diamNom;
	bodyLgt = stod(global_length);
	RHO = 7.8;

	choix();
}

WEIGHT::WEIGHT() { }

WEIGHT::~WEIGHT() { }

// Returns the weight (stored here as kilograms) as grams
double WEIGHT::getWgt() { return weight * 1000; }

// If 0 remains from modulo 10 of qty, means it's not needed to round up.
// Otherwise, calculate (10 - remain) and add that to the qty so it is rounded up to nearest 10.
int WEIGHT::getBulk() { return (bulk % 10 == 0) ? bulk : (bulk + (10 - (bulk % 10))); }

void WEIGHT::choix() {
	if (prdType == 6)  pressureScrew();
}

void WEIGHT::pressureScrew() { calculBulk(); }

void WEIGHT::calculBulk() {
	VT = ((M_PI * pow(headDiam, 2)) / 4) * headHgt;
	VC = ((M_PI * pow(diamNom, 2)) / 4) * bodyLgt;
	VTOT = (VT + VC) / 1000000;		// Total volume of the piece

	weight = VTOT * RHO;
	if (!qty) bulk = 18 / weight;	// If not given an explicit quantity through params, calculate how many items can fit into 18kg
	else if (qty > 1) bulk = qty;

	bulk = bulk < 20 ? 10 : bulk;	// If bulk smaller than 20, make it 10

	if ((weight * bulk) > 18) { 
		bulk = (18 / weight);
		bulk -= bulk % 10;
	}
}