#pragma once

class PRICE_CALCULATORS {
public:
	PRICE_CALCULATORS(string productPrice, int quantity, string info);
	PRICE_CALCULATORS();
	~PRICE_CALCULATORS();
	string getPrice();

private:
	float finalPrice;
	float prdPrice;
	string info;
	int qty;

	void calculFinalPrice();
};