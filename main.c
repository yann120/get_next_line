
#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
		free(line);
	if (argc == 2)
		close(fd);
}

// // main 03
// int main(void)
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	char 	*str;
// 	int		gnl_ret;

// 	str = (char *)malloc(1000 * 1000);
// 	*str = '\0';
// 	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	out = dup(1);
// 	pipe(p);
// 	dup2(p[1], 1);

// 	write(1, str, strlen(str));
// 	close(p[1]);
// 	dup2(out, 1);
// 	gnl_ret = get_next_line(p[0], &line);
// 	printf("line =\n%s\n",line);
// 	printf("\n");
// 	printf("str =\n%s\n",str);
// 	printf("strcmp %d\n", ft_strcmp(line, str));
// 	printf("gnlret %d\n", gnl_ret);
// }

// int main(void)
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	int		fd;
// 	int		gnl_ret;

// 	out = dup(1);
// 	pipe(p);

// 	fd = 1;
// 	dup2(p[1], fd);
// 	write(fd, "abc\n\n", 5);
// 	close(p[1]);
// 	dup2(out, fd);

// 	/* Read abc and new line */
// 	gnl_ret = get_next_line(p[0], &line);
// 	printf("%d\n",gnl_ret == 1);
// 	printf("%d\n",strcmp(line, "abc") == 0);

// 	/* Read new line */
// 	gnl_ret = get_next_line(p[0], &line);
// 	printf("%d\n",gnl_ret == 1);
// 	printf("%d\n",line == NULL || *line == '\0');

// 	/* Read again, but meet EOF */
// 	gnl_ret = get_next_line(p[0], &line);
// 	printf("%d\n",gnl_ret == 0);
// 	printf("%d\n",line == NULL || *line == '\0');

// 	/* Let's do it once again */
// 	gnl_ret = get_next_line(p[0], &line);
// 	printf("%d\n",gnl_ret == 0);
// 	printf("%d\n",line == NULL || *line == '\0');
// }