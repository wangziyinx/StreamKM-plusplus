#include "mex.h"

#include <iostream>
#include "Coreset.hpp"
#include "StreamModel.hpp"
#include "other_functions.hpp"
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>

void matrix2vector(double * M,  mwSize N, mwSize dim, vector < double * > & D );
void vector2matrix(double * M, mwSize N, mwSize dim, vector <double *> &D);