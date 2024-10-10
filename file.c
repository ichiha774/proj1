#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char buff[10];
	int fd;
	fd =open("test.txt", O_RDONLY);
	if(fd < 0){
		perror("Error opning file");
		exit(1);
	}
	
	ssize_t bytes_read = read(fd, buff, 10);
	if(bytes_read < 0) {
		perror("Error opening file");
		close(fd);
		exit(1);
	}
	
	ssize_t bytes_written = write(1, buff, bytes_read);
	if(bytes_written < 0) {
		perror("Error opening file");
		close(fd);
		exit(1);
	}
	
	if(close(fd) < 0) {
		perror("Error closing file");
		exit(1);
	}
	
	return 0;
	

}

