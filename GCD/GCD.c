#include <stdio.h>
#include <stdint.h>

long long int gcd(long long int a, long long int b);

int main(void){
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", gcd(a, b));
	return 0;
	}

long long int gcd(long long int a, long long int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}