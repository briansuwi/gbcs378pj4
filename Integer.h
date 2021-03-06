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
 * @param n  an int, the number of digits to shift by
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * (s << n) => x
 */
template <typename II, typename OI>
OI shift_left_digits (II b, II e, int n, OI x) {
    while (b != e) {
		*x = *b;
		b++;
		x++;
	}
	for (int i = 0; i < n; i++) {
		*x = 0;
		x++;
	}
    return x;
}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param n  an int, the number of digits to shift by
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * (s >> n) => x
 */
template <typename II, typename OI>
OI shift_right_digits (II b, II e, int n, OI x) {
    while (b != (e - n)){
		*x = *b;
		b++;
		x++;
	}
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
	int carry = 0;
	int sum;
	OI tempX = x += (e1 - b1);
	
	while (e2 != b2) {
		sum = *(e1-1) + *(e2-1) + carry;
		
		carry = sum / 10;
		sum %= 10;
		*(x-1) = sum;
		e1--;
		e2--;
		x--;
	}
	
	while (e1 != b1) {
		sum = *(e1-1) + carry;				
		
		carry = sum / 10;
		sum %= 10;
		*(x-1) = sum;
		e1--;
		x--;
	}
	
    return tempX;}

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
	bool borrow = false;
	int diff;
	OI tempX = x += (e1 - b1);	
	
	while (e2 != b2) {
		diff = *(e1-1) - *(e2-1) - borrow;
		if (diff < 0) {
			borrow = true;
			diff += 10;
		} else {
			borrow = false;
		}
		*(x-1) = diff;
		 e1--;
		 e2--;
		 x--;
	}
	
	while (e1 != b1) {
		diff = *(e1-1) - borrow;				
		if (diff < 0) {						 
			borrow = true;
			diff += 10;
		} else {
			borrow = false;
		}
		*(x-1) = diff;
		e1--;
		x--;
	}
	
    return tempX;}

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
 * PRECONDITION: x must be an array of sufficient size that contains all ZEROs
 * (s1 * s2) => x
 */
template <typename II1, typename II2, typename OI>
OI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    II1 it;
	OI x_end, x_temp, x_begin = x;
	int pad = 0, carry = 0;
	
	// do the multiplication
	while( b2 != e2 ) {
		x = x_begin + pad++;
		for( it = e1; it != b1; it-- ) {
			*x += *(e2-1) * *(it-1);
			x++;
		}
		e2--;
	}
	x_end = x;
	
	// calculate the carries
	for( x_temp = x_begin; x_temp != x_end; x_temp++ ) {
		*x_temp += carry;
		carry = *x_temp / 10;
		*x_temp %= 10;
	}
	
	while( carry != 0 ) {
		*x_temp += carry;
		carry = *x_temp / 10;
		*x_temp %= 10;
		x_temp++;
		x_end++;
	}
	x = x_end;
	
	// reverse the array
	for( x_temp = x_begin; x_temp < x - 1; x_temp++, x-- )
		std::swap( *x_temp, *(x - 1) );
    
	return x_end;
}

template <typename II1, typename OI>
OI multiplies_digits_2 (II1 b1, II1 e1, int n, OI x) {
	OI x_begin = x;
	int pad = 0, carry = 0;
	
	// do the multiplication
	while (e1 != b1) {
//	std::cout << "MULT 1" << std::endl;
		pad = (*(e1-1)) * n + carry;
		*x = pad % 10;
		carry = pad / 10;
		x++;
		e1--;
	}
	
	if (carry > 0) {
		*x = carry;
		x++;
	}
	
//	std::cout << "MULT 2" << std::endl;	
	OI x_end = x;
	// reverse the array
	for( OI x_temp = x_begin; x_temp < x - 1; x_temp++, x-- )
		std::swap( *x_temp, *(x - 1) );
  //  	std::cout << "MULT 3" << std::endl;
  /*
   	std::cout << "Mult RESULT MD2 -> ";
	while (x_begin != x_end){
		std::cout << *x_begin;
		x_begin++;
	}
	std::cout << std::endl;*/
  
	return x_end;
}

