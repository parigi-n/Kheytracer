/*
** string.h for string in /home/vautie_a/rendu/PSU_2014_42sh/Jules/src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Apr 28 15:46:15 2015 Jules Vautier
** Last update Sun Jun  7 21:59:12 2015 david sebaoun
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
# define ERROR_NO_END		"Error: No <END> variable found"
# define ERROR_BAD_NAME_VAR	"Error: No !NAME after <BEGIN>, or badly defined"
# define ERROR_BAD_NAME_LENGHT	"Error: !NAME is NULL or larger than expected"
# define ERROR_BAD_ONAME_LENGHT	"Error:NAME is NULL or larger than MAX_OBJ_NAME"
# define ERROR_BAD_ARG_LENGHT	"Error: Argument is NULL, or have a wrong size"
# define ERROR_BAD_ORDER	"Error: Excepted a different element (bad order)"
# define ERROR_BAD_ORDER2	"Error: Excepted an another element (incomplete)"
# define ERROR_UNKNOWN_OBJ_TYPE	"Error: Object type doesn't exist"
# define ERROR_UNKNOWN_E_TYPE	"Error : Unknown ELEMENT type found"
# define ERROR_BAD_COLOR_LENGHT	"Error: COLOR can't be more than 6 char long"

/* Cmd */

# define PROMPT			"kheytracer$> "
# define NO_SCENE		"There is currently no scene in memory,"
# define NO_SCENE2		" please choose a name for a new one\n"
# define NO_CAMERA		"You also need a camera\n"
# define ERROR_ACCESS		"Error: Unable to access directory\n"
# define ERROR_NO_SCENE		"Error: No scene loaded\n"
# define ERROR_OPEN_WINDOW	"Error: Error while opening window\n"
# define ERROR_LOAD		"Error: The file could not be loaded\n"
# define ERROR_FILE		"Error: File does not exist or is not compatible\n"
# define ERROR_LINE		"\033[1;41mError : line %d\033[0m\n"
# define LOAD_SUCCESS		"\033[1;32mFile Successfully loaded\033[0m\n"
# define ADD_SUCCESS		"\033[1;32mObject successfuly added\033[0m\n"
# define WRITE_SUCCESS		"\033[1;32mFile Successfully writed\033[0m\n"
# define LOAD_USAGE		"Usage: load file.khey\n"
# define ADD_USAGE		"Usage: add new_object_name\n"

/* Help */

# define HELP_HELP		"help      shows this help\n"
# define HELP_LS		"ls        displays a list of .khey files\n"
# define HELP_ADD		"add       start an object creator tool\n"
# define HELP_SHOW		"show      show informations about loaded objects\n"
# define HELP_LOAD		"load      load a scene from a file\n"
# define HELP_LOAD_EX		"          ex: load file.khey\n"
# define HELP_REND		"render    render the loaded scene\n"
# define HELP_REND_USE		"          [-all]remove all, [-o]shadow, "
# define HELP_REND_USEN		"[-r]rotation, [-i]intensity\n"
# define HELP_WRITE		"write     write the current scene in a file\n"
# define HELP_CLEAR		"clear     clear the screen\n"
# define HELP_EXIT		"exit      exit the program\n"

#endif /* !STRING_H_ */
