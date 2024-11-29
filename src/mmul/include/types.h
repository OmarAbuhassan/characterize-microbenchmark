/* types.h
 *
 * Author: Omar Abuhassan
 * Date  :
 * 
 * This file contains all required types decalartions.
*/

#ifndef __INCLUDE_TYPES_H_
#define __INCLUDE_TYPES_H_

typedef struct {
  float*   input0;
  float*   input1;
  float*   output;

  int m_size;

  int     cpu;
  int     nthreads;
} args_t;

#endif //__INCLUDE_TYPES_H_
