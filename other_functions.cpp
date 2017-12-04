//
//  other_functions.cpp
//  StreamKMpp
//
//  Created by Wang Ziyin on 11/12/16.
//  Copyright © 2016 Wang Ziyin. All rights reserved.
//

#include "other_functions.hpp"

int read_data(string file_name, vector<double *> &Data){
    
    ifstream data_points;
    data_points.open(file_name);
    
    int dim = 0;
    string line;
    while (getline(data_points,  line)) {
        //        cout<<line<<endl;
        vector<string> string_segs=string_split(line," ");
        if (string_segs.size()<1) {
            break;
        }
        double * this_point= new double[string_segs.size()];
        
        dim=(int)string_segs.size();
        for (int i=0; i<string_segs.size(); i++) {
            this_point[i]=stod(string_segs[i]);
        }
        Data.push_back(this_point);
    }
    
    data_points.close();
    return dim;
}


vector<string> string_split(string a, string del){
    char *p=new char[a.size()+1];
    char *d=new char[del.size()+1];
    
    //    char *del=new char[del_str.size()+1];
    int i=0;
    //    int number_of_item;
    vector<string> string_seg;
    
    strcpy(p,a.c_str());
    strcpy(d,del.c_str());
    //    number_of_item=number_of_char(a, del)+1;
    
    
    char *tokenPtr=strtok(p, d);
    while(tokenPtr!=NULL) {
        string_seg.push_back((string)tokenPtr);
        i++;
        tokenPtr=strtok(NULL, d);
    }
    return string_seg;
}
