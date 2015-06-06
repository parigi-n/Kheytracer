/*
** string.h for string in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 15:46:15 2015 Jules Vautier
** Last update Fri Jun  5 17:49:22 2015 Nicolas PARIGI
*/

#ifndef STRING_H_
# define STRING_H_

# define INVALID_READ	"Invalid read.\n"
# define INVALID_CMD	"Invalid command.\n"
# define INVALID_SYNTAX	"Invalid syntax in cmd %s\n"
# define ERROR_PATH	"Can't find the path.\n"
# define ERROR_HOME	"Can't find the home.\n"
# define ERROR_OPEN	"Error Open.\n"
# define ERROR_MALLOC	"Error : Malloc failed.\n"
# define ERROR_INIT	"Error in init function.\n"
# define ERROR_SIGNAL	"Error Signal.\n"
# define ERROR_CLOSE	"Error with Close.\n"
# define ERROR_FORK	"Error with fork.\n"

/* Parser */

# define ERROR_NBR_ARG		"Error : Wrong argument number in one of the element.\n"
# define ERROR_TWICE_BEGIN	"Error : BEGIN is defined twice in the file.\n"
# define ERROR_NO_BEGIN		"Error : No <BEGIN> variable found.\n"
# define ERROR_BAD_NAME_VAR	"Error : No !NAME variable defined after <BEGIN>, or variable is badly defined.\n"
# define ERROR_BAD_NAME_LENGHT	"Error : !NAME content is NULL or is larger than MAX_SCENE_NAME.\n"
# define ERROR_BAD_ONAME_LENGHT	"Error : NAME element string argument is NULL or larger than MAX_OBJ_NAME.\n"
# define ERROR_BAD_ARG_LENGHT	"Error : An element argument is NULL or shorted/larger than excepted.\n"
# define ERROR_BAD_ORDER	"Error : Excepted an another element in the parsed line. Please check order and syntax of your file.\n"
# define ERROR_UNKNOWN_OBJ_TYPE	"Error : Object type doesn't exist.\n"
# define ERROR_BAD_COLOR_LENGHT	"Error : Hexadecimal int of COLOR must be 6 char long.\n"

#endif /* !STRING_H_ */
