#pragma once
// LOOK OUT FOR COPIES OF ITEMS (Same prods many times)

// ALL NON-METRIC PRODUCTS REMOVED
// NEED TO ADD NEW PRODUCTS

#pragma region Boulon

class Boulon
{
public:
	Boulon();
	~Boulon();

	void constructeur(string tag, string titre, string numProduit, float bulk);
	string getTag();
	string getTitre();

private:
	string souschaine[3];
	string texte;
	bool trouver;
	string titre;
	string tag;
	char finethread;
	string numProduit;

	void separation();
	void produit();
	void material();
	void threading();
	void length();
	void grade();
};

Boulon::Boulon()
{
}

Boulon::~Boulon()
{
}

inline void Boulon::constructeur(string tag, string titre, string numProduit, float bulk)
{
	this->numProduit = numProduit;
	this->tag = tag;
	this->titre = titre;
	texte = "";
	trouver = false;

	separation();
	produit();
	material();
	threading();
	length();
	grade();

	int bulksize = bulk;
	this->titre += " [Bulk Size : " + to_string(bulksize) + "]";

}

inline string Boulon::getTag()
{
	return tag;
}

inline string Boulon::getTitre()
{
	return titre;
}

inline void Boulon::separation()
{
	stringstream ss(numProduit);


	for (int j = 0; j < 3; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void Boulon::produit()
{
	string TabProduit[900]
	{
		// Non desired products removed
		"BM",		"BM8",		"BMTE8",	"BM9N",		"BMC", 
		"BMCS",		"BM8N",		"BMTFF",	"0",		"BMTF",	
		"BMFFE",	"BMTF8N",	"BMT8",		"BMTEFF8",  "BMTFFE", 
		"BMFF",		"BMEST",	"BMF8E",	"BMFE",		"BMTE", 
		"BMTF8E",	"BOM",		"BOMS",		"BME",		"BMF", 
		
		"BME8",		"BMF8N",	"BMST",		"BMTFE",	"BMTE8N", 
		"BMTFN",	"0",		"BMT",		"BMF8",		"BMTF8",
		"BMST3",
	};

	string TabProduitTitre[900]
	{
		"Metric Hexagonal Bolt ",										"Metric Hexagonal Bolt ",						"Metric Flanged Hexagonal Bolt Full Thread ",		"Metric Hexagonal Bolt ",									"Metric Carriage Bolt ", 
		"Metric Carriage Bolt ",										"Metric Hexagonal Bolt ",						"Metric Hexagonal Bolt Extra Fine & Full Thread ",	"0 ",														"Metric Hexagonal Bolt Fine & Full Thread ", 
		"Metric Flanged Serrated Hexagonal Bolt Extra Fine Thread ",	"Metric Hexagonal Bolt Fine & Full Thread ",	"Metric Hexagonal Bolt Full Thread ",				"Metric Flanged Hexagonal Bolt Extra Fine & Full Thread ",	"Metric Flanged Hexagonal Bolt Extra Fine & Full Thread ",
		"Metric Hexagonal Bolt Extra Fine Thread ",						"Metric Flanged Hexagonal Bolt Full Thread ",	"Metric Flanged Hexagonal Bolt Fine Thread ",		"Metric Flanged Hexagonal Bolt Fine Thread ",				"Metric Flanged Hexagonal Bolt Full Thread ",
		"Metric Flanged Hexagonal Bolt Full Thread ",					"Metric Ball Joint Rod End ",					"Metric Ball Joint Rod End ",						"Metric Flanged Hexagonal Bolt ",							"Metric Hexagonal Bolt Fine Thread ", 
		
		"Metric Flanged Serrated Hexagonal Bolt ",						"Metric Hexagonal Bolt Fine Thread ",			"Metric Hexagonal Bolt Full Thread ",				"Metric Flanged Hexagonal Bolt Fine & Full Thread ",		"Metric Flanged Hexagonal Bolt Full Thread ", 
		"Metric Hexagonal Bolt Fine & Full Thread ",					"0 ",											"Metric Hexagonal Bolt Full Thread ",				"Hexagonal Bolt Fine Thread ",								"Metric Hexagonal Bolt Fine & Full Thread ",
		"Metric Hexagonal Bolt Full Thread ",
	};

	string TabTAgProduit[900]
	{
		"bolt,hex,metric,partially_threaded,",							"bolt,hex,metric,partially_threaded,",			"bolt,hex,metric,fully_threaded,",					"bolt,hex,metric,partially_threaded,",						"bolt,carriage, metric,fully_threaded,", 
		"bolt,carriage,metric,fully_threaded,",							"bolt,hex,metric,partially_threaded,",			"bolt,hex,metric,fully_threaded,",					"0,",														"bolt,hex,metric,fully_threaded,",
		"bolt,hex,metric,flanged,partially_threaded,",					"bolt,hex,metric,fully_threaded,",				"bolt,hex,metric,fully_threaded,",					"bolt,hex,metric,flanged, fully_threaded,",					"bolt,hex,metric,fully_threaded,flanged,",	
		"bolt,hex,metric,partially_threaded,",							"bolt,hex,metric,flanged,fully_threaded,",		"bolt,hex,metric,flanged,partially_threaded,",		"bolt,hex,metric,flanged,partially_threaded,",				"bolt,hex,metric,fully_threaded,flanged,",
		"bolt,flanged,fully_threaded,metric,",							"ball_joint,metric,partially_threaded,",		"ball_joint,metric,partially_threaded,",			"bolt,hex,metric,flanged,partially_threaded,",				"bolt,hex,metric,partially_threaded,",
		
		"bolt,flanged,partially_threaded,metric,hex,",					"bolt,hex,metric,partially_threaded,",			"bolt,hex,metric,fully_threaded,",					"bolt,hex,metric,flanged,fully_threaded,",					"bolt,hex,metric,fully_threaded,flanged, ", 
		"bolt,hex,metric,fully_threaded,",								"bolt,hex,metric,partially_threaded,",			"bolt,hex,metric,fully_threaded,",					"bolt,hex,metric,partially_threaded,",						"bolt,hex,metric,fully_threaded,",
		"bolt,hex,metric,fully_threaded,", 
	};

	char TabFineTread[900]
	{
		'c',	'c',	'c',	'c',	'c',
		'c',	'c',	'e',	'0',	'f',
		'e',	'f',	'c',	'e',	'e',
		'e',	'c',	'f',	'f',	'c',
		'f',	'c',	'c',	'c',	'f',
		
		'c',	'f',	'c',	'f',	'c',
		'f',	'e',	'c',	'f',	'f',
		'c',
	};

	int i = 0;
	for (int j = 0; j < souschaine[0].length(); j++)
	{
		texte += souschaine[0][j];
	}

	while (trouver == false)
	{
		if (texte == TabProduit[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	titre = titre + TabProduitTitre[i];
	tag += TabTAgProduit[i];
	finethread = TabFineTread[i];
}

inline void Boulon::material()
{
	int k = 0;
	char TabMaterial[10]{ '5','8','9','S','N', 'Y','3','G' };
	string TabMaterialTitre[10]{ "Zinc ","Yellow Zinc ", "Cadium Plated ","Stainless Steel ","Black Steel ", "White Nylon ","316 Stainless Steel ","Galvanized ","Brass " };
	string TabTagMaterial[10]{ "zinc,","yellow_zinc,","cadium_plated,","stainless_steel,304-stainless-steel,","steel,","nylon,","stainless_steel,316-stainless-steel,","galvanized,","brass," };

	for (int i = 0; i < souschaine[0].length(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (souschaine[0][i] == TabMaterial[j])
			{
				k = j;
			}
		}
	}

	if (souschaine[0] == "BM8")
	{
		k = 0;
	}
	else if (souschaine[0] == "BS3" || souschaine[0] == "BST3")
	{
		k = 6;
	}

	if (souschaine[2][0] == 'Y' || souschaine[2] == "UY")
	{
		k = 1;
	}
	else if (souschaine[2][0] == 'N')
	{
		k = 4;
	}

	tag += TabTagMaterial[k];
	titre = titre + TabMaterialTitre[k];
}

inline void Boulon::threading()
{

	COARSE_THREAD Metric_coarse;
	FINE_THREAD Metric_fine;
	EXTRA_FINE_THREAD Metric_extra_fine;
	EXTRA_FINE_THREAD Metric_extra_extra_fine;
	
	switch (finethread)
	{

		case 'c': //coarse
			Metric_coarse.constructeur(numProduit, tag);
			tag = Metric_coarse.getTag();
			titre = titre + Metric_coarse.getThread();
			break;
		case 'f': //fine
			Metric_fine.constructeur(numProduit, tag);
			tag = Metric_fine.getTag();
			titre = titre + Metric_fine.getThread();
			break;
		case 'e': //extra-fine (FF)
			Metric_extra_fine.constructeur(numProduit, tag);
			tag = Metric_extra_fine.getTag();
			titre = titre + Metric_extra_fine.getThread();
			break;
		case 'x': //extra-extra-fine (FF)
			Metric_extra_extra_fine.constructeur(numProduit, tag);
			tag = Metric_extra_extra_fine.getTag();
			titre = titre + Metric_extra_extra_fine.getThread();
			break;
		default:
			cout << "erreur dans le type de thread";
			break;
	}

}

inline void Boulon::length()
{
	trouver = false;
	int i = 0;
	string TabLenght[500]
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


	string TabLenghtTitre[500]
	{

		"* 1mm", "* 2mm", "* 3mm", "* 4mm", "* 5mm", "* 6mm", "* 7mm", "* 8mm", "* 9mm", "* 10mm", 
		"* 11mm ", "* 12mm ", "* 13mm ", "* 14mm", "* 15mm", "* 16mm ", "* 17mm", "* 18mm", "* 19mm", "* 20mm", 
		"* 21mm", "* 22mm", "* 23mm", "* 24mm", "* 25mm", "* 26mm", "* 27mm", "* 28mm", "* 29mm",  "* 30mm",
		"* 31mm", "* 32mm", "* 33mm", "* 34mm", "* 35mm", "* 36mm",	"* 37mm", "* 38mm", "* 39mm", "* 40mm", 
		"* 41mm", "* 42mm", "* 43mm", "* 44mm", "* 45mm","* 46mm", "* 47mm", "* 48mm", "* 49mm", "* 50mm", 
		"* 51mm", "* 52mm","* 53mm", "* 54mm", "* 55mm", "* 56mm", "* 57mm", "* 58mm", "* 59mm", "* 60mm",
		"* 61mm", "* 62mm","* 63mm", "* 64mm", "* 65mm", "* 66mm", "* 67mm", "* 68mm", "* 69mm", "* 70mm",
		"* 71mm", "* 72mm","* 73mm", "* 74mm", "* 75mm", "* 76mm", "* 77mm", "* 78mm", "* 79mm", "* 80mm",
		"* 81mm", "* 82mm","* 83mm", "* 84mm", "* 85mm", "* 86mm", "* 87mm", "* 88mm", "* 89mm", "* 90mm",
		"* 91mm", "* 92mm","* 93mm", "* 94mm", "* 95mm", "* 96mm", "* 97mm", "* 98mm", "* 99mm", "* 100mm",
		
		"* 101mm", "* 102mm","* 103mm", "* 104mm", "* 105mm", "* 106mm", "* 107mm", "* 108mm", "* 109mm", "* 110mm",		
		"* 111mm", "* 112mm","* 113mm", "* 114mm", "* 115mm", "* 116mm", "* 117mm", "* 118mm", "* 119mm", "* 120mm",		
		"* 121mm", "* 122mm","* 123mm", "* 124mm", "* 125mm", "* 126mm", "* 127mm", "* 128mm", "* 129mm", "* 130mm",		
		"* 131mm", "* 132mm","* 133mm", "* 134mm", "* 135mm", "* 136mm", "* 137mm", "* 138mm", "* 139mm", "* 140mm",		
		"* 141mm", "* 142mm","* 143mm", "* 144mm", "* 145mm", "* 146mm", "* 147mm", "* 148mm", "* 149mm", "* 150mm",		
		"* 151mm", "* 152mm","* 153mm", "* 154mm", "* 155mm", "* 156mm", "* 157mm", "* 158mm", "* 159mm", "* 160mm",		
		"* 161mm", "* 162mm","* 163mm", "* 164mm", "* 165mm", "* 166mm", "* 167mm", "* 168mm", "* 169mm", "* 170mm",		
		"* 171mm", "* 172mm","* 173mm", "* 174mm", "* 175mm", "* 176mm", "* 177mm", "* 178mm", "* 179mm", "* 180mm",		
		"* 181mm", "* 182mm","* 183mm", "* 184mm", "* 185mm", "* 186mm", "* 187mm", "* 188mm", "* 189mm", "* 190mm",		
		"* 191mm", "* 192mm","* 193mm", "* 194mm", "* 195mm", "* 196mm", "* 197mm", "* 198mm", "* 199mm", "* 200mm",

		"* 201mm", "* 202mm","* 203mm", "* 204mm", "* 205mm", "* 206mm", "* 207mm", "* 208mm", "* 209mm", "* 210mm",		
		"* 211mm", "* 212mm","* 213mm", "* 214mm", "* 215mm", "* 216mm", "* 217mm", "* 218mm", "* 219mm", "* 220mm",		
		"* 221mm", "* 222mm","* 223mm", "* 224mm", "* 225mm", "* 226mm", "* 227mm", "* 228mm", "* 229mm", "* 230mm",		
		"* 231mm", "* 232mm","* 233mm", "* 234mm", "* 235mm", "* 236mm", "* 237mm", "* 238mm", "* 239mm", "* 240mm",		
		"* 241mm", "* 242mm","* 243mm", "* 244mm", "* 245mm", "* 246mm", "* 247mm", "* 248mm", "* 249mm", "* 250mm",		
		"* 251mm", "* 252mm","* 253mm", "* 254mm", "* 255mm", "* 256mm", "* 257mm", "* 258mm", "* 259mm", "* 260mm",		
		"* 261mm", "* 262mm","* 263mm", "* 264mm", "* 265mm", "* 266mm", "* 267mm", "* 268mm", "* 269mm", "* 270mm",		
		"* 271mm", "* 272mm","* 273mm", "* 274mm", "* 275mm", "* 276mm", "* 277mm", "* 278mm", "* 279mm", "* 280mm",		
		"* 281mm", "* 282mm","* 283mm", "* 284mm", "* 285mm", "* 286mm", "* 287mm", "* 288mm", "* 289mm", "* 290mm",		
		"* 291mm", "* 292mm","* 293mm", "* 294mm", "* 295mm", "* 296mm", "* 297mm", "* 298mm", "* 299mm", "* 300mm",

		"*301mm,", "* 302mm","* 303mm", "* 304mm", "* 305mm", "* 306mm", "* 307mm", "* 308mm", "* 309mm", "* 310mm",
		"*311mm,", "* 312mm","* 313mm", "* 314mm", "* 315mm", "* 316mm", "* 317mm", "* 318mm", "* 319mm", "* 330mm",
		"*331mm,", "* 332mm","* 333mm", "* 334mm", "* 335mm", "* 336mm", "* 337mm", "* 338mm", "* 339mm", "* 330mm",
		"*331mm,", "* 332mm","* 333mm", "* 334mm", "* 335mm", "* 336mm", "* 337mm", "* 338mm", "* 339mm", "* 340mm",
		"*341mm,", "* 342mm","* 343mm", "* 344mm", "* 345mm", "* 346mm", "* 347mm", "* 348mm", "* 349mm", "* 350mm",
		"*351mm,", "* 352mm","* 353mm", "* 354mm", "* 355mm", "* 356mm", "* 357mm", "* 358mm", "* 359mm", "* 360mm",
		"*361mm,", "* 362mm","* 363mm", "* 364mm", "* 365mm", "* 366mm", "* 367mm", "* 368mm", "* 369mm", "* 370mm",
		"*371mm,", "* 372mm","* 373mm", "* 374mm", "* 375mm", "* 376mm", "* 377mm", "* 378mm", "* 379mm", "* 380mm",
		"*381mm,", "* 382mm","* 383mm", "* 384mm", "* 385mm", "* 386mm", "* 387mm", "* 388mm", "* 389mm", "* 390mm",
		"*391mm,", "* 392mm","* 393mm", "* 394mm", "* 395mm", "* 396mm", "* 397mm", "* 398mm", "* 399mm", "* 400mm",
	};

	string TabLenghtTag[500]
	{
		"length_1mm,", "length_2mm,", "length_3mm,", "length_4mm,", "length_5mm,", "length_6mm,", "length_7mm,", "length_8mm,", "length_9mm,", "length_10mm,",
		"length_11mm,", "length_12mm,", "length_13mm,", "length_14mm,", "length_15mm,", "length_16mm,", "length_17mm,", "length_18mm,", "length_19mm,", "length_20mm,",
		"length_21mm,", "length_22mm,", "length_23mm,", "length_24mm,", "length_25mm,", "length_26mm,", "length_27mm,", "length_28mm,", "length_29mm,", "length_30mm,",
		"length_31mm,", "length_32mm,", "length_33mm,", "length_34mm,", "length_35mm,", "length_36mm,", "length_37mm,", "length_38mm,", "length_39mm,", "length_40mm,",
		"length_41mm,", "length_42mm,", "length_43mm,", "length_44mm,", "length_45mm,", "length_46mm,", "length_47mm,", "length_48mm,", "length_49mm,", "length_50mm,",
		"length_51mm,", "length_52mm,", "length_53mm,", "length_54mm,", "length_55mm,", "length_56mm,", "length_57mm,", "length_58mm,", "length_59mm,", "length_60mm,",
		"length_61mm,", "length_62mm,", "length_63mm,", "length_64mm,", "length_65mm,", "length_66mm,", "length_67mm,", "length_68mm,", "length_69mm,", "length_70mm,",
		"length_71mm,", "length_72mm,", "length_73mm,", "length_74mm,", "length_75mm,", "length_76mm,", "length_77mm,", "length_78mm,", "length_79mm,", "length_80mm,",
		"length_81mm,", "length_82mm,", "length_83mm,", "length_84mm,", "length_85mm,", "length_86mm,", "length_87mm,", "length_88mm,", "length_89mm,", "length_90mm,",
		"length_91mm,", "length_92mm,", "length_93mm,", "length_94mm,", "length_95mm,", "length_96mm,", "length_97mm,", "length_98mm,", "length_99mm,", "length_100mm,",
		"length_101mm,", "length_102mm,", "length_103mm,", "length_104mm,", "length_105mm,", "length_106mm,", "length_107mm,", "length_108mm,", "length_109mm,", "length_110mm,",
		"length_111mm,", "length_112mm,", "length_113mm,", "length_114mm,", "length_115mm,", "length_116mm,", "length_117mm,", "length_118mm,", "length_119mm,", "length_120mm,",
		"length_121mm,", "length_122mm,", "length_123mm,", "length_124mm,", "length_125mm,", "length_126mm,", "length_127mm,", "length_128mm,", "length_129mm,", "length_130mm,",
		"length_131mm,", "length_132mm,", "length_133mm,", "length_134mm,", "length_135mm,", "length_136mm,", "length_137mm,", "length_138mm,", "length_139mm,", "length_140mm,",
		"length_141mm,", "length_142mm,", "length_143mm,", "length_144mm,", "length_145mm,", "length_146mm,", "length_147mm,", "length_148mm,", "length_149mm,", "length_150mm,",
		"length_151mm,", "length_152mm,", "length_153mm,", "length_154mm,", "length_155mm,", "length_156mm,", "length_157mm,", "length_158mm,", "length_159mm,", "length_160mm,",
		"length_161mm,", "length_162mm,", "length_163mm,", "length_164mm,", "length_165mm,", "length_166mm,", "length_167mm,", "length_168mm,", "length_169mm,", "length_170mm,",
		"length_171mm,", "length_172mm,", "length_173mm,", "length_174mm,", "length_175mm,", "length_176mm,", "length_177mm,", "length_178mm,", "length_179mm,", "length_180mm,",
		"length_181mm,", "length_182mm,", "length_183mm,", "length_184mm,", "length_185mm,", "length_186mm,", "length_187mm,", "length_188mm,", "length_189mm,", "length_190mm,",
		"length_191mm,", "length_192mm,", "length_193mm,", "length_194mm,", "length_195mm,", "length_196mm,", "length_197mm,", "length_198mm,", "length_199mm,", "length_200mm,",
		"length_201mm,", "length_202mm,", "length_203mm,", "length_204mm,", "length_205mm,", "length_206mm,", "length_207mm,", "length_208mm,", "length_209mm,", "length_210mm,",
		"length_211mm,", "length_212mm,", "length_213mm,", "length_214mm,", "length_215mm,", "length_216mm,", "length_217mm,", "length_218mm,", "length_219mm,", "length_220mm,",
		"length_221mm,", "length_222mm,", "length_223mm,", "length_224mm,", "length_225mm,", "length_226mm,", "length_227mm,", "length_228mm,", "length_229mm,", "length_230mm,",
		"length_231mm,", "length_232mm,", "length_233mm,", "length_234mm,", "length_235mm,", "length_236mm,", "length_237mm,", "length_238mm,", "length_239mm,", "length_240mm,",
		"length_241mm,", "length_242mm,", "length_243mm,", "length_244mm,", "length_245mm,", "length_246mm,", "length_247mm,", "length_248mm,", "length_249mm,", "length_250mm,",
		"length_251mm,", "length_252mm,", "length_253mm,", "length_254mm,", "length_255mm,", "length_256mm,", "length_257mm,", "length_258mm,", "length_259mm,", "length_260mm,",
		"length_261mm,", "length_262mm,", "length_263mm,", "length_264mm,", "length_265mm,", "length_266mm,", "length_267mm,", "length_268mm,", "length_269mm,", "length_270mm,",
		"length_271mm,", "length_272mm,", "length_273mm,", "length_274mm,", "length_275mm,", "length_276mm,", "length_277mm,", "length_278mm,", "length_279mm,", "length_280mm,",
		"length_281mm,", "length_282mm,", "length_283mm,", "length_284mm,", "length_285mm,", "length_286mm,", "length_287mm,", "length_288mm,", "length_289mm,", "length_290mm,",
		"length_291mm,", "length_292mm,", "length_293mm,", "length_294mm,", "length_295mm,", "length_296mm,", "length_297mm,", "length_298mm,", "length_299mm,", "length_300mm,",
		"length_301mm,", "length_302mm,", "length_303mm,", "length_304mm,", "length_305mm,", "length_306mm,", "length_307mm,", "length_308mm,", "length_309mm,", "length_310mm,",
		"length_311mm,", "length_312mm,", "length_313mm,", "length_314mm,", "length_315mm,", "length_316mm,", "length_317mm,", "length_318mm,", "length_319mm,", "length_320mm,",
		"length_321mm,", "length_322mm,", "length_323mm,", "length_324mm,", "length_325mm,", "length_326mm,", "length_327mm,", "length_328mm,", "length_329mm,", "length_330mm,",
		"length_331mm,", "length_332mm,", "length_333mm,", "length_334mm,", "length_335mm,", "length_336mm,", "length_337mm,", "length_338mm,", "length_339mm,", "length_340mm,",
		"length_341mm,", "length_342mm,", "length_343mm,", "length_344mm,", "length_345mm,", "length_346mm,", "length_347mm,", "length_348mm,", "length_349mm,", "length_350mm,",
		"length_351mm,", "length_352mm,", "length_353mm,", "length_354mm,", "length_355mm,", "length_356mm,", "length_357mm,", "length_358mm,", "length_359mm,", "length_360mm,",
		"length_361mm,", "length_362mm,", "length_363mm,", "length_364mm,", "length_365mm,", "length_366mm,", "length_367mm,", "length_368mm,", "length_369mm,", "length_370mm,",
		"length_371mm,", "length_372mm,", "length_373mm,", "length_374mm,", "length_375mm,", "length_376mm,", "length_377mm,", "length_378mm,", "length_379mm,", "length_380mm,",
		"length_381mm,", "length_382mm,", "length_383mm,", "length_384mm,", "length_385mm,", "length_386mm,", "length_387mm,", "length_388mm,", "length_389mm,", "length_390mm,",
		"length_391mm,", "length_392mm,", "length_393mm,", "length_394mm,", "length_395mm,", "length_396mm,", "length_397mm,", "length_398mm,", "length_399mm,", "length_400mm,",

	};

	texte = "";
	for (int j = 2; j < souschaine[1].length(); j++)
	{
		texte += souschaine[1][j];
	}

	if (souschaine[1][0] == '0' && souschaine[1][1] == '0')
	{
		if (texte[0] != '0' && texte[0] != '1' && texte[0] != '2')
		{
			texte[0] = '0';
		}
	}

	while (trouver == false)
	{
		if (texte == TabLenght[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}

	tag += TabLenghtTag[i];
	titre = titre + TabLenghtTitre[i];
}

inline void Boulon::grade()
{
	int k = 0;
	trouver = false;
	
	string TabGradeTitre;
	string tabTagGrade[4]
	{
		 "", "grade-8-8,", "grade-12-9,", "grade-10-9,",
	};



	if (souschaine[0] == "BMST" || souschaine[0] == "BMCS" || souschaine[0] == "BMEST")
	{
		TabGradeTitre = "";
		tag += tabTagGrade[0];
	}
	else if (souschaine[0] == "BM" || souschaine[0] == "BMC"  || souschaine[0] == "BME"  || souschaine[0] == "BMF" || souschaine[0] == "BMFE" || souschaine[0] == "BMFF" 
		|| souschaine[0] == "BMFFE" || souschaine[0] == "BMFTE" || souschaine[0] == "BMT" || souschaine[0] == "BMTE" || souschaine[0] == "BMTF" || souschaine[0] == "BMTFE" 
		|| souschaine[0] == "BMTFF" || souschaine[0] == "BMTFFE"    
		 )
	{
		TabGradeTitre = " Grade 8.8";
		tag += tabTagGrade[1];
	}
	else if (souschaine[0] == "BMH8")
	{
		TabGradeTitre = " Grade 12.9";
		tag += tabTagGrade[2];
	}	

	else
	{
		TabGradeTitre = " Grade 10.9";
		tag += tabTagGrade[3];
	}
	titre = titre + TabGradeTitre;
	
}

#pragma endregion

#pragma region Ecrou
class Ecrou
{
public:
	Ecrou();
	~Ecrou();

	void constructeur(string tag, string titre, string numProduit, float bulk);
	string getTag();
	string getTitre();
	void produit();

private:
	string souschaine[3];
	string texte;
	bool trouver;
	string titre;
	string tag;
	char finethread;
	string numProduit;

	void separation();
	void material();
	void threading();
	void grade();
};

inline void Ecrou::constructeur(string tag, string titre, string numProduit, float bulk)
{
	this->numProduit = numProduit;
	this->tag = tag;
	this->titre = titre;
	texte = "";
	trouver = false;

	separation();
	produit();
	material();
	threading();
	grade();

	int bulksize = bulk;
	this->titre += "[Bulk Size : " + to_string(bulksize) + "]";

}

Ecrou::Ecrou()
{
}

Ecrou::~Ecrou()
{
}


inline string Ecrou::getTag()
{
	return tag;
}

inline string Ecrou::getTitre()
{
	return titre;
}

inline void Ecrou::separation()
{
	stringstream ss(numProduit);


	for (int j = 0; j < 3; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void Ecrou::produit()
{

	string TabProduit[900]
	{
		// Non desired products removed
		"EM",		"EM8",
		"EM8Y",		"EMF",		"EMH",		"EMS",		"EMSH",
		"EMSC",		"EMFE",		"EMFFY",	"EMFH",		"EMFN",
		"0",		"0",		"EME",		"EMP",		"EMSEF",
		"EMSF",		"EMSFF",	"EMSK",		"EMSP",		"EMSE",

		"EMSY",		"EMY",		"EMSR",		"EMR",		"EMF8",
		"EMFF",		"EMSFFY",	"EMYL",		"EMFFQ",	"EMFQ",
		"EMQ8",		"EMB",
	};

	string TabProduitTitre[900]
	{
		"Metric Hexagonal Nut ",					"Metric Hexagonal Nut ",
		"Metric Hexagonal Nut ",					"Metric Hexagonal Nut Fine Thread ",					"Metric Hexagonal Nut ",							"Metric Hexagonal Nut ",							"Metric Hexagonal Nut ",
		"Metric Cap Nut ",							"Metric Hexagonal Flange LockNut ",						"Metric Hexagonal Nut ",							"Metric Hexagonal Nut ",							"Metric Hexagonal Nut ",
		"0 ",										"0 ",													"Metric Serrated Flanged Hexagonal Nut ",			"Metric Wing Nut",									"Metric Hexagonal Flange Nut ",
		"Metric Hexagonal Nut Fine Thread ",		"Metric Hexagonal Nut Fine Thread ",					"Metric Hexagonal LockNut External Tooth",			"Metric Wing Nut",									"Metric Hexagonal Flange Nut ",

		"Metric Hexagonal Nut Nylon Insert ",		"Metric Hexagonal Nut Nylon Insert ",					"Metric Hexagonal Coupling Nut",					"Metric Hexagonal Coupling Nut",					"Metric Hexagonal Nut Fine Thread ",
		"Metric Hexagonal Nut Fine Thread ",		"Metric Hexagonal Nut Nylon Insert Fine Thread ",		"Metric Hexagonal Nut Nylon Insert ",				"Metric Conical Hexagonal LockNut Fine Thread ",	"Metric Conical Hexagonal LockNut Fine Thread ",
		"Metric Conical Hexagonal Nut ",			"Metric Hexagonal But ",
	};
	string TabTAgProduit[900]
	{
		"hex, nut, metric, Metric_Coarse,",			"hex, nut, metric, Metric_Coarse,", 
		"hex, nut, metric, Metric_Coarse,",			"hex, nut, metric, Metric_Fine,",						"hex, nut, metric, Metric_Coarse, left_thread,",	"hex, nut, metric, Metric_Coarse,",					"hex, nut, metric, Metric_Coarse,left_thread,",
		"nut,metric, cap, Metric_Coarse,",			"hex,nut,metric,flanged, Metric_Fine,",					"hex,nut,metric, Metric_Extra_Fine,",				"hex,nut,metric, Metric_Fine,left_thread,",			"hex,nut,metric, Metric_Fine,",
		"0",										"0",													"nut,metric, flanged, Metric_Coarse,",				"nut,metric, wing, Metric_Coarse,",					"hex,nut,metric,flange, Metric_Fine,",
		"hex,nut,metric, Metric_Fine,",				"hex,nut,metric, Metric_Extra_Fine,",					"hex,nut,metric, Metric_Coarse,",					"nut,metric, wing, Metric_Coarse,",					"hex,nut,metric,flange, Metric_Coarse,",

		"nut,metric,nylon_insert, Metric_Coarse,",	"nut,metric,nylon_insert, Metric_Coarse,",				"hex,nut,metric,coupling, Metric_Coarse,",			"hex,nut,metric,coupling, Metric_Coarse,",			"hex, nut, metric, Metric_Fine,",
		"hex, nut, metric, Metric_Fine,",			"nut, hex, nylon_insert,metric, Metric_Extra_Fine,",	"nut,hex, nylon_insert,metric, Metric_Coarse,",		"hex,nut,conique,metric, Metric_Extra_Fine,",		"hex,nut,conique,metric, Metric_Fine,",
		"conique, nut, metric, Metric_Coarse,",		"hex, nut, metric, Metric_Coarse,",
	};

	char TabFineTread[900]
	{
		'c',	'c',	
		'c',	'f',	'c',	'c',	'c',
		'c',	'f',	'e',	'f',	'f',
		'0',	'0',	'c',	'c',	'f',
		'f',	'e',	'c',	'c',	'c',

		'c',	'c',	'c',	'c',	'f',
		'f',	'e',	'c',	'e',	'f',
		'c',	'c',	
	};

	int i = 0;
	for (int j = 0; j < souschaine[0].length(); j++)
	{
		texte += souschaine[0][j];
	}

	while (trouver == false)
	{
		if (texte == TabProduit[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	titre = titre + TabProduitTitre[i];
	tag += TabTAgProduit[i];
	finethread = TabFineTread[i];
}

inline void Ecrou::material()
{
	int k = 0;
	char TabMaterial[10]{ '5','8','9','S','N','3','G', 'N', 'B' };
	string TabMaterialTitre[10]{ "Zinc ","Yellow Zinc ", "Cadium Plated ","Stainless Steel ","Black Steel ","316 Stainless Steel ","Galvanized ","Brass " };
	string TabTagMaterial[10]{ "zinc,","yellow_zinc,","cadium_plated,","stainless_steel,304-stainless-steel,","steel,","stainless_steel,316-stainless-steel,","galvanized,","brass," };

	for (int i = 0; i < souschaine[0].length(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (souschaine[0][i] == TabMaterial[j])
			{
				k = j;
			}
		}
	}

	if (souschaine[2][0] == 'Y')
	{
		k = 1;
	}
	else if (souschaine[2][0] == 'N')
	{
		k = 4;
	}
	if (souschaine[0] == "EMQ8")
	{
		k = 0;
	}

	tag += TabTagMaterial[k];
	titre = titre + TabMaterialTitre[k];
}

inline void Ecrou::threading()
{

	FINE_THREAD fine;
	EXTRA_FINE_THREAD extra_fine;
	EXTRA_FINE_THREAD extra_extra_fine;
	COARSE_THREAD coarse;

	switch (finethread)
	{
	case 'c': //coarse
		coarse.constructeur(numProduit, tag);
		tag = coarse.getTag();
		titre = titre + coarse.getThread();
		break;
	case 'f': //fine
		fine.constructeur(numProduit, tag);
		tag = fine.getTag();
		titre = titre + fine.getThread();
		break;
	case 'e': //extra-fine (FF)
		extra_fine.constructeur(numProduit, tag);
		tag = extra_fine.getTag();
		titre = titre + extra_fine.getThread();
		break;
	default:
		cout << "erreur dans le type de thread";
		break;
	}

	/*extremly fine
	{
		extremly_fine.constructeur(numProduit, tag);
		tag = extremly_fine.getTag();
		titre = titre + extremly_fine.getThread();
	}*/
}

inline void Ecrou::grade()
{
	int k = 0;
	trouver = false;

	string TabGradeTitre;
	string tabTagGrade[4]
	{
		 "", "grade-8-8,", "grade-12-9,", "grade-10-9,",
	};

	if (souschaine[0] == "EMS" || souschaine[0] == "EMSC" || souschaine[0] == "EMSE" || souschaine[0] == "EMSF" || souschaine[0] == "EMSFF" || souschaine[0] == "EMSFY"
		|| souschaine[0] == "EMSH" || souschaine[0] == "EMSK" || souschaine[0] == "EMSP" || souschaine[0] == "EMSR" || souschaine[0] == "EMSY")
	{
		TabGradeTitre = "";
		tag += tabTagGrade[0];
	}
	
	else if (souschaine[0] == "EM" || souschaine[0] == "EMN" || souschaine[0] == "EMB" || souschaine[0] == "EMFN" || souschaine[0] == "EMFFIN" || souschaine[0] == "EMFFQ"
		|| souschaine[0] == "EMFI" || souschaine[0] == "EMFQ" || souschaine[0] == "EMF" || souschaine[0] == "EMFF" || souschaine[0] == "EMFE" || souschaine[0] == "EMFFE"
		|| souschaine[0] == "EMFH" || souschaine[0] == "EMH")
	{
		TabGradeTitre = " Grade 8.8 ";
		tag += tabTagGrade[1];
	}
	else if (souschaine[0] == "EM9")
	{
		TabGradeTitre = " Grade 12.9 ";
		tag += tabTagGrade[2];
	}
	else
	{
		TabGradeTitre = " Grade 10.9 ";
		tag += tabTagGrade[3];
	}
	titre = titre + TabGradeTitre;
}


#pragma endregion

#pragma region Washer
class Washer
{
public:
	Washer();
	~Washer();

	void constructeur(string tag, string titre, string numProduit, float bulk);
	string getTag();
	string getTitre();

private:
	string souschaine[3];
	string texte;
	bool trouver;
	string titre;
	string tag;
	char finethread;
	string numProduit;

	void separation();
	void produit();
	void material();
	void length();
	void grade();
};

Washer::Washer()
{
}

Washer::~Washer()
{
}

inline void Washer::constructeur(string tag, string titre, string numProduit, float bulk)
{
	this->numProduit = numProduit;
	this->tag = tag;
	this->titre = titre;
	texte = "";
	trouver = false;

	separation();
	produit();
	material();
	length();
	grade();

	int bulksize = bulk;
	this->titre += "[ Bulk Size : " + to_string(bulksize) + " ]";

}

inline string Washer::getTag()
{
	return tag;
}

inline string Washer::getTitre()
{
	return titre;
}

inline void Washer::separation()
{
	stringstream ss(numProduit);


	for (int j = 0; j < 3; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void Washer::produit()
{
	string TabProduit[900]
	{
		// Non desired products removed
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0", 
		"0",		"0",		"0",		"RMF",		"0",
		"RMS",		"0",		"RMA",		"0",		"0",
		
		"0",		"RMSDI",	"0",		"0",		"0",
		"RMA8N",	"RMA8",		"0",		"0",		"0",
		"RMY",		"RRM",		"RRMS"
		
	};

	string TabProduitTitre[900]
	{
		"0 ",						"0 ",									"0 ",								"0 ",								"0 ",
		"0 ",						"0 ",									"0 ",								"0 ",								"0 ",
		"0 ",						"0 ",									"0 ",								"0 ",								"0 ",
		"0 ",						"0 ",									"0 ",								"Metric Flat Washer Fender ",		"0 ",
		"Metric Flat Washer USS ",	"0 ",									"Metric Flat Washer SAE ",			"0 ",								"0 ",
		
		"0 ",						"Metric Lock Washer Internal Tooth ",	"0 ",								"0 ",								"0 ",
		"Metric Flat Washer SAE ",	"Metric Flat Washer SAE ",				"0 ",								"0 ",								"0 ", 
		"Metric Flat Washer USS ",	"Metric Lock Washer ",					"Metric Lock Washer ",
	};

	string TabTAgProduit[900]
	{
		"0,",						"0,",									"0,",								"0,",								"0,",
		"0,",						"0,",									"0,",								"0,",								"0,",
		"0,",						"0,",									"0,",								"0,",								"0,",
		"0,",						"0,",									"0,",								"washer,metric, fender,",			"0,",
		"washer,inch, uss,",		"0,",									"washer,inch, sae,",				"0,",								"0,",
		
		"0",						"washer,metric, internal_toothed",		"0",								"0",								"0",
		"washer,metric, sae,",		"washer,metric, sae,",					"0",								"0",								"0",
		"washer,metric, uss,",		"washer,metric, lock,",					"washer,metric, lock,",
	};

	char TabFineTread[900]
	{
		'0',	'0',	'0',	'0',	'0',
		'0',	'0',	'0',	'0',	'0',
		'0',	'0',	'0',	'0',	'0',
		'0',	'0',	'0',	'c',	'0',
		'c',	'0',	'c',	'0',	'0',
		
		'0',	'c',	'0',	'0',	'0',
		'c',	'c',	'0',	'0',	'0',
		'c',	'c',	'c',	
	};

	int i = 0;
	for (int j = 0; j < souschaine[0].length(); j++)
	{
		texte += souschaine[0][j];
	}

	while (trouver == false)
	{
		if (texte == TabProduit[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	titre = titre + TabProduitTitre[i];
	tag += TabTAgProduit[i];
	finethread = TabFineTread[i];
}

inline void Washer::material()
{
	int k = 0;
	char TabMaterial[10]{ '5','8','9','S','N', 'Y','3','G' };
	string TabMaterialTitre[10]{ "Zinc ","Yellow Zinc ", "Cadium Plated ","Stainless Steel ","Black Steel ", "White Nylon ","316 Stainless Steel ","Galvanized ","Brass " };
	string TabTagMaterial[10]{ "zinc,","yellow_zinc,","cadium_plated,","stainless_steel,304-stainless-steel,","steel,","nylon,","stainless_steel,316-stainless-steel,","galvanized,","brass," };

	for (int i = 0; i < souschaine[0].length(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (souschaine[0][i] == TabMaterial[j])
			{
				k = j;
			}
		}
	}

	if (souschaine[0] == "BH8" || souschaine[0] == "BHT8")
	{
		k = 4;
	}
	else if (souschaine[0] == "BS3" || souschaine[0] == "BST3")
	{
		k = 6;
	}

	if (souschaine[2][0] == 'Y')
	{
		k = 1;
	}
	else if (souschaine[2][0] == 'N')
	{
		k = 4;
	}

	tag += TabTagMaterial[k];
	titre = titre + TabMaterialTitre[k];
}

inline void Washer::length()
{
	trouver = false;
	int i = 0;
	string TabLenght[100]
	{
		"005", "006", "007", "008", "009", "010", "011", "012", "014",
		"016", "017", "018", "020", "022", "023", "024", "025", "026", "028", "030",
		"034", "035", "036", "037", "039", "040", "043", "045", "050", "055",
		"060", "065", "070", "075", "080",
		"090", "100", "110", "120", "130",

		"140", "150", "160", "170", "180",
		"200", "240", "250",

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


	};
	string TabLenghtTitre[100]
	{
		"* 5mm", "* 6mm", "* 7mm", "* 8mm",  "* 9mm", "* 10mm", "* 11mm", "* 12mm", "* 14mm",
		"* 16mm", "* 17mm", "* 18mm", "* 20mm", "* 22mm", "* 23mm", "* 24mm", "* 25mm", "* 26mm", "* 28mm", "* 30mm",
		"* 34mm", "* 35mm", "* 36mm", "* 37mm", "* 39mm", "* 40mm", "* 43mm", "* 45mm", "*50mm", "* 55mm",
		"* 60mm", "* 65mm", "* 70mm", "* 75mm", "* 80mm",
		"* 90mm", "* 100mm", "* 110mm","* 120mm", "* 130mm",

		"* 140mm", "* 150mm", "* 170mm", "* 180mm", "* 200mm",
		"* 240mm", "* 250mm",


		//"* 1/16\"\" ", "* 1/8\"\" ", "* 3/16\"\" ", "* 1/4\"\" ", "* 5/16\"\" ", "* 3/8\"\" ", "* 7/16\"\" ", "* 1/2\"\" ", "* 9/16\"\" ", "* 5/8\"\" ", "* 11/16\"\" ", "* 3/4\"\" ", "* 13/16\"\" ", "* 7/8\"\" ", "* 15/16\"\" ",
		//"* 1\"\" ","* 1-1/16\"\" ", "* 1-1/8\"\" ", "* 1-3/16\"\" ", "* 1-1/4\"\" ", "* 1-5/16\"\" ", "* 1-3/8\"\" ", "* 1-7/16\"\" ", "* 1-1/2\"\" ", "* 1-9/16\"\" ", "* 1-5/8\"\" ", "* 1-11/16\"\" ", "* 1-3/4\"\" ", "* 1-13/16\"\" ", "* 1-7/8\"\" ", "* 1-15/16\"\" ",
		//"* 2\"\" ","* 2-1/16\"\" ", "* 2-1/8\"\" ", "* 2-3/16\"\" ", "* 2-1/4\"\" ", "* 2-5/16\"\" ", "* 2-3/8\"\" ", "* 2-7/16\"\" ", "* 2-1/2\"\" ", "* 2-9/16\"\" ", "* 2-5/8\"\" ", "* 2-11/16\"\" ", "* 2-3/4\"\" ", "* 2-13/16\"\" ", "* 2-7/8\"\" ", "* 2-15/16\"\" ",
		//"* 3\"\" ","* 3-1/16\"\" ", "* 3-1/8\"\" ", "* 3-3/16\"\" ", "* 3-1/4\"\" ", "* 3-5/16\"\" ", "* 3-3/8\"\" ", "* 3-7/16\"\" ", "* 3-1/2\"\" ", "* 3-9/16\"\" ", "* 3-5/8\"\" ", "* 3-11/16\"\" ", "* 3-3/4\"\" ", "* 3-13/16\"\" ", "* 3-7/8\"\" ", "* 3-15/16\"\" ",


		//"* 4\"\" ", "* 4-1/4\"\" ", "* 4-1/2\"\" ", "* 4-3/4\"\" ",
		//"* 5\"\" ", "* 5-1/4\"\" ", "* 5-1/2\"\" ", "* 5-3/4\"\" ",
		//"* 6\"\" ", "* 6-1/4\"\" ", "* 6-1/2\"\" ", "* 6-3/4\"\" ",
		//"* 7\"\" ", "* 7-1/4\"\" ", "* 7-1/2\"\" ", "* 7-3/4\"\" ",

		//"* 8\"\" ", "* 8-1/2\"\" ",
		//"* 9\"\" ", "* 9-1/2\"\" ",
		//"* 10\"\" ", "* 10-1/2\"\" ",
		//"* 11\"\" ", "* 11-1/2\"\" ",

		//"* 12\"\" ",
		//"* 13\"\" ",
		//"* 14\"\" ",
		//"* 15\"\" ",
		//"* 16\"\" ",
		//"* 17\"\" ",
		//"* 18\"\" ",
		//"* 19\"\" ",
		//"* 20\"\" "
	};
	texte = "";
	for (int j = 2; j < souschaine[1].length(); j++)
	{
		texte += souschaine[1][j];
	}

	if (souschaine[1][0] == '0' && souschaine[1][1] == '0')
	{
		if (texte[0] != '0' && texte[0] != '1' && texte[0] != '2')
		{
			texte[0] = '0';
		}
	}
	while (trouver == false)
	{
		if (texte[0] == '5')
		{
			texte[0] = '0';
		}
		if (texte == TabLenght[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}


	titre = titre + TabLenghtTitre[i];
}

inline void Washer::grade()
{
	int k = 0;
	trouver = false;
	char TabGrade[4]{ '5','8','9','2' };
	string TabGradeTitre[4]{ "Grade 5 ","Grade 8 ", "Grade 9 ","Grade 2 " };
	string tabTagGrade[4]
	{
		"grade-5,","grade-8,","grade-9,","grade-2"
	};

	for (int i = 0; i < souschaine[0].length(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (souschaine[0][i] == TabGrade[j])
			{
				k = j;
				trouver = true;
			}
		}
	}

	if (souschaine[0] == "BC" || souschaine[0] == "BN" || souschaine[0] == "BE" || souschaine[0] == "BT")
	{
		k = 3;
		trouver = true;
	}


	if (trouver)
	{
		tag += tabTagGrade[k];
		titre = titre + TabGradeTitre[k];
	}
}

#pragma endregion

#pragma region vis
class Vis
{
public:
	Vis();
	~Vis();

	void constructeur(string tag, string titre, string numProduit, float bulk);
	string getTag();
	string getTitre();

private:
	string souschaine[3];
	string texte;
	bool trouver;
	string titre;
	string tag;
	char finethread;
	string numProduit;

	void separation();
	void produit();
	void material();
	void threading();
	void length();
	void grade();
};

Vis::Vis()
{
}

Vis::~Vis()
{
}

inline void Vis::constructeur(string tag, string titre, string numProduit, float bulk)
{
	this->numProduit = numProduit;
	this->tag = tag;
	this->titre = titre;
	texte = "";
	trouver = false;

	separation();
	produit();
	material();
	threading();
	length();
	grade();

	int bulksize = bulk;
	this->titre += "[Bulk Size : " + to_string(bulksize) + "]";

}

inline string Vis::getTag()
{
	return tag;
}

inline string Vis::getTitre()
{
	return titre;
}

inline void Vis::separation()
{
	stringstream ss(numProduit);


	for (int j = 0; j < 3; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void Vis::produit()
{
	string TabProduit[900]
	{
		// Non desired products removed
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",

		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"0",

		"0",		"0",		"VPRFD",	"0",		"0",
		"VPCM",		"VPCMF",	"VPCMFF",	"VPFM",		"VPRD",
		"VPRFD",	"VPSCM",	"VPSCM3",	"0",		"0",
		"0",		"0",		"VMFM",		"VBF",		"VMSFM",
		"0",		"VMSPFC",	"VPSPM",	"VMT",		"VMYPM",
		"VMYPM",	"VPBM",		"VPCMI",	"VMPM",		"VPSBM",
	};

	string TabProduitTitre[900]
	{
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		"0 ",										"0 ",											"0 ",									"0 ",			"0 ",
		
		"0 ",										"0 ",											"Set Screw Fine & Full Thread ",								"0 ",										"0 ",
		"Metric Socket Head Cap Screw ",			"Metric Socket Head Cap Screw ",				"Metric Socket Head Cap Screw Extra Fine Thread",				"Metric Flat Head Cap Screw ",				"Set screw Full Thread Dog Point",
		"Set screw Full Thread Dog Point",			"Metric Socket Head Cap Screw ",				"Metric Socket Head Cap Screw ",								"0 ",										"0 ",
		"0 ",										"0 ",											"Flat Head Machine Screw Full Thread ",							"Flat head Wood screw",						"Flat Head Machine Screw Full Thread ",
		"0 ",										"Flat Head Machine Screw Fine & Full Thread ",	"Metric Flat Head Machine Screw Full Thread ",					"Truss Head Machine Screw Full Thread ",	"Metric Pan Head Metal Screw Full Thread ",
		"Metric Pan Head Metal Screw Full Thread ", "Metric Button Head Cap Screw Full Thread ",	"Metric Low-Profile Button Head Cap Screw Partially Thread ",	"Metric Pan Head Machine Screw ",			"Metric Button Head Cap Screw Full thread ",
	};
	string TabTAgProduit[900]
	{
		"0,",																"0,",																"0,",																	"0,",																"0,",
		"0,",																"0,",																"0,",																	"0,",																"0,",
		"0,",																"0,",																"0,",																	"0,",																"0,",
		"0,",																"0,",																"0,",																	"0,",																"0,",
		"0,",																"0,",																"0,",																	"0,",																"0,",

		"0,",																"0,",																"0,",																	"0,",																"0,",
		"0,",																"0,",																"0,",																	"0,",																"0,",
		"0,",																"0,",																"0,",																	"0,",																"0,",
		"0,",																"0,",																"0,",																	"0,",																"0,",
		"0,",																"0,",																"0,",																	"0,",																"0,",
		
		"0,",																"0,",																"flat_head_cap_screw,inch,pressure_screw,fully_threaded,dog",			"0",																"0",
		"metric,socket_head_cap_screw,pressure_screw,partially_threaded,",	"metric,socket_head_cap_screw,pressure_screw,partially_threaded,",	"metric,socket_head_cap_screw,pressure_screw,partially_threaded,UNEF",	"metric,flat_head_cap_screw,pressure_screw,partially_threaded,",	"pressure_screw,inch,set_screw,fully_threaded,dog",
		"pressure_screw,inch,set_screw,fully_threaded,dog",					"metric,socket_head_cap_screw,pressure_screw,partially_threaded,",	"metric,socket_head_cap_screw,pressure_screw,partially_threaded,",		"0,", "0,",
		"0,",																"0,",																"flat_head, machine_screw,inch,fully_threaded, ",						"flat_head, wood_screw,inch,partially_threaded, ",					"flat_head, machine_screw,inch,fully_threaded, ",
		"0,",																"flat_head, machine_screw,inch,fully_threaded, ",					"flat_head, machine_screw,metric,fully_threaded, ",						"truss_head, machine_screw,inch,fully_threaded, ",					"pan_head, metal_screw,metric, fully_threaded,",
		"pan_head, metal_screw,metric, fully_threaded,",					"button_head_cap_screw,metric,pressure_screw,fully_threaded,",		"button_head_cap_screw,metric,pressure_screw,partially_threaded,",		"pan_head, machine_screw,metric, partially_threaded,",				"metric,button_head_cap_screw,pressure_screw,fully_threaded,"
	};
	char TabFineTread[900]
	{
			'0',	'0',	'0',	'0',	'0',
			'0',	'0',	'0',	'0',	'0',
			'0',	'0',	'0',	'0',	'0',
			'0',	'0',	'0',	'0',	'0',
			'0',	'0',	'0',	'0',	'0',
			 						 		 
			'0',	'0',	'0',	'0',	'0',
			'0',	'0',	'0',	'0',	'0',
			'0',	'0',	'0',	'0',	'0',
			'0',	'0',	'0',	'0',	'0',
			'0',	'0',	'0',	'0',	'0',
			
			'0',	'0',	'f',	'0',	'0',
			'c',	'f',	'e',	'c',	'c',
			'f',	'c',	'c',	'0',	'0',
			'0',	'0',	'c',	'c',	'c',
			'0',	'f',	'c',	'c',	'c',
			'c',	'c',	'c',	'c',	'c',
	};

	int i = 0;
	for (int j = 0; j < souschaine[0].length(); j++)
	{
		texte += souschaine[0][j];
	}

	while (trouver == false)
	{
		if (texte == TabProduit[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	titre = titre + TabProduitTitre[i];
	tag += TabTAgProduit[i];
	finethread = TabFineTread[i];
}

inline void Vis::material()
{
	int k = 0;
	char TabMaterial[10]{ '5','8','9','S','N', 'Y','3','G' };
	string TabMaterialTitre[10]{ "Zinc ","Yellow Zinc ", "Cadium Plated ","Stainless Steel ","Black Steel ", "White Nylon ","316 Stainless Steel ","Galvanized ","Brass " };
	string TabTagMaterial[10]{ "zinc,","yellow_zinc,","cadium_plated,","stainless_steel,304-stainless-steel,","steel,","nylon,","stainless_steel,316-stainless-steel,","galvanized,","brass," };

	for (int i = 0; i < souschaine[0].length(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (souschaine[0][i] == TabMaterial[j])
			{
				k = j;
			}
		}
	}

	if (souschaine[0][0] == 'V' && souschaine[0][1] == 'P')
	{
		k = 4;
	}
	else if (souschaine[0] == "VMBF" || souschaine[0] == "VMBP")
	{
		k = 8;
	}


	if (souschaine[2][0] == 'Y')
	{
		k = 1;
	}
	else if (souschaine[2][0] == 'N')
	{
		k = 4;
	}
	else if (souschaine[2][0] == 'Z')
	{
		k = 0;
	}

	tag += TabTagMaterial[k];
	titre = titre + TabMaterialTitre[k];
}

inline void Vis::threading()
{
	if (souschaine[0][0] == 'V' && souschaine[0][1] == 'M' && souschaine[0][2] == 'E')
	{
		tag += "unc,";
		if (souschaine[1][0] == '0' && souschaine[1][1] == '2')
		{
			titre += "#2 ";
		}
		else if (souschaine[1][0] == '0' && souschaine[1][1] == '4')
		{
			titre += "#4 ";
		}
		else if (souschaine[1][0] == '0' && souschaine[1][1] == '6')
		{
			titre += "#6 ";
		}
		else if (souschaine[1][0] == '0' && souschaine[1][1] == '8')
		{
			titre += "#8 ";
		}
		else if (souschaine[1][0] == '1' && souschaine[1][1] == '0')
		{
			titre += "#10 ";
		}
		else if (souschaine[1][0] == '1' && souschaine[1][1] == '2')
		{
			titre += "#12 ";
		}
		else if (souschaine[1][0] == '1' && souschaine[1][1] == '4')
		{
			titre += "#14 ";
		}
	}
	else
	{
			FINE_THREAD fine;
			EXTRA_FINE_THREAD extra_fine;
			EXTRA_FINE_THREAD extra_extra_fine;
			COARSE_THREAD coarse;

			switch (finethread)
			{
			case 'c': //coarse
				coarse.constructeur(numProduit, tag);
				tag = coarse.getTag();
				titre = titre + coarse.getThread();
				break;
			case 'f': //fine
				fine.constructeur(numProduit, tag);
				tag = fine.getTag();
				titre = titre + fine.getThread();
				break;
			case 'e': //extra-fine (FF)
				extra_fine.constructeur(numProduit, tag);
				tag = extra_fine.getTag();
				titre = titre + extra_fine.getThread();
				break;
			default:
				cout << "erreur dans le type de thread";
				break;
			}

			/*extremly fine
			{
				extremly_fine.constructeur(numProduit, tag);
				tag = extremly_fine.getTag();
				titre = titre + extremly_fine.getThread();
			}*/
		}
}

inline void Vis::length()
{
	trouver = false;
	int i = 0;
	string TabLenght[100]
	{
			"004", "005", "006", "008", "010",	"012", "014",
			"016", "018", "020", "022", "025", "030",
			"035", "040", "045", "050", "055",
			"060", "065", "070", "075", "080",
			"090", "100", "110", "120", "130",

			"140", "150", "170", "180", "200",
			"240", "250", "260",

	};
	string TabLenghtTitre[100]
	{
		"* 4mm", "* 5mm", "* 6mm", "* 8mm", "* 10mm", "* 12mm", "* 14mm",
		"* 16mm", "* 18mm", "* 20mm", "* 22mm", "* 25mm", "* 30mm",
		"* 35mm", "* 40mm", "* 45mm", "*50mm", "* 55mm",
		"* 60mm", "* 65mm", "* 70mm", "* 75mm", "* 80mm",
		"* 90mm", "* 100mm", "* 110mm","* 120mm", "* 130mm",

		"* 140mm", "* 150mm", "* 170mm", "* 180mm", "* 200mm",
		"* 240mm", "* 250mm", "* 260mm",
	};
	texte = "";
	for (int j = 2; j < souschaine[1].length(); j++)
	{
		texte += souschaine[1][j];
	}

	if (souschaine[1][0] == '0' && souschaine[1][1] == '0')
	{
		if (texte[0] != '0' && texte[0] != '1')
		{
			texte[0] = '0';
		}
	}

	while (trouver == false)
	{
		if (texte == TabLenght[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}


	titre = titre + TabLenghtTitre[i];
}

inline void Vis::grade()
{
	int k = 0;
	trouver = false;
	char TabGrade[4]{ '5','8','9','2' };
	string TabGradeTitre[4]{ "Grade 5 ","Grade 8 ", "Grade 9 ","Grade 2 " };
	string tabTagGrade[4]
	{
		"grade-5,","grade-8,","grade-9,","grade-2"
	};

	for (int i = 0; i < souschaine[0].length(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (souschaine[0][i] == TabGrade[j])
			{
				k = j;
				trouver = true;
			}
		}
	}

	if (trouver)
	{
		tag += tabTagGrade[k];
		titre = titre + TabGradeTitre[k];
	}

	if (souschaine[2][0] == 'S')
	{
		titre = titre + "[Slotted Drive] ";
		tag += "slotted,";
	}
	else if (souschaine[2][0] == 'T')
	{
		titre = titre + "[Torx Pin] ";
		tag += "torx_pin,";
	}
	else if (souschaine[2][0] == 'A')
	{
		titre = titre + "[Allen Pin] ";
		tag += "allen_pin,";
	}
	else if (souschaine[2][0] == 'C')
	{
		if (souschaine[0] == "VPSRF")
		{

		}
		else
		{
			titre = titre + "[Square Drive] ";
			tag += "square,";
		}
	}
	else if (souschaine[2][0] == 'Q')
	{
		titre = titre + "[Quadrex Drive] ";
		tag += "quadrex,";
	}
	else if (souschaine[0][0] == 'V' && souschaine[0][1] == 'P')
	{
		if (souschaine[0] == "VPSCA")
		{
			titre = titre + "[Square Drive] ";
			tag += "square,";
		}
		else
		{
			titre = titre + "[Allen Drive] ";
			tag += "allen,";
		}
	}
	else
	{
		titre = titre + "[Philips Drive] ";
		tag += "philips,";
	}
}

#pragma endregion

#pragma region Tige filt�
class Tige_Filte
{
public:
	Tige_Filte();
	~Tige_Filte();

	void constructeur(string tag, string titre, string numProduit, float bulk);
	string getTag();
	string getTitre();

private:
	string souschaine[3];
	string texte;
	bool trouver;
	string titre;
	string tag;
	bool finethread;
	string numProduit;

	void separation();
	void produit();
	void material();
	void threading();
	void length();
	void grade();
};

Tige_Filte::Tige_Filte()
{
}

Tige_Filte::~Tige_Filte()
{
}

inline void Tige_Filte::constructeur(string tag, string titre, string numProduit, float bulk)
{
	this->numProduit = numProduit;
	this->tag = tag;
	this->titre = titre;
	texte = "";
	trouver = false;

	separation();
	produit();
	material();
	threading();
	length();
	grade();

	int bulksize = bulk;
	this->titre += "[ Bulk Size : " + to_string(bulksize) + " ]";

}

inline string Tige_Filte::getTag()
{
	return tag;
}

inline string Tige_Filte::getTitre()
{
	return titre;
}

inline void Tige_Filte::separation()
{
	stringstream ss(numProduit);


	for (int j = 0; j < 3; j++)
	{
		getline(ss, souschaine[j], '-');
	}
}

inline void Tige_Filte::produit()
{
	string TabProduit[900]
	{
		// Non desired products removed
		"0",		"0",		"0",		"0",		"0",
		"0",		"0",		"0",		"0",		"TIM",
		"TIM8",		"TIMS",		"TIMF",		"TIM8FF",
	};

	string TabProduitTitre[900]
	{
		"0 ",				"0 ",				"0 ",							"0 ",							"0 ",		
		"0 ",				"0 ",				"0 ",							"0 ",							"Threaded Rod ",
		"Threaded Rod ",	"Threaded Rod ",	"Threaded Rod Fine Thread ",	"Threaded Rod Fine Thread ",
	};

	string TabTAgProduit[900]
	{
		"0,",					"0,",						"0,",					"0,",						"0,",
		"0,",					"0,",						"0,",					"0,",						"tige_filete,metric,",
		"tige_filete,metric,",	"tige_filete,metric,",		"tige_filete,metric,",	"tige_filete,metric,",
	};

	bool TabFineTread[900]
	{
		0,			0,			0,			0,			0,
		0,			0,			0,			0,			false,
		false,		false,		true,		true,
	};

	int i = 0;
	for (int j = 0; j < souschaine[0].length(); j++)
	{
		texte += souschaine[0][j];
	}

	while (trouver == false)
	{
		if (texte == TabProduit[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}
	titre = titre + TabProduitTitre[i];
	tag += TabTAgProduit[i];
	finethread = TabFineTread[i];
}

inline void Tige_Filte::material()
{
	int k = 0;
	char TabMaterial[10]{ '5','8','9','S','N', 'Y','3','G' };
	string TabMaterialTitre[10]{ "Zinc ","Yellow Zinc ", "Cadium Plated ","Stainless Steel ","Black Steel ", "White Nylon ","316 Stainless Steel ","Galvanized ","Brass " };
	string TabTagMaterial[10]{ "zinc,","yellow_zinc,","cadium_plated,","stainless_steel,304-stainless-steel,","steel,","nylon,","stainless_steel,316-stainless-steel,","galvanized,","brass," };

	for (int i = 0; i < souschaine[0].length(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (souschaine[0][i] == TabMaterial[j])
			{
				k = j;
			}
		}
	}

	if (souschaine[0] == "TIB" || souschaine[0] == "TIBF")
	{
		k = 8;
	}

	if (souschaine[2][0] == 'Y')
	{
		k = 1;
	}
	else if (souschaine[2][0] == 'N')
	{
		k = 4;
	}

	tag += TabTagMaterial[k];
	titre = titre + TabMaterialTitre[k];
}

inline void Tige_Filte::threading()
{
	FINE_THREAD fine;
	COARSE_THREAD coarse;

	if (finethread == true)
	{
		fine.constructeur(numProduit, tag);
		tag = fine.getTag();
		titre = titre + fine.getThread();
	}
	else
	{
		coarse.constructeur(numProduit, tag);
		tag = coarse.getTag();
		titre = titre + coarse.getThread();
	}
}

inline void Tige_Filte::length()
{
	trouver = false;
	int i = 0;
	string TabLenght[100]
	{

		#pragma region "000A - 038A"
		"000A", "001", "001A", "002", "002A", "003", "003A", "005", "005A", "006", "006A", "007", "007A", "008", "008A",
		"010", "010A", "011", "011A", "012", "012A", "013", "013A", "015", "015A", "016", "016A", "017", "017A", "018", "018A",
		"020", "020A", "021", "021A", "022", "022A", "023", "023A", "025", "025A", "026", "026A", "027", "027A", "028", "028A",
		"030", "030A", "031", "031A", "032", "032A", "033", "033A", "035", "035A", "036", "036A", "037", "037A", "038", "038A",
		#pragma endregion
		//Quantit� : 63

		#pragma region 040 - 077
		"040", "042", "045", "047",
		"050", "052", "055", "057",
		"060", "062", "065", "067",
		"070", "072", "075", "077",
		#pragma endregion
		//Quantit� : 79

		#pragma region "080 - 115"
		"080", "085",
		"090", "095",
		"100", "105",
		"110", "115",
		#pragma endregion
		//Quantit� : 87

		#pragma region 120 - 200
		"120",
		"130",
		"140",
		"150",
		"160",
		"170",
		"180",
		"190",
		"200",
		#pragma endregion

	};
	string TabLenghtTitre[100]
	{
		"* 1/16\"\" ", "* 1/8\"\" ", "* 3/16\"\" ", "* 1/4\"\" ", "* 5/16\"\" ", "* 3/8\"\" ", "* 7/16\"\" ", "* 1/2\"\" ", "* 9/16\"\" ", "* 5/8\"\" ", "* 11/16\"\" ", "* 3/4\"\" ", "* 13/16\"\" ", "* 7/8\"\" ", "* 15/16\"\" ",
		"* 1\"\" ","* 1-1/16\"\" ", "* 1-1/8\"\" ", "* 1-3/16\"\" ", "* 1-1/4\"\" ", "* 1-5/16\"\" ", "* 1-3/8\"\" ", "* 1-7/16\"\" ", "* 1-1/2\"\" ", "* 1-9/16\"\" ", "* 1-5/8\"\" ", "* 1-11/16\"\" ", "* 1-3/4\"\" ", "* 1-13/16\"\" ", "* 1-7/8\"\" ", "* 1-15/16\"\" ",
		"* 2\"\" ","* 2-1/16\"\" ", "* 2-1/8\"\" ", "* 2-3/16\"\" ", "* 2-1/4\"\" ", "* 2-5/16\"\" ", "* 2-3/8\"\" ", "* 2-7/16\"\" ", "* 2-1/2\"\" ", "* 2-9/16\"\" ", "* 2-5/8\"\" ", "* 2-11/16\"\" ", "* 2-3/4\"\" ", "* 2-13/16\"\" ", "* 2-7/8\"\" ", "* 2-15/16\"\" ",
		"* 3\"\" ","* 3-1/16\"\" ", "* 3-1/8\"\" ", "* 3-3/16\"\" ", "* 3-1/4\"\" ", "* 3-5/16\"\" ", "* 3-3/8\"\" ", "* 3-7/16\"\" ", "* 3-1/2\"\" ", "* 3-9/16\"\" ", "* 3-5/8\"\" ", "* 3-11/16\"\" ", "* 3-3/4\"\" ", "* 3-13/16\"\" ", "* 3-7/8\"\" ", "* 3-15/16\"\" ",


		"* 4\"\" ", "* 4-1/4\"\" ", "* 4-1/2\"\" ", "* 4-3/4\"\" ",
		"* 5\"\" ", "* 5-1/4\"\" ", "* 5-1/2\"\" ", "* 5-3/4\"\" ",
		"* 6\"\" ", "* 6-1/4\"\" ", "* 6-1/2\"\" ", "* 6-3/4\"\" ",
		"* 7\"\" ", "* 7-1/4\"\" ", "* 7-1/2\"\" ", "* 7-3/4\"\" ",

		"* 8\"\" ", "* 8-1/2\"\" ",
		"* 9\"\" ", "* 9-1/2\"\" ",
		"* 10\"\" ", "* 10-1/2\"\" ",
		"* 11\"\" ", "* 11-1/2\"\" ",

		"* 12\"\" ",
		"* 13\"\" ",
		"* 14\"\" ",
		"* 15\"\" ",
		"* 16\"\" ",
		"* 17\"\" ",
		"* 18\"\" ",
		"* 19\"\" ",
		"* 20\"\" "
	};
	texte = "";
	for (int j = 2; j < souschaine[1].length(); j++)
	{
		texte += souschaine[1][j];
	}

	if (souschaine[1][0] == '0' && souschaine[1][1] == '0')
	{
		if (texte[0] != '0' && texte[0] != '1' && texte[0] != '2')
		{
			texte[0] = '0';
		}
	}

	while (trouver == false)
	{
		if (texte == TabLenght[i])
		{
			trouver = true;
		}
		else
		{
			i++;
		}
	}


	titre = titre + TabLenghtTitre[i];
}

inline void Tige_Filte::grade()
{
	int k = 0;
	trouver = false;
	char TabGrade[4]{ '5','8','9','2' };
	string TabGradeTitre[4]{ "Grade 5 ","Grade 8 ", "Grade 9 ","Grade 2 " };
	string tabTagGrade[4]
	{
		"grade-5,","grade-8,","grade-9,","grade-2"
	};

	for (int i = 0; i < souschaine[0].length(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (souschaine[0][i] == TabGrade[j])
			{
				k = j;
				trouver = true;
			}
		}
	}

	if (souschaine[0] == "BC" || souschaine[0] == "BN" || souschaine[0] == "BE" || souschaine[0] == "BT")
	{
		k = 3;
		trouver = true;
	}


	if (trouver)
	{
		tag += tabTagGrade[k];
		titre = titre + TabGradeTitre[k];
	}
}

#pragma endregion

class TITRE
{
public:
	TITRE();
	~TITRE();
	void constructeur(string numProduit,float bulk, int reponse, string tag);
	string getTag();
	string getTitre();

private:
	string titre;
	string texte;
	bool trouver;
	bool finethread;
	bool extrafinethread;
	bool extraextrafinethread;
	int i;
	string souschaine[3];
	string numProduit;
	int reponse;
	string tag;
	float bulk;

	void produit();
};

TITRE::TITRE()
{
}

TITRE::~TITRE()
{
}

inline void TITRE::constructeur(string numProduit, float bulk,int reponse, string tag)
{
	i = 0;
	trouver = false;
	texte = "";
	this->reponse = reponse;
	this->tag = tag;
	this->bulk = bulk;
	this->numProduit = numProduit;
	produit();
}

inline string TITRE::getTag()
{
	return tag;
}

inline string TITRE::getTitre()
{
	return titre;
}

inline void TITRE::produit()
{
	Boulon bolt;
	Ecrou nut;
	Washer washer;
	Vis screw;
	//Equerre equerre;
	Tige_Filte tige;

	switch (reponse)
	{
	case 1:
		bolt.constructeur(tag, titre, numProduit, bulk);
		tag = bolt.getTag();
		titre = bolt.getTitre();
		break;

	case 2:
		nut.constructeur(tag, titre, numProduit, bulk);
		tag = nut.getTag();
		titre = nut.getTitre();
		break;

	case 3:
		washer.constructeur(tag, titre, numProduit, bulk);
		tag = washer.getTag();
		titre = washer.getTitre();
		break;

	// PLUS D'EQUERRE POUR L'INSTANT
	/*
	case 4:
		equerre.constructeur(tag, titre, numProduit, bulk);
		tag = equerre.getTag();
		titre = equerre.getTitre();
		break;
	*/

	case 5:
		tige.constructeur(tag, titre, numProduit, bulk);
		tag = tige.getTag();
		titre = tige.getTitre();
		break;

	case 6:
		screw.constructeur(tag, titre, numProduit, bulk);
		tag = screw.getTag();
		titre = screw.getTitre();
		break;
	}
	
}