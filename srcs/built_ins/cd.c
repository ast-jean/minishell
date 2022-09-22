#include "../../include/minishell.h"

// NOTE: Built-ins 4/4 (cd)

// // Returns index (int) of 'PWD=' in env
// int	finding_index(t_vars *vars, char *str, int n)
// {
// 	int	i;
// 	i = -1;
// 	while (vars->env[++i] != NULL)
// 	{
// 		if (ft_strnstr(vars->env[i], str, n) != NULL)
// 			return (i);
// 	}
// 			return (-1);		
// }

// int	builtin_cd(t_vars *vars)
// {
// 	t_token *token;
// 	// char **new_env;
// 	// char *oldpwd;
// 	int	i;
// 	int	j;

// 	token = vars->token->first;
// 	if (finding_pwd(vars) != -1)
// 		i = finding_pwd(vars);
// 	else
// 		return (0);
// 	// oldpwd = ft_strdup(vars->env[i]);
// 	// oldpwd = ft_strjoin("OLD", pwd);
// 	// dprintf(2, " i = %d\n", i);
// 	j = -1;
// 	while (vars->env[i][++j] != '\0');
// 	if (ft_strcmp(token->next->cont, "..") == 0)
// 	{
// 		while (vars->env[i][j] != '/')
// 		{
// 			vars->env[i][j] = '\0';
// 			j--;
// 		}
// 		// ft_substr();
// 	}
// 	else if (!ft_strcmp(token->next->cont, "..")) //?
// 	{
// 		ft_strjoin(token->cont, token->next->cont);
// 	}
// 	return (0);
// }

// void	changing_oldpwd(t_vars *vars)
// {
// 	int	p;
// 	int	o;
// 	char *new_oldpwd;

// 	p = finding_index(vars, "PWD=", 4);
// 	if (finding_index(vars, "OLDPWD=", 7) != -1)
// 	{
// 		o = finding_index(vars, "OLDPWD=", 7);
// 		free(vars->env[o]);
// 		vars->env[o] = ft_strjoin("OLD", vars->env[p]);
// 	}
// 	else
// 		ft_arrayadd(vars->env, ft_strjoin("OLD", vars->env[p]));
// }

// int	builtin_cd(t_vars *vars)
// {
// 	t_token	*token;
// 	int		p;

// 	token = vars->token->first;
// 	// changing_oldpwd(vars);
// 	p = finding_index(vars, "PWD=", 4);
// 	if (ft_strcmp(token->next->cont, ".") == 0)
// 	{
// changing_oldpwd(vars);
// 	}
// 	if ("..")
// 	changing_oldpwd(vars);
// 	if (NULL)
// 	changing_oldpwd(vars);
// 	if (dir existant)
// 	changing_oldpwd(vars);
// 	else
// 		// vars->env[p] = vars->env[p];
// }










//  NEW 
//  UPDATE VARS->ENV WHEN NEEDED
//  NEW 

int	builtin_cd(t_vars *vars)
{
	t_token *token;
	char s[100];
	// char *oldpwd;

	token = vars->token->first;
	// if (getenv("OLDPWD") != NULL)
	// 	oldpwd = ft_strjoin("OLDPWD=", getenv("PWD"));
	if (ft_strcmp(token->first->cont, "cd") == 0)
	{
		// ft_putstr_fd("IM IN!\n", 1);
		// if (ft_strcmp(chdir(".."), 0) == 0) NOTE: temp value?? ask baby
		// {
			// ft_putstr_fd("IM IN TOO!\n", 1);
			printf("OLDPWD=%s\n", getcwd(s, 100));
			chdir("..");
			// ft_putstr_fd(ft_strjoin(getenv("PWD"), "\n"), 1);
			printf("PWD=%s\n", getcwd(s, 100));
		// }
	}
	return (1);
}


















/* NOTE: 

- changer vars->pwd pour l'actuel pwd
- ajouter ft_substr pour le cd ..
- ajouter ft_strjoin pour le cd "something"
*/

/*

cd ..					| if (token->next->cont == "..")									--> must erase until '/'
cd .."something"		| if (token->next->cont[0] == '.' && token->next->cont[1] == '.')	--> must erase until '/' then add 'something'
cd "something"			| else if ("something" is directory)								--> must add 'something'

*/