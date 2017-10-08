// Simple command-line kernel monitor useful for
// controlling the kernel and exploring the system interactively.

#include <inc/stdio.h>
#include <inc/string.h>
#include <inc/memlayout.h>
#include <inc/assert.h>
#include <inc/x86.h>

#include <kern/console.h>
#include <kern/monitor.h>
#include <kern/kdebug.h>

#define CMDBUF_SIZE	80	// enough for one VGA text line


struct Command {
	const char *name;
	const char *desc;
	// return -1 to force monitor to exit
	int (*func)(int argc, char** argv, struct Trapframe* tf);
};

static struct Command commands[] = {
	{ "help", "Display this list of commands", mon_help },
	{ "backtrace", "Stack", mon_backtrace },
	{ "bawix", "by BaWiX_", BaWiX },
	{ "clear", "- CLEAR Display", clr },
	{ "kerninfo", "Display information about the kernel", mon_kerninfo },
	{ "exit", "Exit", exit },
};
int
clr()
{
cprintf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
}



/***** Implementations of basic kernel monitor commands *****/

int
mon_help(int argc, char **argv, struct Trapframe *tf)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(commands); i++)
		cprintf("%s - %s\n", commands[i].name, commands[i].desc);
	return 0;
}
int
exit()
{
    cprintf("by BaWiX_ \n");
//asm("movw $0x1000,%ax;	movw %ax,%ss;	movw $0xf000,%sp;	movw $0x5307,%ax;	movw $1,%bx;	movw $3,%cx;	int  $0x15");

asm("    mov %ax, 0x1000;    mov %ax, %ss;    mov %sp, 0xf000;    mov %ax, 0x5307;    mov %bx, 0x0001;    mov %cx, 0x0003; int $0x15 ;");
return 0;
}

