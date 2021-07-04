#ifndef ORDERMGMT_H
#define ORDERMGMT_H

#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

// Data structure consisting of Order ID and date.
struct Node {
  unsigned id;
  unsigned date;
  unsigned leftSize;
  Node *left, *right;
};

typedef struct Node node;
node *root = NULL;
vector<int> data;

// Order Management System consolidating key operational processes.
class OrderMGMT {
 private:
 public:
  void addOrder(unsigned date, unsigned id);
  void deleteOrders(unsigned start, unsigned end);
  list<unsigned> searchByDate(unsigned start, unsigned end);
  list<unsigned> searchByDateRank(unsigned a_th, unsigned b_th);
};

#endif

