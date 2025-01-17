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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	if(i==j){
		return head;
	}
    if(i==0 || j==0){
		
	}
	Node*add1=NULL;
	Node*add2=NULL;
	

	Node*temp=head;
	int cnt=0;
	while(temp!=NULL){
		if(cnt==i-1){
			add1=temp;
			break;
		}else{
			cnt++;
		}
		temp=temp->next;
	}
	cnt=0;
	temp=head;
	while(temp!=NULL){
		if(cnt==j-1){
			add2=temp;
			break;
		}else{
			cnt++;
		}
		temp=temp->next;
	}
	if(add1->next==add2){
		Node*temp=add2->next->next;

		add1->next=add2->next;
		add2->next->next=add2;
		add2->next=temp;
		
	}


	Node*a=add1->next;
	Node*b=add2->next;

	Node*c=a->next;
	Node*d=b->next;

	b->next=c;
	a->next=d;

	add1->next=b;
	add2->next=a;

	return head;
}