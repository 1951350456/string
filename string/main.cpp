#include<bits/stdc++.h>
using namespace std;
struct node{
    node *prior;
    node *next;
    char data;
    node(){
        prior = NULL;
        next = NULL;
        data = NULL;
    }
};
//顺序表实现
class String{
private:
    char *base;
    int length;
public:
    String(){
        base = NULL;
        length = 0;
    }
    String(const char *m){
        int i = 0;
        while(m[i] != '\0'){
            i++;
        }
        length = i;
        base = new char[length+1];
        for(int j = 0; j < length;j++){
            base[j] = m[j];
        }
        base[length] = '\0';
    }
    ~String(){
        if(base!=NULL){
            delete[] base;
        }
        base = NULL;
    }
    bool isEmpty(){
        if(length==0){
            return true;
        }
        return false;
    }
    int getlength(){
        return length;
    }
    void print(){
        cout<<base;
    }
};
//链表实现
class linked_string{
private:
    int length;
    node *head;
public:
    linked_string(){
        head = new node;
        head->next = NULL;
        head->prior = NULL;
        length = 0;
    }
    linked_string(const char *m){
        length = 0;
        head = new node;
        if(m[0]!='\0') {
            head->data = m[0];
            length++;
        }
        node *ptr = head;
        if(strlen(m)>0)
            for(int i=1;m[i]!='\0';i++){
                node *p = new node;
                p->data = m[i];
                ptr->next = p;
                p->prior = ptr;
                ptr = ptr->next;
                length++;
            }
        ptr->next = NULL;
        head->prior = NULL;
    }
    ~linked_string(){
        node *ptr = head;
        while(ptr != NULL){
            node *p = ptr;
            ptr = ptr->next;
            delete p;
        }
    }
    node *gethead(){
        return head;
    }
    int getlength(){
        return length;
    }
    char& operator[](int n){
        node *ptr = head;
        for(int i=0;i<n;i++){
            ptr=ptr->next;
        }
        return ptr->data;
    }
};
//链串比较
int cmp(linked_string &a,linked_string &b){
    node *ptr1 = a.gethead();
    node *ptr2 = b.gethead();
    while(ptr1->data == ptr2->data){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if(ptr1==NULL&&ptr2==NULL){
        return 0;
    }
    else if(ptr1==NULL){
        return -1;
    }
    else if(ptr2==NULL){
        return 1;
    }
    else if(ptr1->data<ptr2->data){
        return -1;
    }
    else
        return 1;
}
//string KMP
int string_kmp(string str,string substr){
    int next[substr.length()];
    next[0] = -1;
    int i =-1;
    int j = 0;
    while(j<substr.length()-1) {
        if(i==-1||substr[j]==substr[i]){
            next[++j] = ++i;
        }
        else{
            i = next[i];
        }
    }
    int m = 0;
    int n = 0;
    while(m<str.length()&&n<(int)substr.length()){
        if(n==-1||str[m]==substr[n]){
            m++;
            n++;
        }
        else{
            n = next[n];
        }
    }
    if(n==substr.length()){
        return m-substr.length();
    }
    else
        return -1;
}
//链串KMP
int linked_str_kmp(linked_string &str,linked_string &substr){
    int next[substr.getlength()];
    next[0] = -1;
    int i =-1;
    int j = 0;
    while(j<substr.getlength()-1) {
        if(i==-1||substr[j]==substr[i]){
            next[++j] = ++i;
        }
        else{
            i = next[i];
        }
    }
    int m = 0;
    int n = 0;
    while(m<str.getlength()&&n<(int)substr.getlength()){
        if(n==-1||str[m]==substr[n]){
            m++;
            n++;
        }
        else{
            n = next[n];
        }
    }
    if(n==substr.getlength()){
        return m-substr.getlength();
    }
    else
        return -1;
}
int main(){
    char a[10];
    char b[10];
    cin>>a;
    cin>>b;
    linked_string m(a);
    linked_string n(b);
    cout<<linked_str_kmp(m,n);
}