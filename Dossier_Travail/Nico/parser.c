int	content_parsing(int fd)
{
  while ((raw_line = get_next_line(fd)) != NULL)
    {
      l
      if (

int	parser(char *path)
{
  char	*raw_line;
  char	*line;
  char	*tab;
  int	fd;
  int	flag_begin;

  flag_begin = 0;
  fd = open(path, RD_ONLY);
  while ((raw_line = get_next_line(fd)) != NULL)
    {
      line = epur_str(raw_line);
      if (my_strcmp(line, "<BEGIN>") == 0 && flag_begin == 1)
	return (puterr("Error : BEGIN is defined twice in the file. Parsing stopped.\n"));
      if (my_strcmp(line, "<BEGIN>") == 0)
	flag_begin = 2;
      else if (flag_line == 2)
	{
	  if ((tab = word_to_tab(line)) == NULL)
	    return (puterr("Error : Malloc failed"));
	  if (my_tablen(tab) == 2 && my_strcmp(tab[0], "!NAME") == 0)
	    {
	      if (tab[1] == NULL || my_strlen(tab[1]) < 1 || my_strlen(tab[1]) > MAX_NAME)
		return(puterr("Error : !NAME content is NULL or is larger than 64 char. Parsing stopped.\n"));
	      flag_line = 1;
	      name = tab[1];
	    }
	  else
	    return (puterr("Error : No !NAME variable defined after <BEGIN>, or variable is badly defined. Parsing stopped.\n"));
	}
      else if (flag_line == 1)
	{
	  parsing(fd);
