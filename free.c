/*
** free.c for  in /home/tetard/EPITECH_Y2/PSU/PSU_2016_malloc
**
** Made by benjamin girard
** Login   <tetard@epitech.net>
**
** Started on  Fri Feb  3 11:01:49 2017 benjamin girard
** Last update Tue Feb  7 11:28:11 2017 benjamin girard
*/

#include <stdbool.h>
#include "malloc.h"
#include "free.h"
#include "thread.h"

static t_block			*assemble_free_block(t_block *first,
						     t_block *second)
{
  first->size += (second->size + sizeof(t_block));
  first->next = second->next;
  if (first->next)
    first->next->previous = first;
  return (first);
}

void				set_free_block(void *ptr)
{
  t_block			*block;

  block = (t_block *)((char *)ptr - sizeof(t_block));
  if (block == NULL)
    return ;
  block->is_free = true;
  if (block->previous && block->previous->is_free == true)
    block = assemble_free_block(block->previous, block);
  if (block->next && block->next->is_free == true)
    block = assemble_free_block(block, block->next);
}

void				free(void *ptr)
{
  lock_thread();
  if (ptr)
    set_free_block(ptr);
  unlock_thread();
  return ;
}
