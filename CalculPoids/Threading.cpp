#pragma once
#include "Globals.h"
#include "Threading.h"


struct_KeyValues threads[100] = {
	{"01", { {"c", "0.25"},	{"f", "0.2"},	{"ff", "X"},	{"fff", "X"} } },
	{"012",{ {"c", "0.25"}, {"f", "0.2"},	{"ff", "X"},	{"fff", "X"} } },
	{"014",{ {"c", "0.3"},	{"f", "0.2"},	{"ff", "X"},	{"fff", "X"} } },
	{"016",{ {"c", "0.35"}, {"f", "0.2"},	{"ff", "X"},	{"fff", "X"} } },
	{"017",{ {"c", "0.35"}, {"f", "0.2"},	{"ff", "X"},	{"fff", "X"} } },
	{"018",{ {"c", "0.35"}, {"f", "0.2"},	{"ff", "X"},	{"fff", "X"} } },
	{"02", { {"c", "0.4"},	{"f", "0.25"},	{"ff", "X"},	{"fff", "X"} } },
	{"022",{ {"c", "0.45"}, {"f", "0.25"},	{"ff", "X"},	{"fff", "X"} } },
	{"023",{ {"c", "0.4"},	{"f", "X"},		{"ff", "X"},	{"fff", "X"} } },
	{"025",{ {"c", "0.45"}, {"f", "0.35"},	{"ff", "X"},	{"fff", "X"} } },
	{"026",{ {"c", "0.45"}, {"f", "X"},		{"ff", "X"},	{"fff", "X"} } },
	{"03", { {"c", "0.5"},	{"f", "0.35"},	{"ff", "X"},	{"fff", "X"} } },
	{"035",{ {"c", "0.6"},	{"f", "0.35"},	{"ff", "X"},	{"fff", "X"} } },
	{"04", { {"c", "0.7"},	{"f", "0.5"},	{"ff", "X"},	{"fff", "X"} } },
	{"05", { {"c", "0.8"},	{"f", "0.5"},	{"ff", "X"},	{"fff", "X"} } },
	{"06", { {"c", "1"},	{"f", "0.75"},	{"ff", "X"},	{"fff", "X"} } },
	{"07", { {"c", "1"},	{"f", "0.75"},	{"ff", "X"},	{"fff", "X"} } },
	{"08", { {"c", "1.25"}, {"f", "1"},		{"ff", "0.75"},	{"fff", "X"} } },
	{"09", { {"c", "1.25"}, {"f", "1"},		{"ff", "0.75"},	{"fff", "X"} } },
	{"10", { {"c", "1.5"},	{"f", "1.25"},	{"ff", "1"},	{"fff", "0.75"} } },
	{"11", { {"c", "1.5"},	{"f", "1"},		{"ff", "0.75"},	{"fff", "X"} } },
	{"12", { {"c", "1.75"}, {"f", "1.5"},	{"ff", "1.25"},	{"fff", "1"} } },
	{"14", { {"c", "2"},	{"f", "1.5"},	{"ff", "1.25"},	{"fff", "1"} } },
	{"16", { {"c", "2"},	{"f", "1.5"},	{"ff", "1"},	{"fff", "X"} } },
	{"18", { {"c", "2.5"},	{"f", "2"},		{"ff", "1.5"},	{"fff", "1"} } },
	{"20", { {"c", "2.5"},	{"f", "2"},		{"ff", "1.5"},	{"fff", "1"} } },
	{"22", { {"c", "2.5"},	{"f", "2"},		{"ff", "1.5"},	{"fff", "1"} } },
	{"24", { {"c", "3"},	{"f", "2"},		{"ff", "1.5"},	{"fff", "1"} } },
	{"27", { {"c", "3"},	{"f", "2"},		{"ff", "1.5"},	{"fff", "1"} } },
	{"30", { {"c", "3.5"},	{"f", "2"},		{"ff", "1.5"},	{"fff", "X"} } },
	{"33", { {"c", "3.5"},	{"f", "3"},		{"ff", "2"},	{"fff", "1.5"} } },
	{"36", { {"c", "4"},	{"f", "3"},		{"ff", "2"},	{"fff", "1.5"} } },
	{"39", { {"c", "4"},	{"f", "3"},		{"ff", "2"},	{"fff", "1.5"} } },
	{"42", { {"c", "4.5"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"45", { {"c", "4.5"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"48", { {"c", "5"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"52", { {"c", "5"},	{"f", "4"},		{"ff", "3"},	{"fff", "X"} } },
	{"56", { {"c", "5.5"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"60", { {"c", "5.5"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"64", { {"c", "6"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"68", { {"c", "6"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"72", { {"c", "6"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"76", { {"c", "6"},	{"f", "X"},		{"ff", "X"},	{"fff", "X"} } },
	{"80", { {"c", "6"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"90", { {"c", "6"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
	{"100",{ {"c", "6"},	{"f", "4"},		{"ff", "3"},	{"fff", "2"} } },
};

THREADING::THREADING() {
	thrdTitle = "";
	threading();
}

THREADING::~THREADING() { }

string THREADING::getTags() { return tags; }

string THREADING::getThread() { return thrdTitle; }

void THREADING::threading() {
	text = global_splittedPrdNbr[0];
	tags = "metric_";
	int index = text.find('F') != string::npos ? text.find('F') : 0;
	if (text[index] == 'F' && text[index + 1] && text[index + 1] == 'F' && text[index + 2] && text[index + 2] == 'F') {
		thrdType = "fff";
		global_thrdType = "ISO Metric Pitch | Extra-extra-fine";
		thrdTitle += "Extra-Extra Fine Thread ";
		tags += "extra-extra_fine,";
	}
	else if (text[index] == 'F' && text[index + 1] && text[index + 1] == 'F') {
		thrdType = "ff";
		global_thrdType = "ISO Metric Pitch | Extra-fine";
		thrdTitle += "Extra Fine Thread ";
		tags += "extra_fine,";
	}
	else if (text[index] == 'F') {
		thrdType = "f";
		global_thrdType = "ISO Metric Pitch | Fine";
		thrdTitle += "Fine Thread ";
		tags += "fine,";
	}
	else {
		thrdType = "c";
		global_thrdType = "ISO Metric Pitch | Coarse";
		tags += "coarse,";
	}

	if (global_splittedPrdNbr[1][0] == '0' && global_splittedPrdNbr[1][1] < 4 && global_splittedPrdNbr[1][2] != '0' && global_splittedPrdNbr[1][2] != '1') {
		text = global_splittedPrdNbr[1][0];
		text += global_splittedPrdNbr[1][1];
		text += global_splittedPrdNbr[1][2];
	}
	else {
		text = global_splittedPrdNbr[1][0];
		text += global_splittedPrdNbr[1][1];
	}

	for (struct_KeyValues k_v : threads) {
		if (k_v.key == text) {
			string formatted = text;
			if (text[0] == '0') {
				text.erase(0, 1);
				if (text[1]) {
					formatted = text[0];		// Converts 0xy to x.y (any other stay as they are) (example: M012 to M1.2)
					formatted += ".";
					formatted += text[1];
				}
				formatted = text;
			}
			thrdTitle += "M" + formatted + " * " + k_v.values[thrdType] + " ";
			global_diamNom = stoi(formatted);

			// If condition for fitting tags with the filters on Shopify (Power Tools Filter)
			if (k_v.values[thrdType].find('.') != string::npos) k_v.values[thrdType][k_v.values[thrdType].find('.')] = '-';

			
			tags += "thread_size_m" + formatted + "_" + k_v.values[thrdType] + ",";
			break;
		}
	}
}