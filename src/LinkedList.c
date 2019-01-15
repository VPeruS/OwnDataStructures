#include <errno.h>
#include <stdlib.h>
#include "LinkedList.h"

link create_node(void* data) {

  link newLink = malloc(sizeof(node));

  if(newLink) {
      newLink->next = NULL;
      newLink->data = data;
    }//if

  return newLink;
}

void destroy_node(link *_link) {
  if((_link != NULL) && (*_link != NULL)) {
      free(*_link);
      *_link = NULL;
    }
}
