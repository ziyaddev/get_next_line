#include "get_next_line.h"

int	main(void)
{
	int				open_testfile_fd;
	char			*my_str;
	char			*mem_space;
	char			*calloc_mem_space;
	unsigned int	mem_space_len;
	int				calloc_size;
	char			*str_test =  "This is a string test !";

	my_str = malloc(sizeof(char) * 10);
	if (!my_str)
		return (-1);

	open_testfile_fd = open("./test.txt", O_RDONLY);
	if (open_testfile_fd < 0)
		return (-1);

	printf("Opened file descriptor : %d\n", open_testfile_fd);
	printf("\nstrlen : %ld\n", ft_strlen("my str len test"));
	printf("\nstrjoin : %s\n", ft_strjoin("my str len test\\", "|/ 2nd part"));
	printf("\nstrchr : %s\n", ft_strchr("salam akhi", 'k'));

	mem_space_len = 6;
	calloc_size = 6500;

	mem_space = ft_calloc(mem_space_len, calloc_size);
	calloc_mem_space = calloc(mem_space_len, calloc_size);

	for (size_t i = 0; i < mem_space_len; i++)
	{
		printf("ft_calloc memspace %ld : %c\t", i, mem_space[i]);
		printf("calloc memspace %ld : %c\n", i, calloc_mem_space[i]);
	}

	printf("\nmemspace : %s\n", mem_space);

	printf("ptr 'T' : %p\n", ft_strchr(str_test, 'T'));
	printf("ptr 'e' : %p\n", ft_strchr(str_test, 'e'));

	printf("\nstrndup test : %s\n\n", ft_strndup("salamouaalaikoum!", 44));

	printf("ft read line : %s\n", ft_read_line(open_testfile_fd));
	
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));
	// printf("%s", get_next_line(open_testfile_fd));

	// write(1, "\nnext gnl ft\n", 13);

	// printf("%s", get_next_line(0));
	// printf("%s", get_next_line(0));
	// printf("%s", get_next_line(0));
	// printf("%s", get_next_line(0));

	// printf("\nstatic variable test %s\n", ft_static_variable_test());
	// printf("\nstatic variable test %s\n", ft_static_variable_test());

	free(mem_space);
	free(calloc_mem_space);

	close(open_testfile_fd);
	return (0);
}
