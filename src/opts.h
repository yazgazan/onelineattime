
#ifndef   _OPTS_H_
# define  _OPTS_H_

# define  USAGE_REGEX "only the matching lines will be wrapped."
# define  USAGE_HEAD  "the first n lines won't be wrapped."

typedef struct  {
  char      *regex;
  int       head;
}           t_opts;

void parse_opts(t_opts * opts, char const * const argv[]);

#endif

