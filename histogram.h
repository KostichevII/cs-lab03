#pragma once
#include <vector>
#include <string>
using namespace std;
void find_min_max(vector <double> numbers, double& min, double& max);
vector <double> input_numbers(size_t count);
vector <size_t> make_hystogram(vector <double> numbers, size_t bin, size_t& MAX_HEIGHT);
