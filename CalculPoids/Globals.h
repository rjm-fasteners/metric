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

extern string title_thrdSize;
extern string title_thrdType;
extern string title_threading;
extern string title_thrdFit;
extern string title_thrdDirection;
extern string title_minThrdLength;
extern string title_length;
extern string title_grade;

extern string title_tensStrength;
extern string title_shearStrength;

extern string title_driveStyle;
extern string title_driveSize;

extern string title_headHeight;
extern string title_headProfile;
extern string title_headType;

extern string title_materialAndPlating;

extern string title_headDiam;

extern int title_diamNom;

extern string global_splittedPrdNbr[3];
extern string global_prdNbr;

extern string comaToDot(string val);
extern string dotToComa(string val);
extern float toFloat(string prix);

struct KeyValuesInterface {
	string key;
	map<string, string> values;
};
#endif