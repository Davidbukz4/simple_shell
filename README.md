# simple_shell
# 0x16. C - Simple Shell

## Description

This Simple Shell project is a collaboration between Gerald Juwah and Ahmed A. Olawale. Who are Software Engineers studing as students of ALX school. This project consists of developing and making our own UNIX command interpreter (Shell).

This Simple_shell project can be compiled and launched from the command line, where its main function is to execute commands read from the standard input.

## Shell Compilation
	$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
## Shell execute
	./hsh

## Commands on shell process
	cd - Change directory
	env - List the current enviroment variables
	exit - exit the shell
	pwd - Print the absolute pathname


## Examples

Some of the examples of this shell working process:

cd:

	#cisfun$ pwd
	/home/vagrant/simple_shell
	#cisfun$ cd
	#cisfun$ pwd
	/home/vagrant
	#cisfun$

cd error:

	#cisfun$ cd hola
	./hsh: 1: cd: can't cd to hola
	#cisfun$

exit:

	#cisfun$ exit 123
	vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ echo $?
	123

exit error:

	#cisfun$ exit hola
	./hsh: 2: exit: Illegal number: hola
	#cisfun$

## Authors
- `David Egwuatu` davidegwuatu2@gmail.com
- `John Nnamani` nnamanijohn123@gmail.com
