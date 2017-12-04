//
//  other_functions.hpp
//  StreamKMpp
//
//  Created by Wang Ziyin on 11/12/16.
//  Copyright © 2016 Wang Ziyin. All rights reserved.
//

#ifndef other_functions_hpp
#define other_functions_hpp

#include <stdio.h>

#include <stdio.h>
#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <ctime>


using namespace std;

int read_data(string file_name, vector<double *> &Data);
vector<string> string_split(string a, string del);


#endif /* other_functions_hpp */
