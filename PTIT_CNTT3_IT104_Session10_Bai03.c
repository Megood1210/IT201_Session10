#include<stdio.h>
#include<stdlib.h>
// Định nghĩa kiểu dữ liệu Node
typedef struct Node{
    int data;
    struct Node *next;
}Node;
// Hàm thêm node vào đầu danh sách
Node* addToHead(int data){
    Node* newNode = (Node*) malloc(sizeof(Node)); // Cấp phát bộ nhớ cho 1 node mới
    if (newNode == NULL){
        printf("Khong the tao node moi");
        exit(1);
    }
    newNode->data = data; // Gán giá trị cho node
    newNode->next = NULL; // Trỏ node mới về node đầu hiện tại

    return newNode;
}

// Hàm duyệt danh sách và in dữ liệu từng phần tử
void traverseList(Node* head){
    Node* temp = head;
    int position = 1;
    if (temp == NULL){
        printf("Danh sach rong");
        return;
    }
    while (temp != NULL){
        printf("%d -> ",
            temp->data);
        temp = temp->next;
        position++;
    }
    printf("NULL");
}
// Hàm thêm phần tử vào cuối danh sách
Node* insertAtEnd(Node* head, int newData){
    Node* newNode = addToHead(newData);
    if (head == NULL){
        printf("Danh sach rong");
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Tạo danh sách với 5 phần tử bất kỳ
    int values[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++){
        Node* newNode = addToHead(values[i]);
        if (head == NULL){
            head = tail = newNode; // Phần tử đầu tiên
        }else{
            tail->next = newNode; // Nối vào cuối danh sách
            tail = newNode;
        }
    }
    // In danh sách ban đầu
    traverseList(head);
    // Thêm số mới vào cuối danh sách
    int newValue;
    printf(" ");
    scanf("%d", &newValue);
    head = insertAtEnd(head, newValue);
    // In kết quả
    traverseList(head);

    return 0;
}
