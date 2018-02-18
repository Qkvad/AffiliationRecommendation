S=mmread('../social_network/S.mtx');
A1=mmread('../social_network/A.mtx');
A=A1';
printf("Matrices A and S loaded\n");

[rows,cols] = size(S);
r_sq = round(sqrt(rows));
for i=1:rows
  crd(i,1) = round(i/r_sq);
  crd(i,2) = mod(i, r_sq);
end
gplot(S,crd,"o-")
printf("User friendship graph drawn\n");

num_of_recomendations = input("Type how many recomendations: ");

katz_result = Katz(A,A1,num_of_recomendations);
katzC_result = KatzC(A,A1,S,0.2,num_of_recomendations);
latent_result = LatentFactors(A,A1,S,0.2,rows,num_of_recomendations);
printf("Model results stored\n");

katz_katzC_similarity = count_same(katz_result,katzC_result,0);
katz_katzC_similarity_measure = count_same_measure(katz_katzC_similarity,num_of_recomendations)

katz_latent_similarity = count_same(katz_result,latent_result,0);
katz_latent_similarity_measure = count_same_measure(katz_latent_similarity,num_of_recomendations)

latent_katzC_similarity = count_same(latent_result,katzC_result,0);
latent_katzC_similarity_measure = count_same_measure(latent_katzC_similarity,num_of_recomendations)
