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

//3. Prime Factorization

void primeFact(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        int c = 0;
        while(n%i==0)
        {
            c++;
            n/=i;
        }
        cout<<i<<" "<<c<<endl;
    }
    if(n>1) cout<<n<<" "<<1<<endl;
} ///O(sqrt(n))

///4. Prime Factorization using Sieve
///   (For Pre Calculation)

const int  N = 100000;
vector<int> prime(N, -1);

void sieve_fact()
{
    for(int i = 2; i <= N; i++)
    {
        if(prime[i]==-1)
        {
            for(int j = i; j <= N; j+=i)
            {
                if(prime[j]==-1)
                {
                    prime[j] = i;
                }
            }
        }
    }
}
void primeFactusingSieve(int n)
{
    while(n != -1)
    {
        if(prime[n]==-1) break;
        cout<<prime[n]<<" ";
        n/=prime[n];
    }
}

/// 5. Modular Exponential
// Calculates a^p % m
int power(int a, int p, int m)
{
    int res = 1;
    while(p)
    {
        if(p%2)
        {
            res = (res * a) % m;
            p--;
        }
        else
        {
            p /= 2;
            b = (a*a) % m;
        }
    }
    return res;
} //O(logn)

///6. Euler Totient Function

int phi(int n)
{
    int res = n;
    for(int i = 2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            res/=i;
            res*=(i-1);
            while(n%i==0) n/=i;
        }
    }

    if(n>1)
    {
        res/=n;
        res*=(n-1);
    }
    return res;
} //O(sqrt(n))

///Euler Totient function returns the number of positive integer upto n which is co prime to n [gcd = 1]

///Euler Totient Function Sieve
int N = 1000;
vector<int> phi(n);

void phi_sieve()
{
    for(int i = 1; i<=N; i++)
    {
        phi[i] = i;
    }
    for(int i = 2; i<=N; i++)
    {
        if(phi[i]==i)
        {
            for(int j = i; j<=N; j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1)
            }
        }
    }
} //O(nlog log n)

///Linear Diophantine Equation, Extended GCD

int extended_gcd(int a, int b, int *x, int *y)
{
    if(a==0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
bool linear_diophantine(int a, int b, int c, int *x, int *y)
{
    int x0, y0;
    int g = extended_gcd(abs(a), abs(b), &x0, &y0);
    if(c % g) return false;
    *x = x0 * (c/g);
    *y = y0 * (c/g);

    if(a < 0) *x = - *x;
}









