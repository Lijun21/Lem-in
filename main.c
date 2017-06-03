/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <lwang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:12:23 by lwang             #+#    #+#             */
/*   Updated: 2017/05/30 21:12:25 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**find_edges(char *name, t_leminfo *info)
{
	char	**dst;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	tmp = NULL;
	dst = NULL;
	dst = (char**)malloc(sizeof(char*) * (info->room_total + 1));
	dst[0] = ft_strdup(name);
	while (info->link[i])
	{
		tmp = ft_strsplit(info->link[i], '-');
		if (!ft_strcmp(tmp[0], name))
		{
			dst[j] = ft_strdup(tmp[1]);
			j++;
		}
		if (!ft_strcmp(tmp[1], name))
		{
			dst[j] = ft_strdup(tmp[0]);
			j++;
		}
		deep_free(tmp);
		tmp = NULL;
		i++;
	}
	dst[j] = NULL;

	// int f = 0;
	// while (dst[f])
	// {
	// 	ft_printf("%s\n", dst[f]);
	// 	f++;
	// }
	return (dst);
}

char	***get_adj_list(t_leminfo *info)
{
	int i;
	char ***adj;
	// char **adj;

	i = 0;
	while (info->room_name[i])
		i++;
	info->room_total = i;
	adj = (char***)malloc(sizeof(char**) * (i + 1));
	i = 0;
	while (info->room_name[i])
	{
		adj[i] = find_edges(info->room_name[i], info);
		i++;
	}
	adj[i] = NULL;

	int j = 0;
	while (adj[j])
	{
		ft_printf("\n%s %s %s %s\n", adj[j][0], adj[j][1], adj[j][2], adj[j][3], adj[j][4], adj[j][5]);
		j++;
	}
	return (adj);
}





// void	print_all_path_util(char *start, char *end, bool *vistited, char **path)
// {


// }



// void	get_all_paths(int s, int e)
// {
// 	int i;
// 	// int path_index;s

// 	i = 0;
// 	bool *vistited = bool[info->room_total];
// 	info->path = (char**)malloc(sizeof(char*) * (info->room_total + 1));
// 	// path_index = 0;
// 	while (i < info->room_total)
// 	{
// 		vistited[i] = false;
// 		i++:
// 	}
// 	print_all_path_util(start, end, vistited, info->path);
// }

// t_vertex	**nub_room(t_leminfo *info)
// {
// 	t_vertex	**dst;
// 	int			i;

// 	i = 0;
// 	while (info->room_name[i])
// 		i++;
// 	info->room_total = i;
// 	dst = (t_vertex**)malloc(sizeof(t_vertex*) * (i + 1));
// 	i = 0;
// 	while (info->room_name[i])
// 	{
// 		dst[i] = (t_vertex*)malloc(sizeof(t_vertex) * 1);
// 		dst[i]->name = ft_strdup(info->room_name[i]);
// 		dst[i]->i = i;
// 		i++;
// 	}
// 	dst[i] = NULL;

// 	int z= 0;
// 	while (dst[z])
// 	{
// 		ft_printf("%s %d\n", dst[z]->name, dst[z]->i);
// 		z++;
// 	}
// 	return (dst);
// }

// char	*get_name(t_vertex **room, int nbr)
// {
// 	int i;

// 	i = 0;
// 	ft_printf("the nbr is %s\n", nbr);
// 	while (room[i])
// 	{
// 		ft_printf("room is and nbr %s, %d\n", room[i]->name, room[i]->i);
// 		if (room[i]->i == nbr)
// 			return (room[i]->name);
// 		i++;
// 	}
// 	ft_printf("somehting wrong\n");
// 	return (NULL);
// }

// int		get_nbr(t_vertex **room, char *name)
// {
// 	int	i;

// 	i = 0;
// 	// ft_printf("the name is %s\n", name);
// 	while (room[i] != NULL)
// 	{
// 		// ft_printf("room %s\n", room[i]->name);
// 		if (!ft_strcmp(room[i]->name, name))
// 			return (room[i]->i);
// 		i++;
// 	}
// 	ft_printf("111somehting wrong\n");
// 	return (0);
// }

// int		*get_adj_helper(t_leminfo *info, t_vertex **room)
// {
// 	int		i;
// 	int		j;
// 	int		*dst;
// 	char	**tmp;

// 	i = 0;
// 	j = 0;
// 	dst = (int*)malloc(sizeof(int) * (info->room_total + 1));
// 	while (info->link[i])
// 	{
// 		tmp = ft_strsplit(info->link[i], '-');
// 		if (!ft_strcmp(tmp[0], get_name(room, i)))
// 		{
// 			dst[j] = get_nbr(room, tmp[1]);
// 			j++;
// 		}
// 		if (!ft_strcmp(tmp[1], get_name(room, i)))
// 		{
// 			dst[j] = get_nbr(room, tmp[0]);
// 			j++;
// 		}
// 		deep_free(tmp);
// 		tmp = NULL;
// 		i++;
// 	}
// 	dst[j] = -100;
// 	return (dst);
// }

// int		**get_adj_list(t_leminfo *info, t_vertex **room)
// {
// 	int		**adj;
// 	int	i;

// 	i = 0;
// 	adj = (int**)malloc(sizeof(int*) * (info->room_total + 1));
// 	while (i < info->room_total)
// 	{
// 		adj[i] = get_adj_helper(info, room);
// 		i++;
// 	}
// 	adj[i] = NULL;

// 	int z= 0;
// 	int h= 0;
// 	while (adj[z] != NULL)
// 	{
// 		while (adj[z][h] != -100)
// 		{
// 			ft_printf("%d", adj[z][h]);
// 			h++;
// 		}
// 		ft_printf("\n");
// 		z++;
// 	}
// 	return (adj);
// }

// void	find_linked(char *s, t_leminfo *info)
// {
// 	int i;

// }

char		*sep(char *s)
{
	char **tmp;

	tmp = ft_strsplit(s, ' ');
	return (tmp[0]);
}

int			loc(char *s, char ***adj)
{
	int i;

	i = 0;
	// ft_printf("s is %s\n", s);
	while (adj[i])
	{
		if (!ft_strcmp(adj[i][0], s))
			return (i);
		i++;
	}
	ft_printf("sth not right happened\n");
	return (0);
}

int			test_vist(char *s, char **path)
{
	int i;

	i = 0;
	while (path[i])
	{
		if (!ft_strcmp(path[i], s))
			return (1);
		i++;
	}
	return (0);
}

int			check_end(t_leminfo *info)
{
	int i;

	i = 0;
	while (info->path[i])
		i++;
	if (!ft_strcmp(info->path[i - 1], sep(info->end)))
		return (1);
	return (0);
}

void		find_path_till(t_leminfo *info, char ***adj, int i, int j)
{
	int tmp;
	
	ft_printf("i is %d info->path[i] is %s\n", i, info->path[i]);
	if (check_end(info))
	{
		ft_printf("haha, found one\n");
		int z=0;
		while (info->path[z])
		{
			ft_printf("%s\n", info->path[z]);
			z++;
		}
	}
	else
	{
		tmp = loc(info->path[i], adj);
		while (adj[tmp][j])
		{	
			ft_printf("tmp is %d j is %d, adj[tmp][j] is %s\n", tmp, j, adj[tmp][j]);
			if (!test_vist(adj[tmp][j], info->path))
			{
				info->path[i + 1] = ft_strdup(adj[tmp][j]);
				info->path[i + 2] = NULL;
				find_path_till(info, adj, i++, j);
			}
			else
				j++;
		}
	}
	// info->path[i - 1] = NULL;
}

void		find_one_path(t_leminfo *info, char ***adj)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 1;
	tmp = 0;
	info->path = (char**)malloc(sizeof(char*) * (info->room_total + 1));
	info->path[i] = ft_strdup(sep(info->start));
	info->path[i + 1] = NULL;
	find_path_till(info, adj, i, j);
}

int	print_lemin_result(t_leminfo *info, char **map)
{
	char		***adj;

	print_map(map, info);

	adj = get_adj_list(info);

	find_one_path(info, adj);

	ft_printf("hello\n");
	int z=0;
	while (info->path[z])
	{
		ft_printf("%s\n", info->path[z]);
		z++;
	}

	return (0);
}

int	main(void)
{
	int			r;
	char		*line;
	char		**map;
	t_leminfo	info;

	ft_memset(&info, 0, sizeof(t_leminfo));
	map = (char**)malloc(sizeof(char*) * (10000 + 1));
	while ((r = get_next_line(0, &line)) && r != -1)
	{
		map[info.count_line] = ft_strdup(line);
		info.count_line++;
		free(line);
	}
	map[info.count_line] = NULL;
	check_range(info.count_line, map);

	validate_map(map, &info);
	if (check_map(map, &info))
	{
		deep_free(map);
		perror("Invalid map");
		return (1);
	}
	if (print_lemin_result(&info, map))
		return (1);
}
