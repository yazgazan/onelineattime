
#define   _BSD_SOURCE

#include  <stdlib.h>
#include  <string.h>
#include  <stdio.h>

#include  "opts.h"

static void init_opts(t_opts * opts);
static void usage(char const * const argv[]);

void parse_opts(t_opts * opts, char const * const argv[])
{
  int i;

  init_opts(opts);
  for (i = 1; argv[i]; ++i)
  {
    if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--regex") == 0)
    {
      ++i;
      if (opts->regex != NULL)
        usage(argv);
      if (argv[i] == NULL)
        usage(argv);
      opts->regex = strdup(argv[i]);
    }
    else if(strcmp(argv[i], "-H") == 0 || strcmp(argv[i], "--head") == 0)
    {
      ++i;
      if (opts->head != 0)
        usage(argv);
      if (argv[i] == NULL)
        usage(argv);
      opts->head = atoi(argv[i]);
    }
    else
    {
      usage(argv);
    }
  }
}

static void init_opts(t_opts * opts)
{
  opts->regex = NULL;
  opts->head = 0;
}

static void usage(char const * const argv[])
{
  fprintf(stderr, "\n");
  fprintf(stderr, "Usage : %s [options]\n\n", argv[0]);
  fprintf(stderr, "options :\n");
  fprintf(stderr, "\t-e, --regex <regex>\t:  %s\n", USAGE_REGEX);
  fprintf(stderr, "\t-H, --head  <n>\t\t:  %s\n\n", USAGE_HEAD);
  exit(1);
}

