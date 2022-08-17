# minishell
Custom shell in C
TODO:
[X]	Historique
[ ] Lancer le bon exec ve, ex: cat lance la commande (xchouina)
[ ] Redirection ex: < , > , << delim, >> (ast-jean) ++mjarry
[ ] Pipes: Pimper les pipes ( et ajouter dans le parsing) (xchouina) ++mjarry
[ ] Gérer les Variables d'env $ (attention a just "=")
[ ] Gérer $?
[X] Gérer les signaux ctrl-C, ctrl-D, ctrl-\
	[X] ctrl-C
	[X] ctrl-D quitte le shell. (done)
	[X] ctrl-\ ne fait rien.
[ ] Créé les buitins
	[ ] echo (with -n) (mjarry)
	[ ] cd (only relative path or absolute)(changer PATH et OLDPATH) (mjarry)
	[ ] export (no flag) -ungoing- (ast-jean)
	[ ] unset (no flag) (ast-jean)
	[X] pwd (no flag)
	[X] env (no flag)
	[X] exit (no flag)
TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline 

 TOFIX  
	- ft_arrayrm
	- signals get displayed
 

GOALS:

- Terminer le parsing avant tout
