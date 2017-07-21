//
// Created by JIANGWEILONGGGG on 2017/6/25.
//

#ifndef C_CODE_UTILS_H
#define C_CODE_UTILS_H

#define LEFTSTRIP 0
#define RIGHTSTRIP 1
#define BOTHSTRIP 2

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

class StringUtils {
public:
    /**
     * 把字符串按照所需的字符分割成为数组
     *
     * @param s 源字符串
     * @param v 目标变量，结果存放位置
     * @param c 需要切割的字符
     */
    static void split(const std::string &s, std::vector<std::string> &v, const std::string &c) {
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

    /**
     * trim两边指定字符
     *
     * @param str 待处理字符串
     * @param striptype 指定要处理哪一边，LEFTSTRIP、RIGHTSTRIP、BOTHSTRIP
     * @param chars 要去除的字符
     * @return
     */
    static std::string trim(const std::string &str, int striptype, const std::string &chars = " \n\r\t") {
        std::string::size_type strlen = str.size();
        std::string::size_type charslen = chars.size();
        std::string::size_type i, j;

        //默认情况下，去除空白符
        if (0 == charslen) {
            i = 0;
            //去掉左边空白字符
            if (striptype != RIGHTSTRIP) {
                while (i < strlen && ::isspace(str[i])) {
                    i++;
                }
            }
            j = strlen;
            //去掉右边空白字符
            if (striptype != LEFTSTRIP) {
                j--;
                while (j >= i && ::isspace(str[j])) {
                    j--;
                }
                j++;
            }
        } else {
            //把删除序列转为c字符串
            const char *sep = chars.c_str();
            i = 0;
            if (striptype != RIGHTSTRIP) {
                //memchr函数：从sep指向的内存区域的前charslen个字节查找str[i]
                while (i < strlen && memchr(sep, str[i], charslen)) {
                    i++;
                }
            }
            j = strlen;
            if (striptype != LEFTSTRIP) {
                j--;
                while (j >= i && memchr(sep, str[j], charslen)) {
                    j--;
                }
                j++;
            }
            //如果无需要删除的字符
            if (0 == i && j == strlen) {
                return str;
            } else {
                return str.substr(i, j - i);
            }
        }
    }

    /**
     * string转int
     *
     * @param int_temp 存放变量
     * @param string_temp 源变量
     */
    static void str2int(int &int_temp, const std::string &string_temp) {
        std::stringstream stream(string_temp);
        stream >> int_temp;
    }

    /**
     * int 转int
     *
     * @param int_temp 源变量
     * @param string_temp 存放变量
     */
    static void int2str(const int &int_temp, std::string &string_temp) {
        std::stringstream stream;
        stream << int_temp;
        string_temp = stream.str();   //此处也可以用 stream>>string_temp
    }

    static void reverse(std::string &source) {
        if (source.length() < 2) {
            return;
        }
        int length = source.length();
        int distance = length / 2;
        for (int i = 0; i < distance; i++) {
            std::swap(source[i], source[length - i - 1]);
        }
    }

    static void reverse(std::string &source, int start, int end) {
        int length = end - start + 1;
        int distance = length / 2;
        if (length < 2) {
            return;
        }
        for (int i = 0; i < distance; i++) {
            std::swap(source[i + start], source[end - i]);
        }
    }
};


#endif //C_CODE_UTILS_H
