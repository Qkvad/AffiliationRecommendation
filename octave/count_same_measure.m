function [measure]=count_same_measure(result,max_same)
  [r,c] = size(result);
  max_sames = max_same*ones([1,c]);
  measure = norm(max_sames - result)/norm(max_sames);