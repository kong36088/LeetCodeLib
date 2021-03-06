//
// Created by wellsjiang on 2017/6/29.
//

#ifndef C_CODE_VECTORGENERATOR_H
#define C_CODE_VECTORGENERATOR_H

#include <iostream>
#include <vector>
#include "lib/jsoncpp.cpp"

class VectorHelper {
public:
    /**
     * 根据输入生成vector数组
     * 例：["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
     *
     * @param input
     * @return 解析结果vector
     */
    static std::vector<std::string> generateString(std::string input) {
        Json::Value root;
        Json::Reader reader;
        if (!reader.parse(input, root, true)) {
            return std::vector<std::string>();
        }

        std::vector<std::string> result;
        if (root.isArray()) {
            for (int i = 0; i < root.size(); i++) {
                result.push_back(root[i].asString());
            }
        }
        return result;
    }

    static std::vector<int> generateInt(std::string input) {
        Json::Value root;
        Json::Reader reader;
        if (!reader.parse(input, root, true)) {
            return std::vector<int>();
        }

        std::vector<int> result;
        if (root.isArray()) {
            for (int i = 0; i < root.size(); i++) {
                result.push_back(root[i].asInt());
            }
        }
        return result;
    }


    /**
     * 遍历输出vector的值
     *
     * @param vec
     */
    static void traverse(std::vector<std::vector<std::string>> vec) {
        std::string output;
        output += '[';
        for (std::vector<std::string> s : vec) {
            output += '[';
            for (std::string x : s) {
                output += x + ',';
            }
            output += ']';
        }
        output += ']';

        std::cout << output << std::endl;
    }

    static void traverse(std::vector<std::string> vec) {
        std::string output;
        output += '[';
        for (std::string s : vec) {
            output += s + ',';
        }
        output += ']';

        std::cout << output << std::endl;
    }

    static void traverse(std::vector<int> vec) {
        std::string output;
        output += '[';
        for (int s : vec) {
            std::string tempString;
            StringUtils::int2str(s, tempString);
            output += tempString + ',';
        }
        output += ']';

        std::cout << output << std::endl;
    }

    /**
     * vector转换成string，根据分隔符切割字段
     *
     * @param vec
     * @return
     */
    static std::string toString(std::vector<std::string> vec, const std::string &delimiter) {
        std::string result;
        for (std::string value : vec) {
            result += value + delimiter;
        }

        return result;
    }
};

#endif //C_CODE_VECTORGENERATOR_H
