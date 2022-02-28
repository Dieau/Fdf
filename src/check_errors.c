/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:13:25 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/22 14:48:49 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"

void	error_exit(char *msg, int exit_code)
{
	ft_putstr_fd(msg, 1);
	exit(exit_code);
}

int	map_length(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0' && str[1] == '0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && (str[0] == '-' || str[0] == '+'))
		return (0);
	return (1);
}

//Check si la map est valide pour notre programme
//Split les nums parsés et effectue le check
//Free et exit sur une erreur
void	check_map(char **nums)
{
	char	**tmp;
	int		map_len;
	int		i;

	i = 0;
	map_len = map_length(nums);
	while (i < map_len)
	{
		tmp = ft_split(nums[i], ',');
		if (!is_number(tmp[0]))
		{
			i = 0;
			while (nums[i])
			{
				free(nums[i]);
				i++;
			}
			free(nums);
			freetab(tmp);
			error_exit("MAP IS INVALID\n", 1);
		}
		i++;
		freetab(tmp);
	}
}
