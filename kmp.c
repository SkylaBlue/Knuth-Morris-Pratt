#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains(char *substr, char *string)
{
	int strSize = strlen(string)-1, substrSize = strlen(substr)-1;
	if (strSize < 1 || substrSize < 1) { return -1; }
	
	int i, j, found = 0;
	int k = strSize, h = substrSize;
	
	for (i = 0; i < strSize, k > 0; i++, k--)
	{
		for (j = 0; j < substrSize, h > 0; j++, h--)
		{	
			if (string[i] == substr[j] && string[i+1] == substr[j+1] && string[i] != string[i+i])
			{	
			    found++;
				while (string[i++] == substr[j++])
				{	
					found++;
					if (string[i] != substr[j])
					{
						j = 0;
						found = 0;
						i++;
						break;
					}
					
					if (found == substrSize+1)
					{
						printf("Found using forward search.\n");
						return i;
					}
				}
				// Break from for loop 
				break;
			}
			
			
			else if (string[k] == substr[h] && string[k-1] == substr[h-1] && string[k] != string[k-k])
			{
			    found++;
				while (string[k--] == substr[h--])
				{	
					found++;
					if (string[k] != substr[h])
					{
						found = 0;
						h = substrSize+1; // Reset h
						j--;
						break;
					}
					
					if (found == substrSize+1)
					{
						printf("Found using backward search");
						return i;
					}
				}
				// Break from for loop 
				break;
			}
			
			else
			{
				// Reset substr length
				j = 0;
				h = substrSize+1;
				i++;
				break;
			}
		}
	}
	
	return -1; // Nothing found
}

int main()
{
	char str[] = "AaaaaabbbbbbbbbbbccccccccddddddddeeeeeeeeeeeffffffffffffffgggggggggggggggghhhhhhhhhhhhiiiiiiiiiiiiiiijjjjjjjjjjjjkkkkkkkkkkkkkkkllllllllllllmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnoooooooooooooopppppppppppqqqqqqqqqqqqqqqqqrrrrrrrrrTestrrrrrrrrrrssssssssssssssstttttttttttttttttuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzz";
	char word[] = "Test";
	int position = contains(word, str)-(strlen(word)-1);

	if (position < 1)
	{
		printf("Not found");
		return 1;
	}
	
	printf("Position: %i", position);
	return 0;
}
