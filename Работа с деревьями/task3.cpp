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

// добавление элемента
void push(tree *&root, int x) {
    tree *temp = make_node(x);

    if (!root) root = temp; // если дерево пустое
    else {
        tree *current = root;

        while (current) { // рекурсивный поиск подходящего места для вставки
            if (temp->value < current->value) {
                if (!current->left) {
                    current->left = temp;
                    temp->parent = current;
                    break;
                }
                else current = current->left;
            } 
            else if (x > current->value) {
                if (!current->right) {
                    current->right = temp;
                    temp->parent = current;
                    break;
                }
                else current = current->right;
            }
        }
    }
}

// рекурсивный вывод дерева
void print_inorder(tree *root) {
    if (root) {
        print_inorder(root->left);

        cout << root->value << " ";
        
        print_inorder(root->right);
    }
}

// функция поиска элемента с заданным значением
tree *find(tree *root, int x) {
    if (!root || root->value == x) return root;
    else if (x < root->value) return find(root->left, x);
    else return find(root->right, x);
}

// минимум в дереве
tree *get_minimum(tree *root) {
    if (!root->left) return root;
    else return get_minimum(root->left);
}

// максимум в дереве
tree *get_maximum(tree *root) {
    if (!root->right) return root;
    else return get_maximum(root->right);
}

// получение предыдущего элемента относительно элемента с заданным значением
tree *get_previous(tree *root, int x) {
    tree *current = find(root, x);

    if (current->left) return get_maximum(current->left);
    else while (current->parent && current->parent->left == current) current = current->parent;

    return current->parent;
}

// аналогичная функция следующего элемента
tree *get_next(tree *root, int x) {
    tree *current = find(root, x);

    if (current->right) return get_minimum(current->right);
    else while (current->parent && current->parent->right == current) current = current->parent;

    return current->parent;
}

// функция удаления
void pop(tree *&root, tree *node) {
    if (!node->left && !node->right) { // нет детей
        if (!node->parent) root = NULL; // дерево из 1 узла
        else {
            if (node->parent->left == node) node->parent->left = NULL;
            else node->parent->right = NULL;
        }

        delete node;
    }
    else if (!node->left || !node->right) { // один сын
        if (!node->parent) { // удаляем корень с одним сыном
            if (node->left) {
                root = node->left;
                node->left->parent = NULL;
            }
            else {
                root = node->right;
                node->right->parent = NULL;
            }
        }
        else {
            tree *grandson = new tree; // сын удаляемого элемента
            if (node->left) grandson = node->left;
            else grandson = node->right;

            if (node->parent->left == node) {
                node->parent->left = grandson;
                grandson->parent = node->parent;
            }
            else {
                node->parent->right = grandson;
                grandson->parent = node->parent;
            }
        }

        delete node;
    }
    else { // если два сына
        tree *previous = get_next(root, node->value); // поиск предыдущего. У него не будет правого сына
        swap(node->value, previous->value); // свап значений

        if (previous->parent->left == previous) previous->parent->left = previous->left; // если предыдущий является левым сыном
        else previous->parent->right = previous->left; // если правым
        
        if (previous->left) previous->left->parent = previous->parent; // если у предыдущего имеется сын

        delete previous;
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

// подсчёт количества узлов с левым сыном
int has_left(tree *node) {
    if (!node) return 0;
    else return (get_left(node)?1:0)+has_left(get_left(node))+has_left(get_right(node)); // рекурсивный подсчёт
}

int main() {
    int n, x;
    tree *root = NULL;
    
    cin >> n;

    for (int i = 0; i < n; i++) { // ввод дерева
        cin >> x;
        push(root, x);
    }

    print_inorder(root); // вывод дерева

    cout << endl << has_left(root) << root->value << endl; // вывод

    return 0;
}