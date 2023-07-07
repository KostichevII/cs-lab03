#include "histogram.h"
#include "histogram_svg.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
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

	vector <string> colors = { "blue", "green", "orange", "grey", "red", "yellow", "black" };

	svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

	double top = 10;
	int i = 0;
	for (size_t bin : bins) {
		double bin_width;
		if (MAX_HEIGHT > MAX_ASTERISK) {
			bin_width = BLOCK_WIDTH * (MAX_ASTERISK * (static_cast<double>(bin) / MAX_HEIGHT));
		}
		else {
			bin_width = BLOCK_WIDTH * bin;
		}
		svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
		svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, colors[i], colors[i] );
		top += BIN_HEIGHT;
		if (i < 5) {
			i++;
		}
		else {
			i = 0;
		}
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