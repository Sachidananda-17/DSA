// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// class HashTable {
// private:
//     static const int TABLE_SIZE = 10;
//     vector<pair<string, int>> table;

//     int hash(const string& key) {
//         int sum = 0;
//         for (char c : key) {
//             sum += c;
//         }
//         return sum % TABLE_SIZE;
//     }

// public:
//     HashTable() : table(TABLE_SIZE) {}

//     void insert(const string& key, int value) {
//         int index = hash(key);
//         table[index] = {key, value};
//     }

//     bool get(const string& key, int& value) {
//         int index = hash(key);
//         if (table[index].first == key) {
//             value = table[index].second;
//             return true;
//         }
//         return false;
//     }

//     void display() {
//         for (int i = 0; i < TABLE_SIZE; i++) {
//             if (!table[i].first.empty()) {
//                 cout << i << ": " << table[i].first << " -> " << table[i].second << endl;
//             }
//         }
//     }
// };

// int main() {
//     HashTable ht;

//     ht.insert("apple", 5);
//     ht.insert("banana", 8);
//     ht.insert("cherry", 12);

//     cout << "Hash Table contents:" << endl;
//     ht.display();

//     int value;
//     if (ht.get("banana", value)) {
//         cout << "Value for 'banana': " << value << endl;
//     } else {
//         cout << "'banana' not found" << endl;
//     }

//     if (ht.get("grape", value)) {
//         cout << "Value for 'grape': " << value << endl;
//     } else {
//         cout << "'grape' not found" << endl;
//     }

//     return 0;
// }

#include<iostream>
using namespace std;
int main()
{
    char ch = '';

    cout<< " the value of ch is "<<int(ch);
}