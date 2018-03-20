/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:33:25 by bsemchuk          #+#    #+#             */
/*   Updated: 2018/03/20 18:32:28 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdio.h>
# include <unistd.h>
# include <assert.h>
# include "../../vm/include/op.h"
# include "lists.h"
# include "../libft/libft.h"
# include "../../ft_printf/src/ft_printf.h"
# define HEADER_TYPE 1
# define INSTRUCTION_TYPE 2
# define LABEL_TYPE 4
# define HELP_ARG "-h"
# define HELP_ARG1 "-help"
# define DEBUG_ARG "-d"
# define DEBUG_ARG1 "-debug"
# define VERSION_ARG "-v"
# define VERSION_ARG1 "-version"
# define ASM_OUT_EXTENSION ".cor"
# define ASM_IN_EXTENSION ".s"
# define FIRST_ITEM 0
# define MY_TRUE 1
# define MY_FALSE 0
# define YES 1
# define NO 0
# define COMMAND 0
# define ARG1 1
# define ARG2 2
# define ARG3 3
# define START_QUOTES			'"'
# define END_QUOTES				START_QUOTES

typedef struct			s_line
{
	unsigned char		*line_content;
	unsigned char		*line_content_trim;
	unsigned char		*line_content_nocommas;
	char				command_index;
	unsigned char		*label;
	unsigned char		**deintegrated_line;
	unsigned char		**args;
	unsigned char		**cmd;
	unsigned			nargs;
	char				*parg;
	int					bytes_needed : 6;
	unsigned			id;
	t_arg_type			argtype[4];
	unsigned char		command_codage;
	unsigned char		linetype : 1;
}						t_line;

typedef struct			s_label
{
	char				*name;
	off_t				location;
}						t_label;

typedef union
{
	int					i;
	char				ch[4];
}						t_union;

typedef struct			s_s
{
	unsigned char		command[50];
	unsigned char		argsmax;
	unsigned char		argsflags[4];
	unsigned char		opcode;
	unsigned short		ctostart;
	unsigned char		description[50];
	unsigned char		codage;
	unsigned char		last;
	unsigned char		labelsize;
}						t_op;

typedef	struct
{
	int					res;
	unsigned short		sres;
}						t_lab;

typedef union
{
	unsigned short		si;
	unsigned char		cu[2];
}						t_u;

typedef struct			s_champion
{
	int					fdin;
	int					fdout;
	off_t				off_in;
	off_t				off_out;
	off_t				off_start_executable;
	off_t				off_size_executable;
	char				prog_name[PROG_NAME_LENGTH + 4];
	char				comment[COMMENT_LENGTH + 4];
	t_llist				*labels;
	unsigned			nerrorline;
	unsigned char		*serrorline;
	unsigned			lines_count;
	char				*out_filename;
	t_line				*tlines;
	int					champion_size;
}						t_champion;

int						validate_line(t_line *line, t_champion *champion);

int						treat_command(t_line *tline, t_champion *champion);
int						is_label_valid_char(char *label);
void					deintegrate_split_trim(t_line *tline);

int						change_filename_extension(char *path, char **new_name);

int						remember_all_labels_and_count_lines(\
								t_champion *champion);

int						count_executable_size(const t_champion *header,\
								unsigned int count_of_lines_for_tline_array);
int						count_args(char **deintegrated);
int						validate_remember_label(char *label,\
								t_champion *champion);
int						arguments_validation_and_codage_writing(t_line *tline,\
								t_champion *champion);
int						flush_dir(char *arg, t_champion *champion,\
								char i, unsigned id);
int						flush_ind(char *arg, t_champion *champion, unsigned id);

int						argtypes_into_tline(t_line *tline);
int						label_exists(char *label, t_champion *champion);
void					print_debug(t_line *line);
void					offset_setting(t_champion *champion);
int						flush_header_structure(t_champion *champion, int fd);
void					get_command_index_and_label_args_pointer(t_line *tline);

int						validate_arg(unsigned char arg_type_flag,\
								char *argument, t_champion *champion);
int						validate_ind(char *argument, t_champion *champion);
int						validate_dir(char *argument, t_champion *champion);
int						validate_reg(char *argument);

int						get_bytes_needed(t_line *tline);

int						finish_header(t_champion *header);
int						label_name_into_list(char *label_in_line,\
								t_champion *champion);
char					ft_replace_commas(unsigned char a);
int						flush_reg(char *arg, t_champion *champion);
int						flush_ind(char *arg, t_champion *champion, unsigned id);
int						flush_arguments(t_line *tline, t_champion *champion);
int						validate_arguments_types(t_line *tline);

int						get_parg_and_pparg(t_line *tline);

int						read_lines(char *path, t_champion *header);
void					do_nothing(void);
int						get_all_info_we_can_into_array_of_tlines(t_line *tline);
void					delete_comments(unsigned char *line);
int						ft_startswithchar(char const *line, char is);
int						ft_endswithchar(char const *line, char is);

void					get_label_if_present(t_line *tline);
int						is_header_valid(t_champion *header);

int						is_string_valid_int(const char *argument);

int						flush_dir_char(char *arg, t_champion\
								*champion, unsigned id);
int						ft_print_deintegrated(char **deintegrated);
int						ft_write_value_big_e4(int fd, int number);
int						ft_write_value_big_e2(int fd, unsigned short number);
int						op_index(const char *cmd);
void					trim_args(const t_line *tline);
int						get_all_info_we_can_into_array_of_tlines(t_line *tline);
int						where_is_my_offset(int fd, off_t *offset);
int						get_codage_to_tline(t_line *tline,\
								t_champion *champion);
int						is_header(unsigned char *line);
int						convert_into_struct_header_of_champion(t_line *tline,\
								t_champion *header);
int						treat_comment_header(char *line, t_champion *champion,\
								int *i);
int						treat_name_header(char *line, t_champion *header,\
								int *i);
int						find_end_name_or_comment(char *line, t_champion \
								*champion, char **end, int *i);
int						check_after_quotes(char *line);
char					*ft_strjoin_whitespace(char const *s1, char const *s2);
int						flush_header_structure(t_champion *champion, int fd);
int						flush_indir_char(char *arg, t_champion *champion,\
								unsigned id);
int						arguments_validation_and_codage_writing(t_line *tline,\
								t_champion *champion);

/*
**	read_lines.c
*/

void					free_lists(t_llist *list);

/*
**	useful
*/

int						ft_nchar(char const *str, char ch);
int						ft_startswithchar(char const *line, char is);
int						ft_endswithchar(char const *line, char with);
int						ft_strchindex(char const unsigned *line,\
								unsigned char ch);
int						ft_write_value_big_e2(int fd, unsigned short number);
int						ft_write_value_big_e4(int fd, int number);
char					*ft_strjumpword(char *str, unsigned n);

int						treat_instruction(t_line *tline, t_champion *header);
int						get_difference_in_bytes(int id_from, int id_to,\
								t_champion *champion);
int						get_label_id(char *label, t_champion *champion);

/*
**	Global variables
*/

extern int				g_is_debug;
extern t_op				g_op_tab[];

#endif
