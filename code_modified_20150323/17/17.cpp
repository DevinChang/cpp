#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    // 查找不在字符c之后的字符串ei
    string pattern("[^c]ei");
    // 我们需要包含pattern的整个单词
  	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase); 	// 构造一个用于查找模式的regex
    smatch results; 		// 定义一个对象保存搜索结果
    // 定义一个string保存与模式匹配和不匹配的文本
    string line;
    while (1)
    {
    		cout << "Enter a word, or q to quit:";
    		getline(cin, line);
        if (line == "q")
        {
            break;
        }

    		// 它将反复调用 regex_search 来寻找文件中的所有匹配
    		for (sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it)
        {
    		  	cout << it->str() << endl; // 匹配的单词
        }
    }

  	return 0;
}
