#include <u.h>
#define NOPLAN9DEFINES
#include <libc.h>

void
p9longjmp(p9jmp_buf buf, int val)
{
	long lbuf[34];
	int i;
	for(i = 0; i < 34; i++) {
		lbuf[i] = buf[i];
	}
	
	siglongjmp(lbuf, val);
}

void
p9notejmp(void *x, p9jmp_buf buf, int val)
{
	USED(x);
	long lbuf[34];
	int i;
	for(i = 0; i < 34; i++) {
		lbuf[i] = buf[i];
	}
	
	siglongjmp(lbuf, val);
}


