#Simple_Shell

##TABLE OF CONTENTS
- [DESCRIPTION](#DESCRIPTION)
- [FLOWCHART](#FLOWCHART)
- [REQUIREMENTS](#Requirements)
- [COMPILATION CMD](#compliationCDM)
- [RETURNS VALUE](#RETURNS_VALUE)
- [EXEMPLES](#Exemplesg)
- [MAN PAGE](#MANPAGE)
- [CHECK MEMORY LEAKS](#CHECKMEMORYLEAKS)
- [AUTHORS](#AUTHORS)


##DESCRIPTION

The shell is a command-line interface enabling the user to interact with a computer's operating system. It acts as a layer of abstraction between the user and the operating system kernel, enabling the user to execute commands, launch programs, navigate directories, manage files and processes, and automate tasks using scripts.

The shell is a powerful tool for interacting with a command-line operating system, enabling users to execute commands, launch programs, navigate directories, manage files and processes, and automate tasks.



##FLOWCHART

![flowchart](https://github.com/Nadely/holbertonschool-simple_shell/blob/main/Flowchart_Simple_Shell.png)

##REQUIREMENTS compiler, list of authorized functions)

_Compiler :_GNU

_List of authorized functions :_
<div style="display: flex;">
  <div style="flex: 50%; padding: 10px;">
  	all functions from string.h</br>
	access (man 2 access)</br>
	chdir (man 2 chdir)</br>
	close (man 2 close)</br>
	closedir (man 3 closedir)</br>
	execve (man 2 execve)</br>
	exit (man 3 exit)</br>
	_exit (man 2 _exit)</br>
	fflush (man 3 fflush)</br>
	fork (man 2 fork)</br>
	free (man 3 free)</br>
	getcwd (man 3 getcwd)</br>
	getline (man 3 getline)</br>
	getpid (man 2 getpid)</br>
	isatty (man 3 isatty)</br>
	kill (man 2 kill)</br>
	malloc (man 3 malloc)</br>
	open (man 2 open)</br>
	opendir (man 3 opendir)</br>
  </div>
  <div style="flex: 50%; padding: 10px;">
	perror (man 3 perror)</br>
	printf (man 3 printf)</br>
	fprintf (man 3 fprintf)</br>
	vfprintf (man 3 vfprintf)</br>
	sprintf (man 3 sprintf)</br>
	putchar (man 3 putchar)</br>
	read (man 2 read)</br>
	readdir (man 3 readdir)</br>
	signal (man 2 signal)</br>
	stat (__xstat) (man 2 stat)</br>
	lstat (__lxstat) (man 2 lstat)</br>
	fstat (__fxstat) (man 2 fstat)</br>
	strtok (man 3 strtok)</br>
	wait (man 2 wait)</br>
	waitpid (man 2 waitpid)</br>
	wait3 (man 2 wait3)</br>
	wait4 (man 2 wait4)</br>
	write (man 2 write)</br>
  </div>
</div>


##COMPILATION CMD
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell

##RETURNS VALUE
	Return the status code : 0 (sucess), 127 or 2 (error).

##EXEMPLES

_Interactive :_

		./simple_shell
		$ ls

_Non-interactive :_

		echo "/bin/ls" | ./simple_shell

##MAN PAGE


##CHECK MEMORY LEAKS

	valgrind ./simple_shell

##AUTHORS

Erwan Rocal, Nadège Tettelin.
