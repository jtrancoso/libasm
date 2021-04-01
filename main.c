#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>

size_t	ft_strlen(char *s);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

void	test_strlen(char *s)
{
	printf("string:    %s\n", s);
	printf("strlen:    %zu\n", strlen(s));
	printf("ft_strlen: %zu\n", ft_strlen(s));
	printf("\n");
}

void	test_strcpy(char *dest, char *src)
{
	printf("src:       %s\n", src);
	printf("strcpy:    %s\n", strcpy(dest, src));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, src));
	printf("\n");
}

int main (void)
{
	char dest[255];
	char *aux;
	char *aux2;

	printf("\033[1;32m\n=============================\n");
	printf("========== FT_STRLEN ========\n");
	printf("=============================\n\n\033[0m");

	test_strlen("hola");
	test_strlen("");
	test_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");

	printf("\033[1;32m\n=============================\n");
	printf("========== FT_STRCPY ========\n");
	printf("=============================\n\n\033[0m");

	test_strcpy(dest, "hola");
	test_strcpy(dest, "");
	test_strcpy(dest, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");


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

	int true_errno = errno;
	int my_errno = errno;

	write(1, "\033[0mreal write: hola\n", 21);
	printf("true_errno: %d\n", true_errno);
	ft_write(1, "ft_write: hola\n", 16);
	printf("my_errno: %d\n", my_errno);
	perror("");

	write(1, "\n", 1);

	write(1, "", 1);
	ft_write(1, "", 1);

	write(1, "\n", 1);

	write(1, "real write: hiduqhdiuqwhdiqwhdiuwqdhqiudhqwiduhqwiwduhqwiduhqwiduhqwiduqwhdiuqwhdiuqwhwdi\n", 90);
	ft_write(1, "ft_write: hiduqhdiuqwhdiqwhdiuwqdhqiudhqwiduhqwiwduhqwiduhqwiduhqwiduqwhdiuqwhdiuqwhwdi\n\n", 89);


	printf("\033[1;32m\n=============================\n");
	printf("========== FT_READ ==========\n");
	printf("=============================\n\n\033[0m");

	char buffer[100];

	write(1, "\033[0mInsert text to read:\n> ", 28);
	read(1, buffer, 100);
	printf("Original: %s\n", buffer);
	ft_read(1, buffer, 100);
	printf("My read: %s\n", buffer);




	return (0);
}
