# minishell
Custom shell in C
TODO:
[X]	Historique
[ ] Lancer le bon exec ve, ex: cat lance la commande
[ ] Redirection ex: < , > , << delim, >>
[ ] Pipes ( et ajouter dans le parsing)
[ ] Gérer les Variables d'env $ (attention a just "=")
[ ] Gérer $?  
[X] Gérer les signaux ctrl-C, ctrl-D, ctrl-\
	[X] ctrl-C
	[X] ctrl-D quitte le shell. (done)
	[X] ctrl-\ ne fait rien.
[ ] Créé les buitins
	[ ] echo (with -n)
	[ ] cd (only relative path or absolute)(changer PATH et OLDPATH)
	[X] pwd (no flag)
	[ ] export (no flag) -ungoing-
	[ ] unset (no flag) 
	[X] env (no flag)
	[X] exit (no flag)
TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline 

 TOFIX  
	- ft_arrayrm
	- signals get displayed

