#Test with d << number of groups

function [final] = ProbabilisticCollaborativeFilteringModel (A,d,c)
  [nu,ng] = size(A);
  [U,sigma,V] = svd(A);
  Aapprox = U(:,1:d)*sigma(1:d,1:d)*V(:,1:d).';
  [rowsum,colsum]=size(Aapprox);
  for i=1:rowsum
    [sorted,index]=sort(Aapprox(i,:),'descend');
    for j=1:c
      final(i,j)=index(j);
    end
  end
endfunction
