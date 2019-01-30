#include "Common_Decl.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
int main()
{
	Doubly_Linked_List DList;
	Circular_Linked_List CList;

	CList.push_tail(3);
	CList.push_tail(2);
	CList.push_tail(1);
	CList.push_tail(0);
	CList.insert_before(3,10);
	CList.show_all();
	return 0;
}