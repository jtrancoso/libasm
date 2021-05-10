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
	int real;
	int mine;

	real = strlen(s);
	mine = ft_strlen(s);
	printf("string:    %s\n", s);
	printf("strlen:    %zu\n", strlen(s));
	printf("ft_strlen: %zu\n", ft_strlen(s));
	if (mine == real)
		printf("\033[1;32m[OK]\n\n\033[0m");
	else
		printf("\033[1;31m[KO]\n\n\033[0m");
}

void	test_strcpy(char *src)
{
	char dest[255];

	char *real;
	char *mine;

	real = strcpy(dest, src);
	mine = ft_strcpy(dest, src);
	printf("src:       %s\n", src);
	printf("strcpy:    %s\n", strcpy(dest, src));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, src));
	if (mine == real)
		printf("\033[1;32m[OK]\n\n\033[0m");
	else
		printf("\033[1;31m[KO]\n\n\033[0m");
}

void	test_strcmp(char *s1, char *s2)
{
	int	real;
	int	mine;

	real = strcmp(s1, s2);
	mine = ft_strcmp(s1, s2);
	printf("s1: %s s2: %s\n", s1, s2);
	printf("strcmp:    %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	if (mine == real)
		printf("\033[1;32m[OK]\n\n\033[0m");
	else
		printf("\033[1;31m[KO]\n\n\033[0m");
}

void	test_strdup(char *src)
{
	char *real;
	char *mine;
	int true_errno;
	int my_errno;
	

	printf("string:          %s\n", src);
	real = strdup(src);
	true_errno = errno;
	printf("strdup:          %s\n", real);
	printf("errno:           %d\n", true_errno);
	perror(0);

	mine = ft_strdup(src);
	my_errno = errno;
	printf("ft_strdup:       %s\n", mine);
	printf("my_errno:        %d\n", my_errno);
	perror(0);
	if (ft_strcmp(real, mine) == 0 && true_errno == my_errno)
		printf("\033[1;32m[OK]\n\n\033[0m");
	else
		printf("\033[1;31m[KO]\n\n\033[0m");
	if (real)
		free(real);
	if (mine)
		free(mine);
	errno = 0;

}

void	test_write(int fd, char *str)
{
	int true_errno;
	int my_errno;
	int real;
	int original_errno;
	ssize_t mine;
	ssize_t mine_errno;


	if (strchr(str, '\n'))
	{
		write(1, "\033[0mreal write: ", 16);
		real = write(fd, str, ft_strlen(str));
		true_errno = errno;
		printf("real errno: %d\n", true_errno);
		ft_write(1, "ft_write:   ", 12);
		mine = ft_write(fd, str, ft_strlen(str));
		my_errno = errno;
		printf("my errno:   %d\n", my_errno);
		perror(0);
		errno = 0;
	}
	else
	{
		write(1, "\033[0mreal write: ", 16);
		real = write(fd, str, ft_strlen(str));
		true_errno = errno;
		write(1, "\n", 1);
		printf("real errno: %d\n", true_errno);
		ft_write(1, "ft_write:   ", 12);
		mine = ft_write(fd, str, ft_strlen(str));
		my_errno = errno;
		write(1, "\n", 1);
		printf("my errno:   %d\n", my_errno);
		perror(0);
		errno = 0;
	}
	if (mine == real && true_errno == my_errno)
		printf("\033[1;32m[OK]\n\n\033[0m");
	else
		printf("\033[1;31m[KO]\n\n\033[0m");

}

void	test_read(int fd)
{
	char buffer[1024];
	int	true_errno;
	int	my_errno;
	int i;
	ssize_t real;
	ssize_t mine;

	write(1, "\033[0mInsert text to read:\n> ", 27);
	real = read(fd, buffer, 1024);
	true_errno = errno;
	printf("\nOriginal: %s", buffer);
	printf("errno(%d)\n", true_errno);
	perror(0);
	write(1, "\n", 1);
	write(1, "Insert text to ft_read:\n> ", 26);
	mine = ft_read(fd, buffer, 1024);
	my_errno = errno;
	printf("\nMy read: %s", buffer);
	printf("errno(%d)\n", my_errno);
	perror(0);
	if (mine == real && true_errno == my_errno)
		printf("\033[1;32m[OK]\n\n\033[0m");
	else
		printf("\033[1;31m[KO]\n\n\033[0m");
	errno = 0;
}

int main (void)
{
	printf("\033[1;34m\n=============================\n");
	printf("========== FT_STRLEN ========\n");
	printf("=============================\n\n\033[0m");

	test_strlen("hola");
	test_strlen("");
	test_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");

	printf("\033[1;34m\n=============================\n");
	printf("========== FT_STRCPY ========\n");
	printf("=============================\n\n\033[0m");

	test_strcpy("hola");
	test_strcpy("");
	test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");


	printf("\033[1;34m\n=============================\n");
	printf("========== FT_STRCMP ========\n");
	printf("=============================\n\n\033[0m");

	test_strcmp("\xff\xff", "\xff");
	test_strcmp("hola", "hola");
	test_strcmp("h", "hh");
	test_strcmp("", "");

	printf("\033[1;34m\n=============================\n");
	printf("========== FT_STRDUP ========\n");
	printf("=============================\n\n\033[0m");

	test_strdup("hola");
	test_strdup("");
	test_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");

	printf("\033[1;34m\n=============================\n");
	printf("========== FT_WRITE =========\n");
	printf("=============================\n\n\033[0m");

	test_write(1, "test\n");
	test_write(-1, "\0test\n");
	test_write(2, "");
	test_write(2, "\0ignore fully me");
	test_write(2, "\0\0\0");
	test_write(2, " ");

	printf("\033[1;34m\n=============================\n");
	printf("========== FT_READ ==========\n");
	printf("=============================\n\n\033[0m");

	test_read(1);
	test_read(-3);
	
	return (0);
}
