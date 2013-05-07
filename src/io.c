
#include  <stdlib.h>
#include  <unistd.h>

#include  "1lineattime.h"
#include  "io.h"

static int g_eof = 0;

static void   reinit_line(char *line, int size);
static char   get_next_char(void);

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
    if (g_eof)
    {
      free(buff);
      buff = NULL;
      return NULL;
    }
    i++;
  }
  return buff;
}

static char   get_next_char(void)
{
  static char *buff = NULL;
  static int  i = -1;
  static int  rd = -1;

  if (buff == NULL)
    buff = calloc(BUFF_SIZE + 1, sizeof(*buff));
  g_eof = 0;
  if (i == -1 || i == rd)
  {
    rd = read(0, buff, BUFF_SIZE);
    i = 0;
    if (rd == 0)
    {
      free(buff);
      buff = NULL;
      g_eof = 1;
      return '\0';
    }
    return get_next_char();
  }
  return buff[i++];
}

static void reinit_line(char *line, int size)
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
