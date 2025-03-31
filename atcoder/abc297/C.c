#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char **array;
	int H;
	int W;

	scanf("%d %d", &H, &W);
	array = calloc(H + 1, sizeof(char*));
	for(int i = 0; i < H; i++)
	{
		array[i] = calloc(W + 1, sizeof(char));
		scanf("%s", array[i]);
		char *str = array[i];
		for(int j = 0; j < W - 1; j++)
		{
			if(str[j] == 'T' && str[j + 1] == 'T')
			{
				str[j] = 'P';
				str[j + 1] = 'C';
			}
		}
	}
	for(int i = 0; i < H; i++)
	{
		printf("%s\n", array[i]);
	}
}