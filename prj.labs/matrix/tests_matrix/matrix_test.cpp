
#include "../matrix.h";
#include <iostream>;

using namespace std;


void test_constructor_without_copy(Matrix &obj, int linesize, int columnsize) {

    if (linesize == obj.numline()) cout << "number of line set Right" << endl;
    else cout << "number of line set Right" << endl;
    if (columnsize == obj.numcolumn()) cout << "number of column set Right" << endl;
    else cout << "number of column set Right" << endl;

    bool result = true;
    for (int i(0); i < linesize; i++) {
        for (int j(0); j < columnsize; j++) {
            if (obj.at(i, j) != 0) result = false;
        }
    }
    if (result) cout << "All basic values (0.0) set right" << endl;
    else cout << "Some basic values (0.0) set wrong" << endl;
    cout << "-------------End_of_the_test-------------" << endl;

}

void test_constructor_with_copy(Matrix &obj, Matrix &copy) {
    if (copy.numline() == obj.numline()) cout << "number of line set Right" << endl;
    else cout << "number of line set Right" << endl;
    if (copy.numcolumn() == obj.numcolumn()) cout << "number of column set Right" << endl;
    else cout << "number of column set Right" << endl;

    bool result = true;
    for (int i(0); i < copy.numline(); i++) {
        for (int j(0); j < copy.numcolumn(); j++) {
            if (obj.at(i, j) != copy.at(i, j)) result = false;
        }
    }
    if (result) cout << "All copy values was set right" << endl;
    else cout << "Some copy values was set wrong" << endl;
    cout << "-------------End_of_the_test-------------" << endl;
}

void test_at(Matrix &obj, int pos_line, int pos_column, double value) {

    if (obj.at(pos_line, pos_column) == value)
        cout << "Value on position {" << pos_line << " , " << pos_column << "} set right" << endl;
    else cout << "Value on position {" << pos_line << " , " << pos_column << "} set wrong" << endl;
    cout << "-------------End_of_the_test-------------" << endl;
}


void test_assignment(Matrix &lhs, Matrix &rhs) {

    test_constructor_with_copy(lhs, rhs);
}


void test_resize(Matrix &newobj, Matrix &oldobj, int new_num_line, int new_num_column) {
    if (new_num_line == newobj.numline()) cout << "number of line set Right" << endl;
    else cout << "number of line set Right" << endl;
    if (new_num_column == newobj.numcolumn()) cout << "number of column set Right" << endl;
    else cout << "number of column set Right" << endl;
    bool result = true;
    for (int i(0); i < new_num_line; i++) {
        for (int j(0); j < new_num_column; j++) {
            if (newobj.at(i, j) != oldobj.at(i, j)) result = false;
        }
    }
    if (result) cout << "All previous values was set right" << endl;
    else cout << "Some previous values was set wrong" << endl;
    cout << "-------------End_of_the_test-------------" << endl;

}

int main() {
    Matrix test(4, 4);
    test_constructor_without_copy(test, 4, 4);

    int q = 0;
    for (int i(0); i < test.numline(); i++) {
        for (int j(0); j < test.numcolumn(); j++) {
            test.at(i, j) = q++;
        }
    }

    Matrix test2(test);

    test_constructor_with_copy(test2, test);


    test2.at(1, 1) = -42;

    test_at(test2, 1, 1, -42);

    test2 = test;

    test_assignment(test2, test);


    test.resize(1, 1);

    test_resize(test, test2, 1, 1);


    Matrix test1(2, 3);
    Matrix test3(5, 5);
    test.resize(4, 3);
    test.resize(2, 4);
    q = -10;
    for (int i(0); i < test3.numline(); i++) {
        for (int j(0); j < test3.numcolumn(); j++) {
            test3.at(i, j) = q++;
        }
    }
    cout << "-------------" << endl;


    for (int i(0); i < test3.numline(); i++) {
        for (int j(0); j < test3.numcolumn(); j++) {
            std::cout << test3.at(i, j) << " ";
        }
        std::cout << std::endl;
    }

    cout << "-------------" << endl;
    for (int i(0); i < test.numline(); i++) {
        for (int j(0); j < test.numcolumn(); j++) {
            std::cout << test.at(i, j) << " ";
        }
        std::cout << std::endl;
    }
    cout << "-------------" << endl;
    test1 = test;
    for (int i(0); i < test1.numline(); i++) {
        for (int j(0); j < test1.numcolumn(); j++) {
            std::cout << test1.at(i, j) << " ";
        }
        std::cout << std::endl;
    }
    cout << "-------------" << endl;


    for (int i(0); i < test2.numline(); i++) {
        for (int j(0); j < test2.numcolumn(); j++) {
            std::cout << test2.at(i, j) << " ";
        }
        std::cout << std::endl;
    }


    test2.resize(3, 3);
    std::cout << " -------------------- " << std::endl;
    for (int i(0); i < test2.numline(); i++) {
        for (int j(0); j < test2.numcolumn(); j++) {
            std::cout << test2.at(i, j) << " ";
        }
        std::cout << std::endl;
    }

    cout << "-------------" << endl;


    test2 = test2;

/*	//budet vidovat exception
	test2.at(20, 1);
	Matrix test10(-1,2);
	
*/
}