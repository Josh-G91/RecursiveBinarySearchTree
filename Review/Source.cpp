#include <iostream>;
#include <vector>;
#include <set>;
#include <iterator>;
using namespace std;

struct TreeNode {

	int value;
	TreeNode* left;
	TreeNode* right;

};
class Tree {
private:
	TreeNode* root;
public:
	Tree() {
		root = NULL;
	}
	~Tree() {
		delete root;
	}
	

	void Insert(TreeNode* tNode, int val) {
		TreeNode* temp = root;
		if (treeEmpty()) {
			tNode->value = val;
			root = tNode;
		}
		else {
			while (temp != NULL) {
				if (val < temp->value) {
					if (temp->left == NULL) {
						tNode->value = val;
						temp->left = tNode;
						return;
					}
					else {
						temp = temp->left;
					}
				}
				else if (val >= temp->value) {

					if (temp->right == NULL) {
						tNode->value = val;
						temp->right = tNode;
						return;
					}
					else {
						temp = temp->right;
					}
				}
			}
		}
	}
	bool treeEmpty() {
		return root == NULL;
	}

    void lookUp(int n) {

		TreeNode* sub = root;
		bool flag = true;
		while (flag) {
			
			if (sub->value == n) {
				cout << "found value in Tree\n";
				flag = false;
			}
			else if (n >= sub->value) {
				sub = sub->right;
				if (sub == NULL) {
					cout << "value not in Tree" << endl;
					flag = false;
				}
			}
			else{
				sub = sub->left;
				if (sub == NULL) {
					cout << "value not in Tree" << endl;
					flag = false;
				}
			}
			
		}
	}
};

struct TreeNode* createNode(int data) {
	TreeNode* node = new TreeNode;
	node->value = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
struct TreeNode* recInsert(TreeNode* node, int data) {
	// 1. If the tree is empty, return a new, single node
	if (node == NULL) {
		return createNode(data);
	}
	else {
		// 2. Otherwise, recur down the tree
		if (data <= node->value) node->left = recInsert(node->left, data);
		else node->right = recInsert(node->right, data);
		return node; // return the (unchanged) node pointer
	}
}
void recLookup(TreeNode* root, int n) {

	if (root == NULL) {
	cout << "Value not found" << endl;
	return;
	}
	else if (n == root->value) cout << "Value found." << endl;
	else if (n <= root->value) recLookup(root->left, n);
	else recLookup(root->right, n);
	

}
int sizeRight(TreeNode* node) {
	if (node == NULL) return 0;
	else { return 1 + sizeRight(node->right); }
	
}
int sizeLeft(TreeNode* node) {
	if (node == NULL) return 0;
	else { return 1 + sizeLeft(node->left); }

}
int size(TreeNode* node) {
	if (node == NULL) return 0;
	else { return 1 + size(node->right) + size(node->left); }

}
void maxDepth(TreeNode* node) {
	int left = sizeLeft(node->left);
	int right = sizeRight(node->right); 
	
	if (left > right) cout << "Max Depth is: " << left << "\n";
	else cout << "Max Depth is: " << right << "\n";

}
int minValue(TreeNode* node) {
	if (node->left == NULL) return node->value;
	else return minValue(node->left);
}
void printTree(TreeNode* node) {
	if (node->left == NULL) cout << (node->value) << "\n";
	else if (node->right == NULL) cout << node->value << "\n";
	else {
		printTree(node->left);
		cout << node->value << "\n";
		printTree(node->right);
	}
}
void printPostorder(TreeNode* node) {
	if (node->left == NULL) cout << (node->value) << "\n";
	else if (node->right == NULL) cout << node->value << "\n";
	else {
		printPostorder(node->left);
		printPostorder(node->right);
		cout << node->value << "\n";
	}
}
int leftpath(TreeNode* node) {
	if (node != NULL) return node->value + leftpath(node->left);
	else return 0;
	
}
int rightpath(TreeNode* node) {
	if (node != NULL) return node->value + rightpath(node->right);
	//if (node->left != NULL) return node->value + rightpath(node->left);
	else return 0;
	
}
int left_right(TreeNode* node) {
	
	if (node != NULL) return node->value + left_right(node->right);
	
	else return 0;
}
int right_left(TreeNode* node) {

	if (node != NULL) return node->value + right_left(node->left);
	else return 0;
}
bool hasPathSum(TreeNode* root, int sum) {

	if (leftpath(root) == sum) return true;
	else if (rightpath(root) == sum) return true;
	else if ((root->value + left_right(root->left)) == sum) return true;
	else if ((root->value + right_left(root->right)) == sum) return true;
	else return false;

}

void primeFactors(int &n) {

	vector<int> list_primes;

	int k = 2;
	int q = 1;
	if (n == 2) {
		cout << n << endl;
		exit(1);

	}
	while (n != k) {

		if (n % k == 0) {
			list_primes.push_back(k);
			q = n / k;
			n = q;
		}

		if (n % k != 0) {
			k++;
		}

		if (n == k) {
			list_primes.push_back(k);
		}
	}

	for (int num : list_primes) {
		std::cout << num << " ";
	}

}
void sieve_of_eratosthenes(int arr[], int lim) {
	set<int> marked;
	vector<int> list_primes;
	int x = 0;
	for (int i = 0; i < lim-1; i++) {
		x = arr[i];

		if (marked.count(x)) {
			continue;
		}
		else {
			list_primes.push_back(x);
		}

		for (int n = 2; n < lim; n++) {
			marked.insert(n * x);
			if (n * x > lim) {
				break;
			}
		}
		
	}

	for (int num : list_primes) {
		cout << num << " ";
	}

}

int main() {


	TreeNode* root;
	root = recInsert(NULL , 4);
	root = recInsert(root, 2);
	root = recInsert(root, 5);
	root = recInsert(root, 1);
	root = recInsert(root, 3);


	printPostorder(root);
	bool t = hasPathSum(root, 8);
	cout << t << endl;
	

	

	

	/*int arr[29] = {}; // n-1
	
	int k = 2;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i] = k;
		k++;
	}
	int limit = arr[28];
	sieve_of_eratosthenes(arr, limit);
	*/




}