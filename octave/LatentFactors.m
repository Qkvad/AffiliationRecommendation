#Test with d << number of groups

function [final] = LatentFactors (A,A1,S,lambdaS,lambdaD,d,c)
  [nu,ng] = size(A);
  C1 = zeros(nu+ng,nu+ng);
  C1(1:nu, 1:nu) = lambdaS * S;
  C1(1:nu, nu+1:nu+ng) = A;
  C1(nu+1:nu+ng, 1:nu) = A1;
  C1(nu+1:nu+ng,nu+1:nu+ng) = lambdaD*(A.'*A);
  [U,sigma,V] = svd(C1);
  Capprox = U(1:nu,1:d)*sigma(1:d,1:d)*V(nu+1:nu+ng,1:d).';
  [rowsum,colsum]=size(Capprox);
  for i=1:rowsum
    [sorted,index]=sort(Capprox(i,:),'descend');
    for j=1:c
      final(i,j)=index(j);
    end
  end
endfunction
