#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

//单链表的头部
#define SLIST_HEAD(name, type) \
struct name {				\
	struct type *slh_first;	\
}
//接下来就是需要一个链表的入口可以理解为链条，用来连接指向下一个节点的。
#define SLIST_ENTRY(type) \
struct {				\
	struct type *sle_next;	\
}
//定义list的访问的方法
#define SLIST_FIRST(head)		((head)->slh_first)
#define SLIST_END(head)			NULL
#define SLIST_EMPTY(head)		(SLIST_FIRST(head) == SLIST_END(head))
#define SLIST_NEXT(elm, field)	((elm)->field.sle_next)
#define SLIST_FOREACH(var, head, field) \
	for((var) = SLIST_FIRST(head); \
		(var) != SLIST_END(head); \
		(var) = SLIST_NEXT(var, field))
        
#define SLIST_INIT(head){ \
	SLIST_FIRST(head) = SLIST_END(head); \
}

#define SLIST_INSERT_AFTER(slistelm, elm, field) do{	\
	(elm)->field.sle_next = (slistelm)->field.sle_next;	\
	(slistelm)->field.sle_next = (elm);		\
}while(0)

#define SLIST_INSERT_HEAD(head, elm, field) do{ \
	(elm)->field.sle_next = (head)->slh_first;	\
	(head)->slh_first = (elm);\
}while(0)

#define SLIST_REMOVE_HEAD(head, field) do{	\
	(head)->slh_first = (head)->slh_first->field.sle_next;\
}while(0)
    
//先定义一个链表头部
SLIST_HEAD(MyHead, ListData) head;
//或者typedef SLIST_HEAD(MyHead, Data) HEAD;这时的HEAD是一个结构的类型

typedef struct ListData {
	SLIST_ENTRY(ListData ) next;
	//宏定义的展开
	/*struct {		
		struct ListData *sle_next;	
	}next;*/
	int _data;
}LISTDATA,*PLIST;

int main()
{
	PLIST pIndex = NULL;
	LISTDATA data1 = { { NULL }, 1 };
	LISTDATA data2 = { { NULL }, 2 };
	LISTDATA data3 = { { NULL }, 3 };
	//初始化头部
	SLIST_INIT(&head);
	//在头部插入数据
	SLIST_INSERT_HEAD(&head, &data1 , next);//现在知道field是干嘛用了的吧
	//链表的尾部插入数据
	SLIST_INSERT_AFTER(&data1, &data2 , next);
	SLIST_INSERT_AFTER(&data2, &data3 , next);
	//循环遍历打印信息
	SLIST_FOREACH(pIndex, &head, next)
	{
		if (pIndex != NULL)
			printf("pIndex->_data = %d\n", pIndex->_data);
	}
	return 0;
}


