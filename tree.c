#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lchild,*rchild;
}*temp=NULL,*root=NULL,*t1,*t2;
int u;
void delete_node(),search_del(struct node*,int data),deletee(struct node *t);
int smallest(struct node *t);
void create(),insert(),search(struct node*t);
void inorder(struct node *t),postorder(struct node *t),preorder(struct node *t);
void create(){
	int n;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d",&n);
	temp->data=n;
	temp->lchild=NULL;
	temp->rchild=NULL;
}
void insert(){
	create();
	if(root == NULL)
	root=temp;
	else
	search(root);
}
void search(struct node*t){
	if((temp->data>t->data) && (t->rchild!=NULL))
	search(t->rchild);
	else if((temp->data>t->data)&&(t->rchild==NULL))
	t->rchild=temp;
	else if((temp->data<t->data) && (t->lchild!=NULL))
	search(t->lchild);
	else if((temp->data<t->data)&&(t->lchild==NULL))
	t->lchild=temp;
}
void inorder(struct node *t){
	if(root==NULL)
	{
		printf("No,elements in a tree to display\n");
		return;
	}
	if(t->lchild!=NULL)
	inorder(t->lchild);
	printf("%d->",t->data);
	if(t->rchild!=NULL)
	inorder(t->rchild);

}
void preorder(struct node *t){
	if(root==NULL)
	{
		printf("No,elements in a tree to display\n");
		return;
	}
	printf("%d->",t->data);
	if(t->lchild!=NULL)
	preorder(t->lchild);
	if(t->rchild!=NULL)
	preorder(t->rchild);
}
void postorder(struct node *t){
	if(root==NULL)
	{
		printf("No,elements in a tree to display\n");
		return;
	}
	if(t->lchild!=NULL)
	postorder(t->lchild);
	if(t->rchild!=NULL)
	postorder(t->rchild);
	printf("%d->",t->data);
}
void delete_node(){
	int val;
	if(root == NULL){
		printf("No elements in tree to delete");
		return;
	}
	else{
		printf("\nEnter the value deleted: ");
		scanf("%d",&val);
		search_del(root,val);
		printf("Deleted %d\n",u);
	}
    return;
}
void search_del(struct node*t,int data){
	if(data>t->data){
		t1=t;
		search_del(t->rchild,data);
	}
	else if(data<t->data){
		t1=t;
		search_del(t->lchild,data);
	}
	else if(data==t->data)
	deletee(t);
	else if(t==NULL)
		printf("Element not found\n");
	return;
}
void deletee(struct node *t){
	int k;
	if((t->lchild==NULL)&&(t->rchild==NULL)){
		if(t1->lchild==t){
			t1->lchild=NULL;
		}
		else{
			t1->rchild=NULL;
		}
		free(t);
		return ;
	}
	else if(t->rchild==NULL){
		if(root==t){
			root=t->lchild;
			t1=root;
		}
		else if(t1->lchild==t)
		t1->lchild=t->lchild;
        else
        t1->rchild=t->lchild;
        t=NULL;
        free(t);
        return;
	}
    else if(t->lchild==NULL){
		if(root==t){
			root=t->rchild;
			t1=root;
		}
		else if(t1->rchild==t)
		t1->rchild=t->rchild;
        else
        t1->lchild=t->rchild;
        t=NULL;
        free(t);
        return;
	}
    else if((t->lchild!=NULL)&&(t->rchild!=NULL)){
        t2=t;
		k=smallest(t->rchild);
        t->data=k;
        return;
    } 
}
int smallest(struct node*t){
    
    if(t->lchild!=NULL){
        t2=t;
        return (smallest(t->lchild));
    }
	else if(t2==root){
		t2->rchild=NULL;
		u=t->data;
        free(t);
    return u;
	}
    else{
        u=t->data;
		t2->lchild=NULL;
        free(t);
    return u;
    }
}
int main(){
	int n;
	do{
		printf("\nEnter your choice\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Delete Node\n6.Exit\n");
		scanf("%d",&n);
		switch(n){
			case 1: insert();
			break;
			case 2: preorder(root);
			break;
			case 3: inorder(root);
			break;
			case 4: postorder(root);
			break;
			case 5: delete_node();
			break;
			case 6: exit(0);
			default :
				printf("Wrong Choice\n");
		}
	}while(1);
	return 0;
}
