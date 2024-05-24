#include <bits/stdc++.h>
using namespace std;



// Number Theory:
// 1.	Prime check:
bool isPrime(int n){
    if(n==1) return false;
    for(int i =2; i*i<=n; i++)
    {
        if(n%i==0) 
return false;
    }
    return true;
} //O(sqrt (n) )

// 2.	Sieve Of Eratosthenes
const int N = 1e5;
vector<int> prime(N, 1);
void sieve()
{
    prime[0] = prime[1] = 0;
    for(int i=2; i*i<=N; i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=N; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
}

