#include<stdio.h>
int top=-1;
void push(int a[20],int n)
{
    int x;
    if(top==n-1)
    {
        printf("\nstack overflow");
        return;
    }
printf("\nenter the data to be pushed:");
scanf("%d",&x);
a[++top]=x;
}
void pop(int a[20])
{
    int x;
    if(top==-1)
    {
        printf("\n stack overflow");
        return;

    }
    x=a[top--];
}
void display(int a[20])
{
    int i;
    if(top==-1)
    {
        printf("no element");
        return;
    }
    printf("\n elements of stack are: ");
    for(i=0;i<=top;i++)
        printf("%d",a[i]);

}
int main()
{
    int stack[20],ch,n;
    printf("\nenter the no of elements:");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\nenter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(stack,n);
            break;
            case 2:pop(stack);
            break;
            case 3:display(stack);
            break;
            case 4:return;
            default:printf("\nwrong choice");

        }
    }
}
