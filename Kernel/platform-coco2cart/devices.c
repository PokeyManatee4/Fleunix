#include <kernel.h>
#include <version.h>
#include <kdata.h>
#include <devfd.h>
#include <devdw.h>
#include <devsys.h>
#include <devlpr.h>
#include <tty.h>
#include <vt.h>
#include <devtty.h>
#include <mini_ide.h>
#include <devsdc.h>
#include <device.h>

struct devsw dev_tab[] =  /* The device driver switch table */
{
// minor    open         close        read      write       ioctl
// -----------------------------------------------------------------
  /* 0: /dev/hd		Hard disc block devices (IDE) */
#ifdef CONFIG_WITH_IDE
  {  ide_open,	    no_close,	 ide_read,  ide_write, ide_ioctl },
#else
  {  no_open,       no_close,    sdc_read,  sdc_write, no_ioctl },
#endif
  /* 1: /dev/fd		Floppy disc block devices  */
  {  no_open,       no_close,    no_rdwr,   no_rdwr ,  no_ioctl },
  /* 2: /dev/tty	TTY devices */
  {  tty_open,      tty_close,   tty_read,  tty_write, gfx_ioctl },
    /* 3: /dev/lpr	Printer devices */
  {  no_open,       no_close,    no_rdwr,   no_rdwr,   no_ioctl  },
  /* 4: /dev/mem etc	System devices (one offs) */
  {  no_open,       no_close,    sys_read, sys_write,  sys_ioctl  },
  /* Pack to 7 with nxio if adding private devices and start at 8 */
  {  nxio_open,     no_close,    no_rdwr,   no_rdwr,   no_ioctl },
  {  nxio_open,     no_close,    no_rdwr,   no_rdwr,   no_ioctl },
  {  nxio_open,     no_close,    no_rdwr,   no_rdwr,   no_ioctl },
  /* 8: /dev/dw		DriveWire remote disk images */
  {  dw_open,       no_close,    dw_read,   dw_write,  no_ioctl },
};

bool validdev(uint16_t dev)
{
    /* This is a bit uglier than needed but the right hand side is
       a constant this way */
    if(dev > ((sizeof(dev_tab)/sizeof(struct devsw)) << 8) - 1)
	return false;
    else
        return true;
}

void device_init(void)
{
#ifdef CONFIG_WITH_IDE
    ide_probe();
#endif
#ifdef CONFIG_WITH_SDC
    devsdc_init();
#endif
}
