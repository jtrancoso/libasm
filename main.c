#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(char *);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);

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

	printf("dest: %s\n", dest);

	printf("strcpy:    %s\n", strcpy(dest, "hola"));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, "hola"));
	printf("\n");

	printf("strcpy:    %s\n", strcpy(dest, ""));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, ""));
	printf("\n");

	printf("strcpy:    %s\n", strcpy(dest, "olawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, "olawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("\n");

	printf("\033[4;32mFT_STRCMP\n\n\033[0m");
	printf("\033[4;37ms1 > s2\n\n\033[0m");
	printf("s1: h s2: a\n\n");
	printf("strcmp:    %d\n", strcmp("h", "a"));
	printf("ft_strcmp: %d\n", ft_strcmp("h", "a"));
	printf("\n");
	
	printf("\033[4;37m!s1 && s2\n\n\033[0m");
	printf("s1:  s2: a\n\n");
	printf("strcmp:   %d\n", strcmp("", "a"));
	printf("ft_strcmp: %d\n", ft_strcmp("", "a"));
	printf("\n");

	printf("\033[4;37ms1 == s2\n\n\033[0m");
	printf("s1: hola s2: hola\n\n");
	printf("strcmp:    %d\n", strcmp("hola", "hola"));
	printf("ft_strcmp: %d\n", ft_strcmp("hola", "hola"));
	printf("\n");

		
	printf("\033[4;37m!s1 && !s2\n\n\033[0m");
	printf("s1:  s2: \n\n");
	printf("strcmp:   %d\n", strcmp("", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("", ""));
	printf("\n");

	printf("\033[4;37ms1 < s2\n\n\033[0m");
	printf("s1: a s2: c\n\n");
	printf("strcmp:   %d\n", strcmp("a", "c"));
	printf("ft_strcmp: %d\n", ft_strcmp("a", "c"));
	printf("\n");

		
	printf("\033[4;37ms1 && !s2\n\n\033[0m");
	printf("s1: h s2: \n\n");
	printf("strcmp:   %d\n", strcmp("h", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("h", ""));
	printf("\n");
	//printf("ft_strcmp: %s\n", ft_strcpy(dest, "hola"));
	return (0);
}