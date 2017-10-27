#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int respond(int fd, char* response) {
  write(fd, response, sizeof(response));
  return 0;
};