int
BaWiX()
{
cprintf("%m %s ",0x0000,"0x0000");
cprintf("%m %s ",0x0100,"0x0100");
cprintf("%m %s ",0x0200,"0x0200");
cprintf("%m %s ",0x0300,"0x0300");
cprintf("%m %s ",0x0400,"0x0400");
cprintf("%m %s ",0x0500,"0x0500");
cprintf("%m %s ",0x0600,"0x0600");
cprintf("%m %s ",0x0700,"0x0700");
cprintf("%m %s ",0x0800,"0x0800");
cprintf("%m %s ",0x0900,"0x0900");
cprintf("%m %s ",0x0a00,"0x0a00");
cprintf("%m %s ",0x0b00,"0x0b00");
cprintf("%m %s ",0x0c00,"0x0c00");
cprintf("%m %s ",0x0d00,"0x0d00");
cprintf("%m %s ",0x0e00,"0x0e00");
cprintf("%m %s ",0x0f00,"0x0f00");
cprintf("%m %s ",0x1000,"0x1000");
cprintf("%m %s ",0x1100,"0x1100");
cprintf("%m %s ",0x1200,"0x1200");
cprintf("%m %s ",0x1300,"0x1300");
cprintf("%m %s ",0x1400,"0x1400");
cprintf("%m %s ",0x1500,"0x1500");
cprintf("%m %s ",0x1600,"0x1600");
cprintf("%m %s ",0x1700,"0x1700");
cprintf("%m %s ",0x1800,"0x1800");
cprintf("%m %s ",0x1900,"0x1900");
cprintf("%m %s ",0x1a00,"0x1a00");
cprintf("%m %s ",0x1b00,"0x1b00");
cprintf("%m %s ",0x1c00,"0x1c00");
cprintf("%m %s ",0x1d00,"0x1d00");
cprintf("%m %s ",0x1e00,"0x1e00");
cprintf("%m %s ",0x1f00,"0x1f00");
cprintf("%m %s ",0x2000,"0x2000");
cprintf("%m %s ",0x2100,"0x2100");
cprintf("%m %s ",0x2200,"0x2200");
cprintf("%m %s ",0x2300,"0x2300");
cprintf("%m %s ",0x2400,"0x2400");
cprintf("%m %s ",0x2500,"0x2500");
cprintf("%m %s ",0x2600,"0x2600");
cprintf("%m %s ",0x2700,"0x2700");
cprintf("%m %s ",0x2800,"0x2800");
cprintf("%m %s ",0x2900,"0x2900");
cprintf("%m %s ",0x2a00,"0x2a00");
cprintf("%m %s ",0x2b00,"0x2b00");
cprintf("%m %s ",0x2c00,"0x2c00");
cprintf("%m %s ",0x2d00,"0x2d00");
cprintf("%m %s ",0x2e00,"0x2e00");
cprintf("%m %s ",0x2f00,"0x2f00");
cprintf("%m %s ",0x3000,"0x3000");
cprintf("%m %s ",0x3100,"0x3100");
cprintf("%m %s ",0x3200,"0x3200");
cprintf("%m %s ",0x3300,"0x3300");
cprintf("%m %s ",0x3400,"0x3400");
cprintf("%m %s ",0x3500,"0x3500");
cprintf("%m %s ",0x3600,"0x3600");
cprintf("%m %s ",0x3700,"0x3700");
cprintf("%m %s ",0x3800,"0x3800");
cprintf("%m %s ",0x3900,"0x3900");
cprintf("%m %s ",0x3a00,"0x3a00");
cprintf("%m %s ",0x3b00,"0x3b00");
cprintf("%m %s ",0x3c00,"0x3c00");
cprintf("%m %s ",0x3d00,"0x3d00");
cprintf("%m %s ",0x3e00,"0x3e00");
cprintf("%m %s ",0x3f00,"0x3f00");
cprintf("%m %s ",0x4000,"0x4000");
cprintf("%m %s ",0x4100,"0x4100");
cprintf("%m %s ",0x4200,"0x4200");
cprintf("%m %s ",0x4300,"0x4300");
cprintf("%m %s ",0x4400,"0x4400");
cprintf("%m %s ",0x4500,"0x4500");
cprintf("%m %s ",0x4600,"0x4600");
cprintf("%m %s ",0x4700,"0x4700");
cprintf("%m %s ",0x4800,"0x4800");
cprintf("%m %s ",0x4900,"0x4900");
cprintf("%m %s ",0x4a00,"0x4a00");
cprintf("%m %s ",0x4b00,"0x4b00");
cprintf("%m %s ",0x4c00,"0x4c00");
cprintf("%m %s ",0x4d00,"0x4d00");
cprintf("%m %s ",0x4e00,"0x4e00");
cprintf("%m %s ",0x4f00,"0x4f00");
cprintf("%m %s ",0x5000,"0x5000");
cprintf("%m %s ",0x5100,"0x5100");
cprintf("%m %s ",0x5200,"0x5200");
cprintf("%m %s ",0x5300,"0x5300");
cprintf("%m %s ",0x5400,"0x5400");
cprintf("%m %s ",0x5500,"0x5500");
cprintf("%m %s ",0x5600,"0x5600");
cprintf("%m %s ",0x5700,"0x5700");
cprintf("%m %s ",0x5800,"0x5800");
cprintf("%m %s ",0x5900,"0x5900");
cprintf("%m %s ",0x5a00,"0x5a00");
cprintf("%m %s ",0x5b00,"0x5b00");
cprintf("%m %s ",0x5c00,"0x5c00");
cprintf("%m %s ",0x5d00,"0x5d00");
cprintf("%m %s ",0x5e00,"0x5e00");
cprintf("%m %s ",0x5f00,"0x5f00");
cprintf("%m %s ",0x6000,"0x6000");
cprintf("%m %s ",0x6100,"0x6100");
cprintf("%m %s ",0x6200,"0x6200");
cprintf("%m %s ",0x6300,"0x6300");
cprintf("%m %s ",0x6400,"0x6400");
cprintf("%m %s ",0x6500,"0x6500");
cprintf("%m %s ",0x6600,"0x6600");
cprintf("%m %s ",0x6700,"0x6700");
cprintf("%m %s ",0x6800,"0x6800");
cprintf("%m %s ",0x6900,"0x6900");
cprintf("%m %s ",0x6a00,"0x6a00");
cprintf("%m %s ",0x6b00,"0x6b00");
cprintf("%m %s ",0x6c00,"0x6c00");
cprintf("%m %s ",0x6d00,"0x6d00");
cprintf("%m %s ",0x6e00,"0x6e00");
cprintf("%m %s ",0x6f00,"0x6f00");
cprintf("%m %s ",0x7000,"0x7000");
cprintf("%m %s ",0x7100,"0x7100");
cprintf("%m %s ",0x7200,"0x7200");
cprintf("%m %s ",0x7300,"0x7300");
cprintf("%m %s ",0x7400,"0x7400");
cprintf("%m %s ",0x7500,"0x7500");
cprintf("%m %s ",0x7600,"0x7600");
cprintf("%m %s ",0x7700,"0x7700");
cprintf("%m %s ",0x7800,"0x7800");
cprintf("%m %s ",0x7900,"0x7900");
cprintf("%m %s ",0x7a00,"0x7a00");
cprintf("%m %s ",0x7b00,"0x7b00");
cprintf("%m %s ",0x7c00,"0x7c00");
cprintf("%m %s ",0x7d00,"0x7d00");
cprintf("%m %s ",0x7e00,"0x7e00");
cprintf("%m %s ",0x7f00,"0x7f00");
getchar();	
cprintf("%m %s ",0x8000,"0x8000");
cprintf("%m %s ",0x8100,"0x8100");
cprintf("%m %s ",0x8200,"0x8200");
cprintf("%m %s ",0x8300,"0x8300");
cprintf("%m %s ",0x8400,"0x8400");
cprintf("%m %s ",0x8500,"0x8500");
cprintf("%m %s ",0x8600,"0x8600");
cprintf("%m %s ",0x8700,"0x8700");
cprintf("%m %s ",0x8800,"0x8800");
cprintf("%m %s ",0x8900,"0x8900");
cprintf("%m %s ",0x8a00,"0x8a00");
cprintf("%m %s ",0x8b00,"0x8b00");
cprintf("%m %s ",0x8c00,"0x8c00");
cprintf("%m %s ",0x8d00,"0x8d00");
cprintf("%m %s ",0x8e00,"0x8e00");
cprintf("%m %s ",0x8f00,"0x8f00");
cprintf("%m %s ",0x9000,"0x9000");
cprintf("%m %s ",0x9100,"0x9100");
cprintf("%m %s ",0x9200,"0x9200");
cprintf("%m %s ",0x9300,"0x9300");
cprintf("%m %s ",0x9400,"0x9400");
cprintf("%m %s ",0x9500,"0x9500");
cprintf("%m %s ",0x9600,"0x9600");
cprintf("%m %s ",0x9700,"0x9700");
cprintf("%m %s ",0x9800,"0x9800");
cprintf("%m %s ",0x9900,"0x9900");
cprintf("%m %s ",0x9a00,"0x9a00");
cprintf("%m %s ",0x9b00,"0x9b00");
cprintf("%m %s ",0x9c00,"0x9c00");
cprintf("%m %s ",0x9d00,"0x9d00");
cprintf("%m %s ",0x9e00,"0x9e00");
cprintf("%m %s ",0x9f00,"0x9f00");
cprintf("%m %s ",0xa000,"0xa000");
cprintf("%m %s ",0xa100,"0xa100");
cprintf("%m %s ",0xa200,"0xa200");
cprintf("%m %s ",0xa300,"0xa300");
cprintf("%m %s ",0xa400,"0xa400");
cprintf("%m %s ",0xa500,"0xa500");
cprintf("%m %s ",0xa600,"0xa600");
cprintf("%m %s ",0xa700,"0xa700");
cprintf("%m %s ",0xa800,"0xa800");
cprintf("%m %s ",0xa900,"0xa900");
cprintf("%m %s ",0xaa00,"0xaa00");
cprintf("%m %s ",0xab00,"0xab00");
cprintf("%m %s ",0xac00,"0xac00");
cprintf("%m %s ",0xad00,"0xad00");
cprintf("%m %s ",0xae00,"0xae00");
cprintf("%m %s ",0xaf00,"0xaf00");
cprintf("%m %s ",0xb000,"0xb000");
cprintf("%m %s ",0xb100,"0xb100");
cprintf("%m %s ",0xb200,"0xb200");
cprintf("%m %s ",0xb300,"0xb300");
cprintf("%m %s ",0xb400,"0xb400");
cprintf("%m %s ",0xb500,"0xb500");
cprintf("%m %s ",0xb600,"0xb600");
cprintf("%m %s ",0xb700,"0xb700");
cprintf("%m %s ",0xb800,"0xb800");
cprintf("%m %s ",0xb900,"0xb900");
cprintf("%m %s ",0xba00,"0xba00");
cprintf("%m %s ",0xbb00,"0xbb00");
cprintf("%m %s ",0xbc00,"0xbc00");
cprintf("%m %s ",0xbd00,"0xbd00");
cprintf("%m %s ",0xbe00,"0xbe00");
cprintf("%m %s ",0xbf00,"0xbf00");
cprintf("%m %s ",0xc000,"0xc000");
cprintf("%m %s ",0xc100,"0xc100");
cprintf("%m %s ",0xc200,"0xc200");
cprintf("%m %s ",0xc300,"0xc300");
cprintf("%m %s ",0xc400,"0xc400");
cprintf("%m %s ",0xc500,"0xc500");
cprintf("%m %s ",0xc600,"0xc600");
cprintf("%m %s ",0xc700,"0xc700");
cprintf("%m %s ",0xc800,"0xc800");
cprintf("%m %s ",0xc900,"0xc900");
cprintf("%m %s ",0xca00,"0xca00");
cprintf("%m %s ",0xcb00,"0xcb00");
cprintf("%m %s ",0xcc00,"0xcc00");
cprintf("%m %s ",0xcd00,"0xcd00");
cprintf("%m %s ",0xce00,"0xce00");
cprintf("%m %s ",0xcf00,"0xcf00");
cprintf("%m %s ",0xd000,"0xd000");
cprintf("%m %s ",0xd100,"0xd100");
cprintf("%m %s ",0xd200,"0xd200");
cprintf("%m %s ",0xd300,"0xd300");
cprintf("%m %s ",0xd400,"0xd400");
cprintf("%m %s ",0xd500,"0xd500");
cprintf("%m %s ",0xd600,"0xd600");
cprintf("%m %s ",0xd700,"0xd700");
cprintf("%m %s ",0xd800,"0xd800");
cprintf("%m %s ",0xd900,"0xd900");
cprintf("%m %s ",0xda00,"0xda00");
cprintf("%m %s ",0xdb00,"0xdb00");
cprintf("%m %s ",0xdc00,"0xdc00");
cprintf("%m %s ",0xdd00,"0xdd00");
cprintf("%m %s ",0xde00,"0xde00");
cprintf("%m %s ",0xdf00,"0xdf00");
cprintf("%m %s ",0xe000,"0xe000");
cprintf("%m %s ",0xe100,"0xe100");
cprintf("%m %s ",0xe200,"0xe200");
cprintf("%m %s ",0xe300,"0xe300");
cprintf("%m %s ",0xe400,"0xe400");
cprintf("%m %s ",0xe500,"0xe500");
cprintf("%m %s ",0xe600,"0xe600");
cprintf("%m %s ",0xe700,"0xe700");
cprintf("%m %s ",0xe800,"0xe800");
cprintf("%m %s ",0xe900,"0xe900");
cprintf("%m %s ",0xea00,"0xea00");
cprintf("%m %s ",0xeb00,"0xeb00");
cprintf("%m %s ",0xec00,"0xec00");
cprintf("%m %s ",0xed00,"0xed00");
cprintf("%m %s ",0xee00,"0xee00");
cprintf("%m %s ",0xef00,"0xef00");
cprintf("%m %s ",0xf000,"0xf000");
cprintf("%m %s ",0xf100,"0xf100");
cprintf("%m %s ",0xf200,"0xf200");
cprintf("%m %s ",0xf300,"0xf300");
cprintf("%m %s ",0xf400,"0xf400");
cprintf("%m %s ",0xf500,"0xf500");
cprintf("%m %s ",0xf600,"0xf600");
cprintf("%m %s ",0xf700,"0xf700");
cprintf("%m %s ",0xf800,"0xf800");
cprintf("%m %s ",0xf900,"0xf900");
cprintf("%m %s ",0xfa00,"0xfa00");
cprintf("%m %s ",0xfb00,"0xfb00");
cprintf("%m %s ",0xfc00,"0xfc00");
cprintf("%m %s ",0xfd00,"0xfd00");
cprintf("%m %s ",0xfe00,"0xfe00");
cprintf("%m %s ",0xff00,"0xff00");

	
return 0;
}

