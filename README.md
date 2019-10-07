# 21sh: As beautiful as Bash
I think for anyone who reading this knows what's the shell and probably using everyday. The goal of this project is to make our own shell, which works just like other similiar ones. Since there's already plenty of shell, serves for different kinds of propers, why do we have to reinvent the wheel? The reason is, althrough we use shell in daily basis, but for most of coders, shell works like a black box. We input command, and command been execute, life goes on...Shell do a lots of job under the table that we rarely noticed. <br>
What's the best way to understand how shell works? The 42 way is...make one from scratch! Ok...probably reading document is more practical in any scene lol, but it's cool isn't it? Through this project, we will get to the core of the Unix system and explore an important part of this system’s API: process creation and synchronisation, plus compile, interpret command receive from user input, just like real shell! We will utilize Termcap library to manipulate terminal.

## Objectives
Of course we didn't been ask to make a fully functional shell, that probably gonna take years...but some mandetory part we were been ask to completed, can make this shell works like a nerf verison of a real shell.<br>

1. User can execute command
2. Some built-in function, like setting environment, move directory etc.
3. Allow command line operators like '|', '<', '>', '<<', '>>', ';'
4. Keyboard shortcuts like cut, paste, copy etc.
5. Cursor manipulation like move cursor by words
6. Record command history, recall by up & down arrow

## User guide

### How to start
Build the execuatble call '21sh' by makefile
'''
make
'''
After build, run the shell
'''
./21sh
'''
Input the command line just like some other shell
'''
// For instance
21sh> ls -la
'''

### Build-in command
You must implement a series of builtins: echo, cd, setenv, unsetenv, env, exit.
You must manage expansions $ and  ̃


## Prior knowledge in Linux

### File structure

### Command execution path




## Line edition

### Termcap




## Tokenize






## Abstract Syntax Tree (AST)

### Pipeline: process synchronisation

### Shell grammar







## Execute AST
