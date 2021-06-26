Write a C program implementing a  Unix shell.
Repeatedly prompt the user for commands, and execute those commands in
a child process.

FILE NAME =>vsh.c

ls -1 > out.txt
is equivalent in vsh to
ls -1 ::out.txt

less < in.txt
in vsh is equivalent to
less in.txt::

time ls -la /usr/bin
and the vsh equivalent is:
ls -la /usr/bin ##

