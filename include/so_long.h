/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <mloubet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:54:28 by mloubet           #+#    #+#             */
/*   Updated: 2022/01/06 21:38:16 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# ifndef MAX_FD
#  define MAX_FD 50
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

/*
// MAC
# define ESC  53
# define UP_W 13
# define UP   126
# define DOWN_S 1
# define DOWN 125
# define LEFT_A 0
# define LEFT 123
# define RIGHT_D 2
# define RIGHT 124
*/

# define ESC  65307
# define UP_W 119
# define UP   65362
# define DOWN_S 115
# define DOWN 65364
# define LEFT_A 97
# define LEFT 65361
# define RIGHT_D 100
# define RIGHT 65363

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct s_player
{
	int	orientation_x;
	int	orientation_y;
	int	prev_x;
	int	prev_y;
	int	curr_x;
	int	curr_y;
	int	collectibles;
	int	n_moves;
}				t_player;

typedef struct s_img
{
	void	*xpm;
	char	*data;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_game
{
	t_mlx		mlx;
	t_img		img;
	t_img		ground;
	t_img		wall;
	t_img		collectible;
	t_img		exit;
	t_img		pacman_left;
	t_img		pacman_right;
	t_img		pacman_up;
	t_img		pacman_down;
	int			total_collectibles;
	char		**map;
	int			width;
	int			height;
	int			bpp;
	int			win_width;
	int			win_height;
	t_player	player;
}				t_game;

void			view_tab(char **s);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
void			exit_error_fd(char *s, int fd);
int				ft_strcmp(char *s, char *t);
int				ft_strcmp_end(char *s, char *t);
void			exit_error_fd(char *s, int fd);
int				is_rectangular(char **line, int ymax, int xmax);
int				right_chars(char **map, int e, int c1, int p);
int				walls(char **map, int ymax, int xmax);
int				right_map(char **map, int ymax, int xmax);
void			free_gnl(char ***gnl);
int				ret_line(char **backup, char **line, int nl_len);
int				ret_last_line(char **backup, char **line, int len_read);
int				get_next_line(int fd, char **line);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strdup(const char *str);
int				ft_strchr(const char *s, int c);
int				is_found(int c, char *s);
int				exit_game(t_game *game);
int				draw_background(t_game *game);
int				draw(t_game *game);
void			colored_square(int x, int y, int color, t_game *game);
void			draw_texture(int x, int y, t_img *sprite, t_game *game);
void			load_img(t_game *game, t_img *img, char *path);
void			load_sprites(t_game *game);
void			my_pixel_put(t_img *img, int x, int y, int color);
unsigned int	pixel_color(int x, int y, t_img *img);
int				move_player(int next_x, int next_y, t_game *game);
int				handle_player_moves(int keysym, t_game *game);
void			get_player_pos_and_collectibles(t_game *game);
int				display_image(t_game *game);
void			load_img(t_game *game, t_img *sprite, char *path);
void			load_sprites(t_game *game);
int				game_display(t_game *game);
void			window_display(t_game *game);
int				exit_game(t_game *game);
void			free_sprites(t_game *game);
void			*ft_calloc(size_t count, size_t size);
void			map_size(int fd, t_game *game);
void			allocate_map(t_game *game);
void			get_map(int fd, t_game *game);

#endif
