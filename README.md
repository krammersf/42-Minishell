# 42_Minishell
Shell implementation called Minishell
minishell

This is a shell implementation called Minishell. It is a command-line interpreter that provides a basic shell environment and supports various features such as command execution, input parsing, redirections, pipes, environment variables, built-in commands, and signal handling.

This project was developed in colaboration with teroVF.
Words of Wisdom
Focus on the requirement 🎯

Please implement only what the subject explicitly requests. Anything that is not requested is not a requirement, and each additional implementation increases development time and adds unnecessary complexity to the project.
Perform extensive testing 🔬

This project has many points of attention that have arisen during development. All of these points have been included in the tests on this page. While not exhaustive, they provide a starting point for things that should work and things that should not. Check the tests
Study other shells 🔍

Our reference shell is Bash, but running certain commands in other shells may produce different results and help us better understand why certain things happen. Use Bash as a reference, but be open to examining the workings of other shells.
Features

    Prompt display: Minishell displays a prompt when waiting for a new command.
    Command history: It has a working history feature that allows navigating and reusing previous commands.
    Command execution: Minishell can search and launch the appropriate executable based on the PATH variable or using a relative or absolute path.
    Quoting: It handles single quotes ', preventing the interpretation of meta-characters within the quoted sequence. Double quotes " prevent the interpretation of meta-characters except for the dollar sign $.
    Redirections: Minishell supports input <, output > and append output >> redirections. It also handles here documents << where input is read until a line containing the specified delimiter.
    Pipes: It implements pipes | to connect the output of one command to the input of the next command in a pipeline.
    Environment variables: Minishell handles the expansion of environment variables ($ followed by a sequence of characters) to their respective values.
    Special variables: It supports the special variable $? which expands to the exit status of the most recently executed foreground pipeline.
    Signal handling: Minishell handles signals such as ctrl-C (SIGINT), ctrl-D (EOF), and ctrl-\ (SIGQUIT) according to the specified behavior in the subject.
    Built-in commands: It provides several built-in commands, including echo, cd, pwd, export, unset, env, and exit, with their respective options and arguments.

Implementation Details

    The shell uses the readline library to provide line editing capabilities and command history.
    Input parsing is done using a combination of string manipulation and state tracking to handle quotes and command boundaries.
    Command execution is managed through a commands_manager function that handles the execution of commands, including pipe setup and file descriptor management.
    Built-in commands are implemented as separate functions and are executed within the shell process itself.
    Error handling and reporting are done through a combination of error codes, error messages, and signal handling.

Usage

To compile the Minishell program, use the provided Makefile by running make in the project directory. This will generate an executable named minishell.

make

To run the Minishell program, simply execute the generated minishell binary.

./minishell

Once running, you can enter commands and interact with the shell.
Requirements

    The Libft library is required and provided along with the project files.
    The program was developed and tested on a Unix-based system. Compatibility with other platforms may vary.

Limitations

    Minishell does not interpret unclosed quotes or special characters that are not required by the subject, such as backslashes \ or semicolons ;.
    The readline() function used in Minishell may cause memory leaks, but the code written specifically for this project should not have memory leaks.

Tests
Check -Wall -Wextra -Werror

make -n

    gcc -Wall -Wextra -Werror -c src/main.c -o obj/main.o

Simple Command

/bin/ls

    include libft Makefile minishell minishell_tester src

date

    Wed 7 Jul 2021 11:00:00 AM -03

ifconfig

    network information

who

    wcorrea- tty2 2023-06-20 10:46 (tty2)

[empty]

    print a new line

[space]

    print a new line

[tab]

    do nothing

Command with Arguments

touch 1 2 3

    create 3 files

/bin/ls -l

    list files with details

rm 1 2 3

    remove 3 files

cat Makefile

    print the content of the Makefile

cat -e Makefile

    print the content of the Makefile with $ at the end of each line

wc -l Makefile

    55 Makefile

echo

echo

    print a new line

echo This is a test

    This is a test

echo -n Hello World

    Hello World/home/wcorrea-$

exit

exit

    exit the minishell

exit 1

    exit the minishell with return code 1

exit 42

    exit the minishell with return code 42

exit -42

    exit the minishell with return code 214

exit 42 10

    minishell: exit: too many arguments

exit 42scholl

    minishell: exit: numeric argument required; then exit with error code 2

Return value of a process

echo $?

    0

/bin/ls

    then run echo $?; the return code is 0

ls notexist

    then run echo $?; the return code is 2

/bin/notexist

    then run echo $?; the return code is 127

expr $? + $?

    then run echo $?; the return code is 2

Signals

ctrl-C on empty prompt

    display a new line with a new prompt
    echo $? must display 130

ctrl-\ on empty prompt

    do nothing

ctrl-D on empty prompt

    quit minishell
    echo $? must display 0

ctrl-C after write some stuff

    display a new line with a new prompt
    echo $? must display 130

ctrl-\ after write some stuff

    do nothing

ctrl-D after write some stuff

    do nothing

ctrl-C in cat without arguments

    ^C
    echo $? must display 130

ctrl-\ in cat without arguments

    \Quit (core dumped)
    echo $? must display 131

ctrl-D in cat without arguments

    close interactive mode
    echo $? must display 0

Double Quotes

"/bin/ls"

    execute ls

""ls""

    execute ls

""ls -l""

    execute ls with details

"""ls -l"""

    minishell: ls -l: command not found

"echo Hello World"

    minishell: echo Hello World: command not found

echo "Hello World"

    Hello World

echo "with       spaces"

    Hello World

echo "test with %specials *chars"

    test with %specials *chars

echo "cat lol.c cat > Iol.c"

    cat lol.c cat > Iol.c

echo "

    minishell: unclosed quotes

Single Quotes

