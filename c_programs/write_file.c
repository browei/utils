#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define FILEPATH "/tmp/a.progress"

int main(int argc, char **argv)
{
	int fd = -1;
	int i = 0;
	char buf[255];
	time_t seconds;

	fd = open(FILEPATH, O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (fd < 0)
		return -1;
	while (++i < 100) {
		ftruncate(fd, 0);
	        seconds = time(NULL);
		snprintf(buf, sizeof(buf), "time=%ld\n", seconds);
		write(fd , buf, strlen(buf));
		sleep(3);
	}

	close(fd);

	return 0;
}
