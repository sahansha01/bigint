#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

typedef struct {
    node*head;
    char sign;
     int size;
}BIGINT;
BIGINT* add(BIGINT* num1,BIGINT* num2);
BIGINT* mul(BIGINT *n1,BIGINT*n2);
BIGINT* mod(BIGINT *num1,BIGINT*num2);
BIGINT*sub(BIGINT* num1, BIGINT* num2);
BIGINT* div1(BIGINT*num1,BIGINT*num2);
int compare(BIGINT*num1,BIGINT*num2,char*c);
BIGINT* initialize();
node* reverse(node*head);
void insert(BIGINT*num,int element);
void display_reverse(node*head);
char cmp(BIGINT*num1,BIGINT*num2);
 BIGINT* copy(BIGINT *num1);
 int length(node*head)
{
    int count=0;
    while(head)
    {
        head=head->next;
        count++;
    }
    return count;
}

node* reverse(node*head)
{
    node*back=NULL,*front=NULL,*current=head;
    while(current!=NULL)
    {
        front=current->next;
        current->next=back;
        back=current;
        current=front;
    }
    return back;
}
BIGINT* initialize(){
     BIGINT*num=(BIGINT*)malloc(sizeof(BIGINT));
    if(num==NULL)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    num->head=NULL;
    char c;
    printf("enter a number ");
    if ((c = getchar()) == '-') {
        num->sign='-';
        c = getchar();
    }
    else{
        num->sign='+';
    }
    while (c != '\n') {
        if (c >= '0' && c <= '9') {
            int digit = c - '0';
             node*temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    temp->data=digit;
    temp->next=num->head;
    num->head=temp;
    num->size+=1;
        }
        else {
        printf("enter a valid digit\n");
        exit(1);
        }
        c = getchar();
    }
  
    return num;
}
void insert(BIGINT*num,int element)
{
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
    temp->data=element;
    temp->next=NULL;
    num->size+=1;
    if(num->head==NULL)
    {
        num->head=temp;
        return;
    }
    node*itr=num->head;
    while(itr->next!=NULL)
    {
        itr=itr->next;
    }
    itr->next=temp;
    
}
void display_reverse(node*head)
   {
        if(head==NULL)
        {
         return;
        }
        display_reverse(head->next);
        printf("%d",head->data);
   }
  
