# minishell
Custom shell in C
TODO:
[X] Splitamary
[ ] check <<
	[ ] $Var within <<
	[ ] Signal ctrl-D close heredoc
[ ] Redirections
	[ ] <	rediriger l’entrée
	[ ] >	rediriger la sortie
	[ ] >>	rediriger la sortie en mode append
[ ] Pipes: looper les pipes (et ajouter dans le parsing)
[ ] Gérer les Variables d'env $ (attention a juste "=")
[ ] Gérer $?
[ ] Add $Vars and remove_quotes()
[ ] Créer les buitins
	[ ] echo (with -n)
	[ ] cd (only relative path or absolute)(changer PATH et OLDPATH)
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
	- signals get displayed //dont care
	- when quotes are not closed it creates SEGFAULT. should be fixed in tokenize
		- also check check_quotes() in syntax_error.c
