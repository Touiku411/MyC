#include<iostream>
using namespace std;

// returns the sum of the k-th powers of digits of n.
int sumPowerDigits( int n, int k )
{
  int sum=0;
  while(n>0){
    sum+=pow(n%10,k);
  	n/=10;
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

      int numDigits = 0; // the number of digits of n
      for( int i = n; i > 0; i /= 10 )
         numDigits++;

      if( n == sumPowerDigits( n, numDigits ) )
         cout << "Armstrong" << endl;
      else
         cout << "Not Armstrong" << endl;
   }
}



