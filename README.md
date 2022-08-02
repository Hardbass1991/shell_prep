<p align="center">
  <img width="409" height="128" src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg">
</p>
# Who knew  Simple Shell could be implemented ?

This repository contains the C program for the **Simple Shell** function written as part of the **Low Level Programming and Algorithm** project at **Holberton School**. The program is the implementation of the Simple Shell C language function that prints the formatted output.

## Project overview

### Compilation:

All files will be compiled with gcc 4.8.4 using the flags:  -Wall -Werror -Wextra -pedantic

      gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

### Betty coding style:

All files are written in C and follows the Betty coding style for Holberton School. For more detail, check this page:

[Betty style documentation](https://github.com/holbertonschool/Betty/wiki)

### Authorized functions and macros
### List of allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

### Tasks

0.README, man, AUTHORS
 -Write a README
 -Write a man for your shell.
 -You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

1.Betty would be proud
 -Write a beautiful code that passes the Betty checks

2.Simple shell 0.1
 -Write a UNIX command line interpreter.
  -Usage: simple_shell
 Your Shell should:
  -Display a prompt and wait for the user to type a command. A command line always ends with a new line.
  -The prompt is displayed again each time a command has been executed.
  -The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
  -The command lines are made only of one word. No arguments will be passed to programs.
  -If an executable cannot be found, print an error message and display the prompt again.
  -Handle errors.
  -You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:
  -use the PATH
  -implement built-ins
  -handle special characters : ", ', `, \, *, &, #
  -be able to move the cursor
  -handle commands with arguments
execve will be the core part of your Shell, don’t forget to pass the environ to it…

3.Simple shell 0.2
Simple shell 0.1 +
  -Handle command lines with arguments

4.Simple shell 0.3
Simple shell 0.2 +
  -Handle the PATH
  -fork must not be called if the command doesn’t exist

5.Simple shell 0.4
Simple shell 0.3 +
  -Implement the exit built-in, that exits the shell
  -Usage: exit
  -You don’t have to handle any argument to the built-in exit

6.Simple shell 1.0
Simple shell 0.4 +
  -Implement the env built-in, that prints the current environment

7.What happens when you type `ls -l *.c` in the shell
Write a blog post describing step by step what happens when you type ls -l *.c and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).

  -Have at least one picture, at the top of the blog post
  -Publish your blog post on Medium or LinkedIn
  -Share your blog post at least on LinkedIn
  -Only one blog post by team
  -The blog post must be done and published before the first deadline (it will be part of the manual review)
  -Please, remember that these blogs must be written in English to further your technical ability in a variety of settings

When done, please add all urls below (blog post, LinkedIn post, etc.)

(aqui va el link de nuestro blog)
## Function prototypes
All function prototypes used to compile the Simple Shell are included in the **missing.h** header file:

## File description

## Function description

## Examples

**Return value:**
## Author
##### Kevin Barzola
Cohort 18
##### Julian Zea
Cohort 18
