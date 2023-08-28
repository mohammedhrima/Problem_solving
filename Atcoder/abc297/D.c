/*
A > B -> A = A - B 
A < B -> B = B - A
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
	int64_t	l;
	int64_t	r;
	int64_t	t;

	scanf("%lld", &l);
	scanf("%lld", &r);
	t = 0;
	while(l != r)
	{
		if (l < r)
		{
			int64_t tmp = l;
			l = r;
			r = tmp;
		}
		if(l > r)
		{
			int64_t nl =  l % r == 0 ? r : l % r ;
			t += (l % r == 0 ? (l - r) / r : (l - nl) / r);
			l = nl;
		}
		//printf("loop");
	}
	printf("%lld\n", t);
}