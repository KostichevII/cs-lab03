#include "histogram.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void find_min_max(vector <double> numbers, double& min, double& max) {
	if (size(numbers) == 0) {
		return;
	}
	min = numbers[0];
	max = numbers[0];
	for (double x : numbers) {
		if (min > x) {
			min = x;
		}
		else
			if (max < x) {
				max = x;
			}
	}
}
vector <double> input_numbers(size_t count) {
	cerr << "Enter numbers:";
	vector <double> numbers(count);
	for (int i = 0; i < count; i++) {
		cin >> numbers[i];
	}
	return numbers;
}
vector <size_t> make_hystogram(vector <double> numbers, size_t bin, size_t& MAX_HEIGHT) {
	double max, min, bin_size;
	find_min_max(numbers, min, max);
	MAX_HEIGHT = 0;
	bin_size = (max - min) / bin;
	vector <size_t> bins(bin);
	for (double x : numbers) {
		bool found = false;
		size_t j;
		for (j = 0; (j < bin - 1); j++) {
			auto lo = min + j * bin_size;
			auto hi = min + (j + 1) * bin_size;
			if ((lo <= x) && (x < hi)) {
				bins[j]++;
				found = true;
				break;
			}
		}
		if (!found) {
			bins[bin - 1]++;
		}
		if (MAX_HEIGHT < bins[j]) {
			MAX_HEIGHT = bins[j];
		}
	}
	return bins;
}
