# minishell
Custom shell in C
TODO:
	[X]	Historique
	[ ] Lancer le bon exec ex: cat lance la commande
	[ ] Redirection ex: < , > , << , >>
	[ ] Pipes
	[ ] Gérer les Variables d'env $ (attention a just "=")
	[ ] Gérer $?  
	[X] Gérer les signaux ctrl-C, ctrl-D, ctrl-\
		◦ ctrl-C
		◦ ctrl-D quitte le shell. (done)
		◦ ctrl-\ ne fait rien.
	[ ] Créé les buitins
		[ ] echo (with -n)
		[ ] cd (only relative path or absolute)
		[X] pwd (no flag)
		[ ] export (no flag)
		[ ] unset (no flag)
		[X] env (no flag)
		[X] exit (no flag)
TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
	demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline 

FIXME: 


TODO:
//-Not yet done-
[X]arrayprint
[X]arraylen
[X]arrayadd (needs further testing)
[X]arraycpy (needs further testing)
[ ]arraysrch
[ ]strcpy
