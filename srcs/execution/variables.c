
#include "../../include/minishell.h"

char	*add_varcontent(char *line, char *var_name, char **env, int count)
{
	char	*newline;
	int		pos;
	char	*var_value;
	int		i;
	int		j;

	j = -1;
	i = 0;
	pos = 0;
	newline = NULL;
	while (line[pos] && (line[i] != ' ' && line[i] != '\'' && line[i] != '\"'))
		pos++;
// TOFIX  arraysrch should check only strings and until it hits a '='
	var_value = ft_arraysrch(env, ft_strjoin(var_name, "=")) + (ft_strlen(var_name) + 1);
/*debug*/printf("\033[43mvar_value=%s\033[0m\n", var_value);
	if (var_value)
	{
		newline = calloc(count + ft_strlen(line), sizeof(char));
		while(++j < (int)ft_strlen(line))
			newline[j] = line[j];
			pos++;
		while(pos <= ((int)ft_strlen(var_value) + (int)ft_strlen(var_name) + 1))
			newline[pos++] = var_value[i++];
		while(line[j])
		{
			newline[pos++] = line[j++];
		}
	}
	if(!newline)
		newline = line;
	// free(line);
	return (newline);
}

char *change_to_var(char *line, char *var_name, char **env)
{
	char	*varremoved;
	char	*newline;
	int		count;
	char	*temp;

	temp = ft_strchr(line, '$');
	varremoved = line;
	//remove $USER from string
	while (*temp && (*temp != ' ' && *temp != '\'' && *temp != '\"') )
	{
		/*debug*/printf("\033[43mBEF:charremove = %s\033[0m\n", varremoved);
		varremoved = ft_rmchar(varremoved, temp); // TOFIX  MIGHT LEAK
		temp++;
	}
	// ft_rmchar(varremoved, temp);
		/*debug*/printf("\033[43mAFT:charremove = %s\033[0m\n", varremoved);
	count = ft_strlen(ft_arraysrch(env, var_name)) - (ft_strlen(var_name)+ 1);
	if(count > 0)
		newline = add_varcontent(varremoved, var_name, env, count);
	else
	{
		free(line);
		return (varremoved);
	}
	return(newline);
}

char *save_varname(char *line)
{
	int	i;
	int count;
	char *var_name;

	i = 0;
	count = 0;
	while (line[count] && (line[i] != ' ' && line[i] != '\'' && line[i] != '\"'))
		count++;
	var_name = ft_calloc(count, sizeof(char));
	while (line[i] && (line[i] != ' ' && line[i] != '\'' && line[i] != '\"'))
	{
		var_name[i] = line[i];
		i++;
	}
	return (var_name);
}

//heredoc	IN: "$USER" $USER '$USER'
//			OUT: "ast-jean" ast-jean 'ast-jean'

//prompt	IN: '$USER' OUT: '$USER'
//			OUT: "ast-jean" ast-jean '$USER' 

char *check_var(char *line, t_vars *vars)
{
	(void)line;
	(void)vars;
	return (NULL);
}

char *check_var_heredoc(char *line, t_vars *vars)
{
	int i;
	char *var_name;
	char *newline;

	i = 0;	
	newline = line;
	if(ft_strchr(line, '$'))
	{
		var_name = save_varname(ft_strchr(line, '$') + 1); 
		while (ft_strchr(newline, '$'))
		{
/*debug*/printf("\033[43msrchr=%s\033[0m\n", ft_strchr(line, '$'));
/*debug*/printf("\033[43mline is env : %s\033[0m\n", ft_arraysrch(vars->env, var_name));
/*debug*/printf("\033[43mvar_name = %s\033[0m\n", var_name); 
			newline = change_to_var(line, var_name, vars->env);
/*debug*/printf("\033[43mnewline=%s\033[0m\n", newline);
		} 
		// free(line);
		// free(var_name)
	return (newline);
	}
	else
		return (line);
}