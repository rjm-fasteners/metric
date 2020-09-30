#pragma once

#pragma region COARSE THREAD
class COARSE_THREAD
{
public:
	COARSE_THREAD();
	~COARSE_THREAD();
	void constructeur(string numProduit, string tag);
	string getTag();
	string getThread();
private:
	string texte;
	string souschaine[2];
	string tag;
	void separation();
	string numProduit;
	int i;
	bool trouver;

	string TabThread[100]
	{

		"01","012","014","016","017","018",
		"02","022","023","025","026","03","035","04",
		"05","06","07","08","09","10","11",
		"12","14","16","18","20","22","24",
		"27","30","33","36","39","42" "45",
		"48","52","56","60","64","68","72",
		"76","80","90","100",
		

		/*		imperial
				"001","002", "003","004","005",
				"006","007","008","009","01",
				"02","03","04","05","06","07",
				"08","09","10","11","12",
				"13","15","20"*/
	};

	string TabThreadTitreC[100]
	{

		"M1 * 0.25 ","M1.2 * 0.25 ","M1.4 * 0.3 ","M1.6 * 0.35 ","M1.7 * 0.35 ","M1.8 * 0.35 ",
		"M2 * 0.4 ","M2.2 * 0.45 ","M2.3 * 0.4 ","M2.5 * 0.45 ","M2.6 * 0.45 ","M3 * 0.5 ","M3.5 * 0.6 ","M4 * 0.7 ",
		"M5 * 0.8 ","M6 * 1.0 ","M7 * 1.0 ","M8 * 1.25 ", "M9 * 1.25 ","M10 * 1.5 ","M11 * 1.5 ",
		"M12 * 1.75 ", "M14 * 2 ", "M16 * 2 ", "M18 * 2.5 ","M20 * 2.5 ", "M22 * 2.5 ", "M24 * 3 ",
		"M27 * 3 ", "M30 * 3.5 ","M33 * 3.5 ", "M36 * 4 ", "M39 * 4 ", "M42 * 4.5 ", "M45 * 4.5 ",
		"M48 * 5 ", "M52 * 5 ", "M56 * 5.5 ", "M60 * 5.5 ", "M64 * 6 ","M68 * 6 ", "M72 * 6 ",
		"M76 * 6 ", "M80 * 6 ", "M90 * 6 ",	"M100 * 6 ",

		/*		imperial
				"1-64 ", "2-56 ", "3-48 ", "4-40 ", "5-40 ",
				"6-32 ", "8-32 ", "10-24 ","12-24 ", "1/4-20 ",
				"5/16-18 ", "3/8-16 ", "7/16-14 ", "1/2-13 ","9/16-12 ",
				"5/8-11 ", "3/4-10 ", "7/8-9 ", "1-8 ", "1-1/8-7 ",
				"1-1/4-7 ", "1-3/8-6 ", "1-1/2-6 ", "2-4-1/2 ",*/
	};

	string TabTagTitreC[100]
	{

		"thread_size_m1_0-25,", "thread_size_m1-2_0-25,", "thread_size_m1-4_0-3,", "thread_size_m1-6_0-35,", "thread_size_m1-7_0-35,", "thread_size_m1-8_0-35,",
		"thread_size_m2_0-4,", "thread_size_m2-2_0-45,", "thread_size_m2-3_0-4,", "thread_size_m2-5_0-45,", "thread_size_m2-6_0-45,", "thread_size_m3_0-5,", "thread_size_m3-5_0-6,", "thread_size_m4_0-7,",
		"thread_size_m5_0-8,", "thread_size_m6_1,", "thread_size_m7_1,", "thread_size_m8_1-25,", "thread_size_m9_1-25,", "thread_size_m10_1-5,", "thread_size_m11_1-5,",
		"thread_size_m12_1-75,", "thread_size_m14_2,", "thread_size_m16_2,", "thread_size_m18_2-5,", "thread_size_m20_2-5,", "thread_size_m22_2-5,", "thread_size_m24_3,",
		"thread_size_m27_3,", "thread_size_m30_3-5,", "thread_size_m33_3-5,", "thread_size_m36_4,", "thread_size_m39_4,", "thread_size_m42_4-5,", "thread_size_m45_4-5,",
		"thread_size_m48_5,", "thread_size_m52_5,", "thread_size_m56_5-5,", "thread_size_m60_5-5,", "thread_size_m64_6,", "thread_size_m68_6,", "thread_size_m72_6,",
		"thread_size_m76_6,", "thread_size_m80_6,", "thread_size_m90_6,", "thread_size_m100_6,",
		

		/*		impérial
				"thread_size_1-64,", "thread_size_2-56,", "thread_size_3-48,", "thread_size_4-40,", "thread_size_5-40,",
				"thread_size_6-32,", "thread_size_8-32,", "thread_size_10-24,", "thread_size_12-24,", "thread_size_1-4-20,",
				"thread_size_5-16-18,", "thread_size_3-8-16,", "thread_size_7-16-14,", "thread_size_1-2-13,", "thread_size_9-16-12,",
				"thread_size_5-8-11,", "thread_size_3-4-10,", "thread_size_7-8-9,", "thread_size_1-8,", "thread_size_1-1-8-7,",
				"thread_size_1-1-4-7,", "thread_size_1-3-8-6,", "thread_size_1-1-2-6,", "thread_size_2-4-1-2,"*/
	};

