#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../hash/hash.h"
#include "../util/color.h"
#include "../util/util.h"
#include "./respond.h"

int matchCommands(char* command) {
  if (strcmp(command, "get") == 0) {
    return 1;
  } else if (strcmp("set", command) == 0) {
    return 2;
  } else {
    return 0;
  }
}

void trim(char* cs) {
  char* p;
  size_t len = strlen(cs);
  for (p = cs + len - 1; isspace(*p); --p) /* nothing */
    ;
  p[1] = '\0';
  for (p = cs; isspace(*p); ++p) /* nothing */
    ;
  memmove(cs, p, len - (size_t)(p - cs) + 1);
}

int handleCommand(char* buf, hashtable_t* hashtable, int fd) {
  char* token;
  char* command;
  char* key;
  char* value_arg;
  int tok_count;

  token = strtok(buf, "\r\n ");
  switch (matchCommands(token)) {
    case 1:
      //
      // HGET
      //
      //
      token = strtok(NULL, " ");
      trim(token);
      char* value = ht_get(hashtable, token);
      respond(fd, value);
      break;
    //
    //
    //
    //
    case 2:
      //
      // HSET
      //
      //
      key = strtok(NULL, "\r\n ");
      value_arg = strtok(NULL, "\r\n ");
      ht_set(hashtable, key, value_arg);
      break;
    //
    //
    //
    //

    default:
      printf("NO MATCH\n");
  }

  while (token != NULL) {
    token = strtok(NULL, " ");
    tok_count++;
  }
  // ht_set(hashtable, "COOL", "OK");
  return tok_count;
}