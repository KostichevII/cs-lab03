#pragma once
#include <vector>
#include <string>
using namespace std;
void show_histogram_svg(const vector<size_t>& bins, size_t MAX_HEIGHT);
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
void svg_frame(double x, double y);
