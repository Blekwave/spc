/* Problema 1542 do URI*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int q, d, p;
	int numberOfPages;

	while(!feof(stdin))  {
		scanf("%d %d %d", &q, &d, &p);
		if(q == 0)
			break;
		numberOfPages = ((-1)*q*p*d)/(q-p);
		if(numberOfPages == 1)
			printf("%d pagina\n", numberOfPages);
		else
		printf("%d paginas\n", numberOfPages);
	}
	return 0;
}