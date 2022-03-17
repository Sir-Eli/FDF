/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:54:46 by esirnio           #+#    #+#             */
/*   Updated: 2021/12/17 15:50:33 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_string(const char *str, int size, int i)
{
	char	*temp;
	int		ind;
	int		tempi;

	ind = 0;
	tempi = i - size;
	temp = (char *)malloc(size + 1);
	if (!temp)
		return (NULL);
	while ((ind + tempi) < (tempi + size))
	{
		temp[ind] = str[tempi + ind];
		ind++;
	}
	temp[ind] = '\0';
	return (temp);
}

static int	howmany(const char *s, char c)
{
	int	i;
	int	howmany;
	int	last;

	i = 0;
	howmany = 0;
	last = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			howmany++;
			last = 0;
		}
		i++;
		last++;
	}
	if (last > 1)
		howmany++;
	return (howmany + 1);
}

static char	**do_split(char **split, int *arr, char *str, char c)
{
	while (str[arr[0]] != '\0')
	{
		if (str[arr[0]] == c && arr[1] > 0)
		{
			split[arr[2]++] = do_string(str, arr[1], arr[0]);
			if (split[arr[2] - 1] == NULL)
				return (ft_free_array(split));
			arr[1] = 0;
		}
		while (str[arr[0]] == c)
			arr[0]++;
		if (str[arr[0]] == '\0')
			break ;
		arr[1]++;
		arr[0]++;
	}
	if (arr[1] > 0)
	{
		split[arr[2]++] = do_string(str, arr[1], arr[0]);
		if (split[arr[2] - 1] == NULL)
			return (ft_free_array(split));
	}
	split[arr[2]] = NULL;
	return (split);
}

char	**ft_strsplit(char const *str, char c)
{
	char	**split;
	int		arr[3];

	ft_memset(arr, 0, sizeof(arr));
	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (howmany(str, c)));
	if (!split)
		return (NULL);
	split = do_split(split, arr, (char *)str, c);
	return (split);
}
