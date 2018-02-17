A=mmread('../social_network/A.mtx');
[rows,cols] = size(A);

r_sq = round(sqrt(rows));

for i=1:rows
   crd(i,1) = round(i/r_sq);
   crd(i,2) = mod(i, r_sq);
 end
 
gplot(A,crd,"o-")