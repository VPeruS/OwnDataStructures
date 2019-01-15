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
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/************************ Defines and typedefs *******************************/

/*! Structure for node */
typedef struct node {
  struct node* next;
  void* data;
} node;

/*! Pointer to the node */
typedef node *link;

/********************** Global Functions Declarations ************************/

/*!
 * \brief Allocate memory for a new node
 * \param data which would be linked to the node
 * \return pointer to newly created node
 */
link create_node(void* data);

/*!
 * \brief Destroy memory with node
 * \param _link Poinder to node
 */
void destroy_node(link *_link);

/*!
 * \brief Add new node to the next
 * \param _link where new node should be attached
 * \param _new_node to attach
 * \return link to the attached node
 */
link add_node(link _link);

/*!
 * \brief Add new node at the end of
 * \param _link to remove
 * \return removed node which should be deleted by destroy_node
 */
link remove_node(link _link);

#ifdef _DEBUG
void printLinkedList();
#endif


/*
 * TBD: Iterator
 * - erase
 * - swap
 * - splice
 * - remove
 * - remove if
 * - unique
 * - merge
 * - reverse
 * - sort
 *
 * - thread safe
 * http://cs.brown.edu/~jwicks/libstdc++/html_user/stl__list_8h-source.html
 */

#endif
