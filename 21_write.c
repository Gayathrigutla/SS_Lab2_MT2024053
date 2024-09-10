#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void){
	int fd, fd1;
	char buff[80], buff1[80];

	fd = open("myfifo", O_WRONLY);
	fd1 = open("myfifo1", O_RDONLY);
	for(;;){
	printf("Enter the text: ");
	scanf(" %[^\n]", buff);
	write(fd, buff, sizeof(buff));

	read(fd1, buff1, sizeof(buff1));
	if (strcmp(buff1, "exit") == 0) {
            break;
        }
	printf(" Text from myfifo: %s\n", buff1);
	}

	close(fd);
	close(fd1);
	return 0;
}
