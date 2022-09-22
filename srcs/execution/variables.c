
#include "../../include/minishell.h"

char	*save_varname(char *line)
{
	int	i;
	int count;
	char *var_name;

	i = 0;
	count = 0;
	while (line[count] && ft_isalnum(line[count]))
		count++;
	var_name = ft_calloc(count, sizeof(char));
	while (line[i] && ft_isalnum(line[i]))
	{
		var_name[i] = line[i];
		i++;
	}
	return (var_name);
}

char *find_var_inline(char *line)
{
	while (*line && *line != '$')
	{
		if (*line == '\'')
		{
			line++;
			while(*line && *line != '\'')	
				line++;
			if(!*line)
				return (NULL);
			line++;
		}
		else
			line++;
	}
	if (*line == '$')
		return ((char *)line);
	else
		return (NULL);
}

char	*find_variable(char **env, char *varname)
{
	int i;
	int j;
	char *var_value;

	var_value = NULL;
	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] == varname[j])
			j++;
		if (env[i][j] == '=')
		{
			j = (int)ft_strlen(varname) + 1;
			while(env[i][j])
			{	
				var_value = ft_addchar(var_value, env[i][j], &var_value[j]);
				j++;
			}
			return (var_value);
		}
	}
	return (var_value);
}

char	*delete_var_name(int pos2 ,char *newline)
{
	int	i;
	char *temp;

	i = pos2;
	while(i >= 0)
	{
		if(newline[i] == '$')
		{
			newline = ft_rmchar(newline, &newline[i--]);
			break ;
		}
		else
			newline = ft_rmchar(newline, &newline[i--]);
	}
	temp = newline;
	free(newline);
	return (temp);
}

char	*add_varcontent(char *line, char *var_name, char *var_value)
{
	char	*newline;
	char	*posstr;
	int		pos;
	int		pos2;
	int		i;

	posstr = find_var_inline(line);
	newline = NULL;
	i = -1;
	pos = 0;
	while(posstr[pos])
		pos++;
	pos--;
	pos = ft_strlen(line) - pos - 1 + ft_strlen(var_name);
	pos2 = pos;
	newline = line;
	while(var_value[++i])
		newline = ft_addchar(newline, var_value[i], &newline[pos++]);
	newline = delete_var_name(pos2, newline);
	return (newline);
}

char *check_var(char *line, t_vars *vars)
{
	int i;
	char *var_name;
	char *newline;
	char *var_value;

	i = 0;	
	newline = line;
	if(find_var_inline(line))
	{
		while (find_var_inline(newline))
		{
			var_name = save_varname(find_var_inline(line)+ 1);
			var_value = find_variable(vars->env, var_name);
			newline = add_varcontent(line, var_name, var_value);
		} 
	return (newline);
	}
	else
		return (line);
}