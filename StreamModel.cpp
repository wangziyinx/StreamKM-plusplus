//
//  StreamModel.cpp
//  StreamKMpp
//
//  Created by Wang Ziyin on 11/12/16.
//  Copyright © 2016 Wang Ziyin. All rights reserved.
//

#include "StreamModel.hpp"



void Stream::insert_points(double * p){
    
    
    if (Buckets[0].size()==m)
        merge();
        
    Buckets[0].push_back(p);
    
}


void Stream:: merge(){
    //merging is always starts from Buckets[0]
    vector<double *> S= Buckets[0];
    Buckets[0].clear();
    
    int i=1;
    while (Buckets[i].size()!=0) {
        CoreTree T;
        T.d=d;
        T.m=m;
        vector<double *> U;
        U.reserve(2*m);
        U.insert(U.end(), S.begin(), S.end());
        U.insert(U.end(), Buckets[i].begin(), Buckets[i].end());
        
        T.TBuild(U);
        S.clear();
        S=T.CoreSet;
        Buckets[i].clear();
        i++;
    }
    Buckets[i]=S;
}









