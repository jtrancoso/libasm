#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(char *);
char	*ft_strcpy(char *dest, char *src);

int main (void)
{
	char dest[200];

	printf("FT_STRLEN\n\n");
	printf("strlen:    %zu\n", strlen("holaa"));
	printf("ft_strlen: %zu\n", ft_strlen("holaa"));
	printf("\n");	

	printf("strlen:    %zu\n", strlen(""));
	printf("ft_strlen: %zu\n", ft_strlen(""));
	printf("\n");

	printf("strlen:    %zu\n", strlen("holawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("ft_strlen: %zu\n", ft_strlen("holawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("\n");

	printf("FT_STRCPY\n\n");
	printf("strcpy:    %s\n", strcpy(dest, "hola"));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, "hola"));
	printf("\n");

	printf("strcpy:    %s\n", strcpy(dest, ""));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, ""));
	printf("\n");


	printf("strcpy:    %s\n", strcpy(dest, "olawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, "olawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("\n");

	return (0);
}