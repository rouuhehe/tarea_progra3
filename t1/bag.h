//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_BAG_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_BAG_H

#include <string>

struct node{
    int data;
    node* next;
};

namespace structures{
    class bag{
        private:
            node *head;
            node *tail;
            int s=0;
        public:
            bag();
            ~bag();
            void add(int elem);
            node *begin();
            node *end();
            int size() const;
    };
}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_BAG_H
