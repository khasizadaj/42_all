/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:44:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/05 20:47:01 by codespace        ###   ########.fr       */
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

    if (argc < 2) {
        printf("Error: Missing argument.\n");
        return (-1);
    }

	// TODO: Read multiple args
	file_id = ft_atoi(argv[1]) - 1;
	files = ft_calloc(1, sizeof(t_files));
	if (!files)
		return (-1);

	if (!get_files(files))
		return (free(files), -1);

	fd = open(files->path_list[file_id], O_RDONLY);
	if (fd == -1)
	{
		printf("Error number: %d\n", errno);
		perror("Program");
		return (-1);
	}
	line = get_next_line(fd);
 
 	int temp_fd = fd;
	fd = open(files->path_list[file_id + 1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error number: %d\n", errno);
		perror("Program");
		return (-1);
	}
	line = get_next_line(fd);
	line = get_next_line(temp_fd);

	if (close(fd) < 0) {
		perror("Program");
		exit(1);
	}
	free(files);
	return 0;
}
