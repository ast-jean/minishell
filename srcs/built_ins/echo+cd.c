#include "../../include/minishell.h"
// NOTE: Built-ins 3/3 (Echo + CD)
int	is_n(char *str)
{
	int	i;
	
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

char *rm_quotes_echo(char *old)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new = malloc(sizeof(char*) * ft_strlen(old));
	while (old[++i] != '\n')
	{
		if (old[i] != '\"' || old[i] != '\'')
			i++;
		else
			new[j++] = old[i];
	}
	// new[j] = '\0';
	return (new);
}

int	builtin_echo(t_vars *vars)
{
	t_token *token;
	bool	n;

		// if (is_n(token->cont))
	token = vars->token->next;
	while (is_n(remove_quotes(token->cont)))
	{
		n = true;
		token = token->next;
	}
	while (token && ft_strcmp(token->cont, "|") != 0)
	{
		ft_putstr_fd(remove_quotes(token->cont), 1);
		// if (token->next != NULL)
			// write(1, " ", 1);
		token = token->next;
	}
	if (n == true)
		return (0);
	else
		ft_putstr_fd("\n", 1);
	return (0);
}





int	finding_pwd(t_vars *vars)
{
	int	i;
	int	p;

	i = -1;
	j = -1;
	while (vars->env[++i] != NULL)
	{
		if (ft_strnstr(vars->env[i], "PWD=", 4) != NULL)
		{
			return (i);
		}
		else
			return (-1);		
	}
}

int	builtin_cd(t_vars *vars)
{
	t_token *token;
	int		i;
	int		j;

	if (finding_pwd(vars) != -1)
		i = finding_pwd(vars);
	else
		return (0);
	j = -1;
	while (vars->env[i][++j] != NULL);
	if (token->next->cont == "..")
	{
		while (vars->env[i][j] != '/')
		{
			vars->env[i][j--] == NULL;
		}
	}
	if (token->next->cont != "..") //?
	{
		ft_strjoin(token->cont, token->next->cont);
	}
}