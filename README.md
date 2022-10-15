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
	- DANS CD : $>pwd | cd srcs
	- in:	$>cat<.s -> out:	Segmentation fault: 11
	- CD : weird error : "cd minishell" gives error message when minishell/ does exist and command does its job anyways
	- REDIRECTIONS : when one infile and one outfile not separated by pipe, segfaults
