# minishell
Custom shell in C
TODO:
[ ] Redirections
	[ ] <	rediriger l’entrée
	[ ] >	rediriger la sortie
	[ ] >>	rediriger la sortie en mode append
[ ] Pipes: Pimper les pipes (et ajouter dans le parsing) (xchouina) ++mjarry
[ ] Gérer les Variables d'env $ (attention a juste "=")
[ ] Gérer $?
[ ] Créer les buitins
	[ ] echo (with -n) (mjarry)
	[ ] cd (only relative path or absolute)(changer PATH et OLDPATH) (mjarry)
	[ ] export (no flag) -ungoing- (ast-jean)
	[ ] unset (no flag) (ast-jean)
	[X] pwd (no flag)
	[X] env (no flag)
	[X] exit (no flag)
[ ] Split la pompt line
[ ] Gérer les heredocs

TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline 

 TOFIX  
	- signals get displayed
	- new_split cases:
		"'ec''ho'" + "'ec'ho"
		"$VAR"
- execution_cmd.c
-init-token_type.c

LOG:

Raccourcis git:

gaa	—> git add .
gst	—> git status
gc		—> git commit
gp	—> git push
gl		—> git pull
gco	—> git checkout
gm	—> git merge
