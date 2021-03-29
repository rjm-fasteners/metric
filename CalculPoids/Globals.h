#pragma once
#ifndef H__GLOBALS__H
#define H__GLOBALS__H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <filesystem>
#include <map>
using namespace std;

# define M_PI 3.14159265358979323846		/* Pi */

extern string global_thrdSize;
extern string global_thrdType;
extern string global_threading;
extern string global_thrdFit;
extern string global_thrdDirection;
extern string global_minThrdLength;
extern string global_length;
extern string global_grade;

extern string global_tensStrength;
extern string global_shearStrength;

extern string global_driveStyle;
extern string global_driveSize;

extern string global_headHeight;
extern string global_headProfile;
extern string global_headType;

extern string global_materialAndPlating;

extern string global_headDiam;

extern int global_diamNom;

extern string global_splittedPrdNbr[3];
extern string global_prdNbr;

extern string comaToDot(string val);
extern string dotToComa(string val);
extern float toFloat(string prix);

struct struct_TypeTitleTags {
	string type;
	string title;
	string tags;
};

struct struct_KeyValues {
	string key;
	map<string, string> values;
};
#endif