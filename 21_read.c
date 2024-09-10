#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void){
	int fd, fd1;
	char buff[80], buff1[80];

	fd = open("myfifo", O_RDONLY);
	fd1 = open("myfifo1", O_WRONLY);
	for(;;){
	read(fd, buff, sizeof(buff));
	printf(" The text from FIFO: %s\n", buff);

	printf("Enter the text: ");
	scanf(" %[^\n]", buff1);
	if (strcmp(buff1, "exit") == 0) {
            write(fd1, buff1, strlen(buff1) + 1); // Inform User 1 to exit
            break;
        }
	write(fd1, buff1, sizeof(buff1));
	}

	close(fd);
	close(fd1);
	return 0;
}