template <typename II1, typename II2>
int comparison (II1 b1, II1 e1, II2 b2, II2 e2) {
/*
	II1 temp1 = b1;
	II2 temp2 = b2;
	
	while (temp1 != e1) {
		std::cout << *temp1;
	}
	std::cout << std::endl;
	
	while (temp2 != e2) {
		std::cout << *temp2;
	}
	std::cout << std::endl;
*/
 
	if (e1 - b1 < e2 - b2) {
		std::cout << e1 - b1<< std::endl;
		std::cout << e2 - b2 << std::endl;
		return 1;
	} else if (e2 - b2 < e1 - b1) {
		return 2;
	} else {
		while (b1 != e1) {
			if (*b1 < *b2) {
				return 1;
			} else if (*b1 > *b2){
				return 2;
			}
			b1++;
			b2++;
		}
	}
	return 0;
}

template <typename II1, typename IP, typename OI>
OI divides_digits_2 (II1 b1, II1 e1, IP d, OI x) {
//	std::cout << "E - B -> " << e1-b1 << std::endl;
//	std::cout << "B =-> " << *b1 << std::endl;
	OI x_b = x;
	
	if (*d == 1) {
		std::copy(b1, e1, x);
	//	std::cout << "Copy =-> " << *b1 << std::endl;
	} else if (*d == 0) {
		return x;
	} else {
		int r = 0, q = 0;
		
		while (b1 != e1) {
			//std::cout << "Divisor -> " << *d << " Dividend -> " << *b1 << std::endl;
     		q = (*b1 + r) / *d;
			r = ((*b1 + r) - (q * (*d)))  * 10;
			if (x_b == x && q == 0) {
			//	std::cout << "Divides 2 -> " << q << std::endl;
				b1++;
			} else {
				*x = q;
				x++;
				b1++;
			}
		//	std::cout << "Qoutient -> " << q << " Remainder -> " << r << std::endl;
		}
	} 
				
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
    if ( (e2 - b2) == 1) {
		return divides_digits_2(b1, e1, b2, x);
	} else if ( (e1 - b1) < (e2 - b2) ) {
		std::copy(b1, e1, x);
		x += (e1 - b1);
	} else if ( (e1 - b1) == (e2 - b2)  ){
		int comp = comparison(b1 , e1, b2, e2);
		
		if (comp == 0) {
			*x = 1;
			x++;
		} else if (comp == 1) {
			std::copy(b1, e1, x);
			x += (e1 - b1);
		} else {
			std::copy(b2, e2, x);
			x += (e2 - b2);
		}
	
	} else {
		std::vector<int> rem;
        std::vector<int> rem_temp;
		std::vector<int> m_temp(e2-b2+1);
		int q_length = (e1 - b1) - (e2 - b2);
		int d2 = (*b2 * 10) + *(b2+1);
		int di3 = 0;
		int qe = 0;
		int lge = -1;
		
		
		for (int c = 0; c < (e2 - b2); c ++) {
			rem.push_back((*(b1 + c)));  
			rem_temp.push_back(*(b1 + c));
		}
	/*	std::vector<int>::iterator it = rem_temp.begin();
		
		while (it != rem_temp.end()){
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;*/
		
		for (int i = 0; i < q_length+1; i++) {
			
			if ( e2-b2 > 2) {
				di3 = rem[0]*100 + rem[1]*10 + rem[2];
			} else {
				di3 = rem[0]*100 + rem[1]*10;
			}
			qe = di3/d2;
			if (qe > 9) {
				qe = 9;
			} //rem_temp.end();
			std::vector<int>::iterator rt_end = multiplies_digits_2(b2, e2, qe, rem_temp.begin());
			//std::cout << "Mult"  << std::endl;   
			lge = comparison(rem_temp.begin(), rt_end, rem.begin(), rem.end());
			//std::cout << "Comp " << std::endl;

			if (lge == 0) {
				*x = qe;
				x++;
				rem.clear();
				rem.push_back(*(b1+q_length+i));
				m_temp.clear();
			} else if (lge == 1) {
				while (lge == 1 && qe < 10) {
					qe++;
					std::vector<int>::iterator rt_end = multiplies_digits_2(b2, e2, qe, rem_temp.begin());
					lge = comparison(rem_temp.begin(), rt_end, rem.begin(), rem.end());
				}			
				if (qe != 0) {
					*x = qe - 1;
					x++;
				} else {
					rem.push_back(0);
				}
				
				//*x = qe - 1;
				std::vector<int>::iterator rt_end = multiplies_digits_2(b2, e2, qe-1, rem_temp.begin());
				
				std::vector<int>::iterator m_e = minus_digits(rem.begin(), rem.end(), rem_temp.begin(), rt_end, m_temp.begin());
				std::vector<int>::iterator m_b = m_temp.begin();
				rem.clear();
				bool flag = true;
				while (m_b != m_e) {
					if (*m_b == 0 && flag){
						m_b++;
					} else if (*m_b != 0) {
						flag = true;
						rem.push_back(*m_b);
						m_b++;
					} else {
						rem.push_back(*m_b);
						m_b++;
					}
				}
				rem.push_back(*(b1+q_length+i));
				m_temp.clear();

			} else if (lge == 2) {
				while (lge == 2 && qe != 0) {
					qe--;
					std::vector<int>::iterator rt_end = multiplies_digits_2(b2, e2, qe, rem_temp.begin());
					lge = comparison(rem_temp.begin(), rt_end, rem.begin(), rem.end());
				}
				if (qe != 0) {
					*x = qe;
					x++;
					std::vector<int>::iterator m_e = minus_digits(rem.begin(), rem.end(), rem_temp.begin(), rt_end, m_temp.begin());
					std::vector<int>::iterator m_b = m_temp.begin();
					rem.clear();
					bool flag = true;
					while (m_b != m_e) {
						if (*m_b == 0 && flag){
							m_b++;
						} else if (*m_b != 0) {
							flag = true;
							rem.push_back(*m_b);
							m_b++;
						} else {
							rem.push_back(*m_b);
							m_b++;
						}
					}
					rem.push_back(*(b1+q_length+i));
					m_temp.clear();
				} else {
					if (i == q_length) {
						*x = 0;
						x++;
					}
					rem.push_back(*(b1+q_length+i));
				}
				
			}
		}

		
	}
	
    return x;}
	

