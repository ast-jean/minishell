# minishell
Custom shell in C
TODO:
[X]	Historique
[X] Lancer le bon exec ve, ex: cat lance la commande (xchouina)
[ ] Redirections
	[ ] <	rediriger l’entrée
	[ ] >	rediriger la sortie
	[ ] <<	heredoc (document temp.) ? ouvrir fd sans fichier? mmmmh?
	[ ] >>	rediriger la sortie en mode append
[ ] Pipes: Pimper les pipes (et ajouter dans le parsing) (xchouina) ++mjarry
[ ] Gérer les Variables d'env $ (attention a juste "=")
[ ] Gérer $?
[X] Gérer les signaux ctrl-C, ctrl-D, ctrl-\
	[X] ctrl-C
	[X] ctrl-D quitte le shell. (done)
	[X] ctrl-\ ne fait rien.
[ ] Créer les buitins
	[ ] echo (with -n) (mjarry)
	[ ] cd (only relative path or absolute)(changer PATH et OLDPATH) (mjarry)
	[ ] export (no flag) -ungoing- (ast-jean)
	[ ] unset (no flag) (ast-jean)
	[X] pwd (no flag)
	[X] env (no flag)
	[X] exit (no flag)
[X] Fonction pour free un double array (xchouina)
TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline 

 TOFIX  
[X]	- ft_arrayrm (xchouina)
	- signals get displayed
	- new_split cases:
		"'ec''ho'" + "'ec'ho"
		"$VAR"



GOALS:

- Gérer les pipes ensemble



LOG:

Raccourcis git:

gaa	—> git add .
gst	—> git status
gc	—> git commit
gp	—> git push
gl	—> git pull
gco	—> git checkout
gm	—> git merge
