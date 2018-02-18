# Affiliation Recomendation

Note that current state of README.md file is relatively poor. Soon it will not be.

## Social Network
We built our own social network due to restrictions on existing ones. Everything related to the social netowork is in social-network/.
config.h contains basic configuration of network, such as `NUMBER_OF_USERS` and `NUMBER_OF_GROUPS`. Change this as you please while testing.

#### Build
```
g++ -std=c++11 main.cpp Person.cpp Group.cpp -o m
```
#### Run
```
./m
```

## Octave
Everything related to the work in Octave is in octave/. Run `main` while in Octave command window to see user by user graph depiction.
User by user matrix is saved as `S`, group by user matrix is saved as `A` and its transpose is saved as `A1`. 

### Graph proximity model
To get the Katz measure of co-occurence matrix `AA'` call function `Katz(A,A1,c)`, where `c` is the number of desired group recommendations.
To get the Katz measure of combined adjacency matrix `C` call function `KatzC(A,A1,S,lambda,c)`, where `c` is the number of desired group recommendations, and `lambda` is a parametar that controls ratio of the weight of friendship to the weight of group membership (usualy used is `lambda=0.2`).

## Tex
Everything related to the work in tex is in tex/.


