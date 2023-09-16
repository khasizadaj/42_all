/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:16:14 by codespace         #+#    #+#             */
/*   Updated: 2023/09/16 12:25:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // Include your library header

int main()
{
    int fd;

    // Open the "sample.txt" file for writing
    fd = open("sample.txt", O_WRONLY | O_CREAT, 0666);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Call your custom ft_putendl_fd function to write a string with newline to the file
    ft_putendl_fd("HEllo", fd);

    // Close the file
    close(fd);

    // Reopen the file for reading
    fd = open("sample.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file for reading");
        return 1;
    }

    // Read and print the contents of the file
    char buffer[10];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1)
    {
        perror("Error reading file");
        return 1;
    }

    buffer[bytes_read] = '\0'; // Null-terminate the string
    printf("Contents of 'sample.txt': %s\n", buffer);

    // Close the file
    close(fd);

    return 0;
}

