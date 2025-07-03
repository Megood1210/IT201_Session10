#include<stdio.h>
#include<stdlib.h>
// Định nghĩa kiểu dữ liệu Node
typedef struct Node{
    int data;
    struct Node *next;
}Node;
// Hàm thêm node vào đầu danh sách
Node* addToHead(Node* head, int value){
    Node* newNode = (Node*) malloc(sizeof (Node)); // Cấp phát bộ nhớ cho 1 node mới
    if (newNode == NULL){
        printf("Khong the tao node moi");
        exit(1);
    }
    newNode->data = value; // Gán giá trị cho node
    newNode->next = NULL; // Trỏ node mới về node đầu hiện tại

    return newNode;
}

// Hàm hiển thị toàn bộ danh sách
void printList(Node* head){
    printf("Danh sach hien tai: \n");
    Node* temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Tạo danh sách với 5 phần tử bất kỳ
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++){
        Node* newNode = addToHead(head, values[i]);
        if (head == NULL){
            head = tail = newNode; // Phần tử đầu tiên
        }else{
            tail->next = newNode; // Nối vào cuối danh sách
            tail = newNode;
        }
    }
    printList(head);
    return 0;
}