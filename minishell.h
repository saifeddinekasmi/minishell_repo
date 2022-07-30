/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:10 by skasmi            #+#    #+#             */
/*   Updated: 2022/07/29 17:58:19 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

// typedef struct s_token
// {
//     int type;
//     char value;
//     s_token *next;
// }   t_token;

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}                   t_list;

#endif