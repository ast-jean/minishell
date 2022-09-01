#include "../../include/minishell.h"

// NOTE: CREATES PIPES
// TOKNOW: - if redirection to file before end of cmd line, redirection overwrites dup2 to pipe and pipe is empty. Next cmd will execute with empty imput.

//srch_inputfile(tokens, "<"); -> srchs while != '|', opens token->next, returns fd of opened file -> returns -1 if inexistant -> return 0 if no redirection
//srch_outputfile(token, ">", ">>"); -> opens token->next, returns fd of opened file -> returns 1 if no redirection


