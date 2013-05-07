
#include  <stdlib.h>

#include  "1lineattime.h"

int           main(int argc, char const * const argv[])  {
  t_opts      opts;

  (void)argc;
  parse_opts(&opts, argv);
  return (onelineattime(&opts));
}

