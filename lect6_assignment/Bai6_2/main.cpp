// Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.
// Draw the heap tree 
// Draw the heap tree after inserting values:  14, 0, 35 
// Draw the heap tree after deleting: 6, 13, 35

//a, vẽ cây
// MIN heap
//          1
//        /   \
//       2     7
//      / \   /  \
//     3   6 8   10
//    / \
//   13 20

//MAX heap 
//          20
//         /  \
//       13    8
//      /  \  / \
//     10  3 2  7
//    /  \
//   1    6

//b, cây sau khi thêm
//MIN heap
//           0
//        /    \
//       1     7
//      / \   /  \
//     2   6 8   10
//    / \  /
//   13 20 3
//  / \
// 14  35

//MAX heap
//           35
//         /    \
//        14     20
//      /   \    / \
//     10   13  8  7
//    / \   /\  /
//   1  6  3 0  2


//c, cây sau khi xóa
//MIN heap
//          0
//        /   \
//       1     7
//      / \   /  \
//     2   3 8   10
//   / \  
//  14 20 

//MAX heap
//           20
//         /    \
//        14     8
//      /   \   / \
//     10   3  2  7
//    /    /  
//   1    0   
// 

//Mã giả hàm insert với cây MIN HEAP
    //Nếu cây rỗng thị tạo nút mới làm gốc
    //Trong khi (while) nút có 2 con trái phải
        //Nếu con trái != null, temp = temp.left
        //Nếu không, temp = temp.right
    //Gắn nút mới vào cây
        //Nếu temp.left = null, tạo nút mới ở temp.left
        //Nếu không, tạo nút mới ở temp.right
        //gán temp cho nút cha mới
    //trả về root


//Mã giả hàm delete với cây MIN HEAP
    //Nếu cây rỗng, dừng hàm
    //Tìm nút cần xóa
    //Nếu không thấy nút, dừng hàm
    //Tìm nút cuối cùng trong HEAP
    //Hoán đổi 2 vị trí với nhau
    //Xóa nút ở cuối cùng
    //Điều chỉnh lại heap từ trên xuống

//Code với MIN HEAP
#include <iostream>
using namespace std;

// Định nghĩa một nút trong Min Heap (danh sách liên kết)
struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int k) {
        key = k;
        left = right = parent = nullptr;
    }
};

// Hàm hoán đổi giá trị giữa hai nút
void swap(Node* a, Node* b) {
    int temp = a->key;
    a->key = b->key;
    b->key = temp;
}

// Hàm trộn xuống (Heapify Down) để duy trì tính chất Min Heap
void heapifyDown(Node* root) {
    if (root == nullptr)
        return;

    Node* smallest = root;

    if (root->left && root->left->key < smallest->key)
        smallest = root->left;

    if (root->right && root->right->key < smallest->key)
        smallest = root->right;

    if (smallest != root) {
        swap(root, smallest);
        heapifyDown(smallest);
    }
}

// Hàm trộn lên (Heapify Up) để duy trì tính chất Min Heap
void heapifyUp(Node* node) {
    if (node == nullptr || node->parent == nullptr)
        return;

    if (node->key < node->parent->key) {
        swap(node, node->parent);
        heapifyUp(node->parent);
    }
}

// Hàm chèn một phần tử vào Min Heap
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    Node* newNode = new Node(key);
    Node* temp = root;

    // Duyệt cây để tìm vị trí thích hợp
    while (temp->left && temp->right) {
        if (!temp->left)
            temp = temp->left;
        else if (!temp->right)
            temp = temp->right;
        else
            temp = temp->left;  // Ưu tiên thêm vào bên trái
    }

    // Gán nút mới vào cây
    if (!temp->left)
        temp->left = newNode;
    else
        temp->right = newNode;

    newNode->parent = temp;
    heapifyUp(newNode);

    return root;
}

// Hàm tìm nút cuối cùng trong Heap
Node* getLastNode(Node* root) {
    if (!root)
        return nullptr;
    
    if (!root->left && !root->right)
        return root;

    if (root->right)
        return getLastNode(root->right);
    else
        return getLastNode(root->left);
}

// Hàm xóa một phần tử trong Min Heap
Node* deleteNode(Node* root, int key) {
    if (!root)
        return nullptr;

    // Tìm nút cần xóa
    Node* target = root;
    while (target && target->key != key) {
        if (target->left && target->left->key == key)
            target = target->left;
        else if (target->right && target->right->key == key)
            target = target->right;
        else
            target = target->left ? target->left : target->right;
    }

    if (!target)
        return root; // Không tìm thấy phần tử cần xóa

    // Tìm nút cuối cùng trong Heap
    Node* lastNode = getLastNode(root);

    // Hoán đổi giá trị với nút cuối cùng và xóa nút cuối cùng
    swap(target, lastNode);
    if (lastNode->parent->left == lastNode)
        lastNode->parent->left = nullptr;
    else
        lastNode->parent->right = nullptr;

    delete lastNode;
    
    heapifyDown(target);
    return root;
}

// Hàm in Heap theo thứ tự (Inorder Traversal)
void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Hàm giải phóng bộ nhớ Heap
void deleteHeap(Node* root) {
    if (!root)
        return;
    deleteHeap(root->left);
    deleteHeap(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;

    // Chèn các phần tử ban đầu vào Min Heap
    int initialData[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int key : initialData)
        root = insert(root, key);

    cout << "Min Heap sau khi chèn các phần tử ban đầu:\n";
    inorder(root);
    cout << endl;

    // Thêm các phần tử 14, 0, 35
    int newElements[] = {14, 0, 35};
    for (int key : newElements)
        root = insert(root, key);

    cout << "\nMin Heap sau khi chèn thêm 14, 0, 35:\n";
    inorder(root);
    cout << endl;

    // Xóa các phần tử 6, 13, 35
    int deleteElements[] = {6, 13, 35};
    for (int key : deleteElements)
        root = deleteNode(root, key);

    cout << "\nMin Heap sau khi xóa 6, 13, 35:\n";
    inorder(root);
    cout << endl;

    // Giải phóng bộ nhớ
    deleteHeap(root);

    return 0;
}

