#include <iostream>

using namespace std;

// дерево
struct tree {
    int value;
    tree *parent;
    tree *left;
    tree *right;
};

// функция создания узла
tree *make_node(int x) {
    tree *temp = new tree;
  
    temp->value = x;
    temp->parent = NULL;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// создание сбалансированного дерева
void create_tree(tree *&root, int n) {
    if (n > 0) {
        int x;
        cin >> x;

        root = make_node(x);

        int left_subtree = n/2;
        int right_subtree = n - left_subtree - 1;

        create_tree(root->left, left_subtree); // рекурсивное создание левого
        create_tree(root->right, right_subtree); // и правого поддеревьев
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

// геттер родителя
tree *get_parent(tree *node) {
    return node->parent;
}

// геттер значения узла
int get_value(tree *node) {
    return node->value;
}

// реализация дерева закончилась
//============================================================================================

// подсчёт количества листьев
int leaves_count(tree *node) {
    if (node) { // если узел существует
        if (!get_left(node) && !get_right(node)) return 1; // если узел является листом
        else return leaves_count(get_left(node))+leaves_count(get_right(node)); // если есть хотя бы один сын
    }
    else return 0; // если узла не существует
}

int main() {
    int n;
    tree *root = NULL;
    
    cin >> n;

    create_tree(root, n); // ввод и создание дерева

    print_preorder(root); // вывод дерева

    cout << endl << leaves_count(root) << endl; // вывод

    return 0;
}