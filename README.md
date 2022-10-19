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
	- REDIRECTIONS : when one infile and one outfile not separated by pipe, segfaults




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



# MINISHELL

## Why:

Minishell is a school team-working project aiming to recreate our own bash.


## How To Use:

Use 'make' then execute './minishell' to start the program. You may use different commands to test the project (see examples below). 


## Examples:

Commands like 'cat', 'ls', 'grep', 'wc', etc. can be used to test the project.<br>
Single quotes and double quotes works the same as bash.<br>
Redirections ('<', '>', '>>', '<<') and pipes ('|') work as well.<br>
Built-ins were also made from scratch (cd, echo, env, export, exit, pwd, unset).<br>
Ctrl+C, Ctrl+D and Ctrl+\ are implemented the same way as bash.<br>


## Credits:

This project was made by the hard-work of Adam St-Jean Lejeune ([astjean](https://github.com/ast-jean)), Marie-Soleil Jarry ([mjarry](https://github.com/mariejarry)) and Xavier Chouinard ([xchouina](https://github.com/xchouina)).
