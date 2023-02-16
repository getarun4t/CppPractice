#include<iostream>
#include "trie.h"
using namespace std;

int main() {
	Trie t;
	t.insert("apple");
	t.insert("aet");
	t.insert("news");
	t.insert("new");
	t.insert("app");
	cout << t.Search("app");
}