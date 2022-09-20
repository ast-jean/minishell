
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



// TOFIX  
// - This shit's broken with normal cases
// - If variable doesnt exist if should erase, but it SEGFAULTs
// - Should loop to multiple $VARs
char	*add_varcontent(char *line, char *var_name, char *var_value)
{
	char	*newline;
	char	*posstr;
	int		pos;
	int		pos2;
	int		i;

	posstr = find_var_inline(line);
	printf("posstr = %s\n", posstr);
	newline = NULL;
	i = -1;
	pos = 0;
	while(posstr[pos++]);
	pos += (int)ft_strlen(var_name) - 1;
	pos2 = pos;
	if (var_value[++i])
	{
		newline = line;
		while(var_value[i])
			newline = ft_addchar(newline, var_value[i++], &newline[pos++]);
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
	}
	return (newline);
}



char *check_var_heredoc(char *line, t_vars *vars)
{
	int i;
	char *var_name;
	char *newline;
	char *var_value;

	i = 0;	
	newline = line;
	if(find_var_inline(line))// TOFIX  change ft_strchr to skip single quotes
	{
		while (find_var_inline(newline))
		{
			var_name = save_varname(find_var_inline(line)+ 1); // TOFIX  change ft_strchr to skip single quotes
			var_value = find_variable(vars->env, var_name);
			newline = add_varcontent(line, var_name, var_value);
/*debug*/printf("\033[43mvar_name = %s\033[0m\n", var_name); 
/*debug*/printf("\033[43mnewline= %s\033[0m\n", newline);
/*debug*/printf("\033[43mAFTER newline= %s\033[0m\n", newline);
		} 
		// free(line);
		// free(var_name)
	return (newline);
	}
	else
		return (line);
}