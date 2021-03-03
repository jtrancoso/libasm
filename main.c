#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(char *);
char	*ft_strcpy(char *dest, char *src);
int		strcmp(const char *s1, const char *s2);

int main (void)
{
	char dest[200];

	printf("\033[4;32mFT_STRLEN\n\n\033[0m");
	printf("string:    hola\n");
	printf("strlen:    %zu\n", strlen("hola"));
	printf("ft_strlen: %zu\n", ft_strlen("hola"));
	printf("\n");	

	printf("string:\n");
	printf("strlen:    %zu\n", strlen(""));
	printf("ft_strlen: %zu\n", ft_strlen(""));
	printf("\n");

	printf("string:    holawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev\n");
	printf("strlen:    %zu\n", strlen("holawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("ft_strlen: %zu\n", ft_strlen("holawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("\n");

	printf("\033[4;32mFT_STRCPY\n\n\033[0m");
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