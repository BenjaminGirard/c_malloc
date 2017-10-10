/*
** malloc.c for  in /home/girard_z/EPITECH_Y02/B-PSU-356/PSU_2016_malloc
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Tue Jan 24 20:35:00 2017 girard_z
** Last update Sat Feb 11 12:57:42 2017 girard_z
*/

#include <stdio.h>
#include <limits.h>
#include "malloc.h"
#include "free.h"
#include "thread.h"

void				*first_address = NULL;

static void			split_block(t_block *block, size_t size)
{
  t_block			*elem;

  elem = (t_block *)((char *)block + (sizeof(t_block) + size));
  elem->is_free = true;
  elem->size = block->size - size - sizeof(t_block);
  elem->previous = block;
  elem->next = block->next;
  if (block->next)
    block->next->previous = elem;
  block->size = size;
  block->next = elem;
  block->is_free = false;
}

static bool			add_block(size_t size)
{
  t_block			*tmp;
  t_block			*new;

  tmp = (t_block*)first_address;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if (SIZE_PAGE(((unsigned long long int)size + (sizeof(t_block) * 2)))
      >= INT_MAX
      || (void *)(new = sbrk(SIZE_PAGE((size + (sizeof(t_block) * 2)))))
      == (void *)(-1))
    if ((unsigned long long int)size + (sizeof(t_block) * 2) >= INT_MAX ||
	(void *)(new = sbrk(size + (sizeof(t_block) * 2))) == (void *)(-1))
      return (false);
  new->is_free = true;
  new->size = (char *)sbrk(0) - ((char *)new + sizeof(t_block));
  new->next = NULL;
  new->previous = tmp;
  if (tmp == NULL)
    first_address = new;
  else
    tmp->next = new;
  set_free_block((char *)new + sizeof(t_block));
  return (true);
}

static void			*parse_blocks(t_block *block, size_t size)
{
  t_block			*tmp;

  tmp = block;
  while (tmp != NULL)
    {
      if (tmp->is_free == true && tmp->size >= size + sizeof(t_block))
	return ((void *)tmp);
      tmp = tmp->next;
    }
  return (tmp);
}

void				*malloc(size_t size)
{
  void				*tmp;

  lock_thread();
  if (size >= INT_MAX)
    {
	  unlock_thread();
	  return (NULL);
    }
  if ((tmp = parse_blocks((t_block *)first_address, size)) == NULL)
      if (add_block(size) == false)
	{
	  unlock_thread();
	  return (NULL);
	}
  tmp = tmp ? tmp : parse_blocks(first_address, size);
  split_block(tmp, size);
  unlock_thread();
  return ((void *)((char *)tmp + sizeof(t_block)));
}

void				show_alloc_mem(void)
{
  void				*tmp;

  tmp = (void *)first_address;
  printf("break : %p\n", sbrk(0));
  while (tmp != NULL)
    {
      printf("%p - %p : %llu bytes\n", tmp + sizeof(t_block),
	     tmp + ((t_block *)tmp)->size + sizeof(t_block),
	     (unsigned long long int)((t_block *)tmp)->size);
      tmp = (void *)(((t_block *)tmp)->next);
    }
}
