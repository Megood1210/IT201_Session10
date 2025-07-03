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

// Hàm xóa tất cả số
Node* deleteNode(Node* head, int value) {
    // Xóa các node ở đầu danh sách nếu trùng
    while (head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }


    Node* current = head;
    Node* prev = NULL;
    //  Duyệt qua danh sách
    while (current != NULL) {
        // Xóa node
        if (current->data == value) {
            Node* temp = current;
            prev->next = current->next; // bỏ qua node hiện tại
            current = current->next; // chuyển sang node kế tiếp
            free(temp);  // giải phóng node bị xóa
        } else {
            // Di chuyển prev và current sang node tiếp theo.
            prev = current;
            current = current->next;
        }
    }

    return head;
}

// Hàm main
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Tạo danh sách
    int values[7] = {5, 4, 3, 5, 2, 1, 5};
    for (int i = 0; i < 7; i++) {
        Node* newNode = createNode(values[i]);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    traverseList(head);
    // Nhập số muốn xóa
    int x;
    printf(" Nhap so bat ky: ");
    scanf("%d", &x);
    // Xóa phần tử
    head = deleteNode(head, x);
    // In kết quả
    traverseList(head);

    return 0;
}