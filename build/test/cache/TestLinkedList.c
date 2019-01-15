#include "build/temp/_TestLinkedList.c"
#include "LinkedList.h"
#include "unity.h"




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

  UnityAssertEqualMemory(( const void*)((someString)), ( const void*)((testLink->data)), (UNITY_UINT32)((strlen(someString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(18), UNITY_ARRAY_TO_ARRAY);

}



void testNodeShouldBeDestroyed(void)

{

  char* someString = "abc";

  link testLink = create_node(someString);

  UnityAssertEqualMemory(( const void*)((someString)), ( const void*)((testLink->data)), (UNITY_UINT32)((strlen(someString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(25), UNITY_ARRAY_TO_ARRAY);

  destroy_node(&testLink);

  UnityAssertEqualNumber((UNITY_INT)((

 ((void *)0)

 )), (UNITY_INT)((testLink)), (

 ((void *)0)

 ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

}
