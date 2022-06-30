/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ast-jean <ast-jean@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:58:16 by ast-jean          #+#    #+#             */
/*   Updated: 2022/06/29 12:50:35 by ast-jean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
# include  <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct s_map
{
	char	*map_file;
	int		width;
	int		height;
	int		is_p;
	int		is_e;
	int		is_c;
	int		is_o;	
	int		d_w;
	int		d_h;
	int		map_size;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	int		moves;
	int		collectible;
	void	*player_direction;
	int		anim;
	int		timer;
	int		timing;
	void	*enemy;
	void	*playerr;
	void	*playerr1;
	void	*playerl;
	void	*playerl1;
	char	direction;
	void	*collectible_sprite;
	void	*wall_sprite;
	void	*floor_sprite;
	void	*opened_sprite;
	void	*closed_sprite;
	void	*topwall_sprite;
	void	*rect;
	int		up;
	int		left;
	int		right;
	int		down;
	int		smallest;
	int		timer_request;
	int		error;
}			t_vars;

int		init_map(t_vars *vars, t_map *map, char *map_name);
void	print_map(t_map *map, t_vars *vars);
void	print_text(t_vars *vars);
int		event_manager(int keycode, t_vars *vars);
int		exit_game(t_vars *vars);
int		find_item(char *s, char c);
int		timer(t_vars *vars);
void	move_enemy(t_vars *vars);
int		animation(t_vars *vars);
int		check_border(t_map *map);
void	spawn_enemies(t_map *map);
void	give_dimensions(t_map *map);
int		get_y(int pos, t_vars *vars);
int		get_x(int pos, t_vars *vars);
void	update_distance(t_vars *vars, int pos_player, int pos_enemy);
void	find_smallest(t_vars *vars, int pos_enemy);
int		map_error(t_vars *vars);
int		check_char(t_map *map);
void	move(t_vars *vars, int pos);
int		checkrect(t_map *map);
void	init_map_item_counter(t_vars *vars);
void	init_enemy_direction(t_vars *vars);

#endif