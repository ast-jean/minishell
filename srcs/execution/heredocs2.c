

#include "../../include/minishell.h"

char *add_varcontent(char *line,int newlen, char *var_name, char **env, int count)
{
	char	*newline;
	int		pos;

	pos = 0;
	while(line[pos] && line[pos]!= ' ')
		pos++;

	printf("pos =%d\n", pos);
	newline = calloc(count + newlen, sizeof(char));

	(void)var_name;
	(void)env;
// add content of var at pos
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
	while (*temp && *temp != ' ')
	{
		varremoved = ft_rmchar(varremoved, temp); // TOFIX  MIGHT LEAK
		temp++;
	}
	ft_rmchar(varremoved, temp);
	printf("varremoved =%s\n", varremoved);
	count = ft_strlen(ft_arraysrch(env, var_name)) - (ft_strlen(var_name)+ 1);
	if(count > 0)
	{
		//replace $USER by env
		newline = add_varcontent(line, ft_strlen(varremoved), var_name, env, count);
	}
	else
		return (free(line), varremoved);
	return(newline);
}

char *save_varname(char *line)
{
	int	i;
	int count;
	char *var_name;

	i = 0;
	count = 0;
	while (line[count] != ' ' && line[count])
		count++;
	var_name = ft_calloc(count, sizeof(char));
	while (line[i] && line[i] != ' ')
	{
		var_name[i] = line[i];
		i++;
	}
	return (var_name);
}

char *check_var(char *line, t_vars *vars)
{
	//input: line of $USER is $UNKNOWN
	//output line of ast-jean is 
	int i;
	char *var_name;
	char *newline;

	newline = "";
	i = 0;	
		var_name = save_varname(ft_strchr(line, '$')); 
/*debug*/printf("%s\n", ft_arraysrch(vars->env, var_name));
	while (ft_strchr(line, '$'))
	{
		var_name = save_varname(ft_strchr(line, '$')); 
		var_name = &var_name[1]; //LEAKKKKKK TOFIX 
/*debug*/printf("var_name = %s\n", var_name); 
		newline = change_to_var(line, var_name, vars->env);
/*debug*/printf("line = %s\n", newline); 
		exit(0);
	} 
	// free(line);
	// free(var_name)
	return (newline);
}