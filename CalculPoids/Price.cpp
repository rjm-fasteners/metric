#pragma once
#include "Globals.h"
#include "Price.h"

PRICE::PRICE(string productPrice, int quantity, string info) {
	finalPrice = 0;
	this->prdPrice = stof(dotToComa(productPrice));
	this->info = info;
	this->qty = quantity;
	calculFinalPrice();
}

PRICE::PRICE() { }

PRICE::~PRICE() { }

string PRICE::getPrice() { return to_string(finalPrice); }

void PRICE::calculFinalPrice() { if (info == "none") finalPrice = qty * prdPrice; }