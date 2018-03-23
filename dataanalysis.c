#include<stdio.h>
#include<stdlib.h>
#include "avl.h"
#include<math.h>
AVLTree InsertEntry(int,char *,char*,char*,char *,char*,int, AVLTree);
AVLTree read_data(char *file);
void maximum_total_reach(AVLTree);
AVLTree maximum_engaged_user(AVLTree);
void display_index(AVLTree );
int main(){
	char file[100]="C:/Users/Rustam/Desktop/FacebookData.csv";
AVLTree t=read_data(file);
	printf("The link(s) with maximum total reaches is(are)\n\n");
	maximum_total_reach(t);
	printf("\n\n\n\n\n\n And the link(s) with maximum engaged users is(are)\n\n");
	displayNode(maximum_engaged_user(t));
	
	
	
}


AVLTree  maximum_engaged_user(AVLTree t){
	static int max=0;
	static AVLTree address;
	if(t==NULL){
		return 0;
	}
	else {
		if((t->engaged)[0]>max){
			max=(t->engaged)[0];
			address=t;
		}
		maximum_engaged_user(t->right);
		maximum_engaged_user(t->left);
	}
	return address;
	//By doing simple calculations we can show that T(n)= log2n + 2^(log2N)t(0); Thus Our function has O(n) which is logical since we need to treverse all nodes in order to find the largest engaged one.
	//Since the engaged numbers are not in any particular order.
	// How can we make this function better? Maybe some Divide-And-Conquere algorythms would increase the preformance although I am not sure How. But generarlly if we'd sort our AVL tree with respect to engaged users.
	// Our job would be much more simpler as in the Maximum_total_reach() function! 
	
}
void maximum_total_reach(AVLTree t){
	if(t==NULL)printf("No elements");
	else if(t->right==NULL)displayNode(t);
	else {
		maximum_total_reach(t->right);
	}
	//It will take the rightmost node since that is the property of a binary search tree. The rightmost one with respect to which we were sorting is the largest one.
	//With each recursion we are throuwing the left part of the tree that is N/2; So after logN successful turns in the worst case will my function will compute the Max_reach!
	// SO this function has a O(logn)
	// It is really the most efficient method, only way to make it even more better is if we had a another structure called where we held our righmost node. And every time when we added a new rightmost node we would update our Tree structure.
}
void display_index(AVLTree t){
	
	if(t==NULL)printf("");
	else {
		display_index(t->left);
		printf("%s %s %s %s %s %d %d\n",(t->id)[0],(t->link)[0],(t->message)[0],(t->type)[0],(t->date)[0],t->reach,t->engaged);
		display_index(t->right);
	}
	
}


AVLTree read_data(char *file){
	AVLTree t=NULL;
	FILE * f=fopen(file,"r");
	if(!f)return NULL;
	
	char c;
	while((c=fgetc(f))!='\n'){
		
	}
	int k=0;
	while((c=fgetc(f))!=EOF){
		
	char *id=(char *)malloc(sizeof(char));
	char *link=(char *)malloc(sizeof(char));
	char *message=(char *)malloc(sizeof(char));
	char *type=(char *)malloc(sizeof(char));
	char *date=(char *)malloc(sizeof(char));
	int reach=0;
	int engaged=0;
	int counter=1;
	while((c=fgetc(f))!=';'){
		counter++;
		id=(char*)realloc(id,sizeof(char)*counter);
		id[counter-2]=c;
	}
	id[counter-1]='\0';
	counter=1;
	while((c=fgetc(f))!=';'){
		counter++;
		link=(char*)realloc(link,sizeof(char)*counter);
		link[counter-2]=c;
	}
	link[counter-1]='\0';
	counter=1;
	while((c=fgetc(f))!=';'){
		counter++;
		message=(char*)realloc(message,sizeof(char)*counter);
		message[counter-2]=c;
	}
	message[counter-1]='\0';
	counter=1;
	while((c=fgetc(f))!=';'){
		counter++;
		type=(char*)realloc(type,sizeof(char)*counter);
		type[counter-2]=c;
	}
	type[counter-1]='\0';
	counter=1;
	while((c=fgetc(f))!=';'){
		counter++;
		date=(char*)realloc(date,sizeof(char)*counter);
		date[counter-2]=c;
	}
	date[counter-1]='\0';
	counter=0;
	while((c=fgetc(f))!=';'){
		reach=reach*10+(c-48);
		counter++;
		
	}
	counter=0;
	while((c=fgetc(f))!=';'){
		engaged=engaged*10+(c-48);
		counter++;
		
	}
	t=InsertEntry(reach,id,link,message,type,date,engaged,t);
	//else InsertEntry(reach,id,link,message,type,date,engaged,t);
	
	free(id);
	free(link);
	free(message);
	free(type);
	free(date);
	k++;

	}
	
	fclose(f);
	
	return t;
}



