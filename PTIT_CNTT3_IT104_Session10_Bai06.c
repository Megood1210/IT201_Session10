#include <stdio.h>
#include <stdlib.h>

// Định nghĩa kiểu dữ liệu Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Hàm thêm node vào đầu danh sách
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm duyệt danh sách và in ra từng phần tử
void traverseList(Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Hàm đếm số node
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm tìm phần tử nằm giữa
Node* findNode(Node* head) {
    int total = countNodes(head);
    if (total == 0){
        printf("Danh sach rong");
        return;
    }

    int middle = total / 2 + 1;
    Node* current = head;
    int count = 1;

    while (current && count < middle) {
        current = current->next;
        count++;
    }
    // In kết quả
    if (current){
        printf("Node %d: %d", middle,current->data);
    }else{
        printf("Khong co phan tu giua");
    }

}

// Hàm main
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Tạo danh sách
    int values[6] = {5, 4, 3, 2, 1, 6};
    for (int i = 0; i < 6; i++) {
        Node* newNode = createNode(values[i]);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    traverseList(head);
    // Tìm phần tử
    findNode(head);

    return 0;
}
