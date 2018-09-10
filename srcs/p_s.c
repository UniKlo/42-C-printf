void		p_s(t_block *blk, union u_type *t, va_list ap)
{
	int i;

	i = -1;
	t->s = va_arg(ap, char*);//store the str in s
	if (!t->s && p->pre == -1)
		t->s = "(null)";
	else if (!t->s)
		t->s = "";
	else if (p->pre > -1)
		t->s = ft_strsub(t->s, 0, p->pre);
	if (p->left == 1)
		buf_s(p, t->s, ft_strlen(t->s));
	while (++i < (int)(p->min_w - ft_strlen(t->s)))
	{
		if (p->zero == 1)
			buf_c(p, '0');
		else
			buf_c(p, ' ');
	}
	if (p->left != 1)
		buf_s(p, t->s, ft_strlen(t->s));
}