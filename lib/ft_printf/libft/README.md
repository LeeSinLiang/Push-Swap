# Libft

Libft is a custom C library that contains implementations of various standard library functions in C. These functions are commonly used in C programming and provide essential functionality for tasks such as string manipulation, memory allocation, and list manipulation. By using Libft, you can have access to these functions without relying on the standard library.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Installation

To use Libft in your C projects, follow these steps:

1. Clone the Libft repository to your local machine:
   ```bash
	https://github.com/LeeSinLiang/Libft
   ```

2. Compile the library by running the Makefile:
   ```bash
   cd Libft
   make
   ```

3. Once the compilation is complete, you will have a `libft.a` file that contains the compiled library. You can link this library with your C programs to use the implemented functions.

4. Finally, compile your C program with the Libft library:
   ```bash
   gcc my_program.c -L. -lft
   ```

## Usage

Libft provides a wide range of functions categorized into different sections, including string manipulation, memory allocation, linked lists, and more. 

To use a specific function from Libft, declare the corresponding prototype function file in your C file and call the function by its name. For example, to use the `ft_atoi` function:

```c
#include  <stdio.h>

int  ft_atoi(const  char *str);

int  main()
{
	char *str = "123456789";
	printf("%d", ft_atoi(str));
	return (0);
}
```

For more details on the available functions and their usage, refer to the individual c files and their corresponding comments.

## License

MIT License
