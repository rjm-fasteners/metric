#pragma once
#include "Globals.h"
#include "Weight.h"

WEIGHT_AND_BULK::WEIGHT_AND_BULK(int userInput_prdType, int quantity) {
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

WEIGHT_AND_BULK::WEIGHT_AND_BULK() { }

WEIGHT_AND_BULK::~WEIGHT_AND_BULK() { }

// Returns the weight (stored here as kilograms) as grams
double WEIGHT_AND_BULK::getWgt() { return weight * 1000; }

// If 0 remains from modulo 10 of qty, means it's not needed to round up.
// Otherwise, calculate (10 - remain) and add that to the qty so it is rounded up to nearest 10.
int WEIGHT_AND_BULK::getBulk() { return (bulk % 10 == 0) ? bulk : (bulk + (10 - (bulk % 10))); }

void WEIGHT_AND_BULK::choix() {
	if (prdType == 6) { 
		calculWeight(); 
		if (qty > 1) calculBulk();
	}
}

void WEIGHT_AND_BULK::calculWeight() {
	VT = ((M_PI * pow(headDiam, 2)) / 4) * headHgt;
	VC = ((M_PI * pow(diamNom, 2)) / 4) * bodyLgt;
	VTOT = (VT + VC) / 1000000;		// Total volume of the piece

	weight = VTOT * RHO;
}

// Automatic calcul of how many items can fit into 18kg
void WEIGHT_AND_BULK::calculBulk() {
	bulk = qty;
	if ((weight * bulk) > 18) {
		bulk = 18 / weight;
		bulk -= bulk % 10;
	}
}