#include <kernel.h>
#include <kdata.h>
#include <printf.h>
#include <devtty.h>
#include <blkdev.h>
#include <devide.h>
#include <devsd.h>
#include "config.h"
#include <z180.h>
#include <ds1302.h>
#include <netdev.h>
#include "sc126.h"

static uint8_t has_1mb;	/* additional 512K RAM located in U2 socket */

void init_hardware_c(void)
{
	has_1mb = detect_1mb();

	if (has_1mb) {
		ramsize = 1024;
		procmem = 1024 - 64;
	} else {
		ramsize = 512;
		procmem = 512 - 64;
	}
	/* zero out the initial bufpool */
	memset(bufpool, 0, (char *) bufpool_end - (char *) bufpool);
	/* FIXME add a platform param for tuning wait states for memory
	   I/O and DMA (and one for the CF adapter of its own ?) */
}

void pagemap_init(void)
{
	int i;

	/* RC2014 has RAM in the top 512K of physical memory. 
	 * First 64K is used by the kernel. 
	 * Each process gets the full 64K for now.
	 * Set the low bit on the map indexes so that we can index page 0
	 * without confusing it with swap.
	 * Page size is 4KB. */
	for (i = 0x91; i < (1024 >> 2); i += 0x10)
		pagemap_add(i);
	/* Modded SC126 may have additional 512K starting at 0. */
	if (has_1mb)
		for (i = 0x01; i < (512 >> 2); i += 0x10)
			pagemap_add(i);

	ds1302_init();
	if (ds1302_present)
		kputs("DS1302 detected at 0x0C.\n");
}

void map_init(void)
{
	/* clone udata and stack into a regular process bank, return with common memory
	   for the new process loaded */
	copy_and_map_process(&init_process->p_page);
	/* kernel bank udata (0x300 bytes) is never used again -- could be reused? */
}

uint8_t plt_param(char *p)
{
	used(p);
	return 0;
}

void device_init(void)
{
	devide_init();
	devsd_init();
#ifdef CONFIG_NET
	netdev_init();
#endif
}
