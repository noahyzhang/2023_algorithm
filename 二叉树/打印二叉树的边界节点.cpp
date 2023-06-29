#include <vector>
#include <iostream>

struct Node {
    int value{0};
    struct Node* left{nullptr};
    struct Node* right{nullptr};

    explicit Node(int v) : value(v) {}
};

int get_height(Node* head, int height) {
    if (head == nullptr) {
        return height;
    }
    return std::max(get_height(head->left, height+1), get_height(head->right, height+1));
}

void set_edge_vec(Node* node, int height, std::vector<std::vector<Node*>>& edge_vec) {
    if (node == nullptr) {
        return;
    }
    edge_vec[height][0] = edge_vec[height][0] == nullptr ? node : edge_vec[height][0];
    edge_vec[height][1] = node;
    set_edge_vec(node->left, height+1, edge_vec);
    set_edge_vec(node->right, height+1, edge_vec);
}

void print_leaf_edge(Node* node, int heigth, const std::vector<std::vector<Node*>>& edge_vec) {
    if (node == nullptr) {
        return;
    }
    if (node->left == nullptr && node->right == nullptr
        && node != edge_vec[heigth][0] && node != edge_vec[heigth][1]) {
        std::cout << node->value << " ";
    }
    print_leaf_edge(node->left, heigth+1, edge_vec);
    print_leaf_edge(node->right, heigth+1, edge_vec);
}

void print_edge(Node* head) {
    if (head == nullptr) {
        return;
    }
    // 获取树的高度
    int height = get_height(head, 0);
    // 保存树上最左的节点和最右的节点
    std::vector<std::vector<Node*>> edge_vec(height, std::vector<Node*>(2, nullptr));
    set_edge_vec(head, 0, edge_vec);
    // 打印左边的所有边界节点
    for (int i = 0; i < height; i++) {
        std::cout << edge_vec[i][0]->value << " ";
    }
    // 打印叶子结点（既不是左边界、也不是右边界）
    print_leaf_edge(head, 0, edge_vec);
    // 最后打印右边界的节点
    for (int i = height-1; i >= 0; i--) {
        if (edge_vec[i][0] != edge_vec[i][1]) {
            std::cout << edge_vec[i][1]->value << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->right = new Node(4);
    head->right->left = new Node(5);
    head->right->right = new Node(6);
    head->left->right->left = new Node(7);
    head->left->right->right = new Node(8);
    head->left->right->right->right = new Node(11);
    head->left->right->right->right->left = new Node(13);
    head->left->right->right->right->right = new Node(14);
    head->right->left->left = new Node(9);
    head->right->left->right = new Node(10);
    head->right->left->left->left = new Node(12);
    head->right->left->left->left->left = new Node(15);
    head->right->left->left->left->right = new Node(16);
    print_edge(head);
    return 0;
}