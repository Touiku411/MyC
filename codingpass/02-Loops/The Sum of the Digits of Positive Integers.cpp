#include <iostream>
using namespace std;

int sumDigits( int number )
{
  int sum =0;
  while(number>0){
    sum+=number%10;
  	number/=10;
  }
  return sum;
}
int main()
{
   int numCases;
   cin >> numCases;
   for( int i = 1; i <= numCases; i++ )
   {
      int n;
      cin >> n;

      cout << sumDigits( n ) << endl;
   }
}

