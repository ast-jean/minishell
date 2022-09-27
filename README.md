# minishell
Custom shell in C
TODO:
[X] Splitamary
[ ] check <<
	[ ] $Var within <<
	[ ] Signal ctrl-C close heredoc
[X] Redirections
	[X] <	rediriger l’entrée
	[X] >	rediriger la sortie
	[X] >>	rediriger la sortie en mode append
[X] Pipes: looper les pipes (et ajouter dans le parsing)
[ ] Gérer les Variables d'env $ (attention a juste "=")
[ ] Gérer $?
[ ] Add $Vars and remove_quotes()
[ ] Créer les buitins
	[ ] echo (with -n) (xchouina)
	[ ] cd (only relative path or absolute)(changer PATH et OLDPATH) (xchouina)
	[ ] export (no flag)	-started-
	[ ] unset (no flag)		-started-
	[X] pwd (no flag)
	[X] env (no flag)
	[X] exit (no flag)
TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline
	- simple quotes = litéral

 TOFIX  
	- After error with << <<< it stil tries to run the command
	- exit with exit code
	- Added Include/readline/ so people dont have to download on brew (we should link it in minishell.h)
	- $VAR if it's a $ with an exception(!<>|'"?#+-% ) maybe ft_alnum following
		Ex: in: "hello$" -> out: hello$
		Ex: in: "hello$v" -> out: hello
		Ex: in: "hello$@" -> out: hello
	- $VAR double quotes -> first doesn't work [X]
	- $VAR single quotes -> second doesn't work [X]
	- Echo: should display a space between arguments ex: $>echo aa aa% out: aa aa% instead of: aaaa
	- Echo: doesnt work with only one char
	- Herestring broken with token changes
	- Echo: doesnt work with only one char as first argument
