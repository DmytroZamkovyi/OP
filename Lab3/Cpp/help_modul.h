#pragma once
#include <iostream>
#include "Geometric_progression.h"
#include <vector>
using namespace std;

vector<Geometric_progression> input_geo_progressions(int length);
int find_max(vector<Geometric_progression> progressions);
double power(double a, int n);