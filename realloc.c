/*
** realloc.c for  in /home/girard_z/EPITECH_Y02/B-PSU-356/PSU_2016_malloc
**
** Made by girard_z
** Login   <girard_z@epitech.net>
**
** Started on  Thu Jan 26 13:15:15 2017 girard_z
** Last update Tue Feb  7 18:01:34 2017 benjamin girard
*/

#include <string.h>
#include "realloc.h"
#include "malloc.h"
#include "free.h"

void				*realloc(void *ptr, size_t size)
{
  void				*tmp;
  t_block			*block;

   if (ptr && size == 0)
    {
      free(ptr);
      return (NULL);
    }
  if ((tmp = malloc(size)) == NULL)
    return (NULL);
  if (!ptr)
    return (tmp);
  block = (t_block *)((char *)ptr - sizeof(t_block));
  if (block)
    tmp = memcpy(tmp, ptr, (block->size < size) ? (block->size) : (size));
  free(ptr);
  return (tmp);
}