int
mon_kerninfo(int argc, char **argv, struct Trapframe *tf)
{
	extern char _start[], entry[], etext[], edata[], end[];

	cprintf("Special kernel symbols:\n");
	cprintf("  _start                  %08x (phys)\n", _start);
	cprintf("  entry  %08x (virt)  %08x (phys)\n", entry, entry - KERNBASE);
	cprintf("  etext  %08x (virt)  %08x (phys)\n", etext, etext - KERNBASE);
	cprintf("  edata  %08x (virt)  %08x (phys)\n", edata, edata - KERNBASE);
	cprintf("  end    %08x (virt)  %08x (phys)\n", end, end - KERNBASE);
	cprintf("Kernel executable memory footprint: %dKB\n",
		ROUNDUP(end - entry, 1024) / 1024);
	return 0;
}

int
mon_backtrace(int argc, char **argv, struct Trapframe *tf)
{

uint32_t* ebp = (uint32_t*) read_ebp();
	cprintf("Stack backtrace:\n");
	while (ebp) {
		uint32_t eip = ebp[1];
		struct Eipdebuginfo info;
		debuginfo_eip(eip,&info);
		cprintf("\t%s:%d: %.*s+%d\n",info.eip_file, info.eip_line,info.eip_fn_namelen, info.eip_fn_name, eip-info.eip_fn_addr);
		cprintf("ebp %x  eip %x  args", ebp, ebp[1]);
		int i;
		for (i = 2; i <= 6; ++i)
			cprintf(" %08.x", ebp[i]);
		cprintf("\n");
		ebp = (uint32_t*) *ebp;
	}
return 0;


}



