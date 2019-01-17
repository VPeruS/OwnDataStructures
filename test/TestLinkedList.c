#include <string.h>

#include "unity.h"
#include "LinkedList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void testNodeShouldBeCreated(void)
{
  char* someString = "abc";
  link testLink = create_node(someString);
  TEST_ASSERT_EQUAL_MEMORY(someString, testLink->data, strlen(someString));
}

void testNodeShouldBeDestroyed(void)
{
  char* someString = "abc";
  link testLink = create_node(someString);
  TEST_ASSERT_EQUAL_MEMORY(someString, testLink->data, strlen(someString));
  destroy_node(&testLink);
  TEST_ASSERT_EQUAL(NULL, testLink);
}

void testNodeAdded(void) {
  char* firstString = "abc";
  char* secondString = "def";

  link firstLink = create_node(firstString);
  link nextLink = create_node(secondString);

  link checkNode = add_node(firstLink, nextLink);

  TEST_ASSERT_EQUAL_MEMORY(secondString, firstLink->next->data, strlen(secondString));
  TEST_ASSERT_EQUAL_MEMORY(checkNode, firstLink->next, sizeof(checkNode));
  TEST_ASSERT_EQUAL_MEMORY(secondString, checkNode->data, strlen(secondString));
}


void testNodeAddedThreeTimes(void) {
  char* firstString = "abc";
  char* secondString = "def";
  char* thirdString = "ghi";

  link firstLink = create_node(firstString);
  link nextLink = create_node(secondString);
  link nextNextLink = create_node(thirdString);

  add_node(firstLink, nextLink);
  link checkNode = add_node(nextLink, nextNextLink);

  TEST_ASSERT_EQUAL_MEMORY(thirdString, firstLink->next->next->data, strlen(thirdString));
  TEST_ASSERT_EQUAL_MEMORY(checkNode, firstLink->next->next, sizeof(checkNode));
  TEST_ASSERT_EQUAL_MEMORY(thirdString, checkNode->data, strlen(thirdString));
}

void testAddNodeParentNull(void) {
  char* someString = "abc";
  link testLink = create_node(someString);

  link checkNode = add_node(NULL, testLink);
  TEST_ASSERT_EQUAL_MEMORY(someString, checkNode->data, strlen(someString));
  TEST_ASSERT_NULL(checkNode->next);
}

void testAddNodeChildNull(void) {
  char* someString = "abc";
  link testLink = create_node(someString);

  link checkNode = add_node(testLink, NULL);
  TEST_ASSERT_EQUAL_MEMORY(someString, checkNode->data, strlen(someString));
  TEST_ASSERT_NULL(checkNode->next);
}


void testNodeRemovedAtTheEnd(void) {
  char* firstString = "abc";
  char* secondString = "def";
  char* thirdString = "ghi";

  link firstLink = create_node(firstString);
  link nextLink = create_node(secondString);
  link nextNextLink = create_node(thirdString);

  add_node(firstLink, nextLink);
  add_node(nextLink, nextNextLink);

  link checkNode = remove_node(nextLink, nextNextLink);
  TEST_ASSERT_EQUAL_MEMORY(thirdString, checkNode->data, strlen(thirdString));
  TEST_ASSERT_NULL(nextLink->next);

   destroy_node(&nextNextLink);
}


void testNodeRemovedBeginning(void) {
  char* firstString = "abc";
  char* secondString = "def";
  char* thirdString = "ghi";

  link firstLink = create_node(firstString);
  link nextLink = create_node(secondString);
  link nextNextLink = create_node(thirdString);

  add_node(firstLink, nextLink);
  add_node(nextLink, nextNextLink);

  link checkNode = remove_node(NULL, firstLink);
  TEST_ASSERT_EQUAL_MEMORY(firstString, checkNode->data, strlen(firstString));
  TEST_ASSERT_NULL(firstLink->next);

   destroy_node(&firstLink);
}


void testNodeRemovedInTheMiddle(void) {
  char* firstString = "abc";
  char* secondString = "def";
  char* thirdString = "ghi";

  link firstLink = create_node(firstString);
  link nextLink = create_node(secondString);
  link nextNextLink = create_node(thirdString);

  add_node(firstLink, nextLink);
  add_node(nextLink, nextNextLink);

  link checkNode = remove_node(firstLink, nextLink);
  TEST_ASSERT_EQUAL_MEMORY(secondString, checkNode->data, strlen(secondString));
  TEST_ASSERT_NULL(nextLink->next);

  TEST_ASSERT_EQUAL_MEMORY(firstLink->next, nextNextLink, sizeof(nextNextLink));

   destroy_node(&firstLink);
}



