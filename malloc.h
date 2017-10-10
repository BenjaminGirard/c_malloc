/*
** malloc.h for  in /home/girard_z/EPITECH_Y02/B-PSU-356/PSU_2016_malloc
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Tue Jan 24 19:43:41 2017 girard_z
** Last update Wed Feb  8 12:12:49 2017 benjamin girard
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <stdbool.h>
#include <unistd.h>

# define DEFAULT_SIZE getpagesize()
# define SIZE_PAGE(size) ((((1 + (size / DEFAULT_SIZE)) * 2) * DEFAULT_SIZE))

typedef struct				s_block
{
  char					is_free;
  unsigned long long int		size;

  struct s_block			*previous;
  struct s_block			*next;
}					t_block;

void					*malloc(size_t size);
void					show_alloc_mem(void);

#endif /* !MALLOC_H_ */
