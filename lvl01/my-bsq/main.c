#include <stdio.h>
#include <stdlib.h>

typedef struct s_bsq
{
	int		r;
	int		c;
	char	e;
	char	o;
	char	f;
	char	**m;
}	t_bsq;

int	ft_min(int a, int b, int c)
{
	int	min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	free_map(t_bsq *b)
{
	int	i = 0;

	while (i < b->r)
		free(b->m[i++]);
	free(b->m);
}

int	parse_first(char *s, t_bsq *b)
{
	int	i = 0;

	while (s[i] && s[i] != '\n')
		i++;

	if (i < 4 || s[i] != '\n')
		return (0);

	b->f = s[i - 1];
	b->o = s[i - 2];
	b->e = s[i - 3];

	if (b->f == b->o || b->f == b->e || b->o == b->e)
		return (0);

	b->r = 0;

	while (*s >= '0' && *s <= '9')
		b->r = b->r * 10 + (*s++ - '0');

	if (*s != b->e || b->r <= 0)
		return (0);

	return (1);
}

int	read_map(FILE *f, t_bsq *b)
{
	char	*line = NULL;
	size_t	n = 0;
	size_t	len;
	int		i = 0;
	int		j;

	b->m = malloc(sizeof(char *) * b->r);

	if (!b->m)
		return (0);

	while (i < b->r)
	{
		len = getline(&line, &n, f);

		if (len <= 1 || line[len - 1] != '\n')
			return (free(line), 0);

		line[len - 1] = 0;

		if (i == 0)
			b->c = len - 1;

		if ((int)(len - 1) != b->c || b->c <= 0)
			return (free(line), 0);

		j = 0;
		while (j < b->c)
		{
			if (line[j] != b->e && line[j] != b->o)
				return (free(line), 0);
			j++;
		}

		b->m[i] = malloc(b->c + 1);

		j = 0;
		while (j < b->c)
		{
			b->m[i][j] = line[j];
			j++;
		}

		b->m[i][j] = 0;
		i++;
	}

	free(line);
	return (1);
}

void	solve(t_bsq *b)
{
	int	*dp;
	int	i, j;
	int	best = 0, bi = 0, bj = 0;

	dp = malloc(sizeof(int) * b->r * b->c);

	i = 0;
	while (i < b->r)
	{
		j = 0;
		while (j < b->c)
		{
			if (b->m[i][j] == b->o)
				dp[i * b->c + j] = 0;
			else if (i == 0 || j == 0)
				dp[i * b->c + j] = 1;
			else
				dp[i * b->c + j] = 1 + ft_min(
					dp[(i - 1) * b->c + j],
					dp[i * b->c + j - 1],
					dp[(i - 1) * b->c + j - 1]);

			if (dp[i * b->c + j] > best)
			{
				best = dp[i * b->c + j];
				bi = i;
				bj = j;
			}
			j++;
		}
		i++;
	}

	i = bi - best + 1;
	while (i <= bi)
	{
		j = bj - best + 1;
		while (j <= bj)
			b->m[i][j++] = b->f;
		i++;
	}

	free(dp);
}

int	main(int ac, char **av)
{
	FILE	*f;
	t_bsq	b;
	char	*line = NULL;
	size_t	n = 0;

	if (ac == 2)
		f = fopen(av[1], "r");
	else
		f = stdin;

	if (!f)
		return (printf("Error\n"));

	if (getline(&line, &n, f) < 0 || !parse_first(line, &b)
		|| !read_map(f, &b))
		return (printf("Error: invalid map\n"));

	free(line);

	solve(&b);

	for (int i = 0; i < b.r; i++)
		printf("%s\n", b.m[i]);

	free_map(&b);

	if (ac == 2)
		fclose(f);

	return (0);
}