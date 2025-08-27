#include <iostream>
#include <queue>
using namespace std;

// Template Node class for BST
template<typename T>
class TreeNodeBst {
private:
    T data;
    TreeNodeBst<T>* left;
    TreeNodeBst<T>* right;

public:
    // Constructor
    TreeNodeBst(T value) : data(value), left(nullptr), right(nullptr) {}

    // Destructor
    ~TreeNodeBst() {}

    // Getter methods
    T getData() const { return data; }
    TreeNodeBst<T>* getLeft() const { return left; }
    TreeNodeBst<T>* getRight() const { return right; }

    // Setter methods
    void setData(T value) { data = value; }
    void setLeft(TreeNodeBst<T>* node) { left = node; }
    void setRight(TreeNodeBst<T>* node) { right = node; }

    // Friend class to allow BST to access private members
    template<typename U>
    friend class BST;
};

template<typename T>
class BST {
private:
    TreeNodeBst<T>* root;

    // Helper function for insertion
    TreeNodeBst<T>* insertHelper(TreeNodeBst<T>* node, T value) {
        if (node == nullptr) {
            return new TreeNodeBst<T>(value);
        }

        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }
        // If value equals node->data, we don't insert (no duplicates)

        return node;
    }

    // Helper function for search
    bool searchHelper(TreeNodeBst<T>* node, T value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

    // Helper function for deletion
    TreeNodeBst<T>* deleteHelper(TreeNodeBst<T>* node, T value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteHelper(node->left, value);
        } else if (value > node->data) {
            node->right = deleteHelper(node->right, value);
        } else {
            // Node to be deleted found

            // Case 1: Node with only right child or no child
            if (node->left == nullptr) {
                TreeNodeBst<T>* temp = node->right;
                delete node;
                return temp;
            }
            // Case 2: Node with only left child
            else if (node->right == nullptr) {
                TreeNodeBst<T>* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Node with two children
            // Find inorder successor (smallest in right subtree)
            TreeNodeBst<T>* temp = findMin(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = deleteHelper(node->right, temp->data);
        }
        return node;
    }

    // Find minimum value node
    TreeNodeBst<T>* findMin(TreeNodeBst<T>* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Find maximum value node
    TreeNodeBst<T>* findMax(TreeNodeBst<T>* node) {
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Helper for inorder traversal
    void inorderHelper(TreeNodeBst<T>* node) {
        if (node != nullptr) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    // Helper for preorder traversal
    void preorderHelper(TreeNodeBst<T>* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    // Helper for postorder traversal
    void postorderHelper(TreeNodeBst<T>* node) {
        if (node != nullptr) {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
        }
    }

    // Helper to calculate height
    int heightHelper(TreeNodeBst<T>* node) {
        if (node == nullptr) {
            return -1;
        }
        return max(heightHelper(node->left), heightHelper(node->right)) + 1;
    }

    // Helper to count nodes
    int countHelper(TreeNodeBst<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countHelper(node->left) + countHelper(node->right);
    }

    // Helper for destroying tree (cleanup)
    void destroyTree(TreeNodeBst<T>* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Destructor
    ~BST() {
        destroyTree(root);
    }

    // Public interface functions
    void insert(T value) {
        root = insertHelper(root, value);
    }

    bool search(T value) {
        return searchHelper(root, value);
    }

    void remove(T value) {
        root = deleteHelper(root, value);
    }

    void inorderTraversal() {
        cout << "Inorder: ";
        inorderHelper(root);
        cout << endl;
    }

    void preorderTraversal() {
        cout << "Preorder: ";
        preorderHelper(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Postorder: ";
        postorderHelper(root);
        cout << endl;
    }

    void levelOrderTraversal() {
        if (root == nullptr) {
            cout << "Level order: (empty)" << endl;
            return;
        }

        cout << "Level order: ";
        queue<TreeNodeBst<T>*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNodeBst<T>* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }

    int height() {
        return heightHelper(root);
    }

    int count() {
        return countHelper(root);
    }

    T findMinValue() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty!");
        }
        return findMin(root)->data;
    }

    T findMaxValue() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty!");
        }
        return findMax(root)->data;
    }

    bool isEmpty() {
        return root == nullptr;
    }
};

// Function to display menu
void displayMenu() {
    cout << "\n=== Template Binary Search Tree Operations ===" << endl;
    cout << "1. Insert a value" << endl;
    cout << "2. Search for a value" << endl;
    cout << "3. Delete a value" << endl;
    cout << "4. Inorder Traversal" << endl;
    cout << "5. Preorder Traversal" << endl;
    cout << "6. Postorder Traversal" << endl;
    cout << "7. Level Order Traversal" << endl;
    cout << "8. Find Minimum" << endl;
    cout << "9. Find Maximum" << endl;
    cout << "10. Tree Height" << endl;
    cout << "11. Count Nodes" << endl;
    cout << "12. Check if Empty" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to demonstrate different data types
void demonstrateTemplates() {
    cout << "\n=== Template BST Demonstration ===" << endl;

    // Integer BST
    cout << "\n--- Integer BST ---" << endl;
    BST<int> intTree;
    intTree.insert(50);
    intTree.insert(30);
    intTree.insert(70);
    intTree.insert(20);
    intTree.insert(40);
    intTree.insert(60);
    intTree.insert(80);
    intTree.inorderTraversal();

    // Double BST
    cout << "\n--- Double BST ---" << endl;
    BST<double> doubleTree;
    doubleTree.insert(3.14);
    doubleTree.insert(2.71);
    doubleTree.insert(4.5);
    doubleTree.insert(1.41);
    doubleTree.insert(3.0);
    doubleTree.inorderTraversal();

    // Character BST
    cout << "\n--- Character BST ---" << endl;
    BST<char> charTree;
    charTree.insert('m');
    charTree.insert('h');
    charTree.insert('s');
    charTree.insert('d');
    charTree.insert('k');
    charTree.insert('p');
    charTree.insert('x');
    charTree.inorderTraversal();

    // String BST
    cout << "\n--- String BST ---" << endl;
    BST<string> stringTree;
    stringTree.insert("dog");
    stringTree.insert("cat");
    stringTree.insert("elephant");
    stringTree.insert("ant");
    stringTree.insert("bear");
    stringTree.insert("fish");
    stringTree.inorderTraversal();
}

int main() {
    cout << "Welcome to Template Binary Search Tree Implementation!" << endl;

    // Show template demonstration
    demonstrateTemplates();

    // Interactive menu for integer BST
    BST<int> tree;
    int choice, value;

    cout << "\nNow you can interact with an Integer BST:" << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter integer value to insert: ";
            cin >> value;
            tree.insert(value);
            cout << "Value " << value << " inserted successfully!" << endl;
            break;

        case 2:
        {
            cout << "Enter multiple integer values to insert:" << endl;
            cout << "Options:" << endl;
            cout << "  A) Enter count first, then values" << endl;
            cout << "  B) Enter values continuously (enter -999 to stop)" << endl;
            cout << "Choose option (A/B): ";
            char option;
            cin >> option;

            if (option == 'A' || option == 'a') {
                int count;
                cout << "How many values do you want to insert? ";
                cin >> count;
                cout << "Enter " << count << " values: ";
                for (int i = 0; i < count; i++) {
                    cin >> value;
                    tree.insert(value);
                    cout << "Inserted: " << value << endl;
                }
                cout << "Successfully inserted " << count << " values!" << endl;
            } else if (option == 'B' || option == 'b') {
                cout << "Enter values (enter -999 to stop): ";
                int insertCount = 0;
                while (true) {
                    cin >> value;
                    if (value == -999) {
                        break;
                    }
                    tree.insert(value);
                    cout << "Inserted: " << value << endl;
                    insertCount++;
                }
                cout << "Successfully inserted " << insertCount << " values!" << endl;
            } else {
                cout << "Invalid option!" << endl;
            }
        }
        break;

        case 3:
            cout << "Enter integer value to search: ";
            cin >> value;
            if (tree.search(value)) {
                cout << "Value " << value << " found in the tree!" << endl;
            } else {
                cout << "Value " << value << " not found in the tree!" << endl;
            }
            break;

        case 4:
            cout << "Enter integer value to delete: ";
            cin >> value;
            if (tree.search(value)) {
                tree.remove(value);
                cout << "Value " << value << " deleted successfully!" << endl;
            } else {
                cout << "Value " << value << " not found in the tree!" << endl;
            }
            break;

        case 5:
            tree.inorderTraversal();
            break;

        case 6:
            tree.preorderTraversal();
            break;

        case 7:
            tree.postorderTraversal();
            break;

        case 8:
            tree.levelOrderTraversal();
            break;

        case 9:
            if (!tree.isEmpty()) {
                try {
                    cout << "Minimum value: " << tree.findMinValue() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
            } else {
                cout << "Tree is empty!" << endl;
            }
            break;

        case 10:
            if (!tree.isEmpty()) {
                try {
                    cout << "Maximum value: " << tree.findMaxValue() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
            } else {
                cout << "Tree is empty!" << endl;
            }
            break;

        case 11:
            cout << "Tree height: " << tree.height() << endl;
            break;

        case 12:
            cout << "Number of nodes: " << tree.count() << endl;
            break;

        case 13:
            if (tree.isEmpty()) {
                cout << "Tree is empty!" << endl;
            } else {
                cout << "Tree is not empty!" << endl;
            }
            break;

        case 0:
            cout << "Thank you for using Template BST! Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }

    return 0;
}