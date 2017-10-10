/*
** thread.c for  in /home/girard_z/tek2/PSU/PSU_2016_malloc
**
** Made by benjamin girard
** Login   <girard_z@epitech.net>
**
** Started on  Tue Jan 31 14:56:41 2017 benjamin girard
** Last update Tue Jan 31 14:58:25 2017 benjamin girard
*/

#include <pthread.h>

static pthread_mutex_t			mut = PTHREAD_MUTEX_INITIALIZER;

void					lock_thread(void)
{
  pthread_mutex_lock(&mut);
}


void					unlock_thread(void)
{
  pthread_mutex_unlock(&mut);
}