template <typename II1, typename IP, typename OI>
OI modulus_digits_2 (II1 b1, II1 e1, IP d, OI x) {
//	std::cout << "E - B -> " << e1-b1 << std::endl;
//	std::cout << "B =-> " << *b1 << std::endl;
	OI x_b = x;
	int r = 0, q = 0;	
	
	if (*d == 1) {
		std::copy(b1, e1, x);
	//	std::cout << "Copy =-> " << *b1 << std::endl;
	} else if (*d == 0) {
		return x;
	} else {

		
		while (b1 != e1) {
			//std::cout << "Divisor -> " << *d << " Dividend -> " << *b1 << std::endl;
     		q = (*b1 + r) / *d;
			r = ((*b1 + r) - (q * (*d)))  * 10;
			if (x_b == x && q == 0) {
			//	std::cout << "Divides 2 -> " << q << std::endl;
				b1++;
			} else {
				*x = q;
				x++;
				b1++;
			}
		//	std::cout << "Qoutient -> " << q << " Remainder -> " << r << std::endl;
		}
	} 
				
    return r;}
	

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
OI modulus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
	std::vector<int> rem;
	std::vector<int> rem_temp;
	std::vector<int> m_temp(e2-b2+1);
	int q_length = (e1 - b1) - (e2 - b2);
	int d2 = (*b2 * 10) + *(b2+1);
	int di3 = 0;
	int qe = 0;
	int lge = -1;
	int comp = comparison(b1 , e1, b2, e2);


    if ( (e2 - b2) == 1) {
		return divides_digits_2(b1, e1, b2, x);
	} else if ( (e1 - b1) < (e2 - b2) ) {
		std::copy(b1, e1, x);
		x += (e1 - b1);
	} else if ( (e1 - b1) == (e2 - b2)  && comp < 2 ){
				
		if (comp == 0) {
			*x = 1;
			x++;
		} else if (comp == 1) {
			std::copy(b1, e1, x);
			x += (e1 - b1);
		} 
	} else {
		
		for (int c = 0; c < (e2 - b2); c ++) {
			rem.push_back((*(b1 + c)));  
			rem_temp.push_back(*(b1 + c));
		}
	/*	std::vector<int>::iterator it = rem_temp.begin();
		
		while (it != rem_temp.end()){
			std::cout << *it;
			it++;
		}
		std::cout << std::endl;*/
		
		for (int i = 0; i < q_length+1; i++) {
			
			if ( e2-b2 > 2) {
				di3 = rem[0]*100 + rem[1]*10 + rem[2];
			} else {
				di3 = rem[0]*100 + rem[1]*10;
			}
			qe = di3/d2;
			if (qe > 9) {
				qe = 9;
			} //rem_temp.end();
			std::vector<int>::iterator rt_end = multiplies_digits_2(b2, e2, qe, rem_temp.begin());
			//std::cout << "Mult"  << std::endl;   
			lge = comparison(rem_temp.begin(), rt_end, rem.begin(), rem.end());
			//std::cout << "Comp " << std::endl;

			if (lge == 0) {
				*x = qe;
				x++;
				rem.clear();
				rem.push_back(*(b1+q_length+i));
				m_temp.clear();
			} else if (lge == 1) {
				while (lge == 1 && qe < 10) {
					qe++;
					std::vector<int>::iterator rt_end = multiplies_digits_2(b2, e2, qe, rem_temp.begin());
					lge = comparison(rem_temp.begin(), rt_end, rem.begin(), rem.end());
				}			
				if (qe != 0) {
					*x = qe - 1;
					x++;
				} else {
					rem.push_back(0);
				}
				
				//*x = qe - 1;
				std::vector<int>::iterator rt_end = multiplies_digits_2(b2, e2, qe-1, rem_temp.begin());

				std::cout << std::endl;
				std::vector<int>::iterator m_e = minus_digits(rem.begin(), rem.end(), rem_temp.begin(), rt_end, m_temp.begin());
				std::vector<int>::iterator m_b = m_temp.begin();
				rem.clear();
				bool flag = true;
				while (m_b != m_e) {
					if (*m_b == 0 && flag){
						m_b++;
					} else if (*m_b != 0) {
						flag = true;
						rem.push_back(*m_b);
						m_b++;
					} else {
						rem.push_back(*m_b);
						m_b++;
					}
				}
				rem.push_back(*(b1+q_length+i));
				m_temp.clear();
				//rem = m_temp;
				
				

				
				//x++;
			} else if (lge == 2) {;
				while (lge == 2 && qe != 0) {
					qe--;
					std::vector<int>::iterator rt_end = multiplies_digits_2(b2, e2, qe, rem_temp.begin());
					lge = comparison(rem_temp.begin(), rt_end, rem.begin(), rem.end());
				}
				if (qe != 0) {
					*x = qe;
					x++;
					std::vector<int>::iterator m_e = minus_digits(rem.begin(), rem.end(), rem_temp.begin(), rt_end, m_temp.begin());
					std::vector<int>::iterator m_b = m_temp.begin();
					rem.clear();
					bool flag = true;
					while (m_b != m_e) {
						if (*m_b == 0 && flag){
							m_b++;
						} else if (*m_b != 0) {
							flag = true;
							rem.push_back(*m_b);
							m_b++;
						} else {
							rem.push_back(*m_b);
							m_b++;
						}
					}
					rem.push_back(*(b1+q_length+i));
					m_temp.clear();
				} else {
					if (i == q_length) {
						*x = 0;
						x++;
					}
					rem.push_back(*(b1+q_length+i));
				}
				
			}
		}

		
	}
	
    return rem;}

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
		* @param lhs the left hand operand
		* @param rhs the right hand operand
		* @return true if lhs is equal to rhs, false otherwise
		 */
        friend bool operator == (const Integer& lhs, const Integer& rhs) {
			if (lhs.polarity != rhs.polarity)
				return false;
						
			if (lhs.digits.size() != rhs.digits.size()) {
				return false;
			} else {
				for (unsigned int i = 0; i < lhs.digits.size(); i++) {
					if(lhs.digits[i] != rhs.digits[i]){
						return false;
					}
				}
			}
            return true;}

        // -----------
        // operator !=
        // -----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return true if lhs is not equal to rhs, false otherwise
		 */
        friend bool operator != (const Integer& lhs, const Integer& rhs) {
            return !(lhs == rhs);}

        // ----------
        // operator <
        // ----------

        /**
         * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return true if lhs is less than rhs, false otherwise
         */
        friend bool operator < (const Integer& lhs, const Integer& rhs) {
			if( !lhs.polarity && !rhs.polarity )
				return -lhs > -rhs;
			
			if( !lhs.polarity && rhs.polarity )
				return true;
			if( lhs.polarity && !rhs.polarity )
				return false;
			
			if( lhs.digits.size() < rhs.digits.size() )
				return true;
			if( lhs.digits.size() > rhs.digits.size() )
				return false;
			
			typename C::const_reverse_iterator lhs_it, rhs_it;
			for (lhs_it = lhs.digits.rbegin(), rhs_it = rhs.digits.rbegin(); lhs_it != lhs.digits.rend() && rhs_it != rhs.digits.rend(); lhs_it++, rhs_it++ ) {
				if( *lhs_it > *rhs_it )
					return false;
				
				if( *lhs_it < *rhs_it )
					return true;
			}
			
			return false;
        }

        // -----------
        // operator <=
        // -----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return true if lhs is less than or equal to rhs, false otherwise
		 */
        friend bool operator <= (const Integer& lhs, const Integer& rhs) {
            return !(rhs < lhs);}

        // ----------
        // operator >
        // ----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return true if lhs is g rhs, false otherwise
		 */
        friend bool operator > (const Integer& lhs, const Integer& rhs) {
            return (rhs < lhs);}

        // -----------
        // operator >=
        // -----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return true if lhs is greater than or equal to rhs, false otherwise
		 */
        friend bool operator >= (const Integer& lhs, const Integer& rhs) {
            return !(lhs < rhs);}

        // ----------
        // operator +
        // ----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return the sum of lhs and rhs
		 */
        friend Integer operator + (Integer lhs, const Integer& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return the difference of lhs and rhs
		 */
        friend Integer operator - (Integer lhs, const Integer& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator *
        // ----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return the product of lhs and rhs
		 */
        friend Integer operator * (Integer lhs, const Integer& rhs) {
            return lhs *= rhs;}

        // ----------
        // operator /
        // ----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return the quotient of lhs and rhs
		 * @throws invalid_argument if (rhs == 0)
         */
        friend Integer operator / (Integer lhs, const Integer& rhs) {
            return lhs /= rhs;}

        // ----------
        // operator %
        // ----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return the remainder of lhs / rhs
		 * @throws invalid_argument if (rhs <= 0)
         */
        friend Integer operator % (Integer lhs, const Integer& rhs) {
            return lhs %= rhs;}

        // -----------
        // operator <<
        // -----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return lhs left-shifted by rhs digits
		 */
        friend Integer operator << (Integer lhs, int rhs) {
            return lhs <<= rhs;}

        // -----------
        // operator >>
        // -----------

        /**
		 * @param lhs the left hand operand
		 * @param rhs the right hand operand
		 * @return lhs right-shifted by rhs digits
		 */
        friend Integer operator >> (Integer lhs, int rhs) {
            return lhs >>= rhs;}

        // -----------
        // operator <<
        // -----------

        /**
		 * @param lhs the output stream to use
		 * @param rhs the Integer to output
		 * @return lhs
		 */
        friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
			if (!rhs.polarity)
				lhs << "-";
			
            typename C::const_reverse_iterator it = rhs.digits.rbegin();
			while( it != rhs.digits.rend() )
				lhs << *it++;
            return lhs;
		}

        /**
         * absolute value
		 * @param x an Integer
		 * @return the absolute value of x (without modifying x)
		 */
        friend Integer abs (Integer x) {
            return x.abs();}

        /**
         * power
		 * @param x the Integer
		 * @param e the power to exponentiate to
		 * @return x^e
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
			/*
			for (unsigned int i = 0; i < digits.size(); i++) {
				if (digits[i] > 9 || digits[i] < 0)
					return false;
			}*/
			typename C::const_iterator it;
			for( it = digits.begin(); it < digits.end(); it++ )
				if( (*it) > 9 || (*it) < 0 )
					return false;
			
			return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * @param value the value to assign to the Integer
         */
        Integer (int value) {
			if( value < 0 ) {
				polarity = false;
				value = -value;
			} else 
				polarity = true;
				
			while( value != 0 ) {
// 				std::cout << value << ",  " << value % 10 << ",  " << value / 10  << std::endl;
				digits.push_back( value % 10 );
				value /= 10;
			}
// 			for( unsigned int i = digits.size()-1; i >= 0; i-- )
// 				std::cout << digits[i];
//  			std::cout << digits.size() << std::endl;
			assert(valid());}

        /**
		 * @param x Integer to copy
		 */
		Integer (const Integer& x) {
			digits = x.digits;
			polarity = x.polarity;
			assert(valid());
		}
			
        /**
		 * @param value the value to assign to the Integer
		 * @throws invalid_argument if value is not a valid representation of an Integer
         */
        explicit Integer (const std::string& value) {
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
            Integer i = *this;
			i.polarity = !i.polarity;
            return i;
		}

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
         * @param rhs An integer to add to the current Integer
		 * @return This Integer after rhs has been added to it
         */
        Integer& operator += (const Integer& rhs) {
			
			T carry = 0, sum;
			typename C::iterator lhs_it = digits.begin();
			typename C::const_iterator rhs_it = rhs.digits.begin();
						
			if( rhs.polarity != polarity)
				return *this -= -rhs;
			
			// lhs is smaller than rhs
            if( rhs.digits.size() > digits.size() ) {
				while( lhs_it != digits.end() ) {
					sum = *lhs_it + *rhs_it + carry;
					*lhs_it = sum % 10;
					carry = sum / 10;
					lhs_it++;
					rhs_it++;
				}

				while( rhs_it != rhs.digits.end() ) {
					sum = *rhs_it + carry;
					digits.push_back(sum % 10);
					carry = sum / 10;
					rhs_it++;
				}
				
				if (carry > 0)
					digits.push_back(carry);
			} else {
			// rhs is smaller than lhs
				while( rhs_it != rhs.digits.end() ) {
					sum = *lhs_it + *rhs_it + carry;
					*lhs_it = sum % 10;
					carry = sum / 10;
					lhs_it++;
					rhs_it++;
				}

				while( carry != 0 && lhs_it != digits.end() ) {
					sum = *lhs_it + carry;
					*lhs_it = sum % 10;
					carry = sum / 10;
					lhs_it++;
				}
				
				if (carry > 0)
					digits.push_back(carry);
			}
				
				
            return *this;
        }

        // -----------
        // operator -=
        // -----------

        /**
         * @param rhs the Integer to subtract
		 * @return This integer, which contains the difference after subtracting rhs
         */
        Integer& operator -= (const Integer& rhs) {
			
			bool borrow = 0;
			T diff;
			typename C::iterator lhs_it = digits.begin();
			typename C::const_iterator rhs_it = rhs.digits.begin();
			
						
			if( rhs.polarity != polarity)
				return *this += -rhs;
			
			if( (polarity && rhs > *this) || (!polarity && rhs < *this) ) {
				*this = rhs - *this;
				polarity = !polarity;
				return *this;
			}
			
			while( rhs_it != rhs.digits.end() ) {
				diff = *lhs_it - *rhs_it - borrow;
				if( diff < 0 ) {
					borrow = true;
					diff += 10;
				} else
					borrow = false;
				*lhs_it = diff;
				lhs_it++;
				rhs_it++;
			}
				
			while( borrow && lhs_it != digits.end() ) {
				diff = *lhs_it - borrow;
				if( diff < 0 )
					diff += 10;
				else 
					borrow = false;
				*lhs_it = diff;	
				lhs_it++;
			}
			
			while( digits.back() == 0 )
				digits.erase( digits.end()-1 );
			
			return *this;
		}

        // -----------
        // operator *=
        // -----------

        /**
         * @param rhs the Integer to multiply by
		 * @return This integer, which contains the product with rhs
         */
        Integer& operator *= (const Integer& rhs) {
			typename C::const_iterator lhs_it, rhs_it = rhs.digits.begin();
			C product;
			typename C::iterator p_it;
			int pad = 0, carry = 0;
	
			// do the multiplication
			while( rhs_it != rhs.digits.end() ) {
				p_it = product.begin() + pad++;
				
				for( lhs_it = digits.begin(); lhs_it != digits.end(); lhs_it++ ) {
					if( p_it == product.end() ) {
						product.push_back(0);
						p_it = product.end()-1;
					}
					*p_it += *rhs_it * *lhs_it;
					p_it++;
				}
				rhs_it++;
			}
			
			// calculate the carries
			for( p_it = product.begin(); p_it != product.end(); p_it++ ) {
				*p_it += carry;
				carry = *p_it / 10;
				*p_it %= 10;
			}
	
			while( carry != 0 ) {
				product.push_back(0);
				p_it = product.end()-1;
				*p_it += carry;
				carry = *p_it / 10;
				*p_it %= 10;
				p_it++;
			}
	
			digits = product;
			polarity = (polarity == rhs.polarity);
		
			return *this;
		}

        // -----------
        // operator /=
        // -----------

        /**
         * @param rhs the Integer to divide by
		 * @return This integer, which contains the quotient after dividing by rhs
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
			C temp;
			divides_digits(digits.begin(), digits.end(), rhs.digits.begin(), rhs.digits.end(), temp.begin());
			digits = temp;
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * @param rhs the Integer to divide by
		 * @return This integer, which contains the remainder after dividing by rhs
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
			C temp;
			modulus_digits(digits.begin(), digits.end(), rhs.digits.begin(), rhs.digits.end(), temp.begin());
			digits = temp;
            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * @param n the number of digits to shift by
		 * @return This integer, which contains the digit-shifted Integer
         */
        Integer& operator <<= (int n) {
            for (int i = 0; i < n; i++){
				digits.insert( digits.begin() ,0 );
			}
            return *this;
        }

        // ------------
        // operator >>=
        // ------------

        /**
         * @param n the number of digits to shift by
		 * @return This integer, which contains the digit-shifted Integer
         */
        Integer& operator >>= (int n) {
            for (int i = 0; i < n; i++) {
				digits.erase(0);
			}
            return *this;
        }

        // ---
        // abs
        // ---

        /**
         * absolute value
         * @return This integer, which contains the result of the absolute value operation
         */
        Integer& abs () {
            polarity = true;
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * @param e the exponent
         * @return this to the power e (modifying this)
         * @throws invalid_argument if (this == 0) && (e == 0)
         * @throws invalid_argument if (e < 0)
         */
        Integer& pow (int e) {
			if( e < 0 )
				throw std::invalid_argument("Integer::pow()");
			else if( e == 0 ) {
				if( *this == 0 )
					throw std::invalid_argument("Integer::pow()");

				return *this = 1;
			}
			if( *this == 0 )
				return *this;
			
			if( e == 1 )
				return *this;
			
			Integer mult = *this * *this;
			if( e % 2 == 0 )     // e is even
				*this = mult.pow( e/2 );
			else                 // e is odd
				*this = *this * mult.pow( e/2 );

			return *this;
		}

        // ---
        // numDigits
        // ---

        /**
         * numDigits
         * @return the number of digits the integer contains
         */
        int numDigits () const {
        	return digits.size();
        }
};

#endif // Integer_h
