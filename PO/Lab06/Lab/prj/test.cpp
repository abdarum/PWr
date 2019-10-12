#include <iostream>
#include <cmath>

int main()
{

  for(int i=1;i<5;++i)
    {
      std::cout<<"  "<<i-1<<"  "<<i%4<<std::endl;
    }

  std::cout<<std::endl;

   for(int i=0;i<4;++i)
    {
      std::cout<<"  "<<i<<"  "<<(i==3?0:i+1)<<std::endl;
    }


  return 0;
}
