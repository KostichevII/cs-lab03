#include <iostream>
#include <vector>

using namespace std;

vector <double> input_numbers(size_t count);
void find_min_max(vector <double> numbers, double& min, double& max);
vector <size_t> make_hystogram(vector <double> numbers, size_t bin, size_t& MAX_HEIGHT);
void show_hystogram_text(vector <size_t> bins, size_t MAX_HEIGHT);

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
	show_hystogram_text(bins, MAX_HEIGHT);
}
vector <double> input_numbers(size_t count) {
	cerr << "Enter numbers:";
	vector <double> numbers(count);
	for (int i = 0; i < count; i++) {
		cin >> numbers[i];
	}
	return numbers;
}
void find_min_max(vector <double> numbers, double& min, double& max) {
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
void show_hystogram_text(vector <size_t> bins, size_t MAX_HEIGHT) {
	size_t MAX_ASTERISK, height;
	MAX_ASTERISK = 74;
	string frame = "+";
	if (MAX_HEIGHT < MAX_ASTERISK) {
		frame.append(MAX_HEIGHT + 5, '-');
	}
	else {
		frame.append((MAX_ASTERISK + 5), '-');
	}
	frame += '+';
	cout << frame << '\n';
	for (int i = 0; i < size(bins); i++) {
		height = bins[i];
		cout << "|";
		if (bins[i] < 100) {
			cout << " ";
		}
		if (bins[i] < 10) {
			cout << " ";
		}
		cout << bins[i];
		cout << '|';
		if (MAX_HEIGHT < MAX_ASTERISK) {
			for (int j = 0; j < height; j++) {
				cout << '*';
			}
			for (int j = 0; j <= (MAX_HEIGHT - height); j++) {
				cout << " ";
			}
		}
		else {
			height = round(MAX_ASTERISK * (static_cast<double>(bins[i]) / MAX_HEIGHT));
			if (bins[i] == MAX_HEIGHT) {
				for (int j = 0; j < MAX_ASTERISK; j++) {
					cout << '*';
				}
			}
			else {
				for (int j = 0; j < height; j++) {
					cout << '*';
				}
			}
			for (int j = 0; j <= (MAX_ASTERISK - height); j++) {
				cout << " ";
			}
		}
		cout << "|" << "\n";
	}
	cout << frame;
}
