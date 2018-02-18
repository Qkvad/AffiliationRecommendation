function [final]=KatzC(A,A1,S,lambda,c)
  [V,D]=eig(A*A1);
  maxi=max(diag(D));
  beta=1/maxi * 0.1;
  sum=beta*A;
  sum=sum+beta*beta*lambda*S*A;
   for k=3:5
    sum=sum + (beta^k)*( (lambda^(k-1))*(S^(k-1))*A + ((A*A1)^(k-2))*A ) ;
   end
   [rowsum,colsum]=size(sum);
   for i=1:rowsum
    [sorted,index]=sort(sum(i,:),'descend');
    for j=1:c
      final(i,j)=index(j);
    end
  end
     
     