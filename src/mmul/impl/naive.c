/* naive.c
 *
 * Author: Omar Abuhassan
 * Date  :
 *
 *  Description
 */

/* Standard C includes */
#include <stdlib.h>
#include <stdio.h>

/* Include common headers */
#include "common/macros.h"
#include "common/types.h"

/* Include application-specific headers */
#include "include/types.h"

/* Naive Implementation */
#pragma GCC push_options
#pragma GCC optimize ("O1")
void* impl_scalar_naive(void* args)
{
  /* Get the argument struct */
  args_t *parsed_args = (args_t *)args;

  /* Get all the arguments */
  // hint the compiler to save the value in a register
  register int m_size = parsed_args->m_size;

  register float *dest = (float *)(parsed_args->output);
  register const float *src0 = (const float *)(parsed_args->input0);
  register const float *src1 = (const float *)(parsed_args->input1);

  if (!dest || !src0 || !src1)
  {
    printf("Memory allocation error: One or more matrices are unallocated.\n");
    return NULL;
  }

  for (register int i = 0; i < m_size; i++)
  {
    for (register int j = 0; j < m_size; j++)
    {
      for (register int k = 0; k < m_size; k++)
      {
        dest[i * m_size + j] += src0[i * m_size + k] * src1[k * m_size + j];
      }
    }
  }
  return NULL;
}
#pragma GCC pop_options
