#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void populate_sieve(bool *sieve, int n)
{
  int s = (int)sqrt(n);
  sieve[0] = 0;
  sieve[1] = 0;
  sieve[2] = 0;
  for (int i = 2; i <= s; i++)
  {
    if (!sieve[i])
    {
      //i is prime so mark all composites having i as factor
      for (int j = i * i; j <= n; j += i)
      { //for 3 we will start marking from 9 as 6 was marked by 2
        sieve[j] = true;
      }
    }
  }
}

void get_prime_factorization(int n, vector<int> &primes, vector<int> &factorization)
{
  if (n < 2)
  {
    return;
  }
  int prime;
  for (int i = 0; i < primes.size(); i++)
  {
    prime = primes[i];
    while (n>1 && n % prime == 0)
    {
      factorization.push_back(prime);
      n /= prime;
      if(n<=1){
        break;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  /* code */
  int n;
  cin >> n;
  bool sieve[n + 1];
  populate_sieve(sieve, n);

  vector<int> primes;
  cout << "primes till n: " << n << "\n";
  for (int i = 2; i <= n; i++)
  {
    if (!sieve[i])
    {
      primes.push_back(i);
      cout << i << " ";
    }
  }
  cout << "\n";

  cout << "Prime factorization of n: " << n << "\n";
  vector<int> factors;
  get_prime_factorization(n, primes, factors);
   for (int i = 0; i < factors.size(); i++){
     cout << factors[i] << " ";
   }
   cout << "\n";
  return 0;
}
