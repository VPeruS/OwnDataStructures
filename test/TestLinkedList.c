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
