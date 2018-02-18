function [correct]=count_same(v1,v2,user)
  [m,n]=size(v1);
  % count for specific user
  if (user!=0)
    correct=0;
    for j=1:n
      for k=1:n
        if(v1(user,j) == v2(user,k))
          correct++;
          break;
        end
      end
    end
  else % count for all users
    for i=1:m
      correct(i)=0;
      for j=1:n
        for k=1:n
          if(v1(i,j) == v2(i,k))
            correct(i)++;
            break;
          end
        end
      end
    end
  end