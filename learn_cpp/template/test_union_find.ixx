export module test_union_find;
import union_find;
import <iostream>;
import <cassert>;
import <set>;

export namespace test_union_find {

    // 辅助函数：打印测试结果
    void print_test_result (const std::string& test_name, bool passed) {
        std::cout << "[" << (passed ? "PASS" : "FAIL") << "] " << test_name << "\n";
    }

    // 测试 1: 基本构造和独立性
    bool test_construction_and_isolation () {
        try {
            UnionFind uf (5);
            // 初始状态下，每个节点都是自己的根，且互不连通
            for (int i = 0; i < 5; ++i) {
                if (uf.find (i) != i) return false;
            }
            // 检查连通性
            for (int i = 0; i < 5; ++i) {
                for (int j = i + 1; j < 5; ++j) {
                    // 注意：原版 UnionFind 没有 connected 方法
                    // 我们用 find 来模拟
                    if (uf.find (i) == uf.find (j)) return false;
                }
            }
            return true;
        }
        catch (...) {
            return false;
        }
    }

    // 测试 2: 简单合并
    bool test_simple_unite () {
        UnionFind uf (4); // {0}, {1}, {2}, {3}

        uf.unite (0, 1); // {0,1}, {2}, {3}
        uf.unite (2, 3); // {0,1}, {2,3}

        // 0和1应该连通
        bool c1 = (uf.find (0) == uf.find (1));
        // 2和3应该连通
        bool c2 = (uf.find (2) == uf.find (3));
        // {0,1} 和 {2,3} 应该不连通
        bool c3 = (uf.find (0) != uf.find (2));

        return c1 && c2 && c3;
    }

    // 测试 3: 复杂合并和路径压缩
    bool test_complex_unite_and_path_compression () {
        UnionFind uf (10); // {0}...{9}

        // 创建链式结构: 0-1-2-3-4
        for (int i = 0; i < 4; ++i) {
            uf.unite (i, i + 1);
        }
        // 此时, 0,1,2,3,4 应在一个集合中
        int root_0 = uf.find (0);
        for (int i = 1; i <= 4; ++i) {
            if (uf.find (i) != root_0) return false;
        }

        // 再创建另一条链: 5-6-7-8-9
        for (int i = 5; i < 9; ++i) {
            uf.unite (i, i + 1);
        }
        // 5,6,7,8,9 应在一个集合中
        int root_5 = uf.find (5);
        for (int i = 6; i <= 9; ++i) {
            if (uf.find (i) != root_5) return false;
        }

        // 两组之间应不连通
        if (uf.find (0) == uf.find (5)) return false;

        // 连接两条链
        uf.unite (4, 5); // {0-1-2-3-4-5-6-7-8-9}

        // 现在所有点都应该连通
        int final_root = uf.find (0);
        for (int i = 1; i < 10; ++i) {
            if (uf.find (i) != final_root) return false;
        }

        // 路径压缩测试：多次查找根节点，确保效率
        // 这很难直接断言，但可以通过根节点一致性来间接验证
        int root_after_compression = uf.find (3);
        if (root_after_compression != final_root) return false;

        return true;
    }


    // 测试 4: 边界情况 - 单个元素
    bool test_single_element () {
        UnionFind uf (1);
        return uf.find (0) == 0;
    }

    // 测试 5: [[nodiscard]] 属性 (编译时检查)
    // 注意：这个测试主要看编译器是否会给出警告
    // 我们在代码中故意忽略返回值来触发警告
    void test_nodiscard_attribute () {
        UnionFind uf (5);
        // 下面这行（如果取消注释）在支持 [[nodiscard]] 的编译器上应该产生警告
        // uf.find(1); // Expected warning: ignoring return value
        // 为了测试通过，我们使用返回值
        [[maybe_unused]] auto r = uf.find (1); // 使用 [[maybe_unused]] 压制未使用变量警告
    }


    // 主测试入口
    void run_all_tests () {
        std::cout << "Running UnionFind tests...\n\n";

        print_test_result ("Construction and Isolation", test_construction_and_isolation ());
        print_test_result ("Simple Unite", test_simple_unite ());
        print_test_result ("Complex Unite and Path Compression", test_complex_unite_and_path_compression ());
        print_test_result ("Single Element", test_single_element ());

        test_nodiscard_attribute (); // 编译时检查
        std::cout << "[INFO] Nodiscard attribute test compiled. Check compiler warnings if expected.\n";

        std::cout << "\nAll tests completed.\n";
    }

} // namespace test_union_find
