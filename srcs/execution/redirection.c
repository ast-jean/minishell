#include "../../include/minishell.h"
// NOTE: Redirection (sortie en mode append)




int	redirect_append(char *txt_2_add, char *file)
{
	int	fd;

	fd = open(file, O_APPEND | O_CREAT | O_RDWR, 0777);
	return (fd);
}
