/* opt.c
 *
 * Author: Omar Abuhassan
 * Date  :
 *
 * Optimized Implementation using Blocking (Tiling)
 */

/* Standard C includes */
#include <stdlib.h>
#include <stdio.h>

/* Include common headers */
#include "common/macros.h"
#include "common/types.h"

/* Include application-specific headers */
#include "include/types.h"
#include <algorithm>

#pragma GCC push_options
#pragma GCC optimize ("O1")
void* impl_scalar_opt(void* args)
{
  /* Get the argument struct */
  args_t *parsed_args = (args_t *)args;

  /* Get all the arguments */
  register int m_size = parsed_args->m_size;

  register float *dest = (float *)(parsed_args->output);
  register const float *src0 = (const float *)(parsed_args->input0);
  register const float *src1 = (const float *)(parsed_args->input1);

  if (!dest || !src0 || !src1)
  {
    printf("Memory allocation error: One or more matrices are unallocated.\n");
    return NULL;
  }

  register int block_size = 32;

  for (register int ii = 0; ii < m_size; ii += block_size) {
    for (register int jj = 0; jj < m_size; jj += block_size) {
      for (register int kk = 0; kk < m_size; kk += block_size) {

        register int i_end = std::min(ii + block_size, m_size);
        register int j_end = std::min(jj + block_size, m_size);
        register int k_end = std::min(kk + block_size, m_size);

        for (register int i = ii; i < i_end; i++) {
          for (register int j = jj; j < j_end; j++) {
            register float val = dest[i * m_size + j];
            for (register int k = kk; k < k_end; k++) {
              val += src0[i * m_size + k] * src1[k * m_size + j];
            }
            dest[i * m_size + j] = val;
          }
        }

      } 
    } 
  }

  return NULL;
}
#pragma GCC pop_options
