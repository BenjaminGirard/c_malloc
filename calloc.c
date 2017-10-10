/*
** calloc.c for  in /home/girard_z/tek2/PSU/PSU_2016_malloc
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue Jan 31 14:29:14 2017 benjamin girard
** Last update Tue Jan 31 16:16:00 2017 benjamin girard
*/

#include <string.h>
#include "malloc.h"

void			*calloc(size_t nmemb, size_t size)
{
  void			*ptr;

  if ((ptr = malloc(nmemb * size)) == NULL)
    return (NULL);
  memset(ptr, 0, nmemb * size);
  return (ptr);
}