'/bin/ls'

    execute ls

''ls''

    execute ls

''ls -l''

    execute ls with details

'''ls -l'''

    minishell: ls -l: command not found

'echo Hello World'

    minishell: echo Hello World: command not found

echo 'Hello World'

    Hello World

echo 'with       spaces'

    Hello World

echo '$USER'

    $USER

echo '

    minishell: unclosed quotes

echo '$HOME > home.txt'

    $HOME > home.txt

echo '$?'

    $?

env

env

    print the environment variables

env PATH

    minishell: env: Arguments and options aren't supported

export

export

    print the exported environment variables

export NEW_VAR=42

    add NEW_VAR with content 42

export NEW_VAR="A little change"

    replace the value of NEW_VAR

export NEW_VAR=

    replace the content of NEW_VAR to empty

export NEW_VAR=$USER

    replace the value of NEW_VAR

export NEW_VAR="with unclosed quotes

    minishell: unclosed quotes

export -p NEW_VAR

    minishell: export: options aren't supported

export NEW_VAR="   -l  |"

    replace the content of NEW_VAR to ' -l |'

unset

unset NEW_VAR

    remove the environment variable

unset -n NEW_VAR

    minishell: unset: options aren't supported

cd

cd .

    stay in the same directory

cd . ls

    minishell: cd: too many arguments

cd ..

    go to the parent directory

cd /usr/bin

    go to the /usr/bin directory

cd

    go to the home directory

cd notexist

    minishell: cd: notexist: No such file or directory

pwd

pwd

    /home/wcorrea-/workplace/common_core/minishell/minishell

pwd -L

    minishell: pwd: options aren't supported

Relative Path

./minishell

    execute the minishell inside minishell

../../../../../../bin/ls

    include libft Makefile minishell minishell_tester src

Environment path

echo $PATH

    /home/wcorrea-/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin

unset PATH

    remove the PATH environment variable

ls

    minishell: ls: command not found

export PATH=/bin:/usr/bin

    set the PATH environment variable with the basic path again

Redirection

ls -l > test

    create a file with the files list inside

cat Makefile >> test

    append the content of the Makefile to the file

wc -l < test

    63

wc -c < test > test_out

    test_out receive the number of characters in the file test

cat << EOF

    start the here document

cat << EOF | wc -l

    print the number of lines in the here document

Pipes

cat Makefile | grep NAME | wc -l

    5

cat notexist | wc -l

    cat: notexist: No such file or directory 0

< Makefile grep NAME | wc -l > out

    put the result in out

Go Crazy and history

up down to navigate in the history

 dsfdfdfd

    minishell: command not found

wc -l < /etc/passwd > file1 > file2 > file3 > file4

    write the result in the last redirection

cat | cat | ls

    print list files and open the interactive mode

Environment variables

echo $USER

    wcorrea-

echo $notexist

    print an empty line

echo "$HOME"

    /home/wcorrea-

echo ~

    /home/wcorrea-

echo ~test

    ~test

echo test~

    test~

echo ~/test

    /home/wcorrea-/test

Trouble Cases

$EMPTYVAR

    show a new prompt line

echo -n -n -n -n -n Hello World

    Hello World/home/wcorrea-$

echo -nnnnnnnnn Hello World

    Hello World/home/wcorrea-$

echo $HOME.test

    /home/wcorrea-.test

echo $HOME/test

    /home/wcorrea-/test

;

    minishell: no support for operator `;'

*

    minishell: no support for operator `*'

>

    minishell: syntax error near unexpected token `newline'

<

    minishell: syntax error near unexpected token `newline'

< .

    minishell: syntax error near unexpected token `newline'

>>

    minishell: syntax error near unexpected token `newline'

<<

    minishell: syntax error near unexpected token `newline'

|

    minishell: syntax error near unexpected token `|'

d|

    minishell: no support for pipe prompt

ls | wc |

    minishell: no support for pipe prompt

ls | wc >

    minishell: syntax error near unexpected token `newline'

ls | wc <

    minishell: syntax error near unexpected token `newline'

ls | wc <<

    minishell: syntax error near unexpected token `newline'

ls | wc >>

    minishell: syntax error near unexpected token `newline'

ls | cat << > | wc

    minishell: syntax error near unexpected token `<< '

export =

    minishell: export: `=': not a valid identifier

export =test

    minishell: export: `=test': not a valid identifier

export TEST.=test

    minishell: export: `TEST.=test': not a valid identifier

export 1TEST=test

    minishell: export: `1TEST=test': not a valid identifier

export TEST=ABCD

    create a var TEST with content ABCD

export $TEST=1234

    create a var ABCD with content 1234

export $ABCD=more

    minishell: export: `1234=more': not a valid identifier

export a_test b_test

    create tmp vars without content

unset a_test

    remove the tmp var a_test

export b_test=1234

    transform the tmp var b_test in a environment var with content 1234

unset b_test

    remove the environment var b_test

export TEST1="withdouble" TEST2 TEST3=wihoutquotes TEST4="with spaces and expand $USER" TEST5="ok, but it has more" TEST6= TEST7='with single $PATH' = TEST8 9TEST9 TEST10="" TEST11=too=many=equals TEST.12="    " TEST13='withsingle' TEST14/

    This test will try to create environment vars and tmp vars with different cases. Check the difference with env and export commands

unset TEST1 TEST2 TEST3 TEST4 TEST5 TEST6 TEST7 TEST8 9TEST9 TEST10 TEST11 TEST.12 TEST13 TEST14/

    unset all these variables that were valid

Not required but done

cd -

    go to the previous directory

<< EOF

    start the here document

> file

    create a file

>> file

    append to a file

Grade: 100/100
Used tests

    minishell_tester: https://github.com/kichkiro/minishell_tester
