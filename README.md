# FemtoUtils

This repo includes the following unix utilities which are built on system calls:
* echo
* pwd
* cp
* mv

Compilation command for each utility:

```
$ gcc echo.c -o echo
$ gcc pwd.c -o pwd
$ gcc cp.c -o cp
$ gcc mv.c -o mv
```

$echo run example:
```
$ ./echo Hello From Linux!
Hello From Linux! 
```
$pwd run example:
```
$ ./pwd
/home/wizo/workarea/FemtoUtils
```
$cp run example:
```
$ ./cp /etc/passwd mypasswd
$ ls
cp  cp.c  echo  echo.c  mv  mv.c  mypasswd  pwd  pwd.c
$ diff /etc/passwd mypasswd
$
```
As you can see there is no difference between the original and copy files.

$mv run example:
```
$ ./mv mypasswd ../mypasswd
$ ls
cp  cp.c  echo  echo.c  mv  mv.c  pwd  pwd.c
$ ls ../
FemtoShell  FemtoUtils  mypasswd
```
As you can see the file is moved up.
