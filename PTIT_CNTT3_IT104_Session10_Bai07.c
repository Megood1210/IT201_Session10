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
// Hàm sắp xếp danh sách liên kết theo thứ tự tăng dần
void sortList(Node* head) {
    // Danh sách rỗng
    if (!head || !head->next) {
        return;
    }
    int swap; // Cờ kiểm tra để kiểm tra cần sắp xếp không
    Node *ptr1, *ptr2; // Trỏ hiện tại và tiếp

    do{
        swap = 0; // Đặt lại cờ mỗi vòng lặp
        ptr1 = head; // Bắt đầu từ đầu danh sách

        while (ptr1->next) {
            ptr2 = ptr1->next;
            if (ptr1->data > ptr2->data) {
                // Đổi dữ liệu
                int temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
                swap = 1; // Tiếp tục lặp
            }
            ptr1 = ptr1->next; // Di chuyển đến node tiếp
        }
    }
    while (swap); // Nếu không có hoán đổi thì sắp xếp xong
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Tạo danh sách
    int values[3] = {5, 7, 3};
    for (int i = 0; i < 3; i++) {
        Node* newNode = createNode(values[i]);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    traverseList(head);
    // Sắp xếp phần tử
    sortList(head);
    // In kết quả
    traverseList(head);

    return 0;
}
