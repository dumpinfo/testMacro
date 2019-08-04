#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

//�������ͷ��
#define SLIST_HEAD(name, type) \
struct name {				\
	struct type *slh_first;	\
}
//������������Ҫһ���������ڿ������Ϊ��������������ָ����һ���ڵ�ġ�
#define SLIST_ENTRY(type) \
struct {				\
	struct type *sle_next;	\
}
//����list�ķ��ʵķ���
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
    
//�ȶ���һ������ͷ��
SLIST_HEAD(MyHead, ListData) head;
//����typedef SLIST_HEAD(MyHead, Data) HEAD;��ʱ��HEAD��һ���ṹ������

typedef struct ListData {
	SLIST_ENTRY(ListData ) next;
	//�궨���չ��
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
	//��ʼ��ͷ��
	SLIST_INIT(&head);
	//��ͷ����������
	SLIST_INSERT_HEAD(&head, &data1 , next);//����֪��field�Ǹ������˵İ�
	//�����β����������
	SLIST_INSERT_AFTER(&data1, &data2 , next);
	SLIST_INSERT_AFTER(&data2, &data3 , next);
	//ѭ��������ӡ��Ϣ
	SLIST_FOREACH(pIndex, &head, next)
	{
		if (pIndex != NULL)
			printf("pIndex->_data = %d\n", pIndex->_data);
	}
	return 0;
}


