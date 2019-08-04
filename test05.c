#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define __null NULL

typedef struct ListData {
 struct { struct ListData *sle_next; } next;
 int _data;
}LISTDATA,*PLIST;


struct MyHead { struct ListData *slh_first; } head;


int main()
{
 PLIST pIndex = __null;
 LISTDATA data1 = { { __null }, 1 };
 LISTDATA data2 = { { __null }, 2 };
 LISTDATA data3 = { { __null }, 3 };
 { ((&head)->slh_first) = __null; };
 do{ (&data1)->next.sle_next = (&head)->slh_first; (&head)->slh_first = (&data1);}while(0);
 do{ (&data2)->next.sle_next = (&data1)->next.sle_next; (&data1)->next.sle_next = (&data2); }while(0);
 do{ (&data3)->next.sle_next = (&data2)->next.sle_next; (&data2)->next.sle_next = (&data3); }while(0);
 for((pIndex) = ((&head)->slh_first); (pIndex) != __null; (pIndex) = ((pIndex)->next.sle_next))
 {
  if (pIndex != __null)
   printf("pIndex->_data = %d\n", pIndex->_data);
 }
 return 0;
}
