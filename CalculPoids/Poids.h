#pragma once
#include "PrdSpecsAndTitle.h"

#pragma region Boulon

class BOULON
{
public:
	BOULON();
	~BOULON();
	double getpoid();
	float getbulk();
	void constructeur(string numProduit, float bulk);
private:
	string souschaine[2];
	string texte;
	string numProduit;
	int i;
	int j;
	bool trouver;
	double poid;
	float bulk;

	string thread[500]
	{
					"010", "011", "012", "020", "021", "022", "030", "031", "032", "040", 
					"041", "042", "050", "051", "052", "060", "061", "062", "070", "071", 
					"072", "080", "081", "082", "090", "091", "092", "100", "101", "102",
					"110", "111", "112", "120", "121", "122", "130", "131", "132", "140", 
					"141", "142", "150", "151", "152", "160", "161", "162", "170", "171",
					"172", "180", "181", "182", "190", "191", "192", "200", "201", "202",

					"220", "221", "222", "230", "231", "232", "240", "241", "242", "250", 
					"251", "252", "260", "261", "262", "270", "271", "272", "280", "281", 
					"282", "290", "291", "292", "300", "310",
					"320", "330", "340", "350", "360", "370", "380", "390", "400", "410",
					"420", "430", "440", "450", "460", "470", "480", "490", "500", "510",
					"520", "530", "540", "550", "560", "570", "580", "590", "600", "610",
					"620", "630", "640", "650", "660", "670", "680", "690", "700", "710",
					
					"720", "730", "740", "750", "760", "770", "780", "790", "800", "810",
					"820", "830", "840", "850", "860", "870", "880", "890", "900", "910",
					"920", "930", "940", "950", "960", "970", "980", "990",

	};

	double width[500]
	{
		0.197, 0.197, 0.197, 0.209, 0.209, 0.209, 0.217, 0.217, 0.217, 0.276, 
		0.276, 0.276, 0.315, 0.315, 0.315, 0.394, 0.394, 0.394, 0.433, 0.433, 
		0.433, 0.512, 0.512, 0.512, 0.591, 0.591, 0.591, 0.669, 0.669, 0.669, 
		0.709, 0.709, 0.709, 0.748, 0.748, 0.748, 0.787, 0.787, 0.787, 0.866, 
		0.866, 0.866, 0.906, 0.906, 0.906, 0.945, 0.945, 0.945, 0.984, 0.984, 
		0.984, 1.063, 1.063, 1.063, 1.102, 1.102, 1.102, 1.181, 1.181, 1.181,

		1.220, 1.220, 1.220, 1.299, 1.299, 1.299, 1.339, 1.339, 1.339, 1.378, 
		1.378, 1.378, 1.417, 1.417, 1.417, 1.457, 1.457, 1.457, 1.496, 1.496, 
		1.496, 1.614, 1.614, 1.614, 1.693, 1.732,

		1.811, 1.850, 1.890, 1.929, 1.969, 2.087, 2.126, 2.165, 2.205, 2.244,
		2.283, 2.323, 2.362, 2.402, 2.441, 2.480, 2.520, 2.559, 2.598, 2.638,
		2.874, 3.071, 3.280, 3.496, 3.772, 4.087, 4.480, 4.913, 5.425, 6.016,
		6.685, 7.394, 8.142, 8.929, 9.795, 10.701, 11.646, 12.630, 13.693, 14.795,
		15.976, 17.197, 18.496, 19.835, 21.213, 22.630, 24.087, 25.583, 27.197, 28.890,
		30.622, 32.433, 34.283, 36.173, 38.102, 40.071, 42.157, 44.283, 46.449, 48.653,
		50.898, 53.181, 55.504, 57.866, 60.268, 62.709, 65.189, 67.709, 70.268, 72.866, 

	};

