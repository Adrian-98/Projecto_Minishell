/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-a <glopez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:10:01 by amunoz-p          #+#    #+#             */
/*   Updated: 2020/09/11 19:21:41 by glopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


static	t_shell		*ft_create_struct(t_shell *f)
{
	if (!(f = malloc(sizeof(t_shell))))
		return 0;
	f->pwd = getcwd(f->pwd, 4096);
	f->c = 32;
	f->quote = 0;
	return(f);
}

void	ft_get_path(t_shell *f)
{
	while (*f->envv)
	{
		if (!ft_strncmp(*f->envv, "PATH=", 5))
		{
			f->path = ft_split(*f->envv + 5, ':', f);
			break;
		}
		f->envv++;
	}
	while (*f->path)
		{
			printf("%s\n", *f->path);
			f->path++;
		}
}

int main(int argc, char **argv, char **env)
{
	int i;
	t_shell *f;

	i = 0;
	f = NULL;
	f = ft_create_struct(f);
	f->envv = env;
	ft_get_path(f);
	while (1)
	{
		display_msg(f);			
		get_next_line(0, &f->line);
		f->arguments = ft_split_cmd(f->line, ";|");
		while (*f->arguments)
		{
			printf("%s\n", *f->arguments);
			f->arguments++;
		}
		exit(1);
		i = ft_quotes(f);
		if (i == 1)
			ft_quote2(f);	
		else
		{
			f->arguments = ft_split(f->line, f->c, f);
			ft_cases(f);
		}
		free(f->line);
	}
	return 0;
}
