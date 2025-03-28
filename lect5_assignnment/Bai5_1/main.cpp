#include <iostream>
using namespace std;

struct Node{    //xây dựng cấu trúc node
    int data;   //khai báo biến lưu giá trị
    Node* firstchild;   //con trỏ đến con đầu
    Node* nextSibling;  //con trỏ đến chị em
    
    Node(int val) : data(val), firstchild(nullptr), nextSibling(nullptr){}
};

class Tree{
public:
    int height; //khai báo biến lưu chiều cao cây
    Node* root; //node trỏ đến gốc
    Node* nodeList[1001] = {}; //  danh sách các node
    bool isChild[1001] = {false}; // xác định xem thằng nào là root
    
    // Hàm thêm con
    void AddChild(int u, int v){
        // Kiểm tra xem nút đã tồn tại chưa
        if (nodeList[u] == nullptr){
            nodeList[u] = new Node(u);   //Tạo nít cha nếu chưa có
        } 
        if (nodeList[v] == nullptr){
            nodeList[v] = new Node(v);   //Tạo nút con nếu chưa có
        }
        Node* parent = nodeList[u]; //gán cho u là cha
        Node* child = nodeList[v];  //gán cho v là con
        
        if (!parent->firstchild) {
            parent->firstchild = child;
        } else {
            Node* temp = parent->firstchild; //gán giá trị nút con cho nút tạm
            while (temp->nextSibling) {
                temp = temp->nextSibling;   // Duyệt danh sách để tìm con cuối cùng
            }
            temp->nextSibling = child;  // gắn chị em
        }
        isChild[v] = true;  //gán giá trị đúng
    }
    
    //Cập nhật gốc cây
    void UpdateRoot(int N){
        for (int i = 0; i <= N; i++){   //Kiểm tra từ đầu cây đến cuối
            if (nodeList[i] && !isChild[i]){    // xem node có là node con hay không (nếu false thì là gốc)
                root = nodeList[i]; //gán gốc cho node
                break;  //dừng vòng for sau khi tìm được gốc
            }
        }
    }
    
    // Chiều cao cây
    int CalculateHeight(Node* node){
        if (!node) return - 1;    //kiểm tra node có tồn tại không
        int maxHeight = - 1;  //khai báo biến để lưu chiều cao cây
        Node* temp = node->firstchild;  //tạo node tạm và trỏ đến con đầu
        while (temp) {  //lặp đệ quy
            
            maxHeight = max(maxHeight, CalculateHeight(temp));  //gán max cho giá trị lớn nhất khi so sánh gtri htai với chiều cao cây con
            temp = temp->nextSibling;   //trỏ đến nút chị em để tiếp tục so sánh r gán giá trị nếu thỏa man
            
        }
        return maxHeight + 1;   // trả về giá trị chiều cao cây
    }
    
    // Duyệt cây theo preorder 
    void Preorder(Node* node) {
        if (!node) return;  //ktra nếu node tồn tại, không thì dừng hàm
        cout << node->data << " ";  //in ra giá trị của node
        Node* temp = node->firstchild;  // tạo node tạm trỏ đến con đầu
        while (temp) {  // lặp đến khi node tạm đến null
            Preorder(temp); //gọi lại hàm duyệt preorder
            temp = temp->nextSibling;   // trỏ đến node chị em tiếp theo
        }
    }
    
    // duyệt cây theo postorder
    void Postorder(Node* node) {
        if (!node) return;  //ktra nếu node tồn tại, không thì dừng hàm
        Node* temp = node->firstchild;  // tạo node tạm trỏ đến con đầu
        while (temp) {
            Postorder(temp);    //gọi lại hàm duyệt postorder
            temp = temp->nextSibling;   // trỏ đến node chị em tiếp theo
        }
        cout << node->data << " ";  //in ra giá trị của node
    }
    
    //Kiểm tra có phải cây nhị phân không
    bool IsBinaryTree(Node* node) {
        if (!node) return true; //ktra node tồn tại không
        int count = 0;  //khai báo biến đếm
        Node* temp = node->firstchild;  // tạo node tạm trỏ đến con đầu
        while (temp) {
            count++;    //tăng biến đếm
            if (count > 2) return false; // Nếu có hơn 2 con, không phải cây nhị phân
            if (!IsBinaryTree(temp)) return false;  //nếu không phải cây nhị phân trả về false
            temp = temp->nextSibling;   // trỏ đến node chị em tiếp theo
        }
        return true;
    }
    
    //duyệt cây theo inorder
    void Inorder(Node* node) {
        if (!node) return;  //ktra nếu node tồn tại, không thì dừng hàm
        if (node->firstchild) Inorder(node->firstchild); // Duyệt con trái
        cout << node->data << " ";  //in ra giá trị node
        if (node->firstchild && node->firstchild->nextSibling) Inorder(node->firstchild->nextSibling); // Duyệt con phải, gọi lại hàm inorder
    }
    
    //hàm giải quyết, thực hiện yêu cầu theo đề bài
    void Solve(int N) {
        UpdateRoot(N); //Gọi hàm cập nhật node
        cout << CalculateHeight(root) << endl;   //in ra chiều cao cây
        Preorder(root); //Gọi hàm duyệt theo pre
        cout << endl;   //Xuống dòng
        Postorder(root);    //Gọi hàm duyệt theopost
        cout << endl;   //Xuống dòng
        //Kiểm tra xem có phải cây nhị phân không
        if (IsBinaryTree(root)) {
            Inorder(root);  //Nếu là nhị phân thì gọ hàm duyệt theo in
            cout << endl;   //Xuống dòng
        } else {
            cout << "NOT BINARY TREE" << endl;  // nếu false in ra không là cây nhị phân
        }
    }
};

// HÀM CHÍNH
int main() {
    int N, M; //khai báo biến lưu số node, số dòng
    cin >> N >> M;  //nhập giá trị N,M từ bàn phím
    Tree tree;  //khởi tạo class tên tree
    for (int i = 0; i < M; ++i) { //lặp M lần
        int u, v;   //khai báo biến lưu giá trị các node cha con
        cin >> u >> v;  //nhập giá trị các node cha con
        tree.AddChild(u, v);    //gọi hàm thêm node cha con
    }
    tree.Solve(N); // gọi hàm giải quyết bài toán
    return 0;
}
