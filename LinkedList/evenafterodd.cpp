/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *evenAfterOdd(Node *head)
{
	//write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node*temp=head;
	
	Node*oddHead=NULL,*oddTail=NULL,*evenHead=NULL,*evenTail=NULL;

	while(temp!=NULL){
		if((temp->data)%2!=0){
			if(oddHead==NULL){
				oddHead=temp;
				oddTail=temp;
			}else{
				oddTail->next=temp;
				oddTail=temp;
			}
		}else{
			if(evenHead==NULL){
				evenHead=temp;
				evenTail=temp;
			}else{
				evenTail->next=temp;
				evenTail=temp;
			}
		}
		temp=temp->next;
	}

	if(oddHead==NULL){
		return evenHead;
	}

  oddTail->next=evenHead;
  evenTail->next=NULL;

	return oddHead;
}

