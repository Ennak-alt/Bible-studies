static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
  if (month < 0 || month > 12 || day < 0)
    return -1;

  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if (day > *(*(daytab+leap)+month))
    return -1;

  for (i = 1; i < month; i++)
    day += *(*(daytab+leap)+i);
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  if (yearday < 0)
    return;

  leap = year % 4 == 0 && year % 100 || year % 400 == 0;

  if ((yearday > 366 && leap == 1) || (yearday > 365 && leap == 0))
    return;

  for (i = 1; yearday > *(*(daytab+leap)+i); i++)
    yearday -= *(*(daytab+leap)+i);
  *pmonth = i;
  *pday = yearday;
}