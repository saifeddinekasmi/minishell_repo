/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/11 18:51:12 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	ft_new_env(char **env)
{
	t_env	**new_env;
	char	**splt;
	int		i;

	g_var.env = NULL;
	new_env = &g_var.env;
	i = 0;
	while (env[i])
	{
		splt = ft_split(env[i], '=');
		ft_lst_addback_env(new_env, ft_lstnew_env(splt[0], splt[1]));
		i++;
	}
}

void only_export()
{
	t_env *env;

	env = g_var.env;
	while (env)
	{
		if (env->value)
			printf("declare -x %s=\"%s\"\n", env->data, env->value);
		else
			printf("declare -x %s\n", env->data);
		env = env->next;
	}
}

int	ft_bulletin(char *cmd)
{

	t_pipe	*lst_of_args;
	t_redic	*lst_of_red;
	char	**ptr;

	lst_of_args = NULL;
	lst_of_red = NULL;
	ft_get_args_and_red(cmd, &lst_of_args, &lst_of_red);
	if (lst_of_red)
		run_rediction(lst_of_red);
	ptr = args_lst_to_tab(lst_of_args);


	ft_convert_to_lower(ptr[0]);
	
	/*
		if (ft_strcmp(ptr[0], "exit") == 0)
			return (ft_exit(ptr[0]), 1);
		if (ft_strcmp(ptr[0], "pwd") == 0)
			return (ft_pwd(ptr[0]), 1);
		if (ft_strcmp(ptr[0], "env") == 0)
			return (ft_env(t), 1);
	*/

	if (ft_strcmp(ptr[0], "cd") == 0)
		return (ft_cd(ptr[1]), 1);
	else if (ft_strcmp(ptr[0], "env") == 0)
			return (ft_env(), 1);
	else if (ft_strcmp(ptr[0], "unset") == 0)
		return (ft_unset_more_then_one(ptr), 1);
	else if (ft_strcmp(ptr[0], "export") == 0)
	{
		if (!ptr[1])
			return (only_export(), 1);
		return (ft_export(ptr), 1);
	}
	return (0);
}


/**
	to do list 
	expand // need to be fixed
	convert comand to lowercase LS=>ls
	extract comand from dqoutes "l""s" => ls
	heredoc
	echo 
	export
	exuction
 */


/**
 * 
 * 
 * export -------> done
 * exucution --------> done
 * 
 * 
 */



/**
 *  # error need to be fixed in bultins
 * 
 * 
 *  
 * ## builtins errors
 * echo with -nnnnnnnnnn
 * unset with multipe var // remove the middle one
 * cd error // when remove courent folder
 * pwd error // when can't find .
 * 
 * 
 * 
 * ## bultins finished
 * ---> export
*/


/**
 * # syntax errors
 * 
 * <<< // must be handle
 * echo "'   << >     |"| // syntax error
 * |" d" // syntax error
 * 
 * 
*/


int only_space(char *cmd)
{
	int i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] != ' ')
			return 0;
	}
	return 1;
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	int		fd[2];
	char	**check_espace;

	fd[0] = dup(0);
	fd[1] = dup(1);
	(void) av;
	if (ac == 1)
	{
		ft_new_env(env);
		//if (!g_var.env)
		//	ft_export(ft_split("SHLVL=1", ' '));
		while (1)
		{
			cmd = readline("\033[37mFRATELLO😈=> ");
			if (!cmd)
			 	break ; // free allocated memory
			check_espace = ft_split(cmd, ' ');
			if (cmd[0] == '\0' || only_space(cmd))
				continue;
			add_history(cmd);
			if (ft_syntax_general(cmd) == 1)
				printf("\033[31mMinishell : syntax error !!!\n\033[37m");
			else
			{
				// continue;
				ft_pipe(cmd);
			}
			dup2(fd[0], 0);
			dup2(fd[1], 1);
		}
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}



