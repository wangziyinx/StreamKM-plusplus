//
//  Coreset.cpp
//  StreamKMpp
//
//  Created by Wang Ziyin on 11/11/16.
//  Copyright © 2016 Wang Ziyin. All rights reserved.
//

#include "Coreset.hpp"

//-----------------------------------------------------------------------
//                                  CoreTree
//-----------------------------------------------------------------------

void CoreTree:: TBuild(vector<double *> & P){
    int indx=rand() % P.size();
    root = new cnode ();
    root->q=P[indx];
    root->d=d;
    
    for (int i=0; i<P.size(); i++) {
        root->Points.push_back(P[i]);
    }
    root->computeSSD();
    
    
    n_leaf=1;
    for (int i=0; i<m-1; i++) {
        cnode * l=random_leaf(root);
        l->split();
        n_leaf++;
    }
    CoreSetExtract(root);
}

void CoreTree::CoreSetExtract(cnode * r){
    if (r==nullptr) {
        return;
    }
    if (r->left==nullptr || r->right==nullptr) {
        CoreSet.push_back(r->q);
    }
    else
    {
        CoreSetExtract(r->left);
        CoreSetExtract(r->right);
    }
}


cnode * random_leaf(cnode * root){
    if (root==nullptr) {
        return nullptr;
    }
    if (root->left==nullptr|| root->right==nullptr) {
        return root;
    }
    
    double w = (double)rand() / RAND_MAX;
    if (w<root->left->SSD/(root->SSD))
        return random_leaf(root->left);
    else
        return random_leaf(root->right);
}


//-----------------------------------------------------------------------
//                                  cnode
//-----------------------------------------------------------------------



void cnode::split(){
    int indx=KMpp_seed(Points, q , SSD, d);
    
    double * q2=Points[indx];
    
    left=new cnode ();
    right=new cnode();
    
    left->q=q;
    left->d=d;
    left->parent=this;
    right->q=q2;
    right->d=d;
    right->parent=this;
    
    for (int i=0; i<Points.size(); i++) {
        double disLeft=Dsqure(Points[i], left->q, d);
        double disRight=Dsqure(Points[i], right->q, d);
        if (disLeft>disRight) {
            right->Points.push_back(Points[i]);
            right->SSD+=disRight;
        }
        else
        {
            left->Points.push_back(Points[i]);
            left->SSD+=disLeft;
        }
    }
    
    Points.clear();
    update_SSD(this);
}


void update_SSD(cnode * root){
    if (root==nullptr) {
        return;
    }
    if (root-> left!=nullptr && root->right != nullptr) {
        root->SSD=root->left->SSD+root->right->SSD;
        
    }
    root=root->parent;
    update_SSD(root);
}

void cnode::computeSSD(){
    for (int i=0; i<Points.size(); i++) {
        SSD+=Dsqure(Points[i], q, d);
    }
}


//general
int KMpp_seed(vector<double *> & P, double * q, double SSD, int d){
    double r = (double)rand() / RAND_MAX;
    
    double S=0;
    for (int i=0; i<P.size(); i++) {
        S+=Dsqure(P[i], q, d);
        if (S/SSD>r) {
            return i;
        }
    }
    return (int)P.size()-1;
}

double Dsqure(double * p, double * q, int d){
    double s=0;
    for (int i=0; i<d; i++) {
        s+=(p[i]-q[i])*(p[i]-q[i]);
    }
    return s;
}

















