import stack;
import <string>;
import <print>;
import tree;

int main () {
	std::println ("Learn data structure");
	std::string s{ "{([])}" };
	if (isValidParentheses (s)) {
		std::println ("Success");
	}
	else std::println ("Failure");

	// 手动创建二叉树用于测试中序线索化
	// 构造如下二叉树：
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5
	ThreadTree* n1 = new ThreadTree{1, nullptr, nullptr, 0, 0};
	ThreadTree* n2 = new ThreadTree{2, nullptr, nullptr, 0, 0};
	ThreadTree* n3 = new ThreadTree{3, nullptr, nullptr, 0, 0};
	ThreadTree* n4 = new ThreadTree{4, nullptr, nullptr, 0, 0};
	ThreadTree* n5 = new ThreadTree{5, nullptr, nullptr, 0, 0};

	n1->left = n2; n1->right = n3;
	n2->left = n4; n2->right = n5;

	// 创建中序线索
	create_in_thread(n1);

	// 使用线索进行中序遍历并打印
	ThreadTree* cur = n1;
	// 找到最左节点
	while (cur->l_tag == 0 && cur->left != nullptr) cur = cur->left;
	std::println ("In-order threaded traversal:");
	while (cur != nullptr) {
		std::println ("{}", cur->data);
		if (cur->r_tag == 1) {
			cur = cur->right; // 线索指向后继
		} else {
			// 否则进入右子树并到达最左节点
			cur = cur->right;
			while (cur != nullptr && cur->l_tag == 0 && cur->left != nullptr) cur = cur->left;
		}
	}

	std::println ("测试结束");
	return 0;
}