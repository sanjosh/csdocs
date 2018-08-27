#pragma once

/**
 * Userspace handling of io_getevents()
 * as seen in fio - engines/libaio.c
 * and https://github.com/qemu/qemu/blob/master/block/linux-aio.c
 */

struct aio_ring {
  unsigned id;/** kernel internal index number */
  unsigned nr;/** number of io_events */
  unsigned head;
  unsigned tail;
  unsigned magic;
  unsigned compat_features;
  unsigned incompat_features;
  unsigned header_length;/** size of aio_ring */
  struct io_event events[0];
};

#define AIO_RING_MAGIC 0xa10a10a1

#define read_barrier() __asm__ __volatile__("": : :"memory")

int user_io_getevents(io_context_t aio_ctx, unsigned int max,
           struct io_event *events)
{
  long i = 0;
  unsigned head;
  struct aio_ring *ring = (struct aio_ring*) aio_ctx;
  while (i < max) {
    head = ring->head;
    if (head == ring->tail) {
      /* There are no more completions */
      break;
    } else {
      /* There is another completion to reap */
      events[i] = ring->events[head];
      read_barrier();
      ring->head = (head + 1) % ring->nr;
      i++;
    }
  }
  return i;
}
