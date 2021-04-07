#pragma once

class PRICE {
public:
	PRICE(string productPrice, int quantity, string info);
	PRICE();
	~PRICE();
	string getPrice();

private:
	float finalPrice;
	float prdPrice;
	string info;
	int qty;

	void calculFinalPrice();
};