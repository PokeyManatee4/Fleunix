#include <kernel.h>
#include <timer.h>
#include <kdata.h>
#include <printf.h>
#include <devtty.h>
#include <devinput.h>

uint16_t ramtop = PROGTOP;

/* On idle we spin checking for the terminals. Gives us more responsiveness
   for the polled ports */
void plt_idle(void)
{
  /* We don't want an idle poll and IRQ driven tty poll at the same moment */
  __asm
   halt
  __endasm;
}

uint8_t timer_wait;

void plt_interrupt(void)
{
 tty_pollirq();
 tty_polluart();
 timer_interrupt();
 poll_input();
 if (timer_wait)
   wakeup(&timer_interrupt);
}

/* This points to the last buffer in the disk buffers. There must be at least
   four buffers to avoid deadlocks. */
struct blkbuf *bufpool_end = bufpool + NBUFS;

/*
 *	We pack discard into the memory image is if it were just normal
 *	code but place it at the end after the buffers. When we finish up
 *	booting we turn everything from the buffer pool to the start of
 *	user space into buffers.
 *
 *	Discard gets turned into buffers or user space
 */
void plt_discard(void)
{
	uint16_t discard_size = 0xE000 - (uint16_t)bufpool_end;
	bufptr bp = bufpool_end;

	discard_size /= sizeof(struct blkbuf);

	kprintf("%d buffers added\n", discard_size);

	bufpool_end += discard_size;

	memset( bp, 0, discard_size * sizeof(struct blkbuf) );

	for( bp = bufpool + NBUFS; bp < bufpool_end; ++bp ){
		bp->bf_dev = NO_DEVICE;
		bp->bf_busy = BF_FREE;
	}
}

/* Adding dummy swapper since it is referenced by tricks.s */
void swapper(ptptr p)
{
  p;
}
