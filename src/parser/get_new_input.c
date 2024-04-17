static short    quotes(const char c)
{
    static short    double_q;
    static short    simple_q;

    if (c == '"' && !simple_q)
        double_q ^= 1;
    else if (c == '\'' && !double_q)
        simple_q ^= 1;
    return (double_q || simple_q);
}

static int    get_len(const char *input)
{
    int        i;
    int        len;
    int        space;

    i = 0;
    len = 0;
    space = 0;
    while (input[i])
    {
        if (quotes(input[i]))
            len++;
        else if (input[i] != ' ')
        {
            space = 0;
            len++;
        }
        else if (input[i] == ' ' && !space)
        {
            space ^= 1;
            len++;
        }
        i++;
    }
    return (len);
}

char  *fill(char *result, char *origin)
{
  int i;
  int j;
  int space;

  i = 0;
  j = 0;
  space = 0;
  while (origin[i])
  {
      if (quotes(origin[i]))
      {
        result[j] = origin[i];
        j++;
      }
      else if (origin[i] != ' ')
      {
          space = 0;
          result[j] = origin[i];
          j++;
      }
      else if (origin[i] == ' ' && !space)
      {
          space ^= 1;
          result[j] = origin[i];
          j++;
      }
      i++;
  }
  return (result);
}

char *get_new_input(char *input)
{
  int len;
  char *result;

  len = get_len(input);
  
  result = (char *)calloc(len + 1, sizeof(char));
  if (!result)
    return (NULL);
  result = fill(result, input);
  return (result);
}