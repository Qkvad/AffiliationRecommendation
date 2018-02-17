S=mmread('../social_network/S.mtx');
A1=mmread('../social_network/A.mtx');
A=A1';
[rows,cols] = size(S);

r_sq = round(sqrt(rows));

for i=1:rows
   crd(i,1) = round(i/r_sq);
   crd(i,2) = mod(i, r_sq);
 end
 
gplot(S,crd,"o-")