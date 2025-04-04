// Given a list of integer numbers: 2, 1, 10, 6, 3, 8, 7, 13, 20.  - 
// Draw the binary search tree - - 
// Draw the binary search tree after inserting values:  14, 0, 35 
// Draw the binary search tree after deleting: 6, 13, 35 


//a, vẽ cây
    //      2
    //    /  \
    //   1   10
    //      /  \
    //     6    13
    //   / \      \
    //   3  8       20
    //      /
    //     7
//  duyệt theo inorder: 1, 2, 3, 6, 7, 8, 10, 13, 20 


//b, vẽ sau khi thêm insert
    //      2
    //     / \
    //   1   10
    //  /   /   \
    // 0   6     13
    //   / \    /  \
    //   3   8  14  20
    //      /         \
    //     7           35

//c, vễ cây sau khi xóa
    //     2
    //    / \
    //   1   10
    //  /   /  \
    // 0   7    14
    //    / \    \
    //   3   8    20


//Mã giả hàm insert (sử dụng linkedlist)
    //Nếu root = null thì khởi tạo linkedlist và gán giá trị vào root
    //Nếu dữ liệu (data) < gốc (root), gọi đệ quy hàm insert với root.left
    //Nếu dữ liệu (data) > gốc (root), gọi đệ quy hàm insert với root.right
    //Nếu không, thêm giá trị vào danh sách liên kết nếu trùng khóa
    // trả về root
    
//Mã giả hàm delete (sử dụng linkedlist)
    //Nếu root = null, kết thúc hàm
    //Nếu dữ liệu (data) < gốc (root), gọi đệ quy hàm delete với root.left
    //Nếu dữ liệu (data) > gốc (root), gọi đệ quy hàm delete với root.right
    //Nếu không, xóa giá trị khỏi danh sách liên kết
    //Nếu danh sách trống thì xóa nút
        //Nếu nút trái bằng null trả về nút trái
        //Nếu nút phải bằng null trả về nút phải
        //Tìm nút nhỏ nhất của nhánh bên phải
        //Thay thế nút nhỏ nhất vừa tìm vào vị trí nút cần xóa
        //Xóa nút
    //Trả về root

// Code

#include <iostream>
using namespace std;

// Định nghĩa một nút trong cây BST
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    
    //khởi tạo node
    TreeNode(int k) {
        key = k;
        left = right = nullptr;
    }
};

// Hàm chèn một phần tử vào BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr)
        return new TreeNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Hàm tìm nút nhỏ nhất trong cây (phục vụ xóa)
TreeNode* findMin(TreeNode* root) {
    while (root->left)
        root = root->left;
    return root;
}

// Hàm xóa một phần tử trong BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Trường hợp 1: Nút không có con hoặc chỉ có 1 con
        if (root->left == nullptr)
            return root->right;
        else if (root->right == nullptr)
            return root->left;

        // Trường hợp 2: Nút có cả 2 con
        TreeNode* successor = findMin(root->right);
        root->key = successor->key;
        root->right = deleteNode(root->right, successor->key);
    }
    return root;
}

// Hàm in cây theo thứ tự trung tố (Inorder)
void inorder(TreeNode* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Hàm giải phóng bộ nhớ cây BST
void deleteTree(TreeNode* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;

    // Xây dựng cây ban đầu với gốc 2
    int initialData[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int key : initialData)
        root = insert(root, key);

    cout << "Cây BST sau khi chèn các phần tử ban đầu:\n";
    inorder(root);
    cout << endl;

    // Chèn thêm các phần tử 14, 0, 35
    int newElements[] = {14, 0, 35};
    for (int key : newElements)
        root = insert(root, key);

    cout << "\nCây BST sau khi chèn thêm 14, 0, 35:\n";
    inorder(root);
    cout << endl;

    // Xóa các phần tử 6, 13, 35
    int deleteElements[] = {6, 13, 35};
    for (int key : deleteElements)
        root = deleteNode(root, key);

    cout << "\nCây BST sau khi xóa 6, 13, 35:\n";
    inorder(root);
    cout << endl;

    // Giải phóng bộ nhớ
    deleteTree(root);

    return 0;
}
