#include "OrderMGMT.h"
// Function to insert a new order.
// date: Date of a order.
// id: Order ID.

node *insert(node *Root, unsigned id, unsigned date) 
{
	node *current;
  	if (Root == NULL) {
    		current = (node *)malloc(sizeof(node));
    		assert(current != NULL);
		data.push_back(date);
    		current->date = date;
    		current->id = id;
    		current->left = NULL;
    		current->right = NULL;
    		return current;
  	}
  	if (date < Root->date) {
    		Root->left = insert(Root->left, id, date);
	} else if (date > Root->date) {
    		Root->right = insert(Root->right, id, date);
	}
  	return Root;
}

void OrderMGMT::addOrder(unsigned date, unsigned id)
{	
	root = insert(root, id, date);
}

// Function to delete orders from a given range.
// start: Begin date.
// end: End date.

node *del(node *Root, int key) 
{
	if (Root->date > key) {
            	Root->left = del(Root->left, key);
        } else if (Root->date < key) {
            	Root->right = del(Root->right, key);
        } else {
            	if (Root->left == NULL || Root->right == NULL) {
			if (Root->left != NULL) {
				Root = Root->left;
			} else {
				Root = Root->right;
			}
            	} else {
                	node *current = Root->right;
                	while (current->left != NULL) {
				current = current->left;
			}
                	Root->date = current->date;
			Root->id = current->id;
                	Root->right = del(Root->right, current->date);
            }
        }
        return Root;
}

void OrderMGMT::deleteOrders(unsigned start, unsigned end)
{
	int count = -1;
	vector<int> temp;
	sort(data.begin(), data.end());
	if (data.front() > end || data.back() < start) {
		return;
	}
	for (int i = 0; i < data.size(); i++) {
		count++;
		temp.push_back(data[i]);
		if (data[i] >= start && data[i] <= end) {
			root = del(root, data[i]);
			temp.pop_back();			
		}
		
	}
	data.assign(temp.begin(), temp.end());
}

// Function to return a STL list of order IDs from a given range of dates.
// start: Begin date.
// end: End date.

unsigned get_id(node *Root, int date) 
{
	unsigned ans;
	if (date == Root->date) {
		return Root->id;
	}
	if (date > Root->date) {
		ans = get_id(Root->right, date);
	} else if (date < Root->date) {
		ans = get_id(Root->left, date);
	}
	return ans; 
}

list<unsigned> OrderMGMT::searchByDate(unsigned start, unsigned end)
{
	sort(data.begin(), data.end());
	list<unsigned> ans;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] >= start && data[i] <= end) {
			ans.push_back(get_id(root, data[i]));
		}
	}
	return ans;	
}

// Function to return a STL list of order IDs starting from the a_th rank of date to the b_th rank of date.
// a_th: Begin rank.
// b_th: End rank.

list<unsigned> OrderMGMT::searchByDateRank(unsigned a_th, unsigned b_th)
{
	sort(data.begin(), data.end());
	list<unsigned> ans;
	if (a_th > data.size()) {
		//
	} else if (b_th > data.size()) {
		for (int i = a_th; i <= data.size(); i++) {
			ans.push_back(get_id(root, data[i - 1]));
		}	
	} else {
		for (int i = a_th; i <= b_th; i++) {
			ans.push_back(get_id(root, data[i - 1]));
		}	
	}
	return ans;	
}

