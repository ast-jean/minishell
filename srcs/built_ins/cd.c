#include "../../include/minishell.h"

// NOTE: Built-ins 4/4 (cd)

// Returns index (int) of 'PWD=' in env
int	finding_pwd(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->env[++i] != NULL)
	{
		if (ft_strnstr(vars->env[i], "PWD=", 4) != NULL)
			return (i);
	}
			return (-1);		
}

int	builtin_cd(t_vars *vars)
{
	t_token *token;
	char **new_env;
	char *oldpwd;
	int	i;
	int	j;

	token = vars->token->first;
	if (finding_pwd(vars) != -1)
		i = finding_pwd(vars);
	else
		return (0);
	oldpwd = ft_strdup(vars->env[i]);
	dprintf(2, " i = %d\n", i);
	j = -1;
	while (vars->env[i][++j] != '\0');
	if (ft_strcmp(token->next->cont, "..") == 0)
	{
		while (vars->env[i][j] != '/')
		{
			vars->env[i][j] = '\0';
			j--;
		}
		ft_substr();
	}
	else if (!ft_strcmp(token->next->cont, "..")) //?
	{
		ft_strjoin(token->cont, token->next->cont);
	}
	return (0);
}

// Returns new pwd path (str)
char *cd_parameters(t_vars *vars, )
{

}

// PWD=/Users/xchouina/CURSUS/8. minishell/minishell/testdir

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