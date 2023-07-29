//
//  main.cpp
//  StackArray
//
//  Created by Uby H on 28/07/23.
//

#include <iostream>
using namespace std;
struct Stack
{
    int size;
    int top;
    int *s;
};
void create(struct Stack *st)
{
    cout<<"Enter the size of the array : "<<endl;
    cin>>st->size;
    st->top=-1;
    st->s=(int*)malloc(sizeof(int)*(st->size));
}
void Display(struct Stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        cout<<st.s[st.top]<<" ";
        st.top--;
    }
    cout<<endl;
}
void push(struct Stack *st, int x)
{
    if(st->top>=(st->size)-1)
        cout<<"Stack overflow"<<endl;
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(struct Stack *st)
{
    int x=-1;
    if(st->top<0)
        cout<<"Stack underflow"<<endl;
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct Stack st, int pos)
{
    int x=-1;
    if((st.top-pos+1)<0)
        cout<<"Invalid index"<<endl;
    else
        x=st.s[st.top-pos+1];
    return x;
}
int StackTop(struct Stack st)
{
    if(st.top==-1)
        return -1;
    else
        return st.s[st.top];
}
bool isEmpty(struct Stack st)
{
    if(st.top==-1)
        return true;
    else
        return false;
}
bool isFull(struct Stack st)
{
    if(st.top==st.size-1)
        return true;
    else
        return false;
}
int main()
{
    int n=0,x=0;
    struct Stack st;
    create(&st);
    cout<<"Enter the number of elements you want to enter in the array : "<<endl;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        push(&st,x);
    }
    cout<<"The array elements are given by : "<<endl;
    Display(st);
    cout<<"The array elements after popping one element are given by : "<<endl;
    pop(&st);
    Display(st);
    cout<<"The array elements after popping another element are given by : "<<endl;
    pop(&st);
    Display(st);
    cout<<"The topmost element in the array is : "<<StackTop(st)<<endl;
    cout<<"Enter the position of element you would like to display : "<<endl;
    cin>>x;
    cout<<"The element at the given position is : "<<peek(st,x)<<endl;
    cout<<isFull(st)<<endl;
    cout<<isEmpty(st)<<endl;
    return 0;
}
