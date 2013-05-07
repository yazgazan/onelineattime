
#ifdef unix
static char term_buffer[2048];
#else
# define term_buffer 0
#endif

#include  <curses.h>
#include  <stdlib.h>
#include  <string.h>
#include  <term.h>
#include  <unistd.h>

#include  "1lineattime.h"
#include  "terminal.h"

static void   rewind_cursor(void);

void          init_terminal_data (void)
{
  const char  *termtype = getenv("TERM");

  if (termtype == NULL)
    tgetent(term_buffer, "vt100");
  else
    tgetent(term_buffer, termtype);
}

void          clear_line(void)
{
  static char *_clear = NULL;
  static int  len_clear = -1;

  if (_clear == NULL)
  {
    _clear = tgetstr("ce", NULL);
    len_clear = strlen(_clear);
  }
  rewind_cursor();
  write(1, _clear, len_clear);
}

static void   rewind_cursor(void)
{
  static char *_rewind = NULL;
  static int  len_rewind = -1;

  if (_rewind == NULL)
  {
    _rewind = tgetstr("cr", NULL);
    len_rewind = strlen(_rewind);
  }
  write(1, _rewind, len_rewind);
}
