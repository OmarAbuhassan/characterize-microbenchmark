/* ref.c
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

/* Reference Implementation */
void* impl_ref(void* args)
{
  /* Get the argument struct */
  args_t *parsed_args = (args_t *)args;

  /* Get all the arguments */
  // hint the compiler to save the value in a register
  register int m_size = parsed_args->m_size;

  register float *ref = (float *)(parsed_args->output);
  register const float *src0 = (const float *)(parsed_args->input0);
  register const float *src1 = (const float *)(parsed_args->input1);

  if (!ref || !src0 || !src1)
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
        ref[i * m_size + j] += src0[i * m_size + k] * src1[k * m_size + j];
      }
    }
  }
  return NULL;
}
