/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:27:22 by adrian            #+#    #+#             */
/*   Updated: 2020/08/29 11:27:33 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_msg(t_shell *f)
{
	ft_putstr(" \033[31m♛");
	ft_putstr("\033[0m\033[34m☻\033[0m\033[35m♛\033[0m➣% ");
}
 
void	ft_pwd(t_shell *f)
{
	f->path = getcwd(f->path, 4096);
	printf("esto es path%s\n", f->path);
}