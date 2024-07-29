#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 10240

// Function to copy a file from source to destination
int copy(const char *src, const char *dst) {
    int src_fd, dst_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    // Open the source file for reading
    src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("open src");
       return -1;
    }

    // Open the destination file for writing (create if it doesnt exist)
    dst_fd = open(dst, O_WRONLY | O_CREAT);
    if (dst_fd < 0) {
        perror("open dst");
        close(src_fd);
        return -1;
    }

    // Copy the file contents
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write");
            close(src_fd);
            close(dst_fd);
            return -1;
        }
    }

    if (bytes_read < 0) {
        perror("read");
    }

    // Close the file descriptors
    close(src_fd);
    close(dst_fd);
}

