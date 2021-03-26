#ifndef H__RECTANGLE__H
#define H__RECTANGLE__H

#include <string>
class Price {
public:
	Price(string productPrice, int quantity, string info);
	Price();
	~Price();
	void finalprice();
	string getPrice();

private:
	float finalPrice;
	float prdPrice;
	string price;
	string info;
	int qty;
};

#endif