void display(BIGINT *num)
{
    if(num->sign=='-')
    {
        printf("%c",'-');
    }
    if(num==NULL || num->head==NULL)
    {
        return;
    }
    display_reverse(num->head);
}
BIGINT*sub(BIGINT* num1, BIGINT* num2){
    
    node*l1=num1->head,*l2=num2->head;
    BIGINT *num3=(BIGINT*)malloc(sizeof(BIGINT));
   // compare(num1,num2,&num3->sign);
   if(num1->sign=='+' && num2->sign=='-')
    {
        num2->sign='+';
        num3=add(num1,num2);
        num2->sign='-';
       num3->sign='+';
        return num3;
    }
    else if(num1->sign=='-'&& num2->sign=='+' )
    {
      num1->sign='+';
      num3=add(num2,num1);
      num1->sign='-';
     num3->sign='-';
      return num3;
    }
    //printf("%d",compare(num1,num2));
     if(compare(num1,num2,&num3->sign))
    {
        node*temp=l1;
        l1=l2;
        l2=temp;
    }

    int sub=0;
    int borrow=0;
    while(l1!=NULL && l2!=NULL)
    {
        sub=l1->data-l2->data+borrow;
        if(sub<0)
        {
            borrow=-1;
            sub=sub+10;
        }
        else
        {
            borrow=0;
        }
        insert(num3,sub);  
        l1=l1->next;
        l2=l2->next;      
    }
   while(l1!=NULL)
    {
        sub=l1->data+borrow;
        borrow=0;
        insert(num3,sub);
        l1=l1->next;
    }
   //remove_trailing_zero(num3);
    return num3;
}
int compare(BIGINT*num1,BIGINT*num2,char *c)
{
   
    //it would return 1 if n2 is greater otherwise 0
    if(num2->size>num1->size)
    {
         *c  = num2->sign;
        return 1;
        
    }
    else if(num2->size==num1->size)
    {
        int return_val=0;
        num1->head= reverse(num1->head);
        num2->head= reverse(num2->head);
        node*head1=num1->head,*head2=num2->head;
        while(head1!=NULL && head2!=NULL)
        {
            if(head2->data>head1->data)
            {
                return_val= 1;
                break;
            }
            else if(head1->data<head2->data)
            {
                return_val= 0;
                break;
            }
            head1=head1->next;
            head2=head2->next;
        }
        num1->head= reverse(num1->head);
        num2->head= reverse(num2->head);
        return return_val;
    }
    *c  = num1->sign;
    return 0;
}
char cmp(BIGINT*num1,BIGINT*num2)
{
   
    //it would return 1 if n2 is greater otherwise 0
    if(num2->size>num1->size)
    {
         return num2->sign;
        
    }
    else if(num2->size==num1->size)
    {
        int return_val=0;
        num1->head= reverse(num1->head);
        num2->head= reverse(num2->head);
        node*head1=num1->head,*head2=num2->head;
        while(head1!=NULL && head2!=NULL)
        {
            if(head2->data>head1->data)
            {
                return_val= 1;
                break;
            }
            else if(head1->data<head2->data)
            {
                return_val= 0;
                break;
            }
            head1=head1->next;
            head2=head2->next;
        }
        num1->head= reverse(num1->head);
        num2->head= reverse(num2->head);
        return return_val;
    }
    return num1->sign;
}
BIGINT* add(BIGINT* num1,BIGINT* num2){
BIGINT *num3 = (BIGINT*)malloc(sizeof(BIGINT));
num3->head=NULL;
num3->size = 0;

    if(num1->sign=='-' && num2->sign=='-')
    {
        num3->sign='-';
    }
    else if(num1->sign=='-' )
    {
      num1->sign='+';
      num3=sub(num2,num1);
      num1->sign='-';
      num3->sign=cmp(num1,num2);
      return num3;
    }
    else if(num2->sign=='-')
    {
      num2->sign='+';
      num3=sub(num1,num2);
      num2->sign='-';
            num3->sign=cmp(num1,num2);
      return num3;
    }
    
    node*l1=num1->head,*l2=num2->head;
    int sum=0;
    int carry=0;
    while(l1!=NULL && l2!=NULL)
    {
        sum=l1->data+l2->data+carry;
        carry=sum/10;
        sum=sum%10;
        insert(num3,sum);  
        l1=l1->next;
        l2=l2->next;      
    }
   while(l1!=NULL)
    {
        sum=l1->data+carry;
        carry=sum/10;
        sum=sum%10;
        insert(num3,sum);
        l1=l1->next;
    }
     while(l2!=NULL)
    {
        sum=l2->data+carry;
        carry=sum/10;
        sum=sum%10;
        insert(num3,sum);
        l2=l2->next;
    }
    if(carry!=0)
    {
        insert(num3,carry);
    }
    return num3;
    
}
BIGINT* mul(BIGINT *n1,BIGINT*n2)
{
    node*num1=n1->head,*num2=n2->head;
    if(num1==NULL || num2==NULL)
    {
        return NULL;
    }
    BIGINT*result,*mid;
    result = (BIGINT*)malloc(sizeof(BIGINT));
    int carry=0,product=0,i=0;
    while(num2!=NULL)
    {
        node*num1=n1->head;
        carry=0;
        mid=(BIGINT*)malloc(sizeof(BIGINT));
        for(int j=0;j<i;j++)
        {
            insert(mid,0);
        }
        while(num1!=NULL)
        {
            product=(num1->data)*(num2->data)+carry;
            insert(mid,product%10);
            carry=product/10;
            num1=num1->next;
        }
     
        if(carry>0)
        {
             insert(mid,carry);
        }
    
        result=add(mid,result);
        node* current = mid->head;
       /* while (current != NULL) {
            node* next = current->next;
            free(current);
            current = next;
        }
        free(mid);*/
        num2=num2->next;
        i++;
    }
    if(n1->sign!=n2->sign)
    {
        result->sign='-';
    }
    return result;
}

  void main(){
        BIGINT *num1,*num2,*num3;
    num1=initialize();

   num2=initialize();
   printf("\n num1 : ");
   display(num1);
    printf("\n num2 : ");
    display(num2);
    printf("\n");
   printf("addition: ");
    num3=add(num1,num2);
     display(num3);
    printf("\n");
    printf("sub: ");
    num3=sub(num1,num2);
       display(num3);
       free(num3);
    printf("\n");
    printf("multiplicaton: ");
    num3=mul(num1,num2);
    
  //  printf("\nsize: %ld\n",num3->size);
    display(num3);
    printf("\n");
   free(num3);
    }
         