#pragma once
using namespace std;

class PRIX {
public:
	PRIX(string productPrice, int quantity, string info);
	PRIX();
	~PRIX();
	void finalprice();
	string getPrice();

private:
	float finalPrice;
	float prdPrice;
	string info;
	int qty;
};


inline PRIX::PRIX(string productPrice, int quantity, string info) {
	finalPrice = 0;
	this->prdPrice = stof(comaToDot(productPrice));
	this->info = info;
	this->qty = quantity;
	finalprice();
}

inline PRIX::PRIX() { }

inline PRIX::~PRIX() { }

inline string PRIX::getPrice() { return to_string(finalPrice); }

inline void PRIX::finalprice() { if (info == "none") finalPrice = qty * prdPrice; }