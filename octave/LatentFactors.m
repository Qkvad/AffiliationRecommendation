function [final] = LatentFactors (A,A1,S,lambda,d)
  [nu,ng] = size(A);
  C1 = zeros(nu+ng,nu+ng);
  C1(1:nu, 1:nu) = lambda * S;
  C1(1:nu, nu+1:nu+ng) = A;
  C1(nu+1:nu+ng, 1:nu) = A1;
  [U,sigma,V] = svd(C1);
  final = U(1:nu,1:d)*sigma(1:d,1:d)*V(nu+1:nu+ng,1:d).';
endfunction
