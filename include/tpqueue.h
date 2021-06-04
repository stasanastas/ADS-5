// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
  struct ITEM {
    T data;
    ITEM *next;
  };

private:
  ITEM *head;
  ITEM *tail;
  ITEM* create(T data) {
    ITEM *item = new ITEM;
    item->data = data;
    item->next = nullptr;
    return item;
  }

 public:
  TPQueue():head(nullptr), tail(nullptr) {}
  ~TPQueue() {
    while (head)
      pop();
  }

  void push(const T&data) {
    if (tail && head) {
      ITEM *temp = head;
      if (temp->data.prior < data.prior) {
        temp = create(data);
        temp->next = next;
        head = temp;
      } else {
        while (temp->next) {
          if (temp->next->data.prior < data.prior) {
            ITEM *item = careate(data);
            item->next = temp->next;
            temp->next = item;
            break;
          } else {
            temp = temp->next;
          }
        }
      }
      if (!temp->next) {
        tail->next = create(data);
        tail = tail->next;
      }
    } else {
      head = create(data);
      tail = head;
    }
  }
  T pop() {
    if (head) {
      ITEM *temp = head->next;
      T data = head->data;
      delete head;
      head = temp;
      return data;
    } else {
      return (T)0;
    }
  }
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
