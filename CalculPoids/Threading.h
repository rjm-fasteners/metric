#pragma once
#include "Globals.h"

KeyValuesInterface threads[100] = {
	{"01", { {"c", "0.25"},	{"f", "0.2"},	{"e", "X"},		{"eff", "X"} } },
	{"012",{ {"c", "0.25"}, {"f", "0.2"},	{"e", "X"},		{"eff", "X"} } },
	{"014",{ {"c", "0.3"},	{"f", "0.2"},	{"e", "X"},		{"eff", "X"} } },
	{"016",{ {"c", "0.35"}, {"f", "0.2"},	{"e", "X"},		{"eff", "X"} } },
	{"017",{ {"c", "0.35"}, {"f", "0.2"},	{"e", "X"},		{"eff", "X"} } },
	{"018",{ {"c", "0.35"}, {"f", "0.2"},	{"e", "X"},		{"eff", "X"} } },
	{"02", { {"c", "0.4"},	{"f", "0.25"},	{"e", "X"},		{"eff", "X"} } },
	{"022",{ {"c", "0.45"}, {"f", "0.25"},	{"e", "X"},		{"eff", "X"} } },
	{"023",{ {"c", "0.4"},	{"f", "X"},		{"e", "X"},		{"eff", "X"} } },
	{"025",{ {"c", "0.45"}, {"f", "0.35"},	{"e", "X"},		{"eff", "X"} } },
	{"026",{ {"c", "0.45"}, {"f", "X"},		{"e", "X"},		{"eff", "X"} } },
	{"03", { {"c", "0.5"},	{"f", "0.35"},	{"e", "X"},		{"eff", "X"} } },
	{"035",{ {"c", "0.6"},	{"f", "0.35"},	{"e", "X"},		{"eff", "X"} } },
	{"04", { {"c", "0.7"},	{"f", "0.5"},	{"e", "X"},		{"eff", "X"} } },
	{"05", { {"c", "0.8"},	{"f", "0.5"},	{"e", "X"},		{"eff", "X"} } },
	{"06", { {"c", "1.0"},	{"f", "0.75"},	{"e", "X"},		{"eff", "X"} } },
	{"07", { {"c", "1.0"},	{"f", "0.75"},	{"e", "X"},		{"eff", "X"} } },
	{"08", { {"c", "1.25"}, {"f", "1"},		{"e", "0.75"},	{"eff", "X"} } },
	{"09", { {"c", "1.25"}, {"f", "1"},		{"e", "0.75"},	{"eff", "X"} } },
	{"10", { {"c", "1.5"},	{"f", "1.25"},	{"e", "1"},		{"eff", "0.75"} } },
	{"11", { {"c", "1.5"},	{"f", "1"},		{"e", "0.75"},	{"eff", "X"} } },
	{"12", { {"c", "1.75"}, {"f", "1.5"},	{"e", "1.25"},	{"eff", "1"} } },
	{"14", { {"c", "2"},	{"f", "1.5"},	{"e", "1.25"},	{"eff", "1"} } },
	{"16", { {"c", "2"},	{"f", "1.5"},	{"e", "1"},		{"eff", "X"} } },
	{"18", { {"c", "2.5"},	{"f", "2"},		{"e", "1.5"},	{"eff", "1"} } },
	{"20", { {"c", "2.5"},	{"f", "2"},		{"e", "1.5"},	{"eff", "1"} } },
	{"22", { {"c", "2.5"},	{"f", "2"},		{"e", "1.5"},	{"eff", "1"} } },
	{"24", { {"c", "3"},	{"f", "2"},		{"e", "1.5"},	{"eff", "1"} } },
	{"27", { {"c", "3"},	{"f", "2"},		{"e", "1.5"},	{"eff", "1"} } },
	{"30", { {"c", "3.5"},	{"f", "2"},		{"e", "1.5"},	{"eff", "X"} } },
	{"33", { {"c", "3.5"},	{"f", "3"},		{"e", "2"},		{"eff", "1.5"} } },
	{"36", { {"c", "4"},	{"f", "3"},		{"e", "2"},		{"eff", "1.5"} } },
	{"39", { {"c", "4"},	{"f", "3"},		{"e", "2"},		{"eff", "1.5"} } },
	{"42", { {"c", "4.5"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"45", { {"c", "4.5"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"48", { {"c", "5"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"X",  { {"c", "5"},	{"f", "4"},		{"e", "3"},		{"eff", "X"} } },
	{"56", { {"c", "5.5"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"60", { {"c", "5.5"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"64", { {"c", "6"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"68", { {"c", "6"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"72", { {"c", "6"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"76", { {"c", "6"},	{"f", "X"},		{"e", "X"},		{"eff", "X"} } },
	{"80", { {"c", "6"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"90", { {"c", "6"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
	{"100",{ {"c", "6"},	{"f", "4"},		{"e", "3"},		{"eff", "2"} } },
};

#pragma region COARSE THREAD
class THREADING {
public:
	THREADING(char threadType);
	THREADING();
	~THREADING();
	string getTags();
	string getThread();

private:
	string texte;
	string souschaine[2];
	string tags;
	string thrdTitle;
	string numProduit;
	string thrdType;

	void threading();

};

THREADING::THREADING() { }

THREADING::THREADING(char threadType) {
	thrdType = threadType;
	thrdTitle = "";
	threading();
}

THREADING::~THREADING() { }

inline string THREADING::getTags() { return tags; }

inline string THREADING::getThread() { return thrdTitle; }

inline void THREADING::threading() {
	if (global_splittedPrdNbr[1][0] == '0' && (global_splittedPrdNbr[1][1] == '1' || global_splittedPrdNbr[1][1] == '2' || global_splittedPrdNbr[1][1] == '3' || global_splittedPrdNbr[1][1] == '4')) {
		texte = global_splittedPrdNbr[1][0];
		texte += global_splittedPrdNbr[1][1];
		texte += global_splittedPrdNbr[1][2];
	}
	else {
		texte = global_splittedPrdNbr[1][0];
		texte += global_splittedPrdNbr[1][1];
	}

	tags = "metric_";

	if (thrdType == "c") {
		title_thrdType = "UNC | Coarse";
		tags += "coarse,";
	}
	else if (thrdType == "f") {
		title_thrdType = "UNF | Fine";
		tags += "fine,";
	}
	else if (thrdType == "e") {
		title_thrdType = "UNEF | Extra-fine";
		tags += "extra-fine,";
	}

	for (KeyValuesInterface k_v : threads) {
		if (k_v.key == texte) {
			string formatted = !texte.front() ? (texte[1] + "." + texte[2]) : texte;	// Converts 0xy to x.y (any other stay as they are) (example: M012 to M1.2)
			thrdTitle = "M" + formatted + " * " + k_v.values[thrdType] + " ";

			tags += "thread_size_m" + formatted + "_" + k_v.values[thrdType] + ",";
			break;
		}
	}
}
#pragma endregion


#pragma region FINE THREAD
class FINE_THREAD
{
public:
	FINE_THREAD();
	~FINE_THREAD();
	void constructeur(string numProduit);
	string getTags();
	string getThread();
private:
	string texte;
	string souschaine[2];
	string tags;
	void separation();
	string numProduit;
	int i;
	bool trouver;


	string TabThreadTitreF[100]
	{
		"M1 * 0.2 ","M1.2 * 0.2 ","M1.4 * 0.2 ","M1.6 * 0.2 ","M1.8 * 0.2 ",
		"M2 * 0.25 ","M2.2 * 0.25 ","M2.5 * 0.35 ","M3 * 0.35 ","M3.5 * 0.35 ","M4 * 0.5 ",
		"M5 * 0.5 ","M6 * 0.75 ","M7 * 0.75 ","M8 * 1 ", "M9 * 1 ","M10 * 1.25 ","M11 * 1 ",
		"M12 * 1.5 ", "M14 * 1.5 ", "M16 * 1.5 ", "M18 * 2 ","M20 * 2 ", "M22 * 2 ", "M24 * 2 ",
		"M27 * 2 ", "M30 * 2 ","M33 * 3 ", "M36 * 3 ", "M39 * 3 ", "M42 * 4 ", "M45 * 4 ",
		"M48 * 4 ", "M52 * 4 ", "M56 * 4 ", "M60 * 4 ", "M64 * 4 ","M68 * 4 ", "M72 * 4 ",
		"M80 * 4 ", "M90 * 4 ","M100 * 4 ",
	};


	string TabTagThreadF[100]
	{
		"thread_size_m1_0-2,", "thread_size_m1-2_0-2,", "thread_size_m1-4_0-2,", "thread_size_m1-6_0-2,", "thread_size_m1-8_0-2,",
		"thread_size_m2_0-25,", "thread_size_m2-2_0-25,", "thread_size_m2-5_0-35,", "thread_size_m3_0-35,", "thread_size_m3-5_0-35,", "thread_size_m4_0-5,",
		"thread_size_m5_0-5,", "thread_size_m6_0-75,", "thread_size_m7_0-75,", "thread_size_m8_1,", "thread_size_m9_1,", "thread_size_m10_1-25,", "thread_size_m11_1,",
		"thread_size_m12_1-5,", "thread_size_m14_1-5,", "thread_size_m16_1-5,", "thread_size_m18_2,", "thread_size_m20_2,", "thread_size_m22_2,", "thread_size_m24_2,",
		"thread_size_m27_2,", "thread_size_m30_2,", "thread_size_m33_3,", "thread_size_m36_3,", "thread_size_m39_3,", "thread_size_m42_4,", "thread_size_m45_4,",
		"thread_size_m48_4,", "thread_size_m52_4,", "thread_size_m56_4,", "thread_size_m60_4,", "thread_size_m64_4,", "thread_size_m68_4,", "thread_size_m72_4,",
		"thread_size_m80_4,", "thread_size_m90_4,", "thread_size_m100_4,",
	};

	void threading();

};

FINE_THREAD::FINE_THREAD()
{
}

FINE_THREAD::~FINE_THREAD()
{
}

inline void FINE_THREAD::constructeur(string numProduit)
{
	this->numProduit = numProduit;
	i = 0;
	trouver = false;
	tags = "metric_fine,";
	separation();
	threading();
}

inline string FINE_THREAD::getTags()
{
	return tags;
}

inline string FINE_THREAD::getThread()
{
	return TabThreadTitreF[i];
}

inline void FINE_THREAD::separation()
{
	stringstream ss(numProduit);

	for (int j = 0; j < 2; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void FINE_THREAD::threading()
{
	if (souschaine[1][0] == '0' && souschaine[1][1] == '0')
	{
		texte += souschaine[1][0];
		texte += souschaine[1][1];
		texte += souschaine[1][2];
	}
	else
	{
		texte += souschaine[1][0];
		texte += souschaine[1][1];
	}
	tags += TabTagThreadF[i];
}
#pragma endregion

#pragma region EXTRA FINE THREAD
class EXTRA_FINE_THREAD
{
public:
	EXTRA_FINE_THREAD();
	~EXTRA_FINE_THREAD();
	void constructeur(string numProduit);
	string getTags();
	string getThread();
private:
	string texte;
	string souschaine[2];
	string tags;
	void separation();
	string numProduit;
	int i;
	bool trouver;

	string TabThread[100]
	{

		"08","09","10","11",
		"12","14","16","18","20","22","24",
		"27","30","33","36","39","42" "45",
		"48","52","56","60","64","68","72",
		"80","90","100",

	};

	string TabThreadTitreFF[100]
	{

		"M8 * 0.75 ", "M9 * 0.75 ", "M10 * 1 ", "M11 * 0.75 ",
		"M12 * 1.25 ", "M14 * 1.25 ", "M16 * 1 ", "M18 * 1.5 ", "M20 * 1.5 ", "M22 * 1.5 ", "M24 * 1.5 ",
		"M27 * 1.5 ", "M30 * 1.5 ", "M33 * 2 ", "M36 * 2 ", "M39 * 2 ","M42 * 3 ", "M45 * 3 ", 
		"M48 * 3 ", "M52 * 3 ", "M56 * 3 ","M60 * 3 ", "M64 * 3 ", "M68 * 3 ", "M72 * 3 ",
		"M80 * 3 ", "M90 * 3 ", "M100 * 3 ",
		

	};


	string TabTagThreadFF[100]
	{

		"thread_size_m8_0-75,", "thread_size_m9_0-75,", "thread_size_m10_1,", "thread_size_m11_0-75,",
		"thread_size_m12_1-25,", "thread_size_m14_1-25,", "thread_size_m16_1,", "thread_size_m18_1-5,", "thread_size_m20_1-5,", "thread_size_m22_1-5,", "thread_size_m24_1-5,",
		"thread_size_m27_1-5,", "thread_size_m30_1-5,", "thread_size_m33_2,", "thread_size_m36_2,", "thread_size_m39_2,", "thread_size_m42_3,", "thread_size_m45_3,",
		"thread_size_m48_3,", "thread_size_m52_3,", "thread_size_m56_3,", "thread_size_m60_3,", "thread_size_m64_3,", "thread_size_m68_3,", "thread_size_m72_3,",
		"thread_size_m80_3,", "thread_size_m90_3,", "thread_size_m100_3,",
		

	};

	void threading();

};

EXTRA_FINE_THREAD::EXTRA_FINE_THREAD()
{
}

EXTRA_FINE_THREAD::~EXTRA_FINE_THREAD()
{
}

inline void EXTRA_FINE_THREAD::constructeur(string numProduit)
{
	this->numProduit = numProduit;
	i = 0;
	trouver = false;
	tags = "metric_extra_fine,";
	separation();
	threading();
}

inline string EXTRA_FINE_THREAD::getTags()
{
	return tags;
}

inline string EXTRA_FINE_THREAD::getThread()
{
	return TabThreadTitreFF[i];
}

inline void EXTRA_FINE_THREAD::separation()
{
	stringstream ss(numProduit);

	for (int j = 0; j < 2; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void EXTRA_FINE_THREAD::threading()
{
	if (souschaine[1][0] == '0' && souschaine[1][1] == '0')
	{
		texte += souschaine[1][0];
		texte += souschaine[1][1];
		texte += souschaine[1][2];
	}
	else
	{
		texte += souschaine[1][0];
		texte += souschaine[1][1];
	}
	while (trouver == false)
	{
		if (texte == TabThread[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	tags += TabTagThreadFF[i];
}
#pragma endregion

#pragma region EXTRA EXTRA FINE THREAD
class EXTRA_EXTRA_FINE_THREAD
{
public:
	EXTRA_EXTRA_FINE_THREAD();
	~EXTRA_EXTRA_FINE_THREAD();
	void constructeur(string numProduit);
	string getTags();
	string getThread();
private:
	string texte;
	string souschaine[2];
	string tags;
	void separation();
	string numProduit;
	int i;
	bool trouver;

	string TabThread[100]
	{

		"10",
		"12","14","18","20","22","24", 
		"27","33","36","39","42","45",
		"48","56","60","64","68","72",
		"80","90","100",

	};

	string TabThreadTitreEFF[100]
	{

		"M10 * 0.75 ", 
		"M12 * 1 ", "M14 * 1 ", "M18 * 1 ", "M20 * 1 ", "M22 * 1 ", "M24 * 1 ", 
		"M27 * 1 ", "M33 * 1.5 ", "M36 * 1.5 ", "M39 * 1.5 ", "M42 * 2 ", "M45 * 2 ", 
		"M48 * 2 ", "M56 * 2 ","M60 * 2 ", "M64 * 2 ", "M68 * 2 ", "M72 * 2 ", 
		"M80 * 2 ", "M90 * 2 ", "M100 * 2 ", 

	};


	string TabTagThreadEFF[100]
	{

		"thread_size_m10_0-75,",
		"thread_size_m12_1,", "thread_size_m14_1,", "thread_size_m18_1,", "thread_size_m20_1,", "thread_size_m22_1,", "thread_size_m24_1,",
		"thread_size_m27_1,", "thread_size_m33_1-5,", "thread_size_m36_1-5,", "thread_size_m39_1-5,", "thread_size_m42_2,", "thread_size_m45_2,",
		"thread_size_m48_2,", "thread_size_m52_2,", "thread_size_m56_2,", "thread_size_m60_2,", "thread_size_m64_2,", "thread_size_m68_2,", "thread_size_m72_2,",
		"thread_size_m80_2,", "thread_size_m90_2,", "thread_size_m100_2,",

	};

	void threading();

};

EXTRA_EXTRA_FINE_THREAD::EXTRA_EXTRA_FINE_THREAD()
{
}

EXTRA_EXTRA_FINE_THREAD::~EXTRA_EXTRA_FINE_THREAD()
{
}

inline void EXTRA_EXTRA_FINE_THREAD::constructeur(string numProduit)
{
	this->numProduit = numProduit;
	i = 0;
	trouver = false;
	tags = "metric_extra_extra_fine,";
	separation();
	threading();
}

inline string EXTRA_EXTRA_FINE_THREAD::getTags()
{
	return tags;
}

inline string EXTRA_EXTRA_FINE_THREAD::getThread()
{
	return TabThreadTitreEFF[i];
}

inline void EXTRA_EXTRA_FINE_THREAD::separation()
{
	stringstream ss(numProduit);

	for (int j = 0; j < 2; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void EXTRA_EXTRA_FINE_THREAD::threading()
{
	if (souschaine[1][0] == '0' && souschaine[1][1] == '0')
	{
		texte += souschaine[1][0];
		texte += souschaine[1][1];
		texte += souschaine[1][2];
	}
	else
	{
		texte += souschaine[1][0];
		texte += souschaine[1][1];
	}
	while (trouver == false)
	{
		if (texte == TabThread[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	tags += TabTagThreadEFF[i];
}
#pragma endregion

