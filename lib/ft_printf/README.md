# ft_printf

This project is a custom implementation of the `printf` function in the C programming language. 

## Introduction

The `printf` function is a widely used function in the C programming language that allows formatted output to the standard output stream. It provides a convenient way to display various types of data, such as strings, numbers, and other variables, in a specified format.

In this project, I implemented my own version of the `printf` function called `ft_printf`. It replicates the functionality of the standard `printf` function while maintaining a customizable and extensible codebase.

## Features

The `ft_printf` function in this project supports the following features:

- Printing formatted output to the standard output stream.
- Handling different conversion specifiers, such as `%d`, `%s`, `%c`, `%u`, `%p`, and more.

## Getting Started

To compile and use the `ft_printf` function, follow these steps:

1. Clone the repository to your local machine using the following command:

   ```shell
   git clone https://github.com/LeeSinLiang/ft_printf.git
   ```

2. Navigate to the project directory:

   ```shell
   cd ft_printf
   ```

3. Compile the project using Makefile:

   ```shell
   make
   ```

4. Start using the `ft_printf` function in your code as you would with the standard `printf` function. For example:

   ```c
   int ft_printf(const char *str, ...);

   int main() {
       ft_printf("Hello, %s!\n", "world");
       return 0;
   }
   ```

   Compile your code with the `libftprintf.a` library:

   ```shell
   gcc -Wall -Wextra -Werror -I includes main.c -L. -lftprintf -o main
   ```

   Run the executable:

   ```shell
   ./main
   ```

   Output:

   ```
   Hello, world!
   ```
  
 **Note: libft is included to utilize several functions such as `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd` and more.**
 
 **More details of libft: https://github.com/LeeSinLiang/libft**
