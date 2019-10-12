#include <iostream>
#include <algorithm>
#define LICZBA_BOKOW 12
#define LICZBA_PUNKTOW 4

using namespace std;
/*
class test {
  
  int _wartosc[3];

  int operator[] (int Ind)const { return _wartosc[Ind];}
  int &operator[] (int Ind) { return _wartosc[Ind];}

  test(int x,int y,int z){
    _wartosc[0]=x;
    _wartosc[1]=y;
    _wartosc[2]=z;
}
}
   */
  /*
std::istream& operator >> (std::istream &Strm, test &Wek)
{
  for(int i=0;i<3;++i)
    std::cin>>Wek[i];
  return Strm;
}


std::ostream& operator << (std::ostream &Strm, const test &Wek)
{
  for(int i=0;i<3;++i)
    StrmWy<<std::setw(16)<<std::fixed<<std::setprecision(10)<< Wek[i];
  return Strm;
}
*/

void funkcja_testowa(int Wart[3])
{
  for(int i=0;i<3;++i)
    std::cout<<Wart[i]<<std::endl;
}

int main()
{
  // double tmp[LICZBA_BOKOW];
  double key;
  int n;  
  int tmp[12]={10,10,160,10,160,110,10,110,12,2,10,12};


  for(int i=0; i<LICZBA_BOKOW ; ++i) cout<<tmp[i]<<'\t';
  cout<<endl;

  //  for(int i=0;i<3;++i)
  //    sort(tmp + i*4*sizeof(double), tmp + i*4*sizeof(double));
sort(tmp , tmp + 4*sizeof(int));
//sort( tmp + 4*sizeof(double), tmp + 8*sizeof(double));
//sort( tmp + 8*sizeof(double), tmp + 12*sizeof(double));

  /*
for(int j,i=1;i<LICZBA_BOKOW;++i)
    {
      key=tmp[i];
      for(j=i-1;(j>=0)&&(tmp[j]<key);--j)
	tmp[j+1]=tmp[j];
      //      cout<<"j  "<<j<<'\t';
      tmp[j+1]=key;

      //      cout<<"i  "<<i<<'\t';
    }
  */  

  /*    
  int i,j;
  for(n=0;n<3;++n)
    {
    for(i=n*4+1;i<LICZBA_BOKOW*n/3;++i)
      {
	cout<<i<<'\t';
	key=tmp[i];
	for(j=i-1;(j>=0)&&(tmp[j]<key);--j)
	  tmp[j+1]=tmp[j];
	tmp[j+1]=key;
	cout<<i<<endl;
      }
    cout<<"n  "<<n<<endl;
    }
  */
  /*
  test Wek;

  for(int j=0,i=0;i<4;++i)
    for(j=0;j<3;++j)
      std::cin>>Wek[j][i];
  
  int Wek[3];
  for(int i=0;i<3;++i)
  cin>>Wek[i]; */

  for(int i=0; i<LICZBA_BOKOW ; ++i) cout<<tmp[i]<<'\t';
  
  //  funkcja_testowa({Wek[0],Wek[1],Wek[2]});
  


  return 0;
}

/*



*/
