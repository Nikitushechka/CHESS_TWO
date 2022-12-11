#include <iostream>
#include "Cell.hpp"
using namespace std;


Cell::Cell(char hor_, char ver_, bool color_): hor_(hor_), ver_(ver_), color_(color_), is_empty_(0), piece_(nullptr) {}
