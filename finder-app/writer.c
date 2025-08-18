#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open the file for writing
    int fd;
    int write_size;
    
    
    // Open syslog
    openlog(NULL, 0, LOG_USER);

    // Validate arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: %d ", argc);
        closelog();
        return 1;
    }


    fd = open(writefile, O_CREAT|O_RDWR, S_IRWXU|S_IRWXG|S_IRWXO);
    if (fd == -1) {
        syslog(LOG_ERR, "Failed to open file: %s", writefile);
        return 1;
    }

    write_size = write(fd,writestr,strlen(writestr));
    // Write the string to the file
    if (write_size == strlen(writestr)) {
    	syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
        //syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
        close(fd);
        closelog();
        return 0;
    }
    else
    {
    	syslog(LOG_ERR, "Failed to write to file: %s", writefile);
	close(fd);
	closelog();
    	return 1;
    }

    
}

