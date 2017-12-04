# StreamKM++
This is an C++ implementation of StreamKM++ wrap with Matlab.

StreamKM++ is a popular clustering algorithm for data streams. It maintains a subset (known as "coreset") of the original dataset such that clustering on coreset is a good approximation of clustering on original dataset.

The detail of this algorithm is present in the following paper:
Ackermann, Marcel R., et al. "StreamKM++: A clustering algorithm for data streams." Journal of Experimental Algorithmics (JEA) 17 (2012): 2-4.


To compile with Matlab mex, run makefile.m

To call for clustering:

[c, a] = streamkm( D, K, m );


D: dataset, in the form of N x d.

K: number of clusters, like K-means.

m: bucket size, 100*K~2000*K is popularly used.

c: clustering centers.

a: clustering index.


Please feel free to use and let me know any issues. 
