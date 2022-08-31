# minishell
Custom shell in C
TODO:
[ ] Splitamary
[ ] check <<
	[ ] Remplacer << par filename (ast-jean)
	[ ] Creer le file et ajouter chaque ligne if(ligne != delim)
	[ ] effacer le delim token
	[ ] loop to next <<
[ ] Redirections
	[ ] <	rediriger l’entrée
	[ ] >	rediriger la sortie
	[ ] >>	rediriger la sortie en mode append
[ ] Pipes: looper les pipes (et ajouter dans le parsing)
[ ] Gérer les Variables d'env $ (attention a juste "=")
[ ] Gérer $?
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
	- signals get displayed
	- test splitamary cases:
		"'ec''ho'" + "'ec'ho"
		"$VAR"
		"<<"
		"<<hello"
-init-token_type.c

LOG:

Raccourcis git:

gaa	—> git add .
gst	—> git status
gc	—> git commit
gp	—> git push
gl	—> git pull
gco	—> git checkout
gm	—> git merge
gcl -> git clone