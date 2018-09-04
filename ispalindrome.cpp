#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
int check(struct node *head,struct node *mid,struct node *rev){
	while(head!=rev && mid!=NULL){
		if(head->data!=mid->data)
		   return 0;
		head=head->next;
		mid=mid->next;
	}return 1;
}
int list_len(struct node *head){
	int count=0;
	while(head!=NULL){
		head=head->next;
		count++;
	}return count;
}
struct node* mid_ele(struct node* head){
	struct node *slow=head;
	struct node *fast=head;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
void reverse(struct node **head){
	struct node *current =*head;
	struct node *prev=NULL;
	struct node *next=NULL;
	while (current != NULL)
        {
            // Store next
            next = current->next;
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        *head=prev;
	return ;
}
int ispalin(struct node *head){
	struct node *mid=mid_ele(head);
	struct node *rev=mid;
	int len=list_len(head);
	if(len%2==0){
		reverse(&mid);
		if(check(head,mid,rev))
		   return 1;
	}
	else{
		reverse(&(mid->next));
		if(check(head,mid,rev))
		   return 1;
	}
	return 0;
}
struct node* insert(struct node* head,int data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	struct node *temp=head;
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		return head;
	}while(temp->next!=NULL){
		temp=temp->next;
	}temp->next=newnode;
	return head;
}
int main(){
	struct node *head=NULL;
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		head=insert(head,x);
	}
	if(ispalin(head))
	   printf("yes");
	else
	   printf("no");
	return 0;
}
