/*
** string.h for string in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 15:46:15 2015 Jules Vautier
** Last update Sat Jun  6 21:55:59 2015 Nicolas PARIGI
*/

#ifndef STRING_H_
# define STRING_H_

# define INVALID_READ		"Invalid read.\n"
# define INVALID_CMD		"Invalid command.\n"
# define INVALID_SYNTAX		"Invalid syntax in cmd %s\n"
# define ERROR_OPEN		"Error Open.\n"
# define ERROR_MALLOC		"Error : Malloc failed.\n"
# define ERROR_INIT		"Error in init function.\n"
# define ERROR_CLOSE		"Error with Close.\n"
# define ERROR_FORK		"Error with fork.\n"

/* Parser */

# define ERROR_NBR_ARG		"Error: Wrong argument number"
# define ERROR_TWICE_BEGIN	"Error: BEGIN is defined twice in the file"
# define ERROR_NO_BEGIN		"Error: No <BEGIN> variable found"
# define ERROR_BAD_NAME_VAR	"Error: No !NAME after <BEGIN>, or badly defined"
# define ERROR_BAD_NAME_LENGHT	"Error: !NAME is NULL or larger than expected"
# define ERROR_BAD_ONAME_LENGHT "Error: NAME is NULL or larger than MAX_OBJ_NAME"
# define ERROR_BAD_ARG_LENGHT	"Error: Argument is NULL, or have a wrong size"
# define ERROR_BAD_ORDER	"Error: Excepted a different element (bad order)"
# define ERROR_BAD_ORDER2	"Error: Excepted an another element (incomplete)"
# define ERROR_UNKNOWN_OBJ_TYPE	"Error: Object type doesn't exist"
# define ERROR_BAD_COLOR_LENGHT	"Error: COLOR can't be more than 6 char long"

/* Cmd */

# define ERROR_LOAD		"Error: The file could not be loaded\n"
# define ERROR_FILE		"Error: File does not exist or is not compatible\n"
# define ERROR_LINE		"\033[1;41mError : line %d\033[0m\n"
# define LOAD_SUCCESS		"\033[1;32mFile Successfully loaded\033[0m\n"
# define WRITE_SUCCESS		"\033[1;32mFile Successfully writed\033[0m\n"
# define LOAD_USAGE		"Usage: load file.khey\n"

#endif /* !STRING_H_ */
