/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahendri <mahendri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:21:47 by mahendri          #+#    #+#             */
/*   Updated: 2026/02/23 11:21:46 by mahendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_splitable_arg(char *arg)
{
	int	i;
	int	has_space;
	int	has_number;

	has_space = 0;
	has_number = 0;
	if (!arg || arg[0] == '\0')
		return (0);
	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			has_space = 1;
		i += skip_flag_on_check(&arg[i], &has_number);
		if (arg[i] == '\0')
			break ;
		if (ft_isdigit(arg[i]))
			has_number = 1;
		if (arg[i] == '-' || arg[i] == '+')
			i++;
		if (!(ft_isdigit(arg[i]) || arg[i] == ' '))
			return (-1);
		i++;
	}
	return (1 * has_space * has_number);
}

int	check_splitable(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 1)
		return (-1);
	while (i < argc && argv[i])
	{
		if (is_splitable_arg(argv[i]) > 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	*join_arg(int argc, char **argv)
{
	char	*joined;
	char	*new_join;
	int		i;

	joined = ft_strjoin("", "");
	if (!joined)
		return (NULL);
	i = 0;
	while (argv[i] && i < argc)
	{
		new_join = strjoin_with_space(joined, argv[i]);
		free(joined);
		joined = new_join;
		i++;
	}
	return (joined);
}

char	**split_all_arg(int argc, char **argv)
{
	char	**split;
	int		splitable_index;
	char	*trimed;
	char	*joined;

	if (!argv)
		return (NULL);
	splitable_index = check_splitable(argc, argv);
	if (splitable_index == -1)
		return (NULL);
	joined = join_arg(argc, argv);
	if (!joined)
		return (NULL);
	trimed = ft_strtrim(joined, " ");
	free(joined);
	if (!trimed)
		return (NULL);
	split = ft_split(trimed, ' ');
	free(trimed);
	if (!split)
		return (NULL);
	return (split);
}
