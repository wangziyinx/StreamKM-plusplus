//
//  StreamModel.hpp
//  StreamKMpp
//
//  Created by Wang Ziyin on 11/12/16.
//  Copyright © 2016 Wang Ziyin. All rights reserved.
//

#ifndef StreamModel_hpp
#define StreamModel_hpp

#include <stdio.h>
#include <vector>
#include <math.h>

#include "Coreset.hpp"
/*StreamModel.hpp and StreamModel.cpp implemented Merge-Reduce process
used in StreamKM++*/
using namespace std;


class Stream{
public:
    int N; // data size
    int m;
    int numB;
    int d;
    vector <vector <double *>> Buckets;
    
    Stream(int N_input, int m_input, int d_input){
        N=N_input;
        m=m_input;
        d=d_input;
        numB=(int) (log2(N/m)+2)+1;
        for (int i=0; i<numB; i++) {
            vector<double *> t;
            Buckets.push_back(t);
        }
    }
    
    void insert_points(double * p);
    void merge();
};

#endif /* StreamModel_hpp */
