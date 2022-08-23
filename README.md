# minishell
Custom shell in C
TODO:
[X]	Historique
[X] Lancer le bon exec ve, ex: cat lance la commande (xchouina)
[ ] Redirection ex: < , > , << delim, >> (ast-jean) ++mjarry
[ ] Pipes: Pimper les pipes (et ajouter dans le parsing) (xchouina) ++mjarry
[ ] Gérer les Variables d'env $ (attention a juste "=")
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
[X] Fonction pour free un double array (xchouina)
TOKNOW: 
	- Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).
	- Ne pas gérer les fuites avec readline 

 TOFIX  
[X]	- ft_arrayrm (xchouina)
	- signals get displayed
 

GOALS:

- Terminer le parsing avant tout



LOG:
22/08:	
	12:50 -	J'ai ajouté "ft_arrayfree" à la libft, puis ajouté cette fonction à 
			"ft_arrayrm", "ft_arrayadd", "ft_arraycpy". Cela semble causer des problèmes, à discuter.
	
	13:00 -	Ajouts des surlignements (NOTE) et (LOG), vous pourrez les ajouter vous aussi
			en regardant ci-dessous. J'ai utilisé le NOTE pour ajouter une description
			des nouvelles fonctions dans la libft.

23/08:
	9:40 - 


À Ajouter:

		{
            "text": "NOTE:",
            "color": "black",
            "backgroundColor": "#778899",
            "border": "1px",
            "borderRadius": "1px",
            "textDecoration": "none",
            "borderStyle": "solid",
            "isWholeLine": true,
        },
        {
            "text": "LOG:",
            "color": "white",
            "backgroundColor": "#191970",
            "border": "1px",
            "borderRadius": "1px",
            "borderStyle": "solid",
            "borderColor": "white",
        },
