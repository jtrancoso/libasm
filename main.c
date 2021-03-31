#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*void	*malloc(size_t a)
{
	return (NULL);
}

void	free(void *ptr)
{
	;
}*/

size_t	ft_strlen(char *);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

int main (void)
{
	char dest[200];
	char *aux;
	char *aux2;

	printf("\033[1;32m\n=============================\n");
	printf("========== FT_STRLEN ========\n");
	printf("=============================\n\n\033[0m");

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

	printf("\033[1;32m\n=============================\n");
	printf("========== FT_STRCPY ========\n");
	printf("=============================\n\n\033[0m");

	printf("dest: %s\n\n", dest);

	printf("strcpy:    %s\n", strcpy(dest, "hola"));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, "hola"));
	printf("\n");

	printf("strcpy:    %s\n", strcpy(dest, ""));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, ""));
	printf("\n");

	printf("strcpy:    %s\n", strcpy(dest, "olawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, "olawqudgweoudgvewyuvewcyewvcyiveiwcvwecvwcuewvcwVCWEYtcvwIYCTVewoucvweiycveOFGFYGFUGO8FGWEOUCvwcuwevcuwevcwegcvwycgvwecyvwcyewgvcwev"));


	printf("\033[1;32m\n=============================\n");
	printf("========== FT_STRCMP ========\n");
	printf("=============================\n\n\033[0m");

	printf("s1: \xff\xff s2: \xff\n");
	printf("strcmp:    %d\n", strcmp("\xff\xff", "\xff"));
	printf("ft_strcmp: %d\n", ft_strcmp("\xff\xff", "\xff"));
	printf("\n");
	printf("\033[4;37ms1 > s2\n\n\033[0m");
	printf("s1: holaz s2: hola\n\n");
	printf("strcmp:    %d\n", strcmp("holaz", "holai"));
	printf("ft_strcmp: %d\n", ft_strcmp("holaz", "holai"));
	printf("\n");
	
	printf("\033[4;37m!s1 && s2\n\n\033[0m");
	printf("s1:  s2: a\n\n");
	printf("strcmp:    %d\n", strcmp("", "a"));
	printf("ft_strcmp: %d\n", ft_strcmp("", "a"));
	printf("\n");

	printf("\033[4;37ms1 == s2\n\n\033[0m");
	printf("s1: holahdaiudhqiudhqwiduqwhdiuqhd s2: holahdaiudhqiudhqwiduqwhdiuqhd\n\n");
	printf("strcmp:    %d\n", strcmp("holahdaiudhqiudhqwiduqwhdiuqhd", "holahdaiudhqiudhqwiduqwhdiuqhd"));
	printf("ft_strcmp: %d\n", ft_strcmp("holahdaiudhqiudhqwiduqwhdiuqhd", "holahdaiudhqiudhqwiduqwhdiuqhd"));
	printf("\n");

		
	printf("\033[4;37m!s1 && !s2\n\n\033[0m");
	printf("s1:  s2: \n\n");
	printf("strcmp:    %d\n", strcmp("", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("", ""));
	printf("\n");

	printf("\033[4;37ms1 < s2\n\n\033[0m");
	printf("s1: hola s2: holc\n\n");
	printf("strcmp:    %d\n", strcmp("hola", "holc"));
	printf("ft_strcmp: %d\n", ft_strcmp("hola", "holc"));
	printf("\n");

		
	printf("\033[4;37ms1 && !s2\n\n\033[0m");
	printf("s1: hola s2: \n\n");
	printf("strcmp:    %d\n", strcmp("hola", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("hola", ""));

	printf("\033[1;32m\n=============================\n");
	printf("========== FT_STRDUP ========\n");
	printf("=============================\n\n\033[0m");

	aux = strdup("hola");
	printf("strdup: %s\n", aux);
	perror(0);

	aux2 = ft_strdup("hola");
	printf("ft_strdup: %s\n", aux2);
	perror(0);

	printf("\n");

	aux = strdup("");
	printf("strdup: %s\n", aux);
	perror("");
	aux2 = ft_strdup("");
	printf("ft_strdup: %s\n", aux2);
	perror("");
	printf("\n");

	aux = strdup("iuifhweiuvbaiuvbarvoyerbvoaerybvaeoruvybaeorvubaroivuabreiuvabrepiuvbaepryvbaeoruvbareuvybaeoruvyboaeoruvybaeoruvybaeoruvybaerouvybaeoruy");
	printf("strdup: %s\n", aux);
	perror("");
	//free (aux);
	aux2 = ft_strdup("iuifhweiuvbaiuvbarvoyerbvoaerybvaeoruvybaeorvubaroivuabreiuvabrepiuvbaepryvbaeoruvbareuvybaeoruvyboaeoruvybaeoruvybaeoruvybaerouvybaeoruy");
	printf("ft_strdup: %s\n", aux2);
	perror("");
	free(aux2);
	printf("\n");

	printf("\033[1;32m\n=============================\n");
	printf("========== FT_WRITE =========\n");
	printf("=============================\n\n\033[0m");

	write(1, "\033[0mreal write: hola\n", 21);
	ft_write(1, "ft_write: hola\n\n", 16);

	write(1, "", 1);
	ft_write(1, "", 1);

	write(1, "real write: hiduqhdiuqwhdiqwhdiuwqdhqiudhqwiduhqwiwduhqwiduhqwiduhqwiduqwhdiuqwhdiuqwhwdi\n", 90);
	ft_write(1, "ft_write: hiduqhdiuqwhdiqwhdiuwqdhqiudhqwiduhqwiwduhqwiduhqwiduhqwiduqwhdiuqwhdiuqwhwdi\n\n", 89);




	return (0);
}