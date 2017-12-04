function [ c,a ] = streamkm( D, K, m )

B=stkmpp(D', m);

% [c,a]=vl_kmeans(B',K,'Initialization', 'plusplus');
% c=c';

[a,c] = kmeans(D,K);
end

