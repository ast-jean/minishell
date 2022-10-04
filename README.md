# minishell
Custom shell in C
TODO:
[X] Splitamary
[X] check <<
	[X] $Var within <<
	[X] Signal ctrl-C close heredoc
[X] Redirections
	[X] <	rediriger l’entrée
	[X] >	rediriger la sortie
	[X] >>	rediriger la sortie en mode append
[X] Pipes: looper les pipes (et ajouter dans le parsing)
[ ] Gérer les Variables d'env $ (attention a juste "=")
[ ] Gérer $?
[X] Add $Vars and remove_quotes()
[ ] Créer les buitins
	[X] echo
	[X] cd
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
	- exit with exit code
	- Added Include/readline/ so people dont have to download on brew (we should link it in minishell.h)
	- $VAR if it's a $ with an exception(!<>|'"?#+-% ) maybe ft_alnum following
		Ex: in: "hello$" -> out: hello$
		Ex: in: "hello$v" -> out: hello
		Ex: in: "hello$@" -> out: hello
	- Echo: doesnt work with only one char as first argument
	- $VAR double quotes -> first doesn't work [X]
	- Herestring broken with token changes
	- DANS CD : $>pwd | cd srcs
	- Echo:
		- $>echo $USER"$HOME" $USER  ->  out: HOMEjean ast-jean
		- $>echo -> out: Segmentation fault: 11
	- in:	$>cat<.s -> out:	Segmentation fault: 11
