#pragma once

#pragma region Calcul Poids
class CALCUL_POIDS
{
public:
	CALCUL_POIDS();
	~CALCUL_POIDS();
	void constructeur(string numproduit, float bulk, char type, int reponse, float rlg);
	string getPoids();
	float getBulk();

private:
	BOULON boulon;
	ECROU ecrou;
	WASHER washer;
	double poid;
	string poids;
	string numproduit;
	float bulk, poidsProduit;
	char type;
	int reponse;
	float rlg;

	void choix();
};

CALCUL_POIDS::CALCUL_POIDS()
{
}

CALCUL_POIDS::~CALCUL_POIDS()
{
}

inline void CALCUL_POIDS::constructeur(string numproduit, float bulk, char type, int reponse, float rlg)
{
	this->numproduit = numproduit;
	this->bulk = bulk;
	this->type = type;
	this->reponse = reponse;
	this->poidsProduit = poidsProduit;
	this->rlg = rlg;

	poid = 0;

	choix();
}

inline string CALCUL_POIDS::getPoids()
{
	return poids;
}

inline float CALCUL_POIDS::getBulk()
{
	return bulk;
}

inline void CALCUL_POIDS::choix()
{
	switch (reponse)
	{
	case 1:
		boulon.constructeur(numproduit, bulk);
		bulk = boulon.getbulk();
		poid = boulon.getpoid();
		switch (type)
		{
		case 'a':
			poid = poid * bulk;
			poids = to_string(poid);
			break;
		case 'b':
			poid = poid * qte;
			poids = to_string(poid);
			break;
		case 'c':
			poids = to_string(poid);
			break;
		}
		break;

	case 2:
		ecrou.constructeur(numproduit, bulk);
		bulk = ecrou.getbulk();
		poid = ecrou.getpoid();
		switch (type)
		{
		case 'a':
			poid = poid * bulk;
			poids = to_string(poid);
			break;
		case 'b':
			poid = poid * qte;
			poids = to_string(poid);
			break;
		case 'c':
			poids = to_string(poid);
			break;
		}
		break;

	case 3:
		washer.constructeur(numproduit, bulk, rlg);
		bulk = washer.getbulk();
		poid = washer.getpoid();
		switch (type)
		{
			case 'a':
				poid = poid * bulk;
				poids = to_string(poid);
				break;
			case 'b':
				poid = poid * qte;
				poids = to_string(poid);
				break;
			case 'c':
				poids = to_string(poid);
				break;
		}
		break;

	case 4:
		poid = 0;
		switch (type)
		{
		case 'a':
			poid = poid * bulk;
			poids = to_string(poid);
			break;
		case 'b':
			poid = poid * qte;
			poids = to_string(poid);
			break;
		case 'c':
			poids = to_string(poid);
			break;
		}
		break;

	case 5:
		boulon.constructeur(numproduit, bulk);
		bulk = boulon.getbulk();
		poid = boulon.getpoid();
		switch (type)
		{
		case 'a':
			poid = poid * bulk;
			poids = to_string(poid);
			break;
		case 'b':
			poid = poid * qte;
			poids = to_string(poid);
			break;
		case 'c':
			poids = to_string(poid);
			break;
		}
		break;

	case 6:
		boulon.constructeur(numproduit, bulk);
		bulk = boulon.getbulk();
		poid = boulon.getpoid();
		switch (type)
		{
		case 'a':
			poid = poid * bulk;
			poids = to_string(poid);
			break;
		case 'b':
			poid = poid * qte;
			poids = to_string(poid);
			break;
		case 'c':
			poids = to_string(poid);
			break;
		}
		break;

	case 7:
		break;
	case 8:
		boulon.constructeur(numproduit, bulk);
		bulk = boulon.getbulk();
		poid = boulon.getpoid();
		switch (type)
		{
		case 'a':
			poid = poid * bulk;
			poids = to_string(poid);
			break;
		case 'b':
			poid = poid * qte;
			poids = to_string(poid);
			break;
		case 'c':
			poids = to_string(poid);
			break;
		}
		break;

	};
}
#pragma endregion