// --------------------------
// projects/integer/Integer.h
// Copyright (C) 20010
// Glenn P. Downing
// --------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector

// -----------------
// shift_left_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * (s << n) => x
 */
template <typename II, typename OI>
OI shift_left_digits (II b, II e, int n, OI x) {
    // <your code>
    return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * (s >> n) => x
 */
template <typename II, typename OI>
OI shift_right_digits (II b, II e, int n, OI x) {
    // <your code>
    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * (s1 + s2) => x
 */
template <typename II1, typename II2, typename OI>
OI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * (s1 - s2) => x
 */
template <typename II1, typename II2, typename OI>
OI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * (s1 * s2) => x
 */
template <typename II1, typename II2, typename OI>
OI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * (s1 / s2) => x
 */
template <typename II1, typename II2, typename OI>
OI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    // <your code>
    return x;}

// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
    public:
        // -----------
        // operator ==
        // -----------

        /**
         * <your documentation>
         */
        friend bool operator == (const Integer& lhs, const Integer& rhs) {
            // <your code>
            return false;}

        // -----------
        // operator !=
        // -----------

        /**
         * <your documentation>
         */
        friend bool operator != (const Integer& lhs, const Integer& rhs) {
            return !(lhs == rhs);}

        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        friend bool operator < (const Integer& lhs, const Integer& rhs) {
            // <your code>
            return false;}

        // -----------
        // operator <=
        // -----------

        /**
         * <your documentation>
         */
        friend bool operator <= (const Integer& lhs, const Integer& rhs) {
            return !(rhs < lhs);}

        // ----------
        // operator >
        // ----------

        /**
         * <your documentation>
         */
        friend bool operator > (const Integer& lhs, const Integer& rhs) {
            return (rhs < lhs);}

        // -----------
        // operator >=
        // -----------

        /**
         * <your documentation>
         */
        friend bool operator >= (const Integer& lhs, const Integer& rhs) {
            return !(lhs < rhs);}

        // ----------
        // operator +
        // ----------

        /**
         * <your documentation>
         */
        friend Integer operator + (Integer lhs, const Integer& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        friend Integer operator - (Integer lhs, const Integer& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator *
        // ----------

        /**
         * <your documentation>
         */
        friend Integer operator * (Integer lhs, const Integer& rhs) {
            return lhs *= rhs;}

        // ----------
        // operator /
        // ----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        friend Integer operator / (Integer lhs, const Integer& rhs) {
            return lhs /= rhs;}

        // ----------
        // operator %
        // ----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        friend Integer operator % (Integer lhs, const Integer& rhs) {
            return lhs %= rhs;}

        // -----------
        // operator <<
        // -----------

        /**
         * <your documentation>
         */
        friend Integer operator << (Integer lhs, int rhs) {
            return lhs <<= rhs;}

        // -----------
        // operator >>
        // -----------

        /**
         * <your documentation>
         */
        friend Integer operator >> (Integer lhs, int rhs) {
            return lhs >>= rhs;}

        // -----------
        // operator <<
        // -----------

        /**
         * <your documentation>
         */
        friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
            // <your code>
            return lhs << "0";}

        /**
         * absolute value
         * <your documentation>
         */
        friend Integer abs (Integer x) {
            return x.abs();}

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if (x == 0) && (e == 0)
         * @throws invalid_argument if (e < 0)
         */
        friend Integer pow (Integer x, int e) {
            return x.pow(e);}

    private:
        // ----
        // data
        // ----

        // <your data>
		C digits;
		bool polarity;

    private:
        // -----
        // valid
        // -----

		bool valid () const {
			
			for (unsigned int i = 0; i < digits.size(); i++) {
				if (digits[i] > 9 || digits[i] < 0)
					return false;
			}
			/*
			for( it = digits.begin(); it < digits.end(); it++ )
				if( (*it) > 9 || (*it) < 0 )
					return false;
			*/
			return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * @param value the value to assign to the Integer
         */
        Integer (int value) {
            int mod = 10;
			if( value < 0 ) {
				polarity = false;
				value = -value;
			} else 
				polarity = true;
				
			while( value != 0 ) {
				digits.push_back( value % mod );
				value /= 10;
			}
			assert(valid());}

        /**
		 * @param value the value to assign to the Integer
		 * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
			std::cout << "Before IF \n";
			std::string v = value;
            if( v[0] == '-' ) {
				polarity = false;
				v.erase( v.begin() );
			}
			else
				polarity = true;
			
			
			std::string::reverse_iterator s_it = v.rbegin();
			while (s_it != v.rend()) {
				digits.push_back( (*s_it)-'0' );
				s_it++;
			}
			
            if (!valid())
                throw std::invalid_argument("Integer::Integer()");}

        // Default copy, destructor, and copy assignment.
        // Integer (const Integer&);
        // ~Integer ();
        // Integer& operator = (const Integer&);

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        Integer operator - () const {
            // <your code>
            return Integer(0);}

        // -----------
        // operator ++
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator ++ () {
            *this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
         */
        Integer& abs () {
            // <your code>
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if (this == 0) && (e == 0)
         * @throws invalid_argument if (e < 0)
         */
        Integer& pow (int e) {
            // <your code>
            return *this;}};

#endif // Integer_h
