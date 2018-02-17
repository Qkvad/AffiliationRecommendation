function [sum]=diff(v1,v2)
  [m,n]=size(v1);
  sum=0;
  for i=1:m
    sumv1=0;
    sumv2=0;
    for j=1:n
      sumv1=sumv1+v1(i,j);
      sumv2=sumv2+v2(i,j);
    end
    if sumv1==sumv2
      sum=sum+1;
    end
  end