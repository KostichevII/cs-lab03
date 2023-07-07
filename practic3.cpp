#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <double> input_numbers(size_t count);
void find_min_max(vector <double> numbers, double& min, double& max);
vector <size_t> make_hystogram(vector <double> numbers, size_t bin, size_t& MAX_HEIGHT);
void show_hystogram_text(vector <size_t> bins, size_t MAX_HEIGHT);
void show_histogram_svg(const vector<size_t>& bins, size_t MAX_HEIGHT);
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void svg_frame(double x, double y);


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
void svg_begin(double width, double height) {
	cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
	cout << "<svg ";
	cout << "width='" << width << "' ";
	cout << "height='" << height << "' ";
	cout << "viewBox='0 0 " << width << " " << height << "' ";
	cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void svg_end() {
	cout << "</svg>\n";
}
void show_histogram_svg(const vector<size_t>& bins, size_t MAX_HEIGHT) {
	size_t MAX_ASTERISK;
	MAX_ASTERISK = 74;
	const auto IMAGE_WIDTH = 1200;
	const auto IMAGE_HEIGHT = 600;
	const auto TEXT_LEFT = 25;
	const auto TEXT_BASELINE = 25;
	const auto TEXT_WIDTH = 60;
	const auto BIN_HEIGHT = 30;
	const auto BLOCK_WIDTH = 10;
	svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
	double top = 10;
	for (size_t bin : bins) {
		double bin_width;
		if (MAX_HEIGHT > MAX_ASTERISK) {
			bin_width = BLOCK_WIDTH * (MAX_ASTERISK * (static_cast<double>(bin) / MAX_HEIGHT));
		}
		else {
			bin_width = BLOCK_WIDTH * bin;
		}
		svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
		svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
		top += BIN_HEIGHT;
	}
	if (MAX_HEIGHT > MAX_ASTERISK) {
		MAX_HEIGHT = MAX_ASTERISK;
	}
	MAX_HEIGHT = MAX_HEIGHT * 10 + 80;
	cerr << MAX_HEIGHT;
	top += 15;
	svg_frame(MAX_HEIGHT, top);
	svg_end();
}
void svg_text(double left, double baseline, string text) {
	cout << "<text x='" << left << "' y ='" << baseline << "'>" << text << "</text>" << '\n';
}
void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
	cout << "<rect x='" << x << "' y ='" << y << "' width = '" << width << "' height = '" << height
		<< "' stroke='" << stroke << "' fill='" << fill << "' />" << '\n';
}
void svg_frame(double x, double y) {
	cout << "<line x1='0' y1='0' x2='" << x << "' y2 = '0' stroke='black' stroke-width='4' stroke-dasharray = '10 10' />" << '\n';
	cout << "<line x1='0' y1='0' x2='0' y2='" << y << "' stroke='black' stroke-width='4' stroke-dasharray = '10 10' />" << '\n';
	cout << "<line x1='" << x << "' y1='0' x2='" << x << "' y2 = '" << y << "' stroke='black' stroke-width='4' stroke-dasharray = '10 10' />" << '\n';
	cout << "<line x1='0' y1='" << y << "' x2 = '" << x << "' y2 = '" << y << "' stroke='black' stroke-width='4' stroke-dasharray = '10 10' />" << '\n';
}