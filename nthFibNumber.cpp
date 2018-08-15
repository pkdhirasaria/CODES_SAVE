#define MOD 1000000007
#define ull unsigned long long
using namespace std;

void multiply(ull A[][2],ull M[][2])
{
    ull firstValue = ((A[0][0] * M[0][0])%MOD + ((A[0][1] * M[1][0])%MOD)%MOD);
	ull secondValue = ((A[0][0] * M[0][1])%MOD + ((A[0][1] * M[1][1])%MOD)%MOD);
	ull thirdValue = ((A[1][0] * M[0][0])%MOD + ((A[1][1] * M[1][0])%MOD)%MOD);
	ull fourthValue = ((A[1][0] * M[0][1])%MOD + ((A[1][1] * M[1][1])%MOD)%MOD);

	A[0][0] =firstValue;
	A[0][1] = secondValue;
	A[1][0] = thirdValue;
	A[1][1] = fourthValue;
}


void martixExponentiation(ull A[2][2],ull n)
{
    if(n == 1)
        return;
    martixExponentiation(A,n/2);
    multiply(A,A);
    if(n%2 != 0)
    {
        ull M[2][2] = {{1,1},{1,0}};
        multiply(A,M);
    }

}

ull getFib(ull n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    ull A[2][2] = {{1,1},{1,0}};
    martixExponentiation(A,n-1);
    return (A[0][0])%MOD;
}


unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
  	ull a = getFib(m+1);
  	ull b = getFib(n+2);
  	return (b-a+MOD)%MOD;
	// Write your code here
}