AVLTree InsertEntry(int reach, char *id,char *link,char *message,char *type,char *date,int engaged, AVLTree t)
{
	if(t==NULL){
		t=(AVLTree)malloc(sizeof(struct Node));
		if(t==NULL)printf("Out of memory space\n");
		else {
		
		t->reach=reach;
		
		t->engaged=(int *)malloc(sizeof(int));
		(t->engaged)[0]=engaged;
		
		t->id=(char **)malloc(sizeof(char *));
		*(t->id)=(char *)malloc(sizeof(char)*(strlen(id)+1));
		strcpy(*(t->id),id);
		
		t->link=(char **)malloc(sizeof(char *));
		*(t->link)=(char *)malloc(sizeof(char)*(strlen(link)+1));
		strcpy(*(t->link),link);
		
		t->message=(char **)malloc(sizeof(char *));
		*(t->message)=(char *)malloc(sizeof(char)*(strlen(message)+1));
		strcpy(*(t->message),message);
		
		t->type=(char **)malloc(sizeof(char *));
		*(t->type)=(char *)malloc(sizeof(char)*(strlen(type)+1));
		strcpy(*(t->type),type);
		
		t->date=(char **)malloc(sizeof(char *));
		*(t->date)=(char *)malloc(sizeof(char)*(strlen(date)+1));
		strcpy(*(t->date),date);
		
		t->elements=1;
		t->right=NULL;
		t->left=NULL;
	}
	}
	else if(reach==t->reach){
		t->elements++;
		
		t->engaged=(int *)realloc(t->engaged,t->elements*sizeof(int));
		(t->engaged)[t->elements-1]=engaged;
		
		t->id=(char **)realloc(t->id,sizeof(char *)*t->elements);
		(t->id)[t->elements-1]=(char *)malloc(sizeof(char)*(strlen(id)+1));
		strcpy((t->id)[t->elements-1],id);
		
		t->link=(char **)realloc(t->link,sizeof(char *)*t->elements);
		(t->link)[t->elements-1]=(char *)malloc(sizeof(char)*(strlen(link)+1));
		strcpy((t->link)[t->elements-1],link);
		
		t->message=(char **)realloc(t->message,sizeof(char *)*t->elements);
		(t->message)[t->elements-1]=(char *)malloc(sizeof(char)*(strlen(message)+1));
		strcpy((t->message)[t->elements-1],message);
		
		t->type=(char **)realloc(t->type,sizeof(char *)*t->elements);
		(t->type)[t->elements-1]=(char *)malloc(sizeof(char)*(strlen(type)+1));
		strcpy((t->type)[t->elements-1],type);
		
		t->date=(char **)realloc(t->date,sizeof(char *)*t->elements);
		(t->date)[t->elements-1]=(char *)malloc(sizeof(char)*(strlen(date)+1));
		strcpy((t->date)[t->elements-1],date);
	}
	else if(reach<t->reach){
		t->left = InsertEntry(reach,id,link,message,type,date,engaged,t->left);

		if (AVLTreeHeight(t->left) - AVLTreeHeight(t->right) == 2)
		if (reach < t->left->reach)
			t = SingleRotateWithLeft(t);
		else
			t = DoubleRotateWithLeft(t);
	}
	else if(reach>t->reach){
		t->right = InsertEntry(reach,id,link,message,type,date,engaged,t->right);

		if (AVLTreeHeight(t->right) - AVLTreeHeight(t->left) == 2)
		if (reach > t->right->reach)
			t = SingleRotateWithRight(t);
		else
			t = DoubleRotateWithRight(t);
	}
		t->height = Max(AVLTreeHeight(t->left), AVLTreeHeight(t->right)) + 1;
		return t;
	}
