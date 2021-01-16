#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char* argv[])
{
	if (argc != 2){
		printf("args err\n");
		return 0;
	}
	int fd = open(argv[1], O_WRONLY|O_CREAT, 0666);
	char buf[256];
	while (1){
		memset(buf, 0x00, sizeof(buf));
		int ret = read(STDIN_FILENO, buf, sizeof(buf));
		if (ret > 0){
			write(fd, buf, ret);
		}
	}
	return 0;
}
