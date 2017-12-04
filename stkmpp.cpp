#include "stkmpp.hpp"

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
/* variable declarations here */
double m;      /* input scalar */

double *D;     /* data is store in colunm*/

mwSize dim;  
mwSize N;


/* get input */
D=mxGetPr(prhs[0]);
N=mxGetN(prhs[0]);
dim=mxGetM(prhs[0]);

m=mxGetScalar(prhs[1]);



// /* code here */



    vector<double * > Data;
    matrix2vector(D, N, dim, Data);
    Stream M(Data.size(), m, dim);
    
    
    for (int i=0; i<Data.size(); i++) {
        M.insert_points(Data[i]);
    }
    
//     ofstream f;
//     f.open ("/Users/WangZiyin/Desktop/c.txt");
//     for (int i=0; i<M.numB; i++) {
//         for (int j=0; j<M.Buckets[i].size(); j++) {
//             for (int k=0; k<M.d; k++) {
//                 f<< M.Buckets[i][j][k]<<' ';
//             }
//             f<<endl;
//         }
//     }
//     
//     f.close();

    
    
    
    vector <double *> CC;
    for (int i=0; i< M.Buckets.size(); i++){
        
        CC.insert(CC.end(), M.Buckets[i].begin(), M.Buckets[i].end());
    }


plhs[0] = mxCreateDoubleMatrix(CC.size(), dim, mxREAL);
double * outMatrix = mxGetPr(plhs[0]);
vector2matrix(outMatrix, CC.size() ,dim, CC);
}



void matrix2vector(double * M,  mwSize N, mwSize dim, vector < double * > & D ){
    mwSize i;
    for (i=0; i<N; i++){
        D.push_back(&M[i*dim]);
    }
}

void vector2matrix(double * M, mwSize N, mwSize dim, vector <double *> &D){
    mwSize i,j;
   
    for (i=0; i<dim; i++)
        for (j=0; j<N; j++)
            M[i*N+j]=D[j][i];
}




