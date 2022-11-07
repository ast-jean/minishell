/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:15:26 by xchouina          #+#    #+#             */
/*   Updated: 2022/11/07 13:52:08 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	int		o;
	char	*str;

	o = finding_index(vars, "OLDPWD=", 7);
	if (o != -1)
	{
		free(vars->env[o]);
		vars->env[o] = oldpwd;
	}
	else
	{	
		str = ft_strjoin("OLDPWD=", vars->cd_oldpwd);
		vars->env = ft_arrayadd(vars->env, str);
	}
}

void	changing_pwd(t_vars *vars)
{
	int		p;
	char	s[1000];

	if (finding_index(vars, "PWD=", 4) != -1)
	{
		p = finding_index(vars, "PWD=", 4);
		free(vars->env[p]);
		vars->env[p] = ft_strjoin("PWD=", getcwd(s, 1000));
	}
}

int	cd_suite(t_vars *vars, char **env, char *s)
{
	char	*new_oldpwd;

	vars->env = ft_arrayrm2(vars->env, "PWD=", 4);
	vars->env = ft_arrayadd(vars->env,
			ft_strdup(env[ft_arrayintsrch(env, "PWD=")]));
	new_oldpwd = ft_strjoin("OLDPWD=", s);
	changing_oldpwd(vars, new_oldpwd);
	changing_pwd(vars);
	return (1);
}

int	builtin_cd(t_vars *vars, char **env)
{
	t_token	*token;
	char	s[100];

	token = vars->token->first->next;
	if (ft_arrayintsrch(vars->env, "PWD=") == -1)
	{
		dprintf(2, "Current directory was not found.\n");
		return (1);
	}
	if (token)
		token->cont = remove_quotes(token->cont);
	vars->cd_oldpwd = getenv("PWD");
	getcwd(s, 100);
	if (!token || ft_strcmp(token->cont, "~") == 0)
		chdir(getenv("HOME"));
	else if (token && chdir(token->cont) != 0
		&& ft_strcmp(token->cont, ".") != 0)
	{
		vars->last_output = 1;
		dprintf(2, "cd: no such file or directory: %s\n", token->cont);
		return (1);
	}
	return (cd_suite(vars, env, s));
}
