
#include "../../include/minishell.h"

char *find_variable(char **env, char *varname)
{
	// TOFIX  arraysrch should check only strings and until it hits a '='
	int i;
	int j;
	char *var_value;

	var_value = NULL;
	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] == varname[j])
		{
			if (env[i][j+1] != '=')
				ft_strcpy(var_value, env[i]+ j + 2);
			j++;
		}
	}
	return (var_value);
}

char	*add_varcontent(char *line, char *var_name, char **env)
{
	char	*newline;
	char	*var_value;
	int		pos;
	int		i;
	int		j;

	newline = NULL;
	j = -1; //not used
	i = -1;
	pos = 0;
	var_value = find_variable(env, var_name);
	while(line[pos++] != '$')
	{ }
	pos += (int)ft_strlen(var_name);
/*debug*/printf("\033[43mvar_value=%s\033[0m\n", var_value);
	if (var_value[++i])
	{
		//hello $USER hello
		ft_strcpy(newline, line);

		//hello $USER hello
		//free + calloc strlen(newline)
		//hello $USERast-jean hello
		while(var_name[i])
		{
			ft_addchar(newline ,var_value[i], &newline[pos]);
			i++;
			pos--;
		}
		printf("test\n");
		i = 0;
		//ft_rmchar() while (strlen(var_name))
		//hello ast-jean hello


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
	char	*temp;

	temp = ft_strchr(line, '$');
	varremoved = line;

	printf("find_variables = >%s<\n", find_variable(env, var_name));
	printf("seg2\n");
	if(ft_strlen(find_variable(env, var_name)) > 0) //fonction arraysrch until =
	{
		newline = add_varcontent(varremoved, var_name, env);
	/*debug*/printf("\033[43mBEF:charremove = %s\033[0m\n", newline);
		while (*temp && (*temp != ' ' && *temp != '\'' && *temp != '\"') )
			newline = ft_rmchar(varremoved, temp++);
	/*debug*/printf("\033[43mAFT:charremove = %s\033[0m\n", newline);
	}
	else
	{
		// free(line);
		while (*temp && (*temp != ' ' && *temp != '\'' && *temp != '\"') )
			varremoved = ft_rmchar(varremoved, temp++);
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
// /*debug*/printf("\033[43msrchr=%s\033[0m\n", ft_strchr(line, '$'));
// /*debug*/printf("\033[43mline is env : %s\033[0m\n", ft_arraysrch(vars->env, var_name));
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