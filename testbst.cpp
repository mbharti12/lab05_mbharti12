// testbst.cpp
// Tests intbst.cpp for CS 24 lab

#include "intbst.h"
#include <vector>
#include <iostream>
using namespace std;

//int getTest();

// creates two trees (one of which is empty),
// and does some simple tests of tree methods

template <class T>
void insertIntoBST(IntBST<T>& b, vector<T>& v){
    for (auto item: v){
        b.insert(item);
    }
}

template <class T>
void printElements(IntBST<T>& s){
    s.printPreOrder();
    cout << endl;
}

int main() {
    vector<int> intVec = {64, 128, 8, 512, 256, 32, 16, 4};
    vector<char> charVec = {'a', 'z', 'r', 'w', 'b', 'n', 'f', 'l'};
    vector<double> doubleVec = {32.4, 12.8, 0.8, 5.12, 25.6, 0.32, 16, 4};

    IntBST <int>intBST;
    IntBST <char>charBST;
    IntBST <double>doubleBST;

    insertIntoBST(intBST, intVec);
    insertIntoBST(charBST, charVec);
    insertIntoBST(doubleBST, doubleVec);

    printElements(intBST);
    printElements(charBST);
    printElements(doubleBST);


    // // insert data to bst1
    // bst1.insert(64);
    // bst1.insert(128);
    // bst1.insert(8);
    // bst1.insert(512);
    // bst1.insert(256);
    // bst1.insert(32);
    // bst1.insert(16);
    // bst1.insert(4);
    
    // for (int i = 0; i < intVec.size(); i++){
    //     intBST.insert(intVec.at(i));
    //     doubleBST.insert(charVec.at(i));
    //     charBST.insert(doubleVec.at(i));
    // }

    // // let user choose one or all tests
    // bool all = true;
    // int testnum = getTest();
    // if (testnum)
    //     all = false;

    // // print and test methods for bst1
    // cout << "BST: " << endl << "  pre-order: ";
    // bst1.printPreOrder();
    // cout << endl;
    // if (all || testnum == 1) {
    //     cout << "  in-order: ";
    //     bst1.printInOrder();
    //     cout << endl;
    // }
    // if (all || testnum == 2) {
    //     cout << "  post-order: ";
    //     bst1.printPostOrder();
    //     cout << endl;
    // }
    // if (all || testnum == 3)
    //     cout << "  sum: " << bst1.sum() << endl;
    // if (all || testnum == 4)
    //     cout << "  count: " << bst1.count() << endl;
    // if (all || testnum == 5) {
	// cout << "  contains 64? " <<
    //         (bst1.contains(64) ? "Y" : "N") << endl;
	// cout << "  contains 4? " <<
    //         (bst1.contains(4) ? "Y" : "N") << endl;
    //     cout << "  contains 16? " <<
    //         (bst1.contains(16) ? "Y" : "N") << endl;
    //     cout << "  contains 128? " <<
    //         (bst1.contains(128) ? "Y" : "N") << endl;
    //     cout << "  contains 17? " <<
    //         (bst1.contains(17) ? "Y" : "N") << endl;
    //     cout << "  contains 512? " <<
    //         (bst1.contains(512) ? "Y" : "N") << endl;
    // }
    // if(all || testnum == 6){
	// cout << "  predecessor of 64 is: " <<
	//     bst1.getPredecessor(64) << endl;
    // cout << "  predecessor of 16 is: " <<
	//     bst1.getPredecessor(16) << endl;
    // cout << "  predecessor of 128 is: " <<
	//     bst1.getPredecessor(128) << endl;
    // cout << "  predecessor of 256 is: " <<
	//     bst1.getPredecessor(256) << endl;
	// cout << "  predecessor of 512 is: " <<
	//     bst1.getPredecessor(512) << endl;
	// cout << "  predecessor of 4 is: " <<
	//     bst1.getPredecessor(4) << endl;
	// cout << "  predecessor of 8 is: " <<
    //     bst1.getPredecessor(8) << endl;
	// cout << "  predecessor of 32 is: " <<
    //     bst1.getPredecessor(32) << endl;
	// cout << "  successor of 64 is: " <<
	//     bst1.getSuccessor(64) << endl;
	// cout << "  successor of 512 is: " <<
	//     bst1.getSuccessor(512) << endl;
	// cout << "  successor of 4 is: " <<
	//     bst1.getSuccessor(4) << endl;
    // }
    // if(all || testnum == 7) {
	// cout << "  removing 4" << endl;
	// bst1.remove(4);
	// cout << "  removing 64" << endl;
	// bst1.remove(64);
	// cout << "  removing 128" << endl;
	// bst1.remove(128);
	// cout << "  contains 64? " <<
    //         (bst1.contains(64) ? "Y" : "N") << endl;
	// cout << "  contains 4? " <<
	//     (bst1.contains(4) ? "Y" : "N") << endl;
    //     cout << "  contains 16? " <<
    //         (bst1.contains(16) ? "Y" : "N") << endl;
    //     cout << "  contains 128? " <<
    //         (bst1.contains(128) ? "Y" : "N") << endl;
    //     cout << "  contains 17? " <<
    //         (bst1.contains(17) ? "Y" : "N") << endl;
    //     cout << "  contains 512? " <<
    //         (bst1.contains(512) ? "Y" : "N") << endl;
	// cout << "  pre-order: ";
    //     bst1.printPreOrder();
    //     cout << endl;
    // }

    // // test methods for empty bst2
    // cout << "Empty BST: " << endl << "  pre-order: ";
    // bst2.printPreOrder();
    // cout << endl;
    // if (all || testnum == 1) {
    //     cout << "  in-order: ";
    //     bst2.printInOrder();
    //     cout << endl;
    // }
    // if (all || testnum == 2) {
    //     cout << "  post-order: ";
    //     bst2.printPostOrder();
    //     cout << endl;
    // }
    // if (all || testnum == 3)
    //     cout << "  sum: " << bst2.sum() << endl;
    // if (all || testnum == 4)
    //     cout << "  count: " << bst2.count() << endl;
    // if (all || testnum == 5)
    //     cout << "  contains 16? " <<
    //         (bst2.contains(16) ? "Y" : "N") << endl;

    // // add tests for optional methods that you attempt to implement
    // // but don't do that until after submitting the basic version

    return 0;
}

// int getTest() {
//     cout << "Choice of tests:\n"
// 	 << "  0. all tests\n"
// 	 << "  1. just printInOrder\n"
// 	 << "  2. just printPostOrder\n"
// 	 << "  3. just sum\n"
// 	 << "  4. just count\n"
// 	 << "  5. just contains\n"
// 	 << "  6. just predecessor/successor\n"
// 	 << "  7. just remove\n";
	 
//     do {
//         int choice;
//         cout << "Enter choice:\n";
//         cin >> choice;
//         if (choice >=0 && choice <= 7)
//             return choice;
//         cout << "0, 1, 2, 3, 4, 5, 6, or 7 only!\n";
//     } while (true);
// }