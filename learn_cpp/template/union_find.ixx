export module union_find;
import <vector>;
//constexpr auto Size = 13;; 
//int UFSets[Size]{};
//void initial (int x[]) {
//	for (auto uf_set : UFSets) {
//		uf_set = -1;
//	}
//}
//int find(int s[],int x) {
//	int root{ x };
//	while (root > -1) {
//		root = s[x];
//	}
//	while (x!=root) {
//		int t = s[x];
//		s[x] = root;
//		x = t;
//	}
//	return root;
//}
//void unite(int s[],const int root1,const int root2) {
//	if (root1 == root2) return;
//	if (s[root1] >= s[root2])
//		s[root2] = root1;
//	else s[root1] = root2;
//}

export class UnionFind {
	std::vector<int> parent;
public:
	explicit UnionFind (const size_t size) :parent (size, -1){}
	[[nodiscard("This result is critical for correctness")]] 
	auto find(int x) -> int;
	void unite (int x1, int x2);
};

int UnionFind::find(int x) {
	if (parent[x] < 0) return x;
	int root{ x };
	while (parent[root] >=0) {
		root = parent[root];
	}
	while (x!=root) {
		const auto next{ parent[x] };
		parent[x] = root;
		x = next;
	}
	return root;
}

void UnionFind::unite(const int x1, const int x2) {
	const auto root1 { find (x1)}; 
	const auto root2{ find (x2) };
	if (root1==root2) return;
	if (parent[root1] > parent[root2]) { //这里是负数比较 -2 > -3, 
		parent[root2] += parent[root1];
		parent[root1] = root2;
	}else {
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}
}
