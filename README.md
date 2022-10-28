# minishell
Custom shell in C
TODO:
[ ] Gérer les Variables d'env $ (attention a juste "=")
[ ] Gérer $? - WIP
NEXT PHASE: 
[ ] General debugging
[ ] Freeing
	[ ] built_ins
	[ ] execution
	[ ] parsing
[ ] Norminette
	[ ] built_ins
	[ ] execution
	[ ] parsing
TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline
	- simple quotes = litéral

 TOFIX  
	- exit with exit code
	- Added Include/readline/ so people dont have to download on brew (we should link it in minishell.h)
	- $Variables
		- $>$USER"$HOME" $USER  ->  out: HOMEjean ast-jean
	- DANS CD : $>pwd | cd srcs
	- in:	$>cat<.s -> out:	Segmentation fault: 11
	- CD : weird error : "cd minishell" gives error messahe when minishell/ does exist and command does its job anyways
	- REDIRECTIONS : when one infile and one outfile not separated by pipe, segfaults
	- "echo '"



 LOG:

 Tests pour exam (what actually doesnt work)
 - if command is only spaces and/or tabs [X]
 - anything with %? (WIP, ik ik)
 - ctrl + C displays " $>^C " on the previous line -> more like a feature
 - ctrl + C after a blocking (hanging) command prints 2 x $> 
 - ctrl + \ after a blocking command (should quit a hanging command but should never quit shell)
 - cd sdfsdfsdf still sends 2 error reports [X]
 - If PATH is unset, cmds still work [X]
 - "cat | " crashes (empty pipes) [X]



Actual README underneath:

What leaks:

- check_var  [execution/variables.c]






Tests:

echo ''
echo hello""world
echo "$PWD"
echo '$PWD'
echo "aspas ->'"
echo "aspas -> ' "
echo 'aspas ->"'
echo 'aspas -> " '
echo "> >> < * ? [ ] | ; [ ] || && ( ) & # $  <<"
echo '> >> < * ? [ ] | ; [ ] || && ( ) & # $  <<'
echo "exit_code ->$? user ->$USER home -> $HOME"
echo 'exit_code ->$? user ->$USER home -> $HOME'
echo "$"
echo '$'
echo $
echo $?
echo $?HELLO
pwd
pwd oi
export
export hello
export HELLO=123
export A-
export HELLO=123 A
export HELLO="123 A-"
export hello world
export HELLO-=123
export =
export 123
unset
unset HELLO
unset HELLO1 HELLO2
unset HOME
unset PATH
unset SHELL
cd $PWD
cd $PWD hi
cd 123123
exit 123
exit 298
exit +100
exit "+100"
exit +"100"
exit -100
exit "-100"
exit -"100"
exit hello
exit 42 world
exit 9223372036854775807
exit 9223372036854775808
exit -9223372036854775807
exit -9223372036854775808
exit -9223372036854775809

env | sort | grep -v SHLVL | grep -v ^_
export | sort | grep -v SHLVL | grep -v "declare -x _" | grep -v "PS.="
cat ./test_files/infile_big | grep oi
cat minishell.h | grep ");"$
export GHOST=123 | env | grep GHOST
grep hi <./test_files/infile
grep hi "<infile" <         ./test_files/infile
echo hi < ./test_files/infile bye bye
grep hi <./test_files/infile_big <./test_files/infile
echo <"./test_files/infile" "bonjour       42"
cat <"./test_files/file name with spaces"
cat <./test_files/infile_big ./test_files/infile
cat <"1""2""3""4""5"
echo <"./test_files/infile" <missing <"./test_files/infile"
echo <missing <"./test_files/infile" <missing
cat <"./test_files/infile"
echo <"./test_files/infile_big" | cat <"./test_files/infile"
echo <"./test_files/infile_big" | cat "./test_files/infile"
echo <"./test_files/infile_big" | echo <"./test_files/infile"
echo hi | cat <"./test_files/infile"
cat <"./test_files/infile" | echo hi
cat <"./test_files/infile" | grep hello










<h1 align="center">MINISHELL</h1>
<p align="center">Un shell minimaliste</p>

## Why:

Minishell is a school team-working project aiming to recreate our own bash.


## How To Use:

Use 'make' then execute './minishell' to start the program. You may use different commands to test the project (see examples below). 


## Examples:

Commands like 'cat', 'ls', 'grep', 'wc', etc. can be used to test the project.<br>
Single quotes and double quotes works the same as bash.<br>
Redirections ('<', '>', '<<', '>>') and pipes ('|') work as well.<br>
Built-ins were also made from scratch (cd, echo, env, export, exit, pwd, unset).<br>
Ctrl+C, Ctrl+D and Ctrl+\ are implemented the same way as bash.<br>


## Credits:

This project was made by the hard-work of Adam St-Jean Lejeune ([astjean](https://github.com/ast-jean)), Marie-Soleil Jarry ([mjarry](https://github.com/mariejarry)) and Xavier Chouinard ([xchouina](https://github.com/xchouina)).
