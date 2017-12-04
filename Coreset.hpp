//
//  Coreset.hpp
//  StreamKMpp
//
//  Created by Wang Ziyin on 11/11/16.
//  Copyright © 2016 Wang Ziyin. All rights reserved.
//

#ifndef Coreset_hpp
#define Coreset_hpp

#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;

class cnode{
public:
//    int d; // dimension
    double * q; //representative
    double SSD;
    int d;
    
    cnode * parent;
    cnode * left;
    cnode * right;
    vector<double *> Points;
    
    void split();
    void computeSSD();
};


class CoreTree{
public:
    cnode * root;
    int d; //data dimension
    int n_leaf;
    int m; // size of coreset
    
    vector<double *> CoreSet;
    
    void TBuild(vector<double *> & P);
    void CoreSetExtract(cnode * r);
};


cnode * random_leaf(cnode * root);
void update_SSD(cnode * root);

double Dsqure(double * p, double * q, int d);
int KMpp_seed(vector<double *> & P, double * q, double SSD, int d);
#endif /* Coreset_hpp */




















