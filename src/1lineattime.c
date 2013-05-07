
#include  <regex.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <term.h>
#include  <unistd.h>

#include  "1lineattime.h"
#include  "terminal.h"
#include  "io.h"
#include  "opts.h"

static void error(char const * str);
static void free_regex(t_opts const * opts, regex_t * regex);

int onelineattime(t_opts const * opts)
{
  char        *buff;
  int         last_len;
  int         i;
  regex_t     regex;
  int         lastmatch;

  init_terminal_data();
  if (opts->regex != NULL)
  {
    if (regcomp(&regex, opts->regex, REG_EXTENDED) != 0)
      error("Could not compile regex.");
  }
  last_len = 0;
  i = 0;
  lastmatch = 1;
  while ((buff = get_next_line()) != NULL)
  {
    int match = 1;
    int tmpret = 0;

    if (opts->regex != NULL && !(i >= opts->head && opts->head != 0))
      tmpret = regexec(&regex, buff, 0, NULL, 0);
    if (tmpret == 0)
      match = 1;
    else if (tmpret == REG_NOMATCH)
      match = 0;
    else
      error("regex failed.");
    if (opts->regex != NULL && (lastmatch == 0 || match == 0))
      write(1, "\n", 1);
    if (i >= opts->head && buff[0] != '\0')
      clear_line();

    last_len = strlen(buff);
    if (buff[0] != '\0')
      write(1, buff, last_len);
    if (!(i >= opts->head && buff[0] != '\0'))
      write(1, "\n", 1);
    lastmatch = match;
    if (buff[0] != '\0')
      ++i;
  }
  write(1, "\n", 1);
  free_regex(opts, &regex);
  return (0);
}

static void free_regex(t_opts const * opts, regex_t * regex)
{
  if (opts->regex != NULL)
  {
    regfree(regex);
    free(opts->regex);
  }
}

static void error(char const * str)
{
  fprintf(stderr, "Error : %s\n", str);
  exit(1);
}
