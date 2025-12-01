import stack;
import <string>;
import <print>;
//import <vector>;
//import <format>;
int main () {
	std::println ("Learn data structure");
	std::string s{ "{([])}" };
	if (isValidParentheses (s)) {
		std::println ("Success");
	}
	else std::println ("Failure");
	std::println ("你好世界");
	return 0;

	//std::vector<int> nums{12,23,45};
	//std::println ("hello c++23");
	//for (auto& item : nums) {
	//	std::println ("{}",item);
	//}
	//for (auto item = nums.begin (); item != nums.end (); ++item) {
	//	std::println ("{2}", item);
	//}
	//auto hello = "hello cpp";
	//auto str = std::format ("你好世界，{}",hello);
	//std::println ("{:a>20}",str);
	return 0;
}