	double height[500]
	{
		0.039, 0.039, 0.039, 0.079, 0.079, 0.079, 0.079, 0.079, 0.079, 0.079, 
		0.079, 0.079, 0.138, 0.138, 0.138, 0.157, 0.157, 0.157, 0.189, 0.189, 
		0.189, 0.209, 0.209, 0.209, 0.224, 0.224, 0.224, 0.252, 0.252, 0.252,
		0.276, 0.276, 0.276, 0.295, 0.295, 0.295, 0.315, 0.315, 0.315, 0.346, 
		0.346, 0.346, 0.362, 0.362, 0.362, 0.394, 0.394, 0.394, 0.433, 0.433, 
		0.433, 0.453, 0.453, 0.453, 0.472, 0.472, 0.472, 0.492, 0.492, 0.492,

		0.512, 0.512, 0.512, 0.551, 0.551, 0.551, 0.571, 0.571, 0.571, 0.591, 
		0.591, 0.591, 0.610, 0.610, 0.610, 0.630, 0.630, 0.630, 0.669, 0.669, 
		0.669, 0.689, 0.689, 0.689, 0.709, 0.736,

		0.764, 0.791, 0.819, 0.846, 1.024, 1.001, 1.050, 1.099, 1.148, 1.197,
		1.246, 1.295, 1.344, 1.393, 1.442, 1.491, 1.540, 1.588, 1.637, 1.929,
		1.969, 2.047, 2.126, 2.205, 2.343, 2.500, 2.689, 2.898, 3.122, 3.374,
		3.650, 3.945, 4.260, 4.606, 4.969, 5.362, 5.795, 6.248, 6.720, 7.213,
		7.724, 8.276, 8.846, 9.437, 10.047, 10.677, 11.346, 12.035, 12.744, 13.480,
		14.244, 15.035, 15.854, 16.701, 17.724, 18.726, 19.776, 20.875, 22.023, 23.220,
		24.466, 25.761, 27.105, 28.498, 29.939, 31.430, 32.970, 34.558, 36.196, 38.125,
	};

	double diametre[500]
	{
		0.0625, 0.0625, 0.095, 0.095, 0.125, 0.125, 0.1875, 0.1875, 
		0.25, 0.25, 0.3, 0.3, 0.3125, 0.3125, 0.34, 0.34, 0.375, 0.375,
		0.4375, 0.4375, 0.475,  0.475, 0.475, 0.5, 0.5, 0.5625, 0.5625, 0.6,  0.6, 
		0.625, 0.625, 0.6875, 0.6875, 0.7, 0.7, 0.75, 0.75, 0.79, 0.79,

		0.8125, 0.875, 0.9, 0.9375, 1, 1.7, 1.13, 1.19, 1.25, 
		1.26, 1.27, 1.28, 1.29, 1.375, 1.40, 1.42, 1.44, 1.48, 1.5,
		1.54, 1.58, 1.63, 1.69, 1.75, 1.79, 1.84, 1.89, 1.95, 2, 
		2.03, 2.06, 2.09, 2.12, 2.15, 2.18, 2.21, 2.24, 2.27, 2.3,
		2.33, 2.36, 2.39, 2.45, 2.5, 2.58, 2.61, 2.64, 2.67, 2.7,
		2.73, 2.76, 2.79, 2.82, 2.85, 2.88, 2.91, 2.94, 2.97, 3.0,
		3.05, 3.10, 3.15, 3.2, 3.25, 3.3, 3.35, 3.4, 3.45, 3.5,
		3.55, 3.6, 3.65, 3.7, 3.75, 3.8, 3.85, 3.9, 3.95, 4, 

	};

	string size[500]
	{
					"001", "002", "003", "004", "005", "006", "007", "008", "009", "010",
					"011", "012", "013", "014", "015", "016", "017", "018", "019", "020",
					"021", "022", "023", "024", "025", "026", "027", "028", "029", "030",
					"031", "032", "033", "034", "035", "036", "037", "038", "039", "040",
					"041", "042", "043", "044", "045", "046", "047", "048", "049", "050",
					"051", "052", "053", "054", "055", "056", "057", "058", "059", "060",
					"061", "062", "063", "064", "065", "066", "067", "068", "069", "070",
					"071", "072", "073", "074", "075", "076", "077", "078", "079", "080",
					"081", "082", "083", "084", "085", "086", "087", "088", "089", "090",
					"091", "092", "093", "094", "095", "096", "097", "098", "099", "100",

					"101", "102", "103", "104", "105", "106", "107", "108", "109", "110",
					"111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
					"121", "122", "123", "124", "125", "126", "127", "128", "129", "130",
					"131", "132", "133", "134", "135", "136", "137", "138", "139", "140",
					"141", "142", "143", "144", "145", "146", "147", "148", "149", "150",
					"151", "152", "153", "154", "155", "156", "157", "158", "159", "160",
					"161", "162", "163", "164", "165", "166", "167", "168", "169", "170",
					"171", "172", "173", "174", "175", "176", "177", "178", "179", "180",
					"181", "182", "183", "184", "185", "186", "187", "188", "189", "190",
					"191", "192", "193", "194", "195", "196", "197", "198", "199", "200",

					"201", "202", "203", "204", "205", "206", "207", "208", "209", "210",
					"211", "212", "213", "214", "215", "216", "217", "218", "219", "220",
					"221", "222", "223", "224", "225", "226", "227", "228", "229", "230",
					"231", "232", "233", "234", "235", "236", "237", "238", "239", "240",
					"241", "242", "243", "244", "245", "246", "247", "248", "249", "250",
					"251", "252", "253", "254", "255", "256", "257", "258", "259", "260",
					"261", "262", "263", "264", "265", "266", "267", "268", "269", "270",
					"271", "272", "273", "274", "275", "276", "277", "278", "279", "280",
					"281", "282", "283", "284", "285", "286", "287", "288", "289", "290",
					"291", "292", "293", "294", "295", "296", "297", "298", "299", "300",

					"301", "302", "303", "304", "305", "306", "307", "308", "309", "310",
					"311", "312", "313", "314", "315", "316", "317", "318", "319", "320",
					"321", "322", "323", "324", "325", "326", "327", "328", "329", "330",
					"331", "332", "333", "334", "335", "336", "337", "338", "339", "340",
					"341", "342", "343", "344", "345", "346", "347", "348", "349", "350",
					"351", "352", "353", "354", "355", "356", "357", "358", "359", "360",
					"361", "362", "363", "364", "365", "366", "367", "368", "369", "370",
					"371", "372", "373", "374", "375", "376", "377", "378", "379", "380",
					"381", "382", "383", "384", "385", "386", "387", "388", "389", "390",
					"391", "392", "393", "394", "395", "396", "397", "398", "399", "400",

	};

