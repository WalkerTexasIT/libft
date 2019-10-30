#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../libft/libft.h"

// gcc test.c ../libft/ft_memset.c ../libft/ft_strdup.c ../libft/ft_strncmp.c ../libft/ft_isdigit.c ../libft/ft_strlcpy.c ../libft/ft_strlcat.c ../libft/ft_strnstr.c ../libft/ft_atoi.c ../libft/ft_bzero.c ../libft/ft_memcpy.c ../libft/ft_memccpy.c ../libft/ft_memmove.c ../libft/ft_memchr.c ../libft/ft_memcmp.c ../libft/ft_strlen.c ../libft/ft_strchr.c ../libft/ft_strrchr.c

void test_memset(char *s, int c, int len);
void test_bzero(void *s, size_t n);
void test_memcpy(void *dst, const void *src, size_t n);
void test_memccpy(void *dst, const void *src, int c, size_t n);
void test_memmove(void *dst, const void *src, size_t len);
void test_memchr(const void *s, int c, size_t n);
void test_memcmp(const void *s1, const void *s2, size_t n);
void test_strlen(const char *s);
void test_strchr(const char *s, int c);
void test_strrchr(const char *s, int c);
void test_strncmp(const char *s1, const char *s2, size_t n);
void test_strlcpy(char *dst, const	char *src, size_t size);
void test_strlcat(char *dst, const char *src, size_t size);
void test_strnstr(const char *haystack, const char *needle, size_t len);
void test_atoi(const char *str);
void test_strdup(const char *str);

