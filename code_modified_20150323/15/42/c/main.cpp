#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <vector>

using std::set;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector; using std::array;

int main(int argc, char **argv)
{
    // gets file to read and builds map to support queries
    TextQuery file = get_file(argc, argv);
    vector<array<string, 3>> h;

    // iterate with the user: prompt for a word to find and print results
    while (true)
    {
        string sought1, sought2, sought3;
        if (!get_word(sought1))
        {
            break;
        }

        if (sought1 != "h")
        {
            cout << "\nenter second and third words: " ;
            cin  >> sought2 >> sought3;
            // find all the occurrences of the requested string
            Query q = (Query(sought1) & Query(sought2)) | Query(sought3);
            h.push_back({sought1, sought2, sought3});
            cout << "\nExecuting Query for: " << q << endl;
            const auto results = q.eval(file);
            // report matches
            print(cout, results);
        }
        else        // 用户输入了"h"，表示要提取历史查询
        {
            cout << "\nenter Query no.: ";
            int i;
            cin >> i;
            if (i < 1 || i > h.size())    // 历史编号合法性检查
            {
                cout << "\nBad Query no." << endl;
            }
            else
            {
                // 提取三个查询词，重构查询
                Query q = (Query(h[i-1][0]) & Query(h[i-1][1])) | Query(h[i-1][2]);;
                cout << "\nExecuting Query for: " << q << endl;
                const auto results = q.eval(file);
                // report matches
                print(cout, results);
            }
        }
    }
    return 0;
}
