/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:03:27 by arpereir          #+#    #+#             */
/*   Updated: 2025/05/01 19:22:15 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		j;
	int		len;

	splitted = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!s || !splitted)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			splitted[j++] = ft_substr(s, i, len);
			i += len;
		}
	}
	return (splitted);
}
/*
 int	main(void)
 {
 	char	str[] = "Ariclenes,Alexandre,SuperGHOST_42";

 	char	**ptr = ft_split(str, ',');
	
 	for (int i = 0; ptr[i] != NULL; i++)
 	{
 		printf("%s\n", ptr[i]);
 		free(ptr[i]);
 	}
 	free(ptr);
	
 	return (0);
}*/
