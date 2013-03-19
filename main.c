
#ifdef unix
static char term_buffer[2048];
#else
# define term_buffer 0
#endif

#include  <curses.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <term.h>
#include  <unistd.h>

#define   MAX_LINE_SIZE   1024
#define   BUFF_SIZE       MAX_LINE_SIZE * 2

void          reinit_line(char *line, int size);
char          get_next_char(void);
char          *get_next_line(void);
void          init_terminal_data (void);

int           main(void)  {
  char        *buff;
  char        *_clear;
  char        *_rewind;
  int         last_len;
  int         len_rewind;
  int         len_clear;

  init_terminal_data();
  _clear = tgetstr("ce", NULL);
  len_clear = strlen(_clear);
  _rewind = tgetstr("cr", NULL);
  len_rewind = strlen(_rewind);
  last_len = 0;
  while ((buff = get_next_line()) != NULL)
  {
    write(1, _rewind, len_rewind);
    write(1, _clear, len_clear);

    last_len = strlen(buff);
    write(1, buff, last_len);
  }
  write(1, "\n", 1);
  return 0;
}

void          reinit_line(char *line, int size)
{
  int         i;

  i = 0;
  while (i < size / 8)
  {
    *(long int *)(line + i * 8) = 0;
    i++;
  }
  if ((size % 8) == 0)
    return;
  i = (i - 1) * 8;
  while (i < size)
    line[i++] = '\0';
}

char          *get_next_line(void)
{
  static char *buff = NULL;
  int         i;

  if (buff == NULL)
    buff = calloc(MAX_LINE_SIZE + 1, sizeof(*buff));
  else
    reinit_line(buff, MAX_LINE_SIZE + 1);

  i = 0;
  while (i < MAX_LINE_SIZE)
  {
    buff[i] = get_next_char();
    if (buff[i] == '\n')
    {
      buff[i] = '\0';
      return buff;
    }
    if (buff[i] == '\0')
      return NULL;
    i++;
  }
  return buff;
}

char          get_next_char(void)
{
  static char *buff = NULL;
  static int  i = -1;
  static int  rd = -1;

  if (buff == NULL)
    buff = calloc(BUFF_SIZE + 1, sizeof(*buff));
  if (i == -1 || i == rd)
  {
    rd = read(0, buff, BUFF_SIZE);
    i = 0;
    if (rd == 0)
      return '\0';
    return get_next_char();
  }
  return buff[i++];
}

void          init_terminal_data (void)
{
  const char  *termtype = getenv ("TERM");

  tgetent(term_buffer, termtype);
}
