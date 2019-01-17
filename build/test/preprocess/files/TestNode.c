#include "build/temp/_TestNode.c"
#include "Node.h"
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



void testNodeAdded(void) {

  char* firstString = "abc";

  char* secondString = "def";



  link firstLink = create_node(firstString);

  link nextLink = create_node(secondString);



  link checkNode = add_node(firstLink, nextLink);



  UnityAssertEqualMemory(( const void*)((secondString)), ( const void*)((firstLink->next->data)), (UNITY_UINT32)((strlen(secondString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(39), UNITY_ARRAY_TO_ARRAY);

  UnityAssertEqualMemory(( const void*)((checkNode)), ( const void*)((firstLink->next)), (UNITY_UINT32)((sizeof(checkNode))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(40), UNITY_ARRAY_TO_ARRAY);

  UnityAssertEqualMemory(( const void*)((secondString)), ( const void*)((checkNode->data)), (UNITY_UINT32)((strlen(secondString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(41), UNITY_ARRAY_TO_ARRAY);

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



  UnityAssertEqualMemory(( const void*)((thirdString)), ( const void*)((firstLink->next->next->data)), (UNITY_UINT32)((strlen(thirdString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(57), UNITY_ARRAY_TO_ARRAY);

  UnityAssertEqualMemory(( const void*)((checkNode)), ( const void*)((firstLink->next->next)), (UNITY_UINT32)((sizeof(checkNode))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(58), UNITY_ARRAY_TO_ARRAY);

  UnityAssertEqualMemory(( const void*)((thirdString)), ( const void*)((checkNode->data)), (UNITY_UINT32)((strlen(thirdString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(59), UNITY_ARRAY_TO_ARRAY);

}



void testAddNodeParentNull(void) {

  char* someString = "abc";

  link testLink = create_node(someString);



  link checkNode = add_node(

                           ((void *)0)

                               , testLink);

  UnityAssertEqualMemory(( const void*)((someString)), ( const void*)((checkNode->data)), (UNITY_UINT32)((strlen(someString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(67), UNITY_ARRAY_TO_ARRAY);

  if ((((checkNode->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(68))));};

}



void testAddNodeChildNull(void) {

  char* someString = "abc";

  link testLink = create_node(someString);



  link checkNode = add_node(testLink, 

                                     ((void *)0)

                                         );

  UnityAssertEqualMemory(( const void*)((someString)), ( const void*)((checkNode->data)), (UNITY_UINT32)((strlen(someString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(76), UNITY_ARRAY_TO_ARRAY);

  if ((((checkNode->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(77))));};

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

  UnityAssertEqualMemory(( const void*)((thirdString)), ( const void*)((checkNode->data)), (UNITY_UINT32)((strlen(thirdString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(94), UNITY_ARRAY_TO_ARRAY);

  if ((((nextLink->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(95))));};



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



  link checkNode = remove_node(

                              ((void *)0)

                                  , firstLink);

  UnityAssertEqualMemory(( const void*)((firstString)), ( const void*)((checkNode->data)), (UNITY_UINT32)((strlen(firstString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(114), UNITY_ARRAY_TO_ARRAY);

  if ((((firstLink->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(115))));};



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

  UnityAssertEqualMemory(( const void*)((secondString)), ( const void*)((checkNode->data)), (UNITY_UINT32)((strlen(secondString))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(134), UNITY_ARRAY_TO_ARRAY);

  if ((((nextLink->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(135))));};



  UnityAssertEqualMemory(( const void*)((firstLink->next)), ( const void*)((nextNextLink)), (UNITY_UINT32)((sizeof(nextNextLink))), 1, (

 ((void *)0)

 ), (UNITY_UINT)(137), UNITY_ARRAY_TO_ARRAY);



   destroy_node(&firstLink);

}
