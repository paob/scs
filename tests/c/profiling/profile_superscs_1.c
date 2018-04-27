/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Pantelis Sopasakis (https://alphaville.github.io),
 *                    Krina Menounou (https://www.linkedin.com/in/krinamenounou), 
 *                    Panagiotis Patrinos (http://homes.esat.kuleuven.be/~ppatrino)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

/* 
 * File:   profile_superscs_1.c
 * Author: Pantelis Sopasakis
 *
 * Created on April 11, 2018, 11:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "scs.h"
#include "scs_parser.h"


#ifndef SCS_DIR
#define SCS_DIR restarted_broyden
#endif

#ifndef SCS_MEM
#define SCS_MEM 50
#endif

#ifndef SCS_PROF_EPS
#define SCS_PROF_EPS 1e-6
#endif

#ifndef PROBLEM_YAML_FILE
    #if(defined _WIN32 || defined _WIN64 || defined _WINDLL)
        #define PROBLEM_YAML_FILE "tests\\c\\data\\test-1.yml"
    #else
        #define PROBLEM_YAML_FILE "tests/c/data/test-1.yml"
    #endif
#endif

int main(int argc, char** argv) {
    ScsData * data = SCS_NULL;
    ScsCone * cone = SCS_NULL;
    ScsInfo * info = scs_init_info();
    ScsSolution * sol = scs_init_sol();
    const char * filepath = (char *) (PROBLEM_YAML_FILE);
    scs_int status;

    status = scs_from_YAML(filepath, &data, &cone);

    if (status != 0) {
        printf("Parsing of %s failed (status code = %d)!\n", filepath, status);
        return 2;
    }

    if (restarted_broyden == SCS_DIR) {
        scs_set_restarted_broyden_settings(data, (scs_int) (SCS_MEM));
    } else if (anderson_acceleration == SCS_DIR) {
        scs_set_anderson_settings(data, (scs_int) (SCS_MEM));
    } else {
        scs_set_default_settings(data);
        data->stgs->memory = (scs_int) (SCS_MEM);
        data->stgs->direction = (ScsDirectionType) (SCS_DIR);
    }
    scs_set_tolerance(data, SCS_PROF_EPS);

    status = scs(data, cone, sol, info);

    printf("status = %d\n", status);

    scs_free_data(data, cone);
    scs_free_info(info);
    scs_free_sol(sol);

    return (EXIT_SUCCESS);
}

