/* 
 * <Please put your name and userid here>
 * Leo Betancourt
 * lkb9719
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif

//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // isolate common 1 bits
  int a = x & y;
  // isolate common 0 bits (represented as ones in b)
  int b = ~x & ~y;
  // only activate (make 1) bits that are not commonly 1 or 0.
  int c = ~a & ~b;
  return c;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // the min two's complement integer has a 1 in the most significant bit
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  // will be 0 when x is TMax
  int a = ~((x + 1) ^ x);
  // ensures no overflow (x is all ones)
  int b = !(x + 1);
  int c = !(a + b);
  return c;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // creates a bit mask with all odd bits equal to 1
  int oddBitMask = (0xAA << 24) + (0xAA << 16) + (0xAA << 8) + 0xAA;
  // mask x, and find differences in bit pattern compared to the mask
  // if there are any differences, return 0 
  int masked = x & oddBitMask;
  int result = !(masked ^ oddBitMask);

  return result;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // the two's complement of a signed integer is given by this equation
  return (~x + 1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 1 in sign bit position
  int negMask = 1 << 31;

  // x - 0x30 >= 0
  int minCheck = !((x + (~0x30 + 1)) & negMask);
  // 0x39 - x >= 0
  int maxCheck = !(((~x + 1) + 0x39) & negMask);
  
  return minCheck & maxCheck;
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // reduce x to: 1 if x is nonzero, 0 if x is 0
  int cond = !!x;
  // mask with all bits equal to cond
  int mask = (cond << 31) >> 31;
  // if x is true, mask will activate all bits in y
  // if x is false, mask will activate all bits in z
  int result = (y & mask) | (z & ~mask);

  return result;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // y - x >= 0
  int negMask = 1 << 31;
 
  // sign bits for x and y 
  int msb_x = x >> 31;
  int msb_y = y >> 31;
  // 1 if bits are differing, 0 if same
  int diff = msb_x ^ msb_y;

  // test y - x >= 0 
  int inequality = y + ~x + 1;
  int isNegative = (inequality & negMask) >> 31;
  // if msb are not differing, overflow isn't possible so evaluate normally
  // if x is negative and y is positive, return 1
  return (!diff & !isNegative) | (msb_x & !msb_y);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int msb = x >> 31;
  int ones = ~0x0;
  // will result in overflow if x is nonzero
  int sum = x + ones;
  // will result in 0 if x is nonzero
  int result = (sum >> 31) & 0x1;
  return ~msb & result;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int numBits = 0;
  // if sign bit is 0, x is left unchanged
  x = x ^ (x >> 31); 
  numBits = numBits + ((!!(x >> (numBits + 16))) << 4);
  numBits = numBits + ((!!(x >> (numBits + 8))) << 3);
  numBits = numBits + ((!!(x >> (numBits + 4))) << 2);
  numBits = numBits + ((!!(x >> (numBits + 2))) << 1);
  numBits = numBits + ((!!(x >> (numBits + 1))));
  numBits = numBits + (x >> numBits);
  return numBits + 1;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legalops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  unsigned signMask = 0x1 << 31;
  int sign = uf & signMask;
  int M = (uf << 9) >> 9;
  int e = (uf << 1) >> 24;
  int result = 0;

  if (e == 0 && M == 0) return uf;
  // f is NaN, so return uf
  if (e == 0xff) return uf;
  if (e == 0x0) return (uf << 1) | sign;
  
  e++;
  // if exponent becomes all ones, result is NaN
  if (e == 0xff) return (sign | (e << 23));
 
  // reformat float 
  result = (sign | (e << 23) | M);
  return result;
}

/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  unsigned sign = x & (0x1 << 31);
  unsigned shiftLeft = 0, flag = 0, tmp;
  unsigned absX = x;
  
  if (x == 0) return 0;
  if (x < 0) absX = -x;

  // compute exp field 
  while (1) {
    tmp = absX;
    absX <<= 1;
    shiftLeft++;
    // shifted all the way to bit 31
    if (tmp & (0x1 << 31)) break;
  }

  // round to even
  if ( (absX & (~((0x1 << 31) >> 22))) > (0x1 << 8)) flag = 1;
  if ( (absX & (~((0x1 << 31) >> 21))) == ((0x1 << 9) + (0x1 << 8))) flag = 1;
 
  // format string as 1 sign bit, 8 exponent bits and 23 mantissa bits 
  return sign + (absX >> 9) + ((159-shiftLeft) << 23) + flag;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  // exponent E
  int e = ((uf >> 23) & 0xff)-127;
  int sign = uf >> 31;
  // mantissa (must re-add 1 bit in position 23)
  int M = ((uf << 9) >> 9) | (1 << 23);
  int overflow = 0x1 << 31;

  // all bits of f are 0, so the number is 0
  if (uf == 0) return 0;
  // outside the range of int
  if (e > 31) return overflow;
  // f < 1, so the int conversion gives 0
  if (e < 0) return 0;

  // apply exponent to mantissa
  // shift right by effective amount (because mantissa
  // is already "shifted" left by 23 bits)
  if (e > 23)
    M <<= (e - 23);
  else // shift left by effective exponent
    M >>= (23 - e);

  // all 31 bits are occupied in M, so overflow 
  // (must have 1 bit for sign)
  if (M >> 31)
    return overflow;
  // if matissa already has correct sign bit, simply return it
  if (!((M >> 31) ^ sign))
    return M;
  
  // M has wrong sign, so return one's complement of M to flip sign
  return ~M + 1;
}