	float length[500]
	{
		0.039, 0.079, 0.118, 0.157, 0.197, 0.236, 0.276, 0.315, 3.354, 0.394,
		0.433, 0.472, 0.512, 0.551, 0.63, 0.699, 0.709, 0.787, 0.827, 0.866,
		0.906, 0.945, 0.984, 1.024, 1.063, 1.102, 1.142, 1.181, 1.201, 1.25,
		1.275, 1.31, 1.35, 1.378, 1.399, 1.433, 1.475, 1.525, 1.575, 1.61,
		1.68, 1.71, 1.772, 1.81, 1.85, 1.91, 1.95, 1.969, 1.985, 2.011,
		2.085, 2.111, 2.165, 2.19, 2.315, 2.333, 2.35, 2.362, 2.375, 2.401,
		2.45, 2.501, 2.559, 2.58, 2.605, 2.65, 3.701, 2.756, 2.79, 2.825,
		2.85, 2.901, 2.953, 2.97, 2.99, 3.101, 3.126, 3.15, 3.18, 3.202,
		3.25, 3.301, 3.346, 3.366, 3.395, 3.44, 3.9, 3.543, 3.589, 3.61,
		3.65, 3.7, 3.74, 3.786, 3.81, 3.86, 3.9, 3.937, 3.937, 3.937, //100

		3.976, 4.016, 4.055, 4.094, 4.134, 4.173, 4.213, 4.252, 7.291, 4.331,
		4.37, 4.409, 4.449, 4.488, 4.567, 4.636, 4.646, 4.724, 4.764, 4.803,
		4.843, 4.882, 4.921, 4.961, 5, 5.039, 5.079, 5.118, 5.138, 5.187,
		5.212, 5.247, 5.287, 5.315, 5.336, 5.37, 5.412, 5.462, 5.512, 5.547,
		5.617, 5.647, 5.709, 5.747, 5.787, 5.847, 5.887, 5.906, 5.922, 5.948,
		6.022, 6.048, 6.102, 6.127, 6.252, 6.27, 6.287, 6.299, 6.312, 6.338,
		6.387, 6.438, 6.496, 6.517, 6.542, 6.587, 7.638, 6.693, 6.727, 6.762,
		6.787, 6.838, 6.89, 6.907, 6.927, 7.038, 7.063, 7.087, 7.117, 7.139,
		7.187, 7.238, 7.283, 7.303, 7.332, 7.377, 7.837, 7.48, 7.526, 7.547,
		7.587, 7.637, 7.677, 7.723, 7.747, 7.797, 7.837, 7.874, 7.874, 7.874, //200

		7.913, 7.953, 7.992, 8.031, 8.071, 8.11, 8.15, 8.189, 11.228, 8.268,
		8.307, 8.346, 8.386, 8.425, 8.504, 8.573, 8.583, 8.661, 8.701, 8.74,
		8.78, 8.819, 8.858, 8.898, 8.937, 8.976, 9.016, 9.055, 9.075, 9.124,
		9.149, 9.184, 9.224, 9.252, 9.273, 9.307, 9.349, 9.399, 9.449, 9.484,
		9.554, 9.584, 9.646, 9.684, 9.724, 9.784, 9.824, 9.843, 9.859, 9.885,
		9.959, 9.985, 10.039, 10.064, 10.189, 10.207, 10.224, 10.236, 10.249, 10.275, 
		10.324, 10.375, 10.433, 10.454, 10.479, 10.524, 11.575, 10.63, 10.664, 10.699, 
		10.724, 10.775, 10.827, 10.844, 10.864, 10.975, 11, 11.024, 11.054, 11.076, 
		11.124, 11.175, 11.22, 11.24, 11.269, 11.314, 11.774, 11.417, 11.463, 11.484, 
		11.524, 11.574, 11.614, 11.66, 11.684, 11.734, 11.774, 11.811, 11.811, 11.811, //300

		11.85, 11.89, 11.929, 11.968, 12.008, 12.047, 12.087, 12.126, 15.165, 12.205,
		12.244, 12.283, 12.323, 12.362, 12.441, 12.51, 12.52, 12.598, 12.638, 12.677,
		12.717, 12.756, 12.795, 12.835, 12.874, 12.913, 12.953, 12.992, 13.012, 13.061,
		13.086, 13.121, 13.161, 13.189, 13.21, 13.244, 13.286, 13.336, 13.386, 13.421,
		13.491, 13.521, 13.583, 13.621, 13.661, 13.721, 13.761, 13.78, 13.796, 13.822,
		13.896, 13.922, 13.976, 14.001, 14.126, 14.144, 14.161, 14.173, 14.186, 14.212,
		14.261, 14.312, 14.37, 14.391, 14.416, 14.461, 15.512, 14.567, 14.601, 14.636,
		14.661, 14.712, 14.764, 14.781, 14.801, 14.912, 14.937, 14.961, 14.991, 15.013,
		15.061, 15.112, 15.157, 15.177, 15.206, 15.251, 15.711, 15.354, 15.4, 15.421,
		15.461, 15.511, 15.551, 15.597, 15.621, 15.671, 15.711, 15.748, 15.748, 15.748, //400
	};

