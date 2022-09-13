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
[ ] Créer les buitins
	[ ] echo (with -n)
		[ ] Add $Vars and remove_quotes()
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

LOG:

	- ADDED HIGHLIGHT (NEW) to use along with [x][a][m] to indicate new stuff to read in the README



        {
            "text": "NEW",
            "color": "black",
            "backgroundColor": "#FF7F50",
            "border": "1px",
            "borderRadius": "1px",
            "textDecoration": "none",
            "borderStyle": "solid",
            "isWholeLine": true,
        },


Raccourcis git:
	gaa	—> git add .
	gst	—> git status
	gc	—> git commit
	gp	—> git push
	gl	—> git pull
	gco	—> git checkout
	gm	—> git merge
	gcl -> git clone