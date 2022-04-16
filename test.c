#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(void)
{
	int status = 0;
	int fd = -1;

	fd = open("/dev/dice", O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "error: failed to open /dev/dice: %s\n", strerror(errno));
		return 1;
	}
	printf("[!] opened /dev/dice\n");

	status = ioctl(fd, 42);
	if (status == -1)
	{
		fprintf(stderr, "error: ioctl failed: %s\n", strerror(errno));
		return 1;
	}

	printf("[!] ioctl success\n");

	close(fd);
	return 0;
}