	string tigefilter[20]
	{
		"120","036","072","144","836","024", "035",
	};
	float tigefiltertexte[20]
	{
		120,36,72,144,36,24,35,
	};

	void separation();
	void Length();
	void calcul();
	void threading();
};

BOULON::BOULON()
{
}

BOULON::~BOULON()
{
}

inline void BOULON::calcul()
{
	double DW = width[j] / 2;
	double B = DW / 3.4641;
	double A = (B * 2) * 2.54;
	double V_TB = 2.5981 * (A * A) * (height[j] * 2.54);
	double V_CB;
	if (souschaine[0][0] == 'T' && souschaine[0][1] == 'I') {
		V_CB = 3.1415926535 * ((diametre[j] * 2.54) / 2) * ((diametre[j] * 2.54) / 2) * (tigefiltertexte[i] * 2.54);
	}
	else {
		V_CB = 3.1415926535 * ((diametre[j] * 2.54) / 2) * ((diametre[j] * 2.54) / 2) * (length[i] * 2.54);
	}

	double V_T = V_CB + V_TB;
	if (souschaine[0][0] == 'V') {
		if (souschaine[0][1] == 'P') poid = 7.0 * V_T;
		else if (souschaine[0][1] == 'M') {
			if (souschaine[0][2] == 'E') poid = 6.25 * V_T;
			else poid = 6.5 * V_T;
		}
		else poid = 6.00 * V_T;
	}
	else if (souschaine[0][0] == 'T' && souschaine[0][1] == 'F') {
		poid = 6.55 * V_T;
	}
	else poid = 8.0 * V_T;

	if (poid < 0.5) poid = 0.51;
	
	bulk = 20000 / poid;

	if (bulk > 20) bulk = round(bulk / 10) * 10;
	
	if (bulk > 2500) bulk = 2500;
}

inline void BOULON::threading()
{
	for (int k = 0; k < 3; k++)
	{
		texte += souschaine[1][k];
	}

	trouver = false;
	while (trouver == false)
	{
		if (texte == thread[j])
		{
			trouver = true;
		}
		else
		{
			j++;
		}
	}
}

inline double BOULON::getpoid()
{
	return poid;
}

inline float BOULON::getbulk()
{
	return bulk;
}

inline void BOULON::constructeur(string numProduit, float bulk)
{		this->numProduit = numProduit;
		i = 0;
		j = 0;
		trouver = false;
		poid = 0;
		this->bulk = bulk;
		texte = "";

		separation();
		Length();
		threading();
		calcul();
}

