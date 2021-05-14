#include "../ft_printf.h"
void store_account(va_list *args,  t_flags *flags)
{
	*va_arg(*args, int *) = flags->count;
}
