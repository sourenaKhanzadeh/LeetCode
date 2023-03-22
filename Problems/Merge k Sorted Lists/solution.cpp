//
// Created by sourena khanzadeh on 2023-03-12.
//
#include "../../Preliminaries/pre.hpp"
#include <map>
#include <vector>

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode * head = new ListNode();
        std::map<int, std::vector<ListNode*>*> map;
        for (int k =0; k < lists.size(); k++){
            ListNode * temp = lists[k];
            while(temp){
                std::vector<ListNode*> *v = new std::vector<ListNode*>();
                v->push_back(temp);
                if (map.find(temp->val) == map.end())
                    map.insert({temp->val, v});
                else{
                    std::vector<ListNode*> *v2 = map.at(temp->val);
                    v2->push_back(temp);
                    map.insert({temp->val, v2});
                }
                temp = temp->next;
            }
        }
        ListNode * res = head;
        for(std::pair<int, std::vector<ListNode*>*> p: map){
            for(auto l: *p.second){
                head->next = l;
                head = head->next;
            }
        }

        return res->next;
    }
};