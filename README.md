# minishell
Custom shell in C

TODO:
	- Historique -DONE-
	- Lancer le bon exec ex: cat lance la commande
	- Redirection ex: < , > , << , >>
	- Pipes
	- Gérer les Variables d'env $ (attention a just "=")
	- Gérer $?  
	- Gérer les signaux ctrl-C, ctrl-D, ctrl-\ -DONE-
		◦ ctrl-C 
		◦ ctrl-D quitte le shell. (done)
		◦ ctrl-\ ne fait rien.
	- Créé les buitins
		- echo (with -n)
		- cd (only relative path or absolute)
		- pwd (no flag) -DONE-
		- export (no flag)
		- unset (no flag)
		- env (no flag) -DONE-
		- exit (no flag) -DONE-
TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
	demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline 

FIXME: 