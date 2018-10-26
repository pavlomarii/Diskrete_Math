#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int p, q, r;
	do
	{
		printf("Choose int(1 or 0) for p\np = ");
		p = GetInt();
	}
	while (p < 0 || p > 1);
	do
	{
		printf("Choose int(1 or 0) for q\nq = ");
		q = GetInt();
	}
	while (q < 0 || q > 1);
	do
	{
		printf("Choose int(1 or 0) for r\nr = ");
		r = GetInt();
	}
	while (p < 0 || p > 1);
	bool result;
	result = (!(p||!q)||(!(q&&!r)||(p||(q==r))));
	printf("Result is %i\n", result);
}