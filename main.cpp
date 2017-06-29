#include <iostream>
#include <unordered_map>
#include "StringUtils.h"
#include "BinaryTree.h"
#include "VectorHelper.h"

using namespace std;

void split(const std::string &s, std::vector<std::string> &v, const std::string &c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        unordered_map<string, vector<string>> resultMap;
        vector<vector<string>> result;

        for (string path :paths) {
            vector<string> pathArr;
            split(path, pathArr, " ");
            string pathRoot = pathArr[0] + '/';

            //遍历所有文件
            for (int i = 1; i < pathArr.size(); i++) {
                string fileName = pathArr[i].substr(0, pathArr[i].find('('));
                string content = pathArr[i].substr(pathArr[i].find('(') + 1, pathArr[i].find(')'));
                if (resultMap.find(content) != resultMap.end()) {
                    resultMap[content].push_back(pathRoot + fileName);
                } else {
                    resultMap[content] = vector<string>({pathRoot + fileName});
                }
            }
            cout << endl;

        }

        unordered_map<string, vector<string>>::iterator it = resultMap.begin();
        for (int i = 0; it != resultMap.end(); it++, i++) {
            if ((*it).second.size() < 2) {
                continue;
            }
            result.push_back((*it).second);
        }
        //VectorHelper::traverse(result);

        return result;

    }
};


int main() {
    string test = "[1,2,3,4,5,6,7,8,9,null,10,11,null,12]";
    TreeNode root(test);

    string t1String = "[1,2,3,4]";
    string t2String = "[2,1,3,null,4,null,7]";
    string t3String = "[1,2,3,null,4]";
    TreeNode t1(t1String);
    TreeNode t2(t2String);
    TreeNode t3(t3String);
    TreeNode *t4 = new TreeNode(t3String);

    vector<vector<int>> testVec;
    testVec.push_back(vector<int>(1, 2));
    testVec.push_back(vector<int>(3, 4));
    Solution *s = new Solution();

    auto result = VectorHelper::generate<string>(
            "[\"root/a 1.txt(abcd) 2.txt(efgh)\",\"root/c 3.txt(abcd)\",\"root/c/d 4.txt(efgh)\",\"root 4.txt(efgh)\"]");
    for (string x : result) {
        cout << x << " 1" << endl;
    }
    cout << endl;
    vector<vector<string>> r = s->findDuplicate(result);

    t4->destroy();
    delete s;

}