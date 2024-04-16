#include "matmul.h"
#include <stdio.h>


extern void matmul(int n, int* matrix_a, int* matrix_b, int* matrix_c);

// See LICENSE for license details.

//**************************************************************************
// Multithreaded matrix multiply benchmark
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Basic Utilities and Multithreading Support
#include "util.h"

int main(void)
{
    static data_t output_data[ARRAY_SIZE];

    struct stats st;

    stats_init(&st);
    matmul(DIM_SIZE, input1_data, input2_data, output_data);

        // Last thread collects statistics and checks result
        int rc;
        stats_print(&st, stringify(MATMUL_FUNC), DIM_SIZE * DIM_SIZE * DIM_SIZE);
        rc = verify(ARRAY_SIZE, output_data, verify_data);
        if (rc != 0) {
            puts("\nactual matrix: ");
            print_matrix(output_data, DIM_SIZE, DIM_SIZE);
            puts("\ncorrect matrix: ");
            print_matrix(verify_data, DIM_SIZE, DIM_SIZE);
        }
        return rc;
}

