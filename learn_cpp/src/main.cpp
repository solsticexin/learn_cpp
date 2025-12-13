import stack;
import tree;
import test_union_find;
import <string>;
import <print>;


void test1() {
	const std::string s{ "{([])}" };
	if (is_valid_parentheses (s)) {
		std::println ("Success");
	}
	else std::println ("Failure");
}
void test2() {
	// 手动创建二叉树用于测试中序线索化
	// 构造如下二叉树：
	//       1
	//      / \
	//     2   3
	//    / \
	//   4   5
	auto* n1 = new ThreadTree{ 1, nullptr, nullptr, 0, 0 };
	auto* n2 = new ThreadTree{ 2, nullptr, nullptr, 0, 0 };
	auto* n3 = new ThreadTree{ 3, nullptr, nullptr, 0, 0 };
	auto* n4 = new ThreadTree{ 4, nullptr, nullptr, 0, 0 };
	auto* n5 = new ThreadTree{ 5, nullptr, nullptr, 0, 0 };

	n1->left = n2; n1->right = n3;
	n2->left = n4; n2->right = n5;

	// 创建中序线索
	create_in_thread (n1);

	// 使用线索进行中序遍历并打印
	ThreadTree* cur = n1;
	// 找到最左节点
	while (cur->l_tag == 0 && cur->left != nullptr) cur = cur->left;
	std::println ("In-order threaded traversal:");
	while (cur != nullptr) {
		std::println ("{}", cur->data);
		if (cur->r_tag == 1) {
			cur = cur->right; // 线索指向后继
		}
		else {
			// 否则进入右子树并到达最左节点
			cur = cur->right;
			while (cur != nullptr && cur->l_tag == 0 && cur->left != nullptr) cur = cur->left;
		}
	}

	std::println ("测试结束");
}
int main () {
	std::println ("Learn data structure");
	test_union_find::run_all_tests ();
	// test1 ();
	// test2 ();
	return 0;
}