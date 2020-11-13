#include<stdio.h>
#include <unordered_map>
using namespace std;

#define uint64_t unsigned long long int

uint64_t f(uint64_t a, uint64_t b, uint64_t c)
{
	if(!b) return 1;
	if(b==1) return a%c;
	
	uint64_t l = f(a, b/2, c);
	if(b%2) return (((l * l) %c) * a) %c;
	else return (l*l) % c;
}

int main()
{
	uint64_t a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	printf("%lld",f(a,b,c));
	return 0;
}
