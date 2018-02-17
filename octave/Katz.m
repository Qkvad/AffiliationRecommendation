function [final]=Katz(A,A1,c)
  [V,D]=eig(A*A1);
  maxi=max(diag(D));
  beta=1/maxi * 0.1;  
  sum=0;
   for k=1:5
    sum=sum+(beta^k)*((A*A1)^k)*A;
   end
  [rowsum,colsum]=size(sum);
  for i=1:rowsum
    sorted=sort(sum(i,:),'descend');
    for j=1:c
      for k=1:colsum
        if sum(i,k)==sorted(j)
          final(i,j)=k;
          break
        end
      end
    end
  end