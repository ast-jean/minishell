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






// void	dispatching_dir(t_vars *vars)
// {
// 	t_token	*token;
// 	char	s[100];
// 	token = vars->token->first;

// 	printf("AFTER CD =	%s\n", getcwd(s, 100));
// 	printf("AFTER CD =	%s\n", getenv("PWD"));
// 	// 	// dprintf(2, "TOKEN->NEXT->CONT = [%s]\n", token->next->cont);
// 	// 	// dprintf(2, "---------------------\n");
// 	// if (ft_strcmp(token->next->cont, "..") == 0)
// 	// 	chdir("..");
// 	// if (ft_strcmp(token->next->cont, "~") == 0 || ft_strcmp(token->next->cont, NULL) == 0)
// 	// 	chdir(getenv("HOME"));
// 	// if (ft_strcmp(token->next->cont, ".") == 0);
// 	// else
// 		// chdir(token->next->cont);
// 	// dprintf(2, "PWD = %s\n", getenv("PWD"));
// 	// if (ft_strcmp(token->next->cont, "srcs") == 0)
// }

// int	builtin_cd(t_vars *vars, char **env)
// {
// 	t_token	*token;
// 	char	*oldpwd;

// 	oldpwd = ft_arraysrch(vars->env, "PWD=") + 4;
// /*debug*/	//ft_putstr_fd(oldpwd, 1);
// 	token = vars->token->first;
// 	dispatching_dir(vars);
	
// 	// free2d(vars->env);
// 	vars->env = ft_arraycpy(env);

// 	changing_oldpwd(vars);
// 	// dprintf(2, "PWD = %s\n", check_var("PWD="));
// 	return (1);
// }






// NEW 



int	finding_index(t_vars *vars, char *str, int n)
{
	int	i;
	i = -1;
	while (vars->env[++i] != NULL)
	{
		if (ft_strnstr(vars->env[i], str, n) != NULL)
			return (i);
	}
			return (-1);		
}

void	changing_oldpwd(t_vars *vars, char *oldpwd)
{
	int	o;

	o = finding_index(vars, "OLDPWD=", 7);
	if (o != -1)
		vars->env[o] = oldpwd;
	else
		ft_arrayadd(vars->env, ft_strjoin("OLDPWD=", vars->cd_oldpwd));
}

void	changing_pwd(t_vars *vars)
{
	int		p;
	char	s[1000];

	if (finding_index(vars, "PWD=", 4) != -1)
	{
		p = finding_index(vars, "PWD=", 4);
		vars->env[p] = ft_strjoin("PWD=", getcwd(s, 1000));
	}
}


int	builtin_cd(t_vars *vars, char **env)
{
	t_token *token;
	char *new_oldpwd;

	char s[100];
	token = vars->token->first->next;
	if (token)
		token->cont = remove_quotes(token->cont);
	vars->cd_oldpwd = getenv("PWD");
	getcwd(s, 100);
	if (!token || ft_strcmp(token->cont, "~") == 0)
		chdir(getenv("HOME"));
	else if (token && ft_strcmp(token->cont, ".") == 0);
	else if (token && chdir(token->cont) != 0)
			return (dprintf(2, "cd: no such file or directory: %s\n", token->cont));
	vars->env = ft_arraycpy(env);
	new_oldpwd = ft_strjoin("OLDPWD=", s);
	changing_oldpwd(vars, new_oldpwd);
	changing_pwd(vars);
	return (1);
}















// {
// 	t_token *token;
// 	char s[100];
// 	// char *oldpwd;

// 	token = vars->token->first;
// 	// if (getenv("OLDPWD") != NULL)
// 	// 	oldpwd = ft_strjoin("OLDPWD=", getenv("PWD"));
// 	if (ft_strcmp(token->first->cont, "cd") == 0)
// 	{
// 		// ft_putstr_fd("IM IN!\n", 1);
// 		// if (ft_strcmp(chdir(".."), 0) == 0) NOTE: temp value?? ask baby
// 		// {
// 			// ft_putstr_fd("IM IN TOO!\n", 1);
// 			printf("OLDPWD=%s\n", getcwd(s, 100));
// 			chdir("..");
// 			// ft_putstr_fd(ft_strjoin(getenv("PWD"), "\n"), 1);
// 			printf("PWD=%s\n", getcwd(s, 100));
// 		// }
// 	}
// 	return (1);
// }


















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