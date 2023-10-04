/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:44:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/04 21:27:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);



typedef struct s_files {
	char    **file_list;
	char    **path_list;
} t_files;

int    get_files(t_files *files)
{
	char    **file_list;
	char    **path_list;

	file_list = ft_calloc(6, sizeof(char *));
	if (!file_list)
		return (-1);

	file_list[0] = "file_1.txt";
	file_list[1] = "file_2.txt";
	file_list[2] = "file_3.txt";
	file_list[3] = "file_4.txt";
	file_list[3] = "file_5.txt";
	file_list[5] = '\0';

	
	path_list = ft_calloc(6, sizeof(char *));
	if (!path_list)
		return (free(file_list), -1);

	path_list[0] = "../test/get_next_line/file_1.txt";
	path_list[1] = "../test/get_next_line/file_2.txt";
	path_list[2] = "../test/get_next_line/file_3.txt";
	path_list[3] = "../test/get_next_line/file_4.txt";
	path_list[3] = "../test/get_next_line/file_5.txt";
	path_list[5] = '\0';
	
	files->file_list = file_list;
	files->path_list = path_list;
	return (1);
}

int main(int argc, char const *argv[])
{
	int     fd;
	char    *line;
	t_files *files;
	int     file_id;

	file_id = ft_atoi(argv[1]) - 1;
	files = ft_calloc(1, sizeof(t_files));
	if (!files)
		return (-1);

	if (!get_files(files))
		return (free(files), -1);

	printf("File %d: %s\n", file_id, files->path_list[file_id]);
	fd = open(files->path_list[file_id], O_RDONLY);
	if (fd == -1)
	{
		printf("Error number: %d\n", errno);
		perror("Program");
	}

	line = get_next_line(fd);
 
	if (close(fd) < 0) {
		perror("Program");
		exit(1);
	}
	return 0;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
	return ;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	res = malloc(size * nmemb);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, size * nmemb);
	return (res);
}