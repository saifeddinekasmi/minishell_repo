/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:43:42 by skasmi            #+#    #+#             */
/*   Updated: 2022/08/31 20:58:21 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ************************ create new list *********************************
t_list  *ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(*lst))))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

// ************************  check last node  ********************************
t_list  *ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

//************* add node to the last node in liked list ***********************
void    ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

// **************** copy string between n & m in new str **********************
char *ft_strnput(char *str, int n, int m)
{
    int i;
    int j;

    j = 0;
    i = 0;
    char *tab;
    tab = (char *)malloc(sizeof(char) * (n + m) + 1);
    while (n < m)
    {
        tab[j] = str[n];
        j++;
        n++;
    }
    tab[j] = '\0';
    return (tab);
}

// ********************* stock all env in table 2D called env_var *************
char    *copy_envs(char **env)
{   
    int nb_of_line = 0;
    int nb_for_alloc = 0;
    char **env_var;
    while (env[nb_of_line])
    {
        nb_for_alloc = strlen(env[nb_of_line]);
        env_var = (char **)malloc(sizeof(char) * nb_for_alloc);
        nb_of_line++;
        // printf("im here\n");
        nb_for_alloc++;
    }
    nb_of_line = 0;
    nb_for_alloc = 0;
    while (env[nb_of_line])
    {
        env_var[nb_for_alloc] = env[nb_of_line];
        nb_for_alloc++;
        nb_of_line++;
    }
    nb_of_line = 0;
    while (env_var[nb_of_line])
    {
        printf("%s\n", env_var[nb_of_line]);
        nb_of_line++;
    }
    return &(**env_var);
}

int main(int ac, char **av, char **env)
{
    int     i;
    int     k;
    char    *str;
    char    **tab;
    int     l;
    (void)ac;
    (void)av;
    (void)env;

    i = 0;
    k = 0;
    l = 0;
    // t_list *t;
    // while (env[l])
    // {
    //     printf("text\n");
    //     t->content = env[l];
    //     l++;
    //     t->next = t->content; 
    // }
    
    copy_envs(env);
    while (1)
    {
        str = readline("FRATELLO😈 => ");
        tab = (char **)malloc(sizeof(char) * strlen(str));
        if (!tab)
            return 0;
        printf("%s\n", str);
    }
    return (0);
}