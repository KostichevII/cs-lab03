#include <iostream>
#include <vector>
#include <string>
#include "histogram.h"
#include "histogram_svg.h"

using namespace std;

int main()
{
	size_t number_count, bin_count, MAX_HEIGHT;
	cerr << "Enter number count:";
	cin >> number_count;
	cerr << '\n';
	cerr << "Enter bin count:";
	cin >> bin_count;
	cerr << '\n';
	const auto numbers = input_numbers(number_count);
	const auto bins = make_hystogram(numbers, bin_count, MAX_HEIGHT);
	show_histogram_svg(bins, MAX_HEIGHT);
}