#include <iostream>

using namespace std;

// дерево
struct tree {
    int value;
    tree *left;
    tree *right;
};

// функция создания узла
tree *make_node(int x) {
    tree *temp = new tree;
  
    temp->value = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// создание сбалансированного дерева
void create_tree(tree *&node, int n) {
    if (n > 0) {
        int x;
        cin >> x;

        node = make_node(x);

        int left_subtree = n/2;
        int right_subtree = n - left_subtree - 1;

        create_tree(node->left, left_subtree); // рекурсивное создание левого
        create_tree(node->right, right_subtree); // и правого поддеревьев
    }
}

// длина пути от корня до крайнего левого листа
int left_height(tree *&root) {
    int height;
    tree *current = root;

    for (height = 0; current; height++, current=current->left);

    return height-1;
}

// длина пути от корня до крайнего правого листа
int right_height(tree *&root) {
    int height;
    tree *current = root;

    for (height = 0; current; height++, current=current->right);

    return height-1;
}

// рекурсивный вывод дерева
void print_preorder(tree *root) {
    if (root) {
        cout << root->value << " ";

        print_preorder(root->left);
        
        print_preorder(root->right);
    }
}

// геттер левого сына
tree *get_left(tree *node) {
    return node->left;
}

// геттер правого сына
tree *get_right(tree *node) {
    return node->right;
}

// геттер значения узла
int get_value(tree *node) {
    return node->value;
}

// реализация дерева закончилась
//============================================================================================

// подсчёт глубины узла со значением X
int node_depth(tree *node, int x) {
    if (!node) return -1; // если узла не существует
    if (get_value(node) == x) return 0; // нашли узел со значением X

    int left_answer = node_depth(get_left(node), x); // рекурсивно полученное значение из левого поддерева
    int right_answer = node_depth(get_right(node), x); // из правого

    if (left_answer >= 0) return left_answer+1; // если нужный узел в левом поддереве
    else if (right_answer >= 0) return right_answer+1; // если в правом
    else return -1; // если ни в одном из них
}

int main() {
    int n, x;
    tree *root = NULL;
    
    cin >> n >> x;

    create_tree(root, n); // ввод и создание дерева

    print_preorder(root); // вывод дерева

    cout << endl << node_depth(root, x) << endl; // вывод

    return 0;
}