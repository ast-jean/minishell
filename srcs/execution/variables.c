
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
	int		i;
	int		j;
	int		k;
	char	*var_value;

	var_value = NULL;
	i = -1;
	k = 0;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] == varname[j])
			j++;
		if (env[i][j] == '=')
		{
			j = (int)ft_strlen(varname) + 1;
			while(env[i][j])
				var_value = ft_addchar(var_value, env[i][j++], &var_value[k++]);
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
	printf("\033[43mdebug add_var: \033[0mvar_value =%s\033[43m-\033[0m\n", var_value);
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
	printf("\033[43mdebug add_var1: \033[0mnewline =%s\033[43m-\033[0m\n", newline);
	while(var_value[++i])
	{
		printf("\033[43mdebug add_var2.1: \033[0mnewline =%s\033[43m-\033[0m\n", newline);
		newline = ft_addchar(newline, var_value[i], &newline[pos++]);
		printf("\033[43mdebug add_var2.2: \033[0mnewline =%s\033[43m-\033[0m\n", newline);
	}
	newline = delete_var_name(pos2, newline);
	printf("\033[43mdebug add_var3: \033[0mnewline =%s\033[43m-\033[0m\n", newline);
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

		while (find_var_inline(newline))
		{
			printf("\033[43mdebug: \033[0mi =%d\033[43m-\033[0m\n", i++);
			var_name = save_varname(find_var_inline(newline)+ 1);
			printf("\033[43mdebug: \033[0mvar_name =%s\033[43m-\033[0m\n", var_name);
			var_value = find_variable(vars->env, var_name);
			printf("\033[43mdebug: \033[0mvar_value =%s\033[43m-\033[0m\n", var_value);
			newline = add_varcontent(newline, var_name, var_value);
			printf("\033[43mdebug: \033[0mnewline =%s\033[43m-\033[0m\n", newline);
			// if (var_name && !var_value)
			// 	ft_putstr_fd("\n", 1);

		} 
	return (			printf("\033[43mdebug: \033[0mnewline return=%s\033[43m-\033[0m\n", newline), newline);
}