/***** Kernel monitor command interpreter *****/

#define WHITESPACE "\t\r\n "
#define MAXARGS 16

static int
runcmd(char *buf, struct Trapframe *tf)
{
	int argc;
	char *argv[MAXARGS];
	int i;

	// Parse the command buffer into whitespace-separated arguments
	argc = 0;
	argv[argc] = 0;
	while (1) {
		// gobble whitespace
		while (*buf && strchr(WHITESPACE, *buf))
			*buf++ = 0;
		if (*buf == 0)
			break;

		// save and scan past next arg
		if (argc == MAXARGS-1) {
			cprintf("Too many arguments (max %d)\n", MAXARGS);
			return 0;
		}
		argv[argc++] = buf;
		while (*buf && !strchr(WHITESPACE, *buf))
			buf++;
	}
	argv[argc] = 0;

	// Lookup and invoke the command
	if (argc == 0)
		return 0;
	for (i = 0; i < ARRAY_SIZE(commands); i++) {
		if (strcmp(argv[0], commands[i].name) == 0)
			return commands[i].func(argc, argv, tf);
	}
	cprintf("Unknown command '%s'\n", argv[0]);
	return 0;
}


void
skuska(){
char name;
    int  number;
    FILE *f;
    f = fopen("contacts.pcl", "a");

    printf("\nNew contact name: ");
    scanf("%s", &name);
    printf("New contact number: ");
    scanf("%i", &number);


    fprintf(f, "%c\n[ %d ]\n\n", name, number);
    fclose(f);
}


void
monitor(struct Trapframe *tf)
{
	char *buf;

	cprintf("\n\n\n\n");

	cprintf("%m%s",0x0200,"      ##  #######  ##    ##    ###    ##    ##     #######   ######  \n      ## ##     ## ##   ##    ## ##    ##  ##     ##     ## ##    ## \n      ## ##     ## ##  ##    ##   ##    ####      ##     ## ##       \n      ## ##     ## #####    ##     ##    ##       ##     ##  ######  \n##    ## ##     ## ##  ##   #########    ##       ##     ##       ## \n##    ## ##     ## ##   ##  ##     ##    ##       ##     ## ##    ## \n ######   #######  ##    ## ##     ##    ##        #######   ######  \n");
	
	cprintf("\n\nWelcome to the Jokay OS kernel monitor!\n");
	cprintf("Type 'help' for a list of commands.\n");


	while (1) {
		
		buf = readline("K> ");
		if((*buf==-30)||(*buf==91)){
			skuska();
					cprintf("%d",*buf);
		}
		
	
		
		
		if (buf != NULL)
			if (runcmd(buf, tf) < 0)
				break;
		
		}
}