inline void BOULON::separation()
{
	stringstream ss(numProduit);
	for (int j = 0; j < 2; j++)
	{
		getline(ss, souschaine[j], '-');
	}

	for (int j = 2; j < souschaine[1].length(); j++)
	{
		texte += souschaine[1][j];
	}


	if (souschaine[1][1] == '0')
	{
		if (texte[0] != '0' && texte[0] != '1' && texte[0] != '2')
		{
			texte[0] = '0';
		}
	}
}

inline void BOULON::Length()
{
	while (trouver == false)
	{
		if (texte == size[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	texte = "";
}

#pragma endregion

#pragma region Ecrou
class ECROU
{
public:
	ECROU();
	~ECROU();
	double getpoid();
	float getbulk();
	void constructeur(string numProduit, float bulk);

private:
	string souschaine[2];
	string texte;
	string numProduit;
	int i;
	int j;
	bool trouver;
	double poid;
	float bulk;

	string thread[500]
	{
			"010", "011", "012", "020", "021", "022", "030", "031", "032", "040",
			"041", "042", "050", "051", "052", "060", "061", "062", "070", "071",
			"072", "080", "081", "082", "090", "091", "092", "100", "101", "102",
			"110", "111", "112", "120", "121", "122", "130", "131", "132", "140",
			"141", "142", "150", "151", "152", "160", "161", "162", "170", "171",
			"172", "180", "181", "182", "190", "191", "192", "200", "201", "202",

			"220", "221", "222", "230", "231", "232", "240", "241", "242", "243", "250",
			"251", "252", "260", "261", "262", "270", "271", "272", "280", "281",
			"282", "290", "291", "292", "300", "301", "310",
			"320", "330", "333", "340", "350", "360", "370", "380", "390", "400", "410",
			"420", "430", "440", "450", "460", "470", "480", "490", "500", "510",
			"520", "530", "540", "550", "560", "570", "580", "590", "600", "610",
			"620", "630", "640", "650", "660", "670", "680", "690", "700", "710",

			"720", "730", "740", "750", "760", "770", "780", "790", "800", "810",
			"820", "830", "840", "850", "860", "870", "880", "890", "900", "910",
			"920", "930", "940", "950", "960", "970", "980", "990",

	};

	double width[500]
	{
		0.4375, 0.4375, 0.4375, 0.5, 0.5, 0.5, 0.5625, 0.5625, 0.5625, 0.6875,
		0.6875, 0.6875, 0.75, 0.75, 0.75, 0.875, 0.875, 0.875, 0.9375, 0.9375,
		0.9375, 1.125, 1.125, 1.125, 1.3125, 1.3125, 1.3125, 1.5, 1.5, 1.5,
		1.6875, 1.6875, 1.6875, 1.875, 1.875, 1.875, 2.0625, 2.0625, 2.0625, 2.25,
		2.25, 2.25, 3.0, 3.0, 3.0, 3.25, 3.25, 3.25, 3.5, 3.5, 
		3.5, 3.75, 3.75, 3.75, 4.0, 4.0, 4.0, 4.25, 4.25, 4.25,

		4.5, 4.5, 4.5, 4.75, 4.75, 4.75, 5.0, 5.0, 5.0, 5.0, 5.25,
		5.25, 5.25, 5.5, 5.5, 5.5, 5.75, 5.75, 5.75, 6.0, 6.0,
		6.0, 6.25, 6.25, 6.25, 6.5, 6.5, 6.75, 
		7.0, 7.25, 7.25, 7.5, 7.75, 8.0, 8.25, 8.5, 8.75, 9.0, 9.25,
		10.0, 10.25, 10.5, 10.75, 11.0, 11.25, 11.5, 11.75, 12.0, 12.25,
		12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0, 14.25, 14.5, 14.75, 
		15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75, 17.0, 17.25,
		17.5, 17.75, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5, 

		19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0,
		22.25, 22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0,

	};

	double height[500]
	{
		0.21875, 0.21875, 0.21875, 0.265625, 0.265625, 0.265625, 0.328125, 0.328125, 0.328125, 0.375,
		0.375, 0.375, 0.4375, 0.4375, 0.4375, 0.484375, 0.484375, 0.484375, 0.546875, 0.546875,
		0.546875, 0.640625, 0.640625, 0.640625, 0.75, 0.75, 0.75, 0.859375, 0.859375, 0.859375,
		0.96875, 0.96875, 0.96875, 1.0625, 1.0625, 1.0625, 1.171875, 1.171875, 1.171875, 1.28125,
		1.28125, 1.28125, 1.71875, 1.71875, 1.71875, 2.21875, 2.21875, 2.21875, 2.265625, 2.265625,
		2.265625, 2.328125, 2.328125, 2.328125, 2.375, 2.375, 2.375, 2.4375, 2.4375, 2.4375, 

		2.484375, 2.484375, 2.484375, 2.546875, 2.546875, 2.546875, 2.640625, 2.640625, 2.640625, 2.640625, 2.75, 
		2.75, 2.75, 2.859375, 2.859375, 2.859375, 2.96875, 2.96875, 2.96875, 3.0625, 3.0625, 
		3.0625, 3.171875, 3.171875, 3.171875, 3.28125, 3.28125, 3.171875,
		3.265625, 3.328125, 3.375, 3.4375, 3.484375, 3.546875, 3.640625, 3.75, 3.859375, 3.96875,
		4.0625, 4.171875, 4.171875, 4.171875, 4.171875, 4.28125, 4.171875, 4.265625, 4.328125, 4.375, 4.4375, 
		4.484375, 4.546875, 4.640625, 4.75, 4.859375, 4.96875, 5.0625, 5.171875, 5.171875, 5.171875, 
		5.28125, 5.171875, 5.265625, 5.328125, 5.375, 5.4375, 5.484375, 5.546875, 5.640625, 5.75, 
		5.859375, 5.96875, 6.0625, 6.171875, 6.171875, 6.171875, 6.28125, 6.171875, 6.265625, 6.328125, 
		
		6.375, 6.4375, 6.484375, 6.546875, 6.640625, 6.75, 6.859375, 6.96875, 7.0625, 7.171875, 
		7.171875, 7.171875, 7.28125, 7.171875, 7.265625, 7.328125, 7.375, 7.4375,

	};

	double diametre[500]
	{
		0.25, 0.25, 0.25, 0.3125, 0.3125, 0.3125, 0.375, 0.375, 0.375, 0.375, 
		0.4375, 0.4375, 0.4375, 0.5, 0.5, 0.5, 0.5625, 0.5625, 0.5625, 0.625,
		0.625, 0.625, 0.75, 0.75, 0.75, 0.875, 0.875, 0.875, 1.0, 1.0, 1.25,
		1.25, 1.25, 1.3125, 1.3125, 1.3125, 1.375, 1.375, 1.375, 1.375, 1.4375,
		1.4375, 1.4375, 1.5, 1.5, 1.5, 1.5625, 1.5625, 1.5625, 1.625, 1.625,
		1.625, 1.75, 1.75, 1.75, 1.875, 1.875, 1.875, 2.0, 2.0, 2.0, 
		
		2.25, 2.25, 2.25, 2.3125, 2.3125, 2.3125, 2.375, 2.375, 2.375, 2.375, 2.375,
		2.4375, 2.4375, 2.4375, 2.5, 2.5, 2.5, 2.5625, 2.5625, 2.5625, 2.625, 
		2.625, 2.625, 2.75, 2.75, 2.75, 2.75, 2.875, 
		3.0, 3.25, 3.25, 3.3125, 3.375, 3.4375, 3.5, 3.5625, 3.625, 3.75, 3.875,
		4.0, 4.25, 4.3125, 4.375, 4.4375, 4.5, 4.5625, 4.625, 4.75, 4.875,
		5.0, 5.25, 5.3125, 5.375, 5.4375, 5.5, 5.5625, 5.625, 5.75, 5.875,
		6.0, 6.25, 6.3125, 6.375, 6.4375, 6.5, 6.5625, 6.625, 6.75, 6.875,

		7.0, 7.25, 7.3125, 7.375, 7.4375, 7.5, 7.5625, 7.625, 7.75, 7.875,
		8.0, 8.25, 8.3125, 8.375, 8.4375, 8.5, 8.5625, 8.625, 8.75, 8.875,
		9.0, 9.25, 9.3125, 9.375, 9.4375, 9.5, 9.5625, 9.625,
	};

	void separation();
	void calcul();
};

ECROU::ECROU()
{
}

ECROU::~ECROU()
{
}

inline void ECROU::calcul()
{
	double DW = width[j] / 2;
	double B = DW / 1.7321;
	double A = (B * 2) * 2.54;
	double V_EC = 2.5981 * (A*A) * (height[j] * 2.54);
	double V_TR = 3.1416 * (((diametre[j] * 2.54) / 2)*((diametre[j] * 2.54) / 2)) * (height[j] * 2.54);
	double V_T = V_EC - V_TR;
	poid = 4 * V_T;


	bulk = 20000 / poid;

	if (bulk > 20)
	{
		bulk = round(bulk / 10) * 10;
	}
	if (bulk >2500)
	{
		bulk = 2500;
	}
}


inline void ECROU::separation()
{
	stringstream ss(numProduit);
	string souschaine[2], texte;

	for (int j = 0; j < 2; j++)
	{
		getline(ss, souschaine[j], '-');
	}

	for (int k = 0; k < 3; k++)
	{
		texte += souschaine[1][k];
	}

	trouver = false;
	while (trouver == false)
	{
		if (texte == thread[j])
		{
			trouver = true;
		}
		else
		{
			j++;
		}
	}
}

inline double ECROU::getpoid()
{
	return poid;
}

inline float ECROU::getbulk()
{
	return bulk;
}

inline void ECROU::constructeur(string numProduit, float bulk)
{
	this->numProduit = numProduit;
	i = 0;
	j = 0;
	trouver = false;
	poid = 0;
	this->bulk = bulk;

	separation();
	calcul();
}
#pragma endregion

#pragma region Washer
class WASHER
{
public:
	WASHER();
	~WASHER();
	double getpoid();
	float getbulk();
	void constructeur(string numProduit, float bulk, float rlg);

private:
	string souschaine[2];
	string texte;
	string numProduit;
	int i;
	int j;
	bool trouver;
	double poid;
	float bulk;
	float rlg;


	string thread[100]
	{
		"010", "020", "021", "025", "030", "031", 
		"040", "050", "051", "060", "070", 
		"071", "080", "081", "090", "091", 
		"100", "101", "110", "111", "120", 
		"121", "130", "150", "151", "001",
		"002", "004", "005", "006", "008",
		"009", "200", "220", "240", "007", "230", "170",
	};

	//double width[100]
	//{
	//	0.4375, 0.5, 0.5, 0.5625, 0.5625, 0.625,
	//	0.75, 0.75, 0.8125, 0.9375, 0.9375,
	//	1.125, 1.125, 1.3125, 1.3125, 1.5, 1.5,
	//	1.6875, 1.6875, 1.875, 1.875, 2.0625, 2.25, 2.25, 0.15625,
	//	0.1875, 0.25, 0.3125, 0.3125, 0.375,
	//	0.4375, 3,
	//};

	//double height[100]
	//{
	//	0.15625, 0.203125, 0.203125, 0.234375, 0.234375, 0.281250,
	//	0.3125, 0.3125, 0.359375, 0.390625, 0.390625,
	//	0.468750, 0.468750, 0.546875, 0.546875, 0.609375, 0.609375,
	//	0.6875, 0.6875, 0.843750, 0.843750, 0.84375, 0.9375, 0.9375, 0.046875,
	//	0.0625, 0.09375, 0.109375, 0.109375, 0.125,
	//	0.15625, 1.71875,
	//};

	//double diametre[100]
	//{
	//	0.25, 0.3125, 0.3125, 0.375, 0.375, 
	//	0.4375,	0.5, 0.5, 0.5625, 0.625, 
	//	0.625, 0.75, 0.75, 0.875, 0.875, 
	//	1, 1, 1.125, 1.125, 1.25, 
	//	1.25, 1.375, 1.5, 1.5, 0.073,
	//	0.086, 0.112, 0.138, 0.164, 0.19,
	//	0.216, 2, 2.25, 2.75, 1.75,
	//};

	string size[100]
	{
		//#pragma region "000A - 038A"
		//"000A", "001", "001A", "002", "002A", "003", "003A", "005", "005A", "006", "006A", "007", "007A", "008", "008A",
		//"010", "010A", "011", "011A", "012", "012A", "013", "013A", "015", "015A", "016", "016A", "017", "017A", "018", "018A",
		//"020", "020A", "021", "021A", "022", "022A", "023", "023A", "025", "025A", "026", "026A", "027", "027A", "028", "028A",
		//"030", "030A", "031", "031A", "032", "032A", "033", "033A", "035", "035A", "036", "036A", "037", "037A", "038", "038A",
		//#pragma endregion
		////Quantit� : 63

		//#pragma region 040 - 077
		//"040", "042", "045", "047",
		//"050", "052", "055", "057",
		//"060", "062", "065", "067",
		//"070", "072", "075", "077",
		//#pragma endregion
		////Quantit� : 79

		//#pragma region "080 - 115"
		//"080", "085",
		//"090", "095",
		//"100", "105",
		//"110", "115",
		//#pragma endregion
		////Quantit� : 87

		//#pragma region 120 - 200
		//"120",
		//"130",
		//"140",
		//"150",
		//"160",
		//"170",
		//"180",
		//"190",
		//"200",
		//#pragma endregion

		"005", "006", "007", "008", "009", "010", "011", "012", "014",
		"016", "017", "018", "020", "022", "023", "024", "025", "026", "028", "030",
		"034", "035", "036", "037", "039", "040", "043", "045", "050", "055",
		"060", "065", "070", "075", "080",
		"090", "100", "110", "120", "130",

		"140", "150", "160", "170", "180",
		"200", "240", "250",

	};

	float length[100]
	{
		/******
					Mesures r�elles en mm convertis plus bas en pouces
					5, 6, 7, 8, 9, 10, 11, 12, 14,
					16, 17, 18, 20, 22, 23, 24, 25, 26, 28, 30,
					34, 35, 36, 37, 39, 40, 43, 45, 50, 55,
					60, 65, 70, 75, 80,
					90, 100, 110, 120, 130,

					140, 150, 160, 170, 180,
					200, 240, 250,******/
				0.19685,  0.23622, 0.275591, 0.314961, 0.354331, 0.393701, 0.475441, 0.433071, 0.551181,
				0.629921, 0.669291, 0.708661, 0.787402, 0.866142, 0.905512, 0,944882, 0.984252, 1.02362, 1.10236, 1.1811,
				1.37795, 1.41732, 1.45669, 1.53543, 1.5748, 1.69291, 1.77165, 1.9685, 2.16535,
				1.33858, 2.3622, 2.55906, 2.75591, 2.95276, 3.14961,
				3.54331, 3.93701, 4.33071, 4.72441, 5.11811,

				5.51181, 5.90551, 6.29921, 6.69291, 7.08661,
				7.87402, 9.44882, 9.84252, 10.2362, 
	};

	float E[100]
	{
		0.0655, 0.0655, 0.0655, 0.0655, 0.0655, 0.0655, 0.0655, 0.0655, 0.0655,
		0.0975, 0.0975, 0.0975, 0.0975, 0.0975, 0.0975, 0.127, 0.127, 0.127, 0.127, 0.127,
		0.134, 0.134, 0.134, 0.134, 0.134, 0.134, 0.134, 0.134, 0.134, 0.134,
		0.134, 0.134, 0.134, 0.164, 0.164,
		0.164, 0.164, 0.183, 0.183, 0.015,
		0.285, 0.032, 0.03, 0.0405, 0.0505,
		0.0505, 0.187, 0.04, 0.2205, 0.187,

	};

	void separation();
	void Length();
	void calcul();
	void threading();
};

WASHER::WASHER()
{
}

WASHER::~WASHER()
{
}

inline void WASHER::calcul()
{
	if (souschaine[0] != "RLG")
	{
	double V_od = 3.1416 * (((length[i] * 2.54) / 2) * ((length[i] * 2.54) / 2));
	double V_T = V_od * E[j] * 2.54;
	poid = 8.65 * V_T;

	bulk = 20000 / poid;
	if (bulk > 20)
	{
		bulk = round(bulk / 10) * 10;
	}
	}
	else
	{
		poid = rlg;
		bulk = 100;
	}
}

inline void WASHER::threading()
{
	for (int k = 0; k < 3; k++)
	{
		texte += souschaine[1][k];
	}

	trouver = false;
	while (trouver == false)
	{
		if (texte == thread[j])
		{
			trouver = true;
		}
		else
		{
			j++;
		}
	}
}

inline double WASHER::getpoid()
{
	return poid;
}

inline float WASHER::getbulk()
{
	return bulk;
}

inline void WASHER::constructeur(string numProduit, float bulk, float rlg)
{
	this->numProduit = numProduit;
	i = 0;
	j = 0;
	trouver = false;
	poid = 0;
	texte = "";
	this->bulk = bulk;
	this->rlg = rlg;

	separation();
	if (souschaine[0] != "RLG")
	{
		Length();
		threading();
	}
	calcul();

}

inline void WASHER::separation()
{
	stringstream ss(numProduit);
	for (int j = 0; j < 2; j++)
	{
		getline(ss, souschaine[j], '-');
	}

	for (int j = 2; j < souschaine[1].length(); j++)
	{
		texte += souschaine[1][j];
	}


	if (souschaine[1][1] == '0')
	{
		if (texte[0] != '0' && texte[0] != '1' && texte[0] != '2')
		{
			texte[0] = '0';
		}
	}
}

inline void WASHER::Length()
{
	while (trouver == false)
	{
		if (texte[0] == '5')
		{
			texte[0] = '0';
		}
		if (texte == size[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	texte = "";
}
#pragma endregion

