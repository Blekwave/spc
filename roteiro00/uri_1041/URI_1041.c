/* Problema 1041 do URI*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	float first_coordinate, second_coordinate;

	scanf("%f %f", &first_coordinate, &second_coordinate);

	if(first_coordinate == 0.0)  {
		if(second_coordinate == 0.0)
			printf("Origem\n");
		else
			printf("Eixo Y\n");
	}
	else  {
		if(second_coordinate == 0.0)
			printf("Eixo X\n");
		if(first_coordinate > 0.0 && second_coordinate > 0.0)
			printf("Q1\n");
		if(first_coordinate < 0.0 && second_coordinate > 0.0)
			printf("Q2\n");
		if(first_coordinate < 0.0 && second_coordinate < 0.0)
			printf("Q3\n");
		if(first_coordinate > 0.0 && second_coordinate < 0.0)
			printf("Q4\n");
	}

	return 0;
}