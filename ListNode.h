//
// Created by wellsjiang on 2017/6/30.
//

#ifndef C_CODE_LISTNODE_H
#define C_CODE_LISTNODE_H

#include <iostream>
#include "StringUtils.h"


class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(std::string input) : next(NULL), val(0) {
        input = StringUtils::trim(input, BOTHSTRIP, "[]");

        std::vector<std::string> nodeValues;
        StringUtils::split(input, nodeValues, ",");
        if (nodeValues.size() < 1) {
            return;
        }

        StringUtils::str2int(this->val, nodeValues[0]);
        ListNode *curr = this;
        for (int i = 1; i < nodeValues.size(); i++) {
            int tempValue;
            StringUtils::str2int(tempValue, nodeValues[i]);
            ListNode *newNode = new ListNode(tempValue);
            newNode->next = NULL;
            curr = curr->insert(newNode);
        }

    }

    void traverse() {
        ListNode *curr = this;
        while (curr->next != NULL) {
            std::cout << curr->val << "->";
            curr = curr->next;
        }
        std::cout << curr->val << std::endl;
    }

    /**
     * 在当前节点插入一个节点
     *
     * @param node
     * @return 插入的节点
     */
    ListNode *insert(ListNode *node) {
        if (node == NULL) {
            return NULL;
        }
        if (this->next != NULL) {
            node->next = this->next;
        } else {
            node->next = NULL;
        }
        this->next = node;
        return node;
    }

    /**
     * 前插入node节点
     *
     * @param node
     * @return
     */
    ListNode *preInsert(ListNode *node) {
        if (node == NULL) {
            return node;
        }
        node->next = this;
        return node;
    }

    void destory() {
        ListNode *curr = this;
        ListNode *nextNode = this->next;
        while (nextNode != NULL) {
            delete curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        delete curr;
    }
};


#endif //C_CODE_LISTNODE_H
