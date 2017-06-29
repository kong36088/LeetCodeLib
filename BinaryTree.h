//
// Created by JIANGWEILONGGGG on 2017/6/25.
//

#ifndef C_CODE_BINARYTREE_H
#define C_CODE_BINARYTREE_H

#include <iostream>
#include <queue>
#include "StringUtils.h"
#include <cmath>
#include <stack>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    int len = 0;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    /**
     * 构造函数生成树结构，例:[1,2,3,4,null,5,6]
     *
     * @param nodeString
     */
    TreeNode(std::string nodeString) {

        std::vector<std::string> nodesValue;
        std::vector<TreeNode *> nodes;

        // 字符串初始化处理
        nodeString = StringUtils::trim(nodeString, BOTHSTRIP, "[]");
        StringUtils::split(nodeString, nodesValue, ",");

        int len = nodesValue.size();
        int indexCurr = 1;
        // 初始化根节点
        StringUtils::str2int(this->val, nodesValue[0]);
        this->left = NULL;
        this->right = NULL;
        nodes.push_back(this);

        while (indexCurr < len) {
            TreeNode *newNode = NULL;
            // 节点非空则初始化
            if (nodesValue[indexCurr] != "null") {
                int tempValue = 0;
                StringUtils::str2int(tempValue, nodesValue[indexCurr]);
                newNode = new TreeNode(tempValue);
            }

            // 父节点为空则抛出错误退出程序
            if (nodes[(indexCurr - 1) / 2] == NULL) {
                std::cout << std::endl << "father point is null, indexCurr is :" << indexCurr;
                exit(1);
            }
            if (indexCurr & 1) {
                nodes[indexCurr / 2]->left = newNode;
            } else {
                nodes[(indexCurr - 1) / 2]->right = newNode;
            }
            nodes.push_back(newNode);
            indexCurr++;
        }

        this->len = len;
    }

    /**
     * 遍历所有节点
     */
    void traverse() {
        genNodesNum();

        std::queue<TreeNode *> nodeQueue;
        TreeNode *curr = NULL;
        int counter = 0; // 每层个数
        int trigger = 1; // 换行触发器
        int level = (int) ceil(log(this->len + 1)); // 层数


        // 层级遍历
        printSpace(level);
        nodeQueue.push(this);
        while (!nodeQueue.empty()) {
            curr = nodeQueue.front();
            nodeQueue.pop();

            if (curr != NULL) {
                std::cout << curr->val;
            } else {
                std::cout << 'n';
            }
            printSpace(1);

            counter++;
            if (counter == trigger) {
                std::cout << std::endl;
                trigger *= 2;
                counter = 0;
                // 打印空格
                level--;
                printSpace(level);
            }

            if (curr == NULL) {
                continue;
            }

            nodeQueue.push(curr->left);
            nodeQueue.push(curr->right);

        }
        std::cout << std::endl;

    }

    /**
     * 获取节点数，返回结果并且结果放入this->len
     *
     * @return 节点数
     */
    int genNodesNum() {
        std::stack<TreeNode *> nodes;
        int nodeNum = 0;

        nodes.push(this);
        while (!nodes.empty()) {
            TreeNode *curr = nodes.top();
            nodes.pop();

            if (curr == NULL) {
                continue;
            }
            nodes.push(curr->left);
            nodes.push(curr->right);
            nodeNum++;
        }
        this->len = nodeNum;
        return nodeNum;
    }


    /**
     * 销毁树
     */
    void destroy() {
        std::stack<TreeNode *> nodes;

        nodes.push(this);
        while (!nodes.empty()) {
            TreeNode *curr = nodes.top();
            nodes.pop();

            if (curr == NULL) {
                continue;
            }
            nodes.push(curr->left);
            nodes.push(curr->right);

            delete curr;
        }
    }


private:
    void printSpace(int num) {
        for (int i = 0; i < num; i++) {
            printf("   ");
        }
    }


};

#endif //C_CODE_BINARYTREE_H
