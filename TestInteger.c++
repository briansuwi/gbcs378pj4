// --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2010
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % g++ -ansi -pedantic -lcppunit -ldl -Wall TestInteger.c++ -o TestInteger.app
    % valgrind TestInteger.app >& TestInteger.out
*/

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Integer.h"

// -----------
// TestInteger
// -----------

struct TestInteger : CppUnit::TestFixture {
    // -----------------
    // shift_left_digits
    // -----------------

    void test_shift_left_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {2, 3, 4, 0, 0};
              int x[10];
        const int* p = shift_left_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 5);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // ------------------
    // shift_right_digits
    // ------------------

    void test_shift_right_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {2};
              int x[10];
        const int* p = shift_right_digits(a, a + 3, 2, x);
        CPPUNIT_ASSERT((p - x) == 1);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, b));}

    // -----------
    // plus_digits
    // -----------

    void test_plus_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {8, 0, 1};
              int x[10];
        const int* p = plus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // ------------
    // minus_digits
    // ------------

    void test_minus_digits () {
        const int a[] = {8, 0, 1};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = minus_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------------
    // multiplies_digits
    // -----------------

    void test_multiplies_digits () {
        const int a[] = {2, 3, 4};
        const int b[] = {5, 6, 7};
        const int c[] = {1, 3, 2, 6, 7, 8};
              int x[10];
        const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 6);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // --------------
    // divides_digits
    // --------------

    void test_divides_digits () {
        const int a[] = {1, 3, 2, 6, 7, 8};
        const int b[] = {5, 6, 7};
        const int c[] = {2, 3, 4};
              int x[10];
        const int* p = divides_digits(a, a + 6, b, b + 3, x);
        CPPUNIT_ASSERT(p - x == 3);
        CPPUNIT_ASSERT(std::equal(const_cast<const int*>(x), p, c));}

    // -----------
    // constructor
    // -----------

    void test_constructor_1 () {
        try {
            const Integer<int> x("abc");
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
			CPPUNIT_ASSERT(strcmp(e.what(), "Integer::Integer()") == 0);}}

    void test_constructor_2 () {
        try {
            const Integer<int> x("2");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_constructor_3 () {
        try {
            const Integer<int> x = 2;}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // abs
    // ---

    void test_abs_1 () {
        try {
            Integer<int>  x = -98765;
            Integer<int>& y = x.abs();
            CPPUNIT_ASSERT( x == 98765);
            CPPUNIT_ASSERT(&x == &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_abs_2 () {
        try {
            const Integer<int> x = -98765;
            const Integer<int> y = abs(x);
            CPPUNIT_ASSERT(x == -98765);
            CPPUNIT_ASSERT(y ==  98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------
    // equal_to
    // --------

    void test_equal_to () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = 98765;
            CPPUNIT_ASSERT(      x == y);
            CPPUNIT_ASSERT(      x == 98765);
            CPPUNIT_ASSERT(  98765 == x);
            CPPUNIT_ASSERT(    !(x != y));
            CPPUNIT_ASSERT(    !(x != 98765));
            CPPUNIT_ASSERT(!(98765 != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------
    // negation
    // --------

    void test_negation () {
        try {
            const Integer<int> x = 98765;
            const Integer<int> y = -x;
            CPPUNIT_ASSERT(y == -98765);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ------
    // output
    // ------

    void test_output () {
        try {
            const Integer<int> x = 98765;
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "98765");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---
    // pow
    // ---

    void test_pow_1 () {
        try {
            Integer<int>       x = 98765;
            const int          e =  9867;
            Integer<int>&      y = x.pow(e);
            CPPUNIT_ASSERT( e == 9867);
            CPPUNIT_ASSERT( x ==    0);
            CPPUNIT_ASSERT(&x ==   &y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_pow_2 () {
        try {
            const Integer<int> x = 98765;
            const int          e =  9867;
            const Integer<int> y = pow(x, e);
            CPPUNIT_ASSERT(x == 98765);
            CPPUNIT_ASSERT(e ==  9867);
            CPPUNIT_ASSERT(y ==     0);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
			
    // ---
    // +=
    // ---
	
	void test_plus_equal_1 () {
		try {
			Integer<int>       x = 98765;
			Integer<int>      y = 1;
			x += y;
			CPPUNIT_ASSERT( x == 98766);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_plus_equal_2 () {
		try {
			Integer<int>       x = 98765;
			Integer<int>      y = 1;
			y += x;
			CPPUNIT_ASSERT( y == 98766);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_plus_equal_3 () {
		try {
			Integer<int>       x = 98765;
			Integer<int>      y = -1;
			x += y;
			CPPUNIT_ASSERT( x == 98764);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_plus_equal_4 () {
		try {
			Integer<int>       x = -98765;
			Integer<int>      y = 1;
			y += x;
			CPPUNIT_ASSERT( y == -98764);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_plus_equal_5 () {
		try {
			Integer<int>       x = -98765;
			Integer<int>      y = -1;
			x += y;
			CPPUNIT_ASSERT( x == -98766);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_plus_equal_6 () {
		try {
			Integer<int>       x = -98765;
			Integer<int>      y = -1;
			y += x;
			CPPUNIT_ASSERT( y == -98766);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}

    // ---
    // -=
    // ---

	void test_minus_equal_1 () {
		try {
			Integer<int>       x = 98765;
			Integer<int>      y = 1;
			x -= y;
			CPPUNIT_ASSERT( x == 98764);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_minus_equal_2 () {
		try {
			Integer<int>       x = 98765;
			Integer<int>      y = 1;
			y -= x;
			CPPUNIT_ASSERT( y == -98764);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_minus_equal_3 () {
		try {
			Integer<int>       x = 98765;
			Integer<int>      y = -1;
			x -= y;
			CPPUNIT_ASSERT( x == 98766);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_minus_equal_4 () {
		try {
			Integer<int>       x = 98765;
			Integer<int>      y = -1;
			y -= x;
			CPPUNIT_ASSERT( y == -98766);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_minus_equal_5 () {
		try {
			Integer<int>       x = -98765;
			Integer<int>      y = -1;
			x -= y;
			CPPUNIT_ASSERT( x == -98764);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}
	
	void test_minus_equal_6 () {
		try {
			Integer<int>       x = -98765;
			Integer<int>      y = -1;
			y -= x;
			CPPUNIT_ASSERT( y == 98764);}
			catch (std::invalid_argument& e) {
				CPPUNIT_ASSERT(false);}
	}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestInteger);
    CPPUNIT_TEST(test_shift_left_digits);
    CPPUNIT_TEST(test_shift_right_digits);
    CPPUNIT_TEST(test_plus_digits);
    CPPUNIT_TEST(test_minus_digits);
    CPPUNIT_TEST(test_multiplies_digits);
    CPPUNIT_TEST(test_divides_digits);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_abs_1);
    CPPUNIT_TEST(test_abs_2);
    CPPUNIT_TEST(test_negation);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_pow_1);
    CPPUNIT_TEST(test_pow_2);
	CPPUNIT_TEST(test_plus_equal_1);
	CPPUNIT_TEST(test_plus_equal_2);
	CPPUNIT_TEST(test_plus_equal_3);
	CPPUNIT_TEST(test_plus_equal_4);
	CPPUNIT_TEST(test_plus_equal_5);
	CPPUNIT_TEST(test_plus_equal_6);
	CPPUNIT_TEST(test_minus_equal_1);
	CPPUNIT_TEST(test_minus_equal_2);
	CPPUNIT_TEST(test_minus_equal_3);
	CPPUNIT_TEST(test_minus_equal_4);
	CPPUNIT_TEST(test_minus_equal_5);
	CPPUNIT_TEST(test_minus_equal_6);
	CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestInteger.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestInteger::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
