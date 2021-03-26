#pragma once
#include "Globals.h"
#include "PriceCalculators.h"

PRICE_CALCULATORS::PRICE_CALCULATORS(string productPrice, int quantity, string info) {
	finalPrice = 0;
	this->prdPrice = stof(comaToDot(productPrice));
	this->info = info;
	this->qty = quantity;
	calculFinalPrice();
}

PRICE_CALCULATORS::PRICE_CALCULATORS() { }

PRICE_CALCULATORS::~PRICE_CALCULATORS() { }

string PRICE_CALCULATORS::getPrice() { return to_string(finalPrice); }

void PRICE_CALCULATORS::calculFinalPrice() { if (info == "none") finalPrice = qty * prdPrice; }