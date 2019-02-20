#include "ft_printf.h"

size_t  mbase_eight_uc(unsigned char c)
{
  size_t	j;

  j = 0;
  while (c != 0)
  {
    c = c / 8;
    ++j;
  }
  return (j);
}

void percent_hho(va_list ap)
{
  char	*str;
	int		i;
	unsigned char	value;
	int		tmp;

	value = (unsigned char)va_arg(ap, int);
	if (value == 0)
	{
		ft_putnbr(0);
		return ;
	}
	tmp = 0;
	i = 0;
	str = ft_strnew(mbase_eight_uc(value));
	while (value != 0)
	{
		tmp = value % 8;
		if (tmp < 10)
			str[i] = tmp + 48;
		else
			str[i] = tmp + 87;
		i++;
		value /= 8;
  }
  ft_putstr(ft_strrev(str));
  free(str);
}
