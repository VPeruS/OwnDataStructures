/******************************************************************************
 *  Name: LinkedList.h
 *
 *  Compilation:
 *  Execution:
 *  Dependencies:
 *  Data files:
 *
 *  Abstract:
 *      This is a singly-linked list.
 *
 *  Author:
 *      Rusakova Anastasiia
 *
 *  Change Log:
 *      14-Jan-2019: Created base fuctionality of linked list
 *
 ******************************************************************************/
#include <errno.h>
#include <stdlib.h>
#include "Node.h"

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

link add_node(link _link, link _new_node) {

  //if parent link is empty - return new node as first
  if(_link == NULL) {
      return _new_node;
    }//if

  //if child link is empty - nothing to add - return
  if(_new_node == NULL) {
      return _link;
    }

  _link->next = _new_node;

  return _link->next;
}

link remove_node(link _parent_link, link _to_remove) {
  //Nothing to remove
  if(_to_remove == NULL) {
      return NULL;
    }

  if(_parent_link != NULL) {
      _parent_link->next = _to_remove->next;
    }

  _to_remove->next = NULL;

  return _to_remove;
}