int main(void)
{
	char *s = malloc(100);
	printf("\nTesting memset...\n");
	test_memset(NULL, 0, 0);
	test_memset(NULL, 0, 1000);
	test_memset(NULL, 0, -1);
	test_memset(s, '0', 0);
	test_memset(s, 'c', 1000);
	test_memset(s, 0, -1);
	printf("\nTesting bzero...\n");
	test_bzero(NULL, 0);
	test_bzero(NULL, 100);
	test_bzero(NULL, -1);
	test_bzero(s, 0);
	test_bzero(s, 100);
	test_bzero(s, -1);
	free(s);
	printf("\nTesting memcpy...\n");
	char *x = malloc(100);
	char *y = malloc(50);
	test_memcpy(NULL, NULL, 0);
	test_memcpy(NULL, NULL, 100);
	test_memcpy(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_memcpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", NULL, 10);
	test_memcpy(x, NULL, 0);
	test_memcpy(x, NULL, 100);
	test_memcpy(x, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_memcpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", x, 10);
	test_memcpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 50);
	test_memcpy(NULL, x, 0);
	test_memcpy(NULL, x, 100);
	test_memcpy(NULL, x, 10);
	test_memcpy(y, x, 0);
	test_memcpy(y, x, 100);
	test_memcpy(y, x, 10);
	test_memcpy(x, y, 0);
	test_memcpy(x, y, 100);
	test_memcpy(x, y, 10);
	free(x);
	free(y);
	printf("\nTesting memccpy...\n");
	char *a = malloc(100);
	char *b = malloc(50);
	test_memccpy(NULL, NULL, 0, 0);
	test_memccpy(NULL, NULL, 0, 100);
	test_memccpy(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 10);
	test_memccpy(a, NULL, 0, 0);
	test_memccpy(a, NULL, 0, 100);
	test_memccpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", NULL, 0, 10);
	test_memccpy(NULL, b, 0, 0);
	test_memccpy(NULL, b, 0, 100);
	test_memccpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 10);
	test_memccpy(NULL, a, 0, 0);
	test_memccpy(NULL, a, 0, 100);
	test_memccpy(a, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 10);
	test_memccpy(b, NULL, 0, 0);
	test_memccpy(b, NULL, 0, 100);
	test_memccpy(b, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 10);
	test_memccpy(NULL, NULL, 20, 0);
	test_memccpy(NULL, NULL, 50, 100);
	test_memccpy(a, NULL, 100, 0);
	test_memccpy(a, NULL, 10, 100);
	test_memccpy(NULL, b, 10, 20);
	test_memccpy(NULL, b, 50, 100);
	test_memccpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 100);
	test_memccpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 'Z', 100);
	test_memccpy(NULL, a, 20, 0);
	test_memccpy(NULL, a, 200, 100);
	test_memccpy(a, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 10);
	test_memccpy(b, NULL, 100, 0);
	test_memccpy(b, NULL, 10, 0);
	test_memccpy(b, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10, 0);
	test_memccpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 'A', 100);
	test_memccpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", '2', 100);
	free(a);
	free(b);
	printf("\nTesting memmove...\n");
	char *f = malloc(100);
	char *h = malloc(50);
	test_memmove(NULL, NULL, 0);
	test_memmove(NULL, NULL, 100);
	test_memmove(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_memmove(f, NULL, 0);
	test_memmove(f, NULL, 100);
	test_memmove("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_memmove(NULL, f, 0);
	test_memmove(NULL, f, 100);
	test_memmove("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 50);
	test_memmove(h, NULL, 0);
	test_memmove(h, NULL, 100);
	test_memmove(f, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_memmove(NULL, h, 0);
	test_memmove(NULL, h, 100);
	test_memmove(h, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_memmove(f, h, 50);
	test_memmove(f, h, -1);
	test_memmove("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_memmove(f, f, 100);
	test_memmove(f, f, 100);
	test_memmove("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 50);
	test_memmove(h, f, 0);
	test_memmove(h, f, 100);
	test_memmove(f, h, 10);
	test_memmove(f, h, 0);
	test_memmove(f, h, 100);
	test_memmove(h, f, 10);
	printf("\nTesting memchr...\n");
	char *p = malloc(100);
	char *o = "Qwertyu";
	test_memchr(NULL, 0, 0);
	test_memchr(NULL, 0, 100);
	test_memchr(p, 0, 0);
	test_memchr(p, 0, 100);
	test_memchr(o, 'x', 0);
	test_memchr(o, 'P', 100);
	printf("\nTesting memcmp...\n");
	char *z = malloc(100);
	char *v = malloc(50);
	test_memcmp(NULL, NULL, 0);
	test_memcmp(NULL, NULL, 100);
	test_memcmp(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 100);
	test_memcmp(z, NULL, 0);
	test_memcmp(z, NULL, 100);
	test_memcmp("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 100);
	test_memcmp(v, NULL, 0);
	test_memcmp(v, NULL, 100);
	test_memcmp(z, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 100);
	test_memcmp(NULL, v, 0);
	test_memcmp(NULL, v, 100);
	test_memcmp(z, v, 100);
	test_memcmp(v, z, 0);
	test_memcmp(v, z, 100);
	test_memcmp("ABCDEFGHIJKLMNOPQRSTUVWXYZ", z, 100);
	test_memcmp(v, z, 0);
	test_memcmp(v, z, 100);
	test_memcmp(z, v, 100);
	test_memcmp(v, z, 0);
	test_memcmp(v, z, 100);
	test_memcmp(v, z, 100);
	printf("\nTesting strlen...\n");
	test_strlen(NULL);
	test_strlen("\0");
	test_strlen("RCTVbynuimowdadawd");
	test_strlen("ctvybunim,\0dyawiuudnawd");
	printf("\nTesting strchr...\n");
	test_strchr(NULL, 0);
	test_strchr(NULL, '\n');
	test_strchr("udvaiwbdiawdaw", 0);
	test_strchr("diuwada\nwadawaw", '\n');
	test_strchr("udvaiwbdiawdaw", 0);
	test_strchr("diuwada\nwadawaw", '\n');
	test_strchr("udvaiwbdiawdaw", 'a');
	test_strchr("diuwada\nwadawawzz", 'z');
	printf("\nTesting strnchr...\n");
	test_strrchr(NULL, 0);
	test_strrchr(NULL, '\n');
	test_strrchr("udvaiwbdiawdaw", 0);
	test_strrchr("diuwada\nwadawaw", '\n');
	test_strrchr("udvaiwbdiawdaw", 0);
	test_strrchr("diuwada\nwadawaw", '\n');
	test_strrchr("udvaiwbdiawdaw", 'a');
	test_strrchr("diuwada\nwadawawzz", 'z');
	printf("\nTesting strncmp...\n");
	char *r = malloc(100);
	char *m = malloc(50);
	test_strncmp(NULL, NULL, 0);
	test_strncmp(NULL, NULL, 100);
	test_strncmp(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strncmp(r, NULL, 0);
	test_strncmp(r, NULL, 100);
	test_strncmp("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strncmp(NULL, r, 0);
	test_strncmp(NULL, r, 100);
	test_strncmp(r, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strncmp(m, NULL, 0);
	test_strncmp(m, NULL, 100);
	test_strncmp(m, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strncmp(NULL, m, 0);
	test_strncmp(NULL, m, 100);
	test_strncmp(r, m, 100);
	test_strncmp(m, r, 10);
	test_strncmp(m, r, 0);
	free(r);
	free(m);
	printf("\nTesting strlcpy...\n");
	r = malloc(100);
	m = malloc(50);
	test_strlcpy(NULL, NULL, 0);
	test_strlcpy(NULL, NULL, 100);
	test_strlcpy(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strlcpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", NULL, 10);
	test_strlcpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0);
	test_strlcpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", NULL, -1);
	test_strlcpy(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10000);
	test_strlcpy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", NULL, -10000);
	test_strlcpy(r, NULL, 0);
	test_strlcpy(r, NULL, 100);
	test_strlcpy(r, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strlcpy(r, NULL, 10);
	test_strlcpy(r, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0);
	test_strlcpy(r, NULL, -1);
	test_strlcpy(r, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10000);
	test_strlcpy(r, NULL, -10000);
	test_strlcpy(m, NULL, 0);
	test_strlcpy(m, NULL, 100);
	test_strlcpy(m, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strlcpy(m, NULL, 10);
	test_strlcpy(m, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0);
	test_strlcpy(m, NULL, -1);
	test_strlcpy(m, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10000);
	test_strlcpy(m, NULL, -10000);
	test_strlcpy(r, m, 0);
	test_strlcpy(r, m, 100);
	test_strlcpy(r, m, 10);
	test_strlcpy(r, m, 10);
	test_strlcpy(r, m, 0);
	test_strlcpy(r, m, -1);
	test_strlcpy(r, m, 10000);
	test_strlcpy(r, m, -10000);
	test_strlcpy(r, r, 0);
	test_strlcpy(r, r, 100);
	test_strlcpy(r, r, 10);
	test_strlcpy(r, r, 10);
	test_strlcpy(r, r, 0);
	test_strlcpy(r, r, -1);
	test_strlcpy(r, r, 10000);
	test_strlcpy(r, r, -10000);
	test_strlcpy(m, r, 0);
	test_strlcpy(m, r, 100);
	test_strlcpy(m, r, 10);
	test_strlcpy(m, r, 10);
	test_strlcpy(m, r, 0);
	test_strlcpy(m, r, -1);
	test_strlcpy(m, r, 10000);
	test_strlcpy(m, r, -10000);
	free(r);
	free(m);
	printf("\nTesting strlcat...\n");
	r = malloc(100);
	m = malloc(50);
	test_strlcat(NULL, NULL, 0);
	test_strlcat(NULL, NULL, 100);
	test_strlcat(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strlcat(r, NULL, 0);
	test_strlcat(r, NULL, 100);
	test_strlcat(r, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strlcat(m, NULL, 0);
	test_strlcat(m, NULL, 100);
	test_strlcat(m, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strlcat(r, m, 0);
	test_strlcat(r, m, 100);
	test_strlcat(r, m, 10);
	test_strlcat(m, r, 0);
	test_strlcat(m, r, 100);
	test_strlcat(m, r, 10);
	free(r);
	free(m);
	printf("\nTesting strnstr...\n");
	r = malloc(100);
	m = malloc(50);
	test_strnstr(NULL, NULL, 0);
	test_strnstr(NULL, NULL, 100);
	test_strnstr(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strnstr(r, NULL, 0);
	test_strnstr(r, NULL, 100);
	test_strnstr(r, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strnstr(m, NULL, 0);
	test_strnstr(m, NULL, 100);
	test_strnstr(m, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	test_strnstr(r, m, 0);
	test_strnstr(r, m, 100);
	test_strnstr(r, m, 10);
	test_strnstr(m, r, 0);
	test_strnstr(m, r, 100);
	test_strnstr(m, r, 10);
	printf("\nTesting atoi...\n");
	test_atoi(NULL);
	test_atoi("");
	test_atoi("0");
	test_atoi("1561681615616818156156113");
	test_atoi("12");
	test_atoi("-51561561561");
	test_atoi("-5");
	test_atoi("-155615611516161561863");
	printf("\nTesting strdup...\n");
	test_strdup(NULL);
	test_strdup("");
	test_strdup("16516181");
	test_strdup("oadniowandinawiodnaw");
	return (0);
}

void test_strdup(const char *str)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strdup(str);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strdup(str);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strdup need to crash with (%s).\n", str);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strdup is crashing with (%s).\n", str);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_atoi(const char *str)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		atoi(str);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_atoi(str);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_atoi need to crash with (%s).\n", str);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_atoi is crashing with (%s).\n", str);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_strnstr(const char *haystack, const char *needle, size_t len)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strnstr(haystack, needle, len);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strnstr(haystack, needle, len);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strnstr need to crash with (%s %s %zu).\n", haystack, needle, len);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strnstr is crashing with (%s %s %zu).\n", haystack, needle, len);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_strlcat(char *dst, const	char *src, size_t size)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strlcat(dst, src, size);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strlcat(dst, src, size);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strlcat need to crash with (%s %s %zu).\n", dst, src, size);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strlcat is crashing with (%s %s %zu).\n", dst, src, size);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_strlcpy(char *dst, const	char *src, size_t size)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strlcpy(dst, src, size);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strlcpy(dst, src, size);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strlcpy need to crash with (%s %s %zu).\n", dst, src, size);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strlcpy is crashing with (%s %s %zu).\n", dst, src, size);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_strncmp(const char *s1, const char *s2, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strncmp(s1, s2, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strncmp(s1, s2, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strncmp need to crash with (%s %s %zu).\n", s1, s2, n);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strncmp is crashing with (%s %s %zu).\n", s1, s2, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_strrchr(const char *s, int c)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strrchr(s, c);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strrchr(s, c);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strrchr need to crash with (%s).\n", s);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strrchr is crashing with (%s).\n", s);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_strchr(const char *s, int c)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strchr(s, c);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strchr(s, c);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strchr need to crash with (%s).\n", s);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strchr is crashing with (%s).\n", s);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_strlen(const char *s)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		strlen(s);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_strlen(s);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strlen need to crash with (%s).\n", s);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_strlen is crashing with (%s).\n", s);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_memcmp(const void *s1, const void *s2, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memcmp(s1, s2, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memcmp(s1, s2, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memcmp need to crash with (%s, %s, %zu).\n", s1, s2, n);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memcmp is crashing with (%s, %s, %zu).\n", s1, s2, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_memchr(const void *s, int c, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memchr(s, c, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memchr(s, c, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memchr need to crash with (%s, %i, %zu).\n", s, c, n);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memchr is crashing with (%s, %i, %zu).\n", s, c, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_memmove(void *dst, const void *src, size_t len)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memmove(dst, src, len);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memmove(dst, src, len);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memmove need to crash with (%s, %s, %zu).\n", dst, src, len);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memmove is crashing with (%s, %s, %zu).\n", dst, src, len);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_memccpy(void *dst, const void *src, int c, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memccpy(dst, src, c, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memccpy(dst, src, c, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memccpy need to crash with (%s, %s, %i, %zu).\n", dst, src, c, n);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memccpy is crashing with (%s, %s, %i, %zu).\n", dst, src, c, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_memcpy(void *dst, const void *src, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memcpy(dst, src, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memcpy(dst, src, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memcpy need to crash with (%s, %s, %zu).\n", dst, src, n);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memcpy is crashing with (%s, %s, %zu).\n", dst, src, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_memset(char *s, int c, int len)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		memset(s, c, len);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_memset(s, c, len);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memset need to crash with (%s, %c, %i).\n", s, c, len);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_memset is crashing with (%s, %c, %i).\n", s, c, len);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}

void test_bzero(void *s, size_t n)
{
	FILE	*crash_file;
	pid_t	org;
	pid_t	new;
	int		org_crash;
	int		new_crash;

	if (!(crash_file = fopen("org_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	if (!(crash_file = fopen("new_crash", "w")))
		exit(0);
	fprintf(crash_file, "1");
	fclose(crash_file);

	org = fork();
	if (!org) {
		bzero(s, n);
		if (!(crash_file = fopen("org_crash", "w")))
			exit(0);
		fprintf(crash_file, "0");
		fclose(crash_file);
		exit(0);
	}
	else {
		new = fork();
		if (!new) {
			ft_bzero(s, n);
			if (!(crash_file = fopen("new_crash", "w")))
				exit(0);
			fprintf(crash_file, "0");
			fclose(crash_file);
			exit(0);
		}
		else {
			sleep(1);
			if (!(crash_file = fopen("org_crash", "r")))
				exit(0);
			org_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (!(crash_file = fopen("new_crash", "r")))
				exit(0);
			new_crash = fgetc(crash_file) - '0';
			fclose(crash_file);

			if (org_crash && !new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_bzero need to crash with (%s, %zu).\n", s, n);
			else if (!org_crash && new_crash)
				printf("\n\t\033[31m[KO]\033[0m ft_bzero is crashing with (%s, %zu)\n", s, n);
			else if (!org_crash && !new_crash)
				printf("\t\033[32m[OK]\033[0m");
			else if (org_crash && new_crash)
				printf("\t\033[32m[OK]\033[0m");
		}
	}
}
