#pragma once
#include <string>
using namespace std;
int qte;

class PRIX
{
public:
	PRIX();
	void constructeur(string prixObject, char info, float bulk);
	~PRIX();
	void sizeBulk();
	void finalprice();
	string getPrice();
private:
	float prixfinal;
	float test;
	string prix;
	string prixObject;
	char info;
	int bulksize;
};


PRIX::PRIX()
{
}

inline void PRIX::constructeur(string prixObject, char info, float bulk)
{
	prixfinal = 0;
	test = stof(prixObject);
	prix = "";
	this->prixObject = prixObject;
	this->info = info;
	this->bulksize = bulk;
	sizeBulk();
	finalprice();
}

PRIX::~PRIX()
{
}

inline void PRIX::sizeBulk()
{
	if (bulksize >= 400)
		qte = 100;
	else if (bulksize < 400 && bulksize >= 200)
		qte = 50;
	else if (bulksize < 200 && bulksize >= 100)
		qte = 25;
	else if (bulksize < 100 && bulksize >= 60)
		qte = 15;
	else if (bulksize < 60 && bulksize >= 30)
		qte = 10;
	else if (bulksize < 30 && bulksize >= 10)
		qte = 5;
	else if (bulksize < 10 && bulksize >= 5)
		qte = 2;
	else
		qte = 0;
}

inline void PRIX::finalprice()
{
	if (info == 'a')
	{
		prixfinal = test * bulksize;
	}
	else if (info == 'b')
	{
		prixfinal = test * qte;
	}

	prix = to_string(prixfinal);
}

inline string PRIX::getPrice()
{
	return prix;
}