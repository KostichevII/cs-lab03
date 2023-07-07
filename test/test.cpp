#include "..\histogram.h"
#include <vector>
#include <cassert>
void test_positive() {
    double min = 0;
    double max = 0;
    find_min_max({ 1, 2, 3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative() {
    double min = 0;
    double max = 0;
    find_min_max({ -1, -2, -3 }, min, max);
    assert(min == -3);
    assert(max == -1);
}
void test_same() {
    double min = 0;
    double max = 0;
    find_min_max({ 1, 1, 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}
void test_null() {
    double min = 0;
    double max = 0;
    find_min_max({}, min, max);
    assert(min == 0);
    assert(max == 0);
}
void test_make() {
    vector <double> numbers = { 4, 4, 4, 4, 4, 5, 5, 3, 3, 3, };
    size_t bin = 3;
    size_t h = 5;
    auto bins = make_hystogram(numbers, bin, h);
    assert(bins[0] == 3);
    assert(bins[1] == 5);
    assert(bins[2] == 2);
}
int main() {
    test_positive();
    test_negative();
    test_same();
    test_null();
    test_make();
}
