/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd+env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:55:48 by xchouina          #+#    #+#             */
/*   Updated: 2022/10/03 10:55:49 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
// NOTE: Built-ins 1/3 (PWD + ENV)

int	builtin_pwd(t_vars *vars)
{
	vars->pwd = ft_arraysrch(vars->env, "PWD=") + 4;
	ft_putstr_fd(vars->pwd, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}

int	builtin_env(t_vars *vars)
{
	ft_arrayprint(vars->env);
	return (1);
}
