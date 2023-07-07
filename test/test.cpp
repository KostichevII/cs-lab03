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
    assert(min == 1);
    assert(max == 3);
}
void test_same() {
    double min = 0;
    double max = 0;
    find_min_max({ 1, 1, 1 }, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_null() {
    double min = 0;
    double max = 0;
    find_min_max({}, min, max);
    assert(min == 1);
    assert(max == 3);
}
