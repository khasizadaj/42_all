/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:44:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/07 12:04:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "program_utils.h"

typedef struct s_files {
	char    **file_list;
	char    **path_list;
} t_files;

int    get_files(t_files *files)
{
	char    **file_list;
	char    **path_list;

	file_list = ft_calloc(7, sizeof(char *));
	if (!file_list)
		return (-1);

	file_list[0] = "file_1.txt";
	file_list[1] = "file_2.txt";
	file_list[2] = "file_3.txt";
	file_list[3] = "file_4.txt";
	file_list[4] = "file_5.txt";
	file_list[5] = "file_6.txt";
	file_list[6] = '\0';

	
	path_list = ft_calloc(7, sizeof(char *));
	if (!path_list)
		return (free(file_list), -1);

	path_list[0] = "../test/get_next_line/file_1.txt";
	path_list[1] = "../test/get_next_line/file_2.txt";
	path_list[2] = "../test/get_next_line/file_3.txt";
	path_list[3] = "../test/get_next_line/file_4.txt";
	path_list[4] = "../test/get_next_line/file_5.txt";
	path_list[5] = "../test/get_next_line/file_6.txt";
	path_list[6] = '\0';
	
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

    if (argc < 2) {
        printf("Error: Missing argument.\n");
        return (-1);
    }

	// TODO: Read multiple args
	file_id = ft_atoi(argv[1]) - 1;
	printf("FILE_ID=%d\n", file_id);
	files = ft_calloc(1, sizeof(t_files));
	if (!files)
		return (1);

	if (!get_files(files))
		return (free(files->path_list), free(files->file_list), free(files), 1);

	printf("[o]\tpath_list[%d]='%s']\n", file_id, files->path_list[file_id]);
	fd = open(files->path_list[file_id], O_RDONLY);
	if (fd == -1)
	{
		printf("Error number: %d\n", errno);
		perror("Program");
		return (1);
	}

	int i = -1;
	while (++i < 100)
	{
		line = get_next_line(fd);
		printf("[main]\t[l=%ld]\t'%s'\n", ft_strlen(line), line);
		if (line == NULL)
			return (free(files->path_list), free(files->file_list), free(files), 1);
		printf("\nLINES READ: %d\n\n\n", i + 1);
		free(line);
	}

	if (close(fd) < 0) {
		perror("Program");
		exit(1);
	}
	return (free(files->path_list), free(files->file_list), free(files), 0);
}
