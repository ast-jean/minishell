# minishell
Custom shell in C
TODO:
[ ] Gérer les Variables d'env $ (attention a juste "=")
[ ] Gérer $?
[ ] General debugging
[ ] Freeing
	[ ] built_ins
	[ ] execution
	[ ] parsing
[ ] Norminette
	[X] built_ins
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
		- $VAR if it's a $ with an exception(!<>|'"?#+-% ) maybe ft_alnum following
			Ex: in: "hello$" -> out: hello$
			Ex: in: "hello$v" -> out: hello
			Ex: in: "hello$@" -> out: hello
		- $>$USER"$HOME" $USER  ->  out: HOMEjean ast-jean
	- Echo: doesnt work with only one char as first argument [X]
	- Herestring broken with token changes [X]
	- DANS CD : $>pwd | cd srcs
	- in:	$>cat<.s -> out:	Segmentation fault: 11
	- Echo: should display a space between arguments ex: $>echo aa aa% out: aa aa% instead of: aaaa [X]
	- $VAR double quotes -> first doesn't work [X]
	- Herestring broken with token changes
	- DANS CD : $>pwd | cd srcs
	- ECHO : space at the end to remove ex echo test | cat -e should be "test$" [X]
	- CD : weird error : "cd minishell" gives error messahe when minishell/ does exist and command does its job anyways
	- REDIRECTIONS : when one infile and one outfile not separated by pipe, segfaults