	void threading();

};

COARSE_THREAD::COARSE_THREAD()
{
}

COARSE_THREAD::~COARSE_THREAD()
{
}

inline void COARSE_THREAD::constructeur(string numProduit, string tag)
{
	this->numProduit = numProduit;
	this->tag = tag;
	i = 0;
	trouver = false;
	this->tag += "metric_coarse,";
	separation();
	threading();
}

inline string COARSE_THREAD::getTag()
{
	return tag;
}

inline string COARSE_THREAD::getThread()
{
	return TabThreadTitreC[i];
}

inline void COARSE_THREAD::separation()
{
	stringstream ss(numProduit);

	for (int j = 0; j < 2; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void COARSE_THREAD::threading()
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
	tag += TabTagTitreC[i];
}
#pragma endregion


#pragma region FINE THREAD
class FINE_THREAD
{
public:
	FINE_THREAD();
	~FINE_THREAD();
	void constructeur(string numProduit, string tag);
	string getTag();
	string getThread();
private:
	string texte;
	string souschaine[2];
	string tag;
	void separation();
	string numProduit;
	int i;
	bool trouver;

	string TabThread[100]
	{

		"01","012","014","016","018",
		"02","022","025","03","035","04",
		"05","06","07","08","09","10","11",
		"12","14","16","18","20","22","24",
		"27","30","33","36","39","42" "45",
		"48","52","56","60","64","68","72",
		"80","90","100",
		

	};

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

inline void FINE_THREAD::constructeur(string numProduit, string tag)
{
	this->numProduit = numProduit;
	this->tag = tag;
	i = 0;
	trouver = false;
	this->tag += "metric_fine,";
	separation();
	threading();
}

inline string FINE_THREAD::getTag()
{
	return tag;
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
	tag += TabTagThreadF[i];
}
#pragma endregion

#pragma region EXTRA FINE THREAD
class EXTRA_FINE_THREAD
{
public:
	EXTRA_FINE_THREAD();
	~EXTRA_FINE_THREAD();
	void constructeur(string numProduit, string tag);
	string getTag();
	string getThread();
private:
	string texte;
	string souschaine[2];
	string tag;
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

inline void EXTRA_FINE_THREAD::constructeur(string numProduit, string tag)
{
	this->numProduit = numProduit;
	this->tag = tag;
	i = 0;
	trouver = false;
	this->tag += "metric_extra_fine,";
	separation();
	threading();
}

inline string EXTRA_FINE_THREAD::getTag()
{
	return tag;
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
	tag += TabTagThreadFF[i];
}
#pragma endregion

#pragma region EXTRA EXTRA FINE THREAD
class EXTRA_EXTRA_FINE_THREAD
{
public:
	EXTRA_EXTRA_FINE_THREAD();
	~EXTRA_EXTRA_FINE_THREAD();
	void constructeur(string numProduit, string tag);
	string getTag();
	string getThread();
private:
	string texte;
	string souschaine[2];
	string tag;
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

inline void EXTRA_EXTRA_FINE_THREAD::constructeur(string numProduit, string tag)
{
	this->numProduit = numProduit;
	this->tag = tag;
	i = 0;
	trouver = false;
	this->tag += "metric_extra_extra_fine,";
	separation();
	threading();
}

inline string EXTRA_EXTRA_FINE_THREAD::getTag()
{
	return tag;
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
	tag += TabTagThreadEFF[i];
}
#pragma endregion

