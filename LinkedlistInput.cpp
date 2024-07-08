#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
#define ln "\n"
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 2e18

template <typename T> class Node {
  public:
	T data;
	Node<T> *next;
	Node(T data) : data(data), next(nullptr) {}
};

class LinkedList {
  public:
	Node<int> *takeInput() {
		Node<int> *head;
		Node<int> *tail;

		string input;
		getline(cin, input);
		stringstream ss(input);

		int val;
		while (ss >> val) {
			Node<int> *newNode = new Node<int>(val);
			if (!head) {
				head = newNode;
				tail = newNode;
			} else {
				tail->next = newNode;
				tail = newNode;
			}
		}
		return head;
	}

	void printList(Node<int> *head) {
		Node<int> *temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	// Hello World
	// cout << "Hello world !" << endl;
	LinkedList ll;
	Node<int> *head = ll.takeInput();
	ll.printList(head);
}