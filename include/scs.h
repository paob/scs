/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Pantelis Sopasakis (https://alphaville.github.io),
 *                    Krina Menounou (https://www.linkedin.com/in/krinamenounou), 
 *                    Panagiotis Patrinos (http://homes.esat.kuleuven.be/~ppatrino)
 * Copyright (c) 2012 Brendan O'Donoghue (bodonoghue85@gmail.com)
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
#ifndef SCS_H_GUARD
#define SCS_H_GUARD

#include "glbopts.h"
#include <string.h>
#include "cones.h"
#include "linAlg.h"
#include "linSys.h"
#include "util.h"
#include "ctrlc.h"
#include "constants.h"
#include <math.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Length of character arrays in #ScsConicProblemMetadata.
     */
#define SCS_METADATA_TEXT_SIZE 1024

    /**
     * \brief Metadata for conic optimization problems.
     * 
     * All fields of this structure are character arrays of a fixed length, 
     * equal to #SCS_METADATA_TEXT_SIZE.
     * 
     * \sa scs_to_YAML
     * \sa scs_from_YAML
     */
    typedef struct scs_conic_probem_metadata {
        /**
         * \brief Unique identifier of the conic problem.
         * 
         * This can be, for example, a URI.
         */
        char id[SCS_METADATA_TEXT_SIZE];
        /**
         * \brief Problem name.
         */
        char problemName[SCS_METADATA_TEXT_SIZE];
        /**
         * \brief License of the problem data.
         * 
         * If applicable, link (URL) to a license.
         */
        char license[SCS_METADATA_TEXT_SIZE];
        /**
         * \brief Creator of the problem.
         */
        char creator[SCS_METADATA_TEXT_SIZE];
        /**
         * \brief YAML version.
         */
        char yamlVersion[SCS_METADATA_TEXT_SIZE];
        /**
         * \brief Creation date.
         */
        char date[SCS_METADATA_TEXT_SIZE];
    } ScsConicProblemMetadata;

    /**
     * \brief Initializes a #ScsConicProblemMetadata structure.
     * 
     * This function creates and initializes a #ScsConicProblemMetadata structure. 
     * It sets the problem name to a given value and initializes all other
     * fields with their default values as follows:
     * 
     * - \ref ScsConicProblemMetadata.id "id": URI of the problem which is <code>%http://superscs.org/problem/{problemName}</code>
     * - \ref ScsConicProblemMetadata.date "date": current date
     * - \ref ScsConicProblemMetadata.license "license": URL of <a href="https://github.com/kul-forbes/scs/blob/master/LICENSE.txt">SuperSCS's license</a>
     * - \ref ScsConicProblemMetadata.yamlVersion "yamlVersion": 1.2
     * - \ref ScsConicProblemMetadata.creator "creator": the \ref #scs_version "current SuperSCS version"
     * 
     * @param problemName problem name
     * @return New instance of #ScsConicProblemMetadata
     * 
     * \sa #scs_to_YAML
     */
    ScsConicProblemMetadata * scs_init_conic_problem_metadata(const char * problemName);

    /**
     * \brief Memory for the computation of directions (Broyden and Anderson's methods).
     * 
     * For Broyden's method, a cache of \f$(s_i, u_i)\f$ where 
     * \f$u_i = \frac{s_i - \tilde{s}_i}{\langle s_i, \tilde{s}_i\rangle}\f$.
     * We do not need to store past values of \f$\tilde{s}_i\f$.
     * 
     * For Anderson's acceleration, it stores pairs \f$(s_i, y_i)\f$.
     * 
     * 
     */
    struct scs_direction_cache {
        scs_float *S; /**< \brief cached values of \f$s_i\f$ (s-memory) */
        scs_float *U; /**< \brief cached values of \f$u_i = \frac{s_i - \tilde{s}_i}{\langle s_i, \tilde{s}_i\rangle}\f$, or cached values of \f$y_i\f$ */
        scs_float *S_minus_Y; /**< \brief The difference \f$S-Y\f$ (for Anderson's acceleration) */
        scs_float *t; /**< \brief Solution of the linear system \f$Yt = R(x)\f$ */
        scs_int ls_wspace_length; /**< \brief Length of workspace used to solve Anderson's linear system */
        scs_float * ls_wspace; /**< \brief Workspace used to solve Anderson's linear system */
        scs_int mem_cursor; /**< \brief current memory cursor [0..mem-1] */
        scs_int mem; /**< \brief (target/maximum/allocated) memory */
        scs_int current_mem; /**< \brief current memory length */
    };

    /**
     *  \brief Workspace for SCS 
     */
    struct scs_work {
        /**
         *  \brief Row dimension of \f$A\f$. 
         */
        scs_int m;
        /**
         *  \brief Column dimension of \f$A\f$.
         */
        scs_int n;
        /**
         *  \brief Dimension of \f$u_k\f$, that is \f$l = m + n + 1\f$ .
         */
        scs_int l;
        /**
         * \brief Vector \f$u_k=(x_k,y_k,\tau_k)\f$.
         */
        scs_float *RESTRICT u;
        /**
         * \brief Vector \f$v_k = Qu_k\f$ (used only in SCS, not in SuperSCS).
         */
        scs_float *RESTRICT v;
        /**
         * \brief Vector \f$\tilde{u}_k\f$.
         */
        scs_float *RESTRICT u_t;
        /**
         * \brief Vector \f$u_{k-1}\f$ of the previous iteration.
         */
        scs_float *RESTRICT u_prev;
        /**
         * \brief Vector \f$\bar{u}_k\f$.
         */
        scs_float *RESTRICT u_b;
        /**
         * \brief Auxiliary variable used in projections on linear spaces.
         */
        scs_float *RESTRICT h;
        /**
         * \brief Auxiliary variable of dimension \f$l-1\f$ used in projections on linear spaces.
         */
        scs_float *RESTRICT g;
        /**
         * \brief Primal residual vector
         * 
         * \f[
         *  \text{pr} = A x + s - b \tau,
         * \f]
         * and in SuperSCS, \f$x\f$ is \f$\bar{x}\f$, \f$s\f$ is \f$\bar{s}\f$
         * and \f$\tau\f$ is \f$\bar{\tau}\f$
         */
        scs_float *RESTRICT pr;
        /**
         * \brief Dual residual vector
         * 
         * \f[
         *  \text{dr} = A'y + c \tau,
         * \f]
         * and in SuperSCS, \f$y\f$ is \f$\bar{y}\f$ and \f$\tau\f$ is \f$\bar{\tau}\f$.
         */
        scs_float *RESTRICT dr;
        /**  
         * \brief The (possibly normalized) vector \f$b\f$.
         */
        scs_float *RESTRICT b;
        /**  
         * \brief The (possibly normalized) vector \f$c\f$.
         */
        scs_float *RESTRICT c;
        /**  
         * \brief Fixed-point residual \f$R_k\f$.
         */
        scs_float *RESTRICT R;
        /**  
         * \brief Fixed-point residual (FPR) of the previous iteration \f$R_{k-1}\f$.
         */
        scs_float *RESTRICT R_prev;
        /**
         * \brief Direction \f$d_k\f$
         */
        scs_float *RESTRICT dir;
        /**
         * \brief Hessian approximation used by the full Broyden method.
         * 
         * @see ::full_broyden
         */
        scs_float *RESTRICT H;
        /** 
         * \brief Direction corresponding to \f$\tilde{u}\f$.
         */
        scs_float *RESTRICT dut;
        /**
         * \brief Variable \f$w_u\f$.
         */
        scs_float *RESTRICT wu;
        /**
         * \brief Variable \f$\tilde{w}_u\f$.
         */
        scs_float *RESTRICT wu_t;
        /**
         * \brief Variable \f$\bar{w}_u\f$.
         */
        scs_float *RESTRICT wu_b;
        /**
         * \brief Vector \f$R(w_u)\f$ from line search.
         */
        scs_float *RESTRICT Rwu;
        /** 
         * \brief \f$\|Ru_k\|\f$. 
         */
        scs_float nrmR_con;
        /**
         *  \brief \f$s_k = u_k - u_{k-1}\f$ 
         */
        scs_float *RESTRICT Sk;
        /** 
         * \brief \f$y_k = R_k - R_{k-1}\f$ 
         */
        scs_float *RESTRICT Yk;
        /** 
         * \brief The current stepsize \f$t_k\f$
         */
        scs_float stepsize;
        /** 
         * \brief Variable that corresponds to the primal slack for the 2nd step of DRS 
         */
        scs_float *RESTRICT s_b;
        /**
         * \brief Auxiliary variable.
         */
        scs_float gTh;
        /**
         * \brief Scaling factor corresponding to \f$b\f$
         */
        scs_float sc_b;
        /**
         * \brief Scaling factor corresponding to \f$c\f$
         */
        scs_float sc_c;
        /**
         * \brief Norm of \f$b\f$
         */
        scs_float nm_b;
        /**
         * \brief Norm of \f$c\f$
         */
        scs_float nm_c;
        /** 
         * \brief Variable for certificates of infeasibility/unboudedness 
         */
        scs_float kap_b;
        /**
         *  \brief The (possibly normalized) \c A matrix 
         */
        ScsAMatrix * A;
        /** 
         * \brief struct populated by linear system solver 
         */
        ScsPrivWorkspace *RESTRICT p;
        /** 
         * \brief contains solver settings specified by user 
         */
        ScsSettings *RESTRICT stgs;
        /**
         * \brief contains the re-scaling data 
         */
        ScsScaling *RESTRICT scal;
        /** 
         * \brief workspace for the cone projection step 
         */
        ScsConeWork *RESTRICT coneWork;
        /**
         * \brief A cache for the computation of Broyden or Anderson's acceleration.
         */
        ScsDirectionCache *RESTRICT direction_cache;
    };

    /**
     *  \brief struct containing problem data 
     */
    struct scs_data {
        /* these cannot change for multiple runs for the same call to scs_init */
        /**
         *  row dimension of \f$A\f$ 
         */
        scs_int m;
        /**
         *  column dimension of \f$A\f$
         */
        scs_int n;
        /**
         * Sparse matrix <code>A</code> is supplied in data format specified by 
         * linsys solver 
         */
        ScsAMatrix *A;
        /* these can change for multiple runs for the same call to scs_init */

        /* dense arrays for b (size m), c (size n) */

        /**
         * Vector <code>b</code>
         */
        scs_float *RESTRICT b;
        /**
         * Vector <code>c</code>
         */
        scs_float *RESTRICT c;
        /**
         * Pointer to solver settings specified by user 
         */
        ScsSettings *RESTRICT stgs;
    };

    /**
     * \brief Settings structure
     */
    struct scs_settings {
        /* settings parameters: default suggested input */


        /* -------------------------------------
         * General Settings
         * 
         * these *cannot* change for multiple runs 
         * with the same call to scs_init
         * ------------------------------------- */

        /** 
         * Boolean, heuristic data rescaling
         * 
         * Default : 1
         */
        scs_int normalize;

        scs_float scale; /**< if normalized, rescales by this factor: 5 */
        scs_float rho_x; /**< x equality constraint scaling: 1e-3 */


        /* -------------------------------------
         * General Settings
         * 
         * these can change for multiple runs with 
         * the same call to scs_init
         * ------------------------------------- */

        /**
         * Maximum time in milliseconds that the algorithm is allowed to 
         * run.
         * 
         * Default: 5 minutes = 1.5e5 milliseconds.
         */
        scs_float max_time_milliseconds;

        /**
         * Maximum iterations to take.
         * 
         * Default: 2500.
         */
        scs_int max_iters;
        /**
         * Maximum iterations of the previous invocation to SCS.
         * 
         * Used to avoid memory leaks when recording the progress of the algorithm.
         */
        scs_int previous_max_iters;
        /** 
         * Convergence tolerance.
         * 
         * Default: 1e-3 
         */
        scs_float eps;
        /** 
         * Relaxation parameter.
         * 
         * Default : 1.8 
         */
        scs_float alpha;
        /**
         * For indirect, tolerance goes down like <code>(1/iter)^cg_rate</code>.
         * 
         * Default: 2.0
         *  
         */
        scs_float cg_rate;
        /** 
         * Level of verbosity.
         * 
         * Three levels are supported: 0, 1 and 2.
         * 
         * Default : 1
         * 
         */
        scs_int verbose;
        /** 
         * Boolean, warm start (put initial guess in Sol struct): 0 
         */
        scs_int warm_start;

        /* -------------------------------------
         * Settings associated with SuperSCS
         * ------------------------------------- */

        scs_int do_super_scs; /**< boolean: whether to use superscs or not */
        scs_int k0; /**< boolean, K0: 1 */
        scs_float c_bl; /**< parameter for blind updates: 0.999 */
        scs_int k1; /**< boolean, K1: 1 */
        scs_int k2; /**< boolean, K2: 1 */
        scs_float c1; /**< Parameter to check condition at K1 */
        scs_float sse; /**< Parameter to update r_safe at K1 (denoted as \f$q\f$ in the paper) */

        /* -------------------------------------
         * Settings associated with the line 
         * search
         * ------------------------------------- */
        /** 
         * max line-search iterations 
         */
        scs_int ls;
        /**
         * Step size reduction coefficient. 
         * 
         * In every line search iteration, the step size is reduced as 
         * \f$t \leftarrow \beta t\f$.
         */
        scs_float beta;
        /** 
         * Line-search parameter 
         */
        scs_float sigma;

        /* -------------------------------------
         * Settings associated with the direction
         * ------------------------------------- */
        /** 
         * Choice of direction
         * 
         * Default : ::restarted_broyden 
         * 
         * \sa #memory
         */
        ScsDirectionType direction;
        /** 
         * Modified Broyden parameter.
         * 
         * Default : 1e-1 
         */
        scs_float thetabar;
        /** 
         * Memory length for limited-memory Broyden or Anderson's acceleration methods
         * 
         * Default: 10
         * 
         * \sa #direction 
         */
        scs_int memory;
        /**
         * Option for the Broyden direction.
         * 
         * Default: 3
         * 
         * @see ::scs_compute_direction
         */
        scs_int tRule;
        /**
         * Boolean; whether an initial scaling is desired 
         * in the full Broyden method
         * 
         * Default : 0
         */
        scs_int broyden_init_scaling;
        /**
         * Whether to record progress data when running SuperSCS.
         */
        scs_int do_record_progress;

        /**
         * Whether to override the default output stream.
         * 
         * \sa #output_stream
         */
        scs_int do_override_streams;
        /**
         * \brief Output stream where progress information is printed.
         * 
         * \note The default value, as this is defined in ::scs_set_default_settings
         * is <code>stdout</code>.
         * 
         * \note It is important to note that in order for a user-defined output
         * stream to take effect, you need to set \ref scs_settings::do_override_streams 
         * "do_override_streams"
         * to <code>1</code>.
         * 
         * \sa #do_override_streams
         */
        FILE *RESTRICT output_stream;
    };

    /**
     *  \brief Primal-dual solution arrays 
     */
    struct scs_solution {
        /**
         * Primal vector \f$x\f$
         */
        scs_float *RESTRICT x;
        /**
         * Dual vector \f$y\f$
         */
        scs_float *RESTRICT y;
        /**
         * Primal vector \f$s\f$
         */
        scs_float *RESTRICT s;
    };

    /**
     *  \brief Terminating information 
     * 
     * \see ::scs_free_info
     */
    struct scs_info {
        char status[32]; /**< \brief status string, e.g. 'Solved' */
        scs_int iter; /**< \brief number of iterations taken */
        scs_int statusVal; /**< \brief status as scs_int, defined in constants.h */
        scs_int history_length; /**< \brief how many history entries */
        scs_float pobj; /**< \brief primal objective */
        scs_float dobj; /**< \brief dual objective */
        scs_float resPri; /**< \brief primal equality residual */
        scs_float resDual; /**< \brief dual equality residual */
        scs_float resInfeas; /**< \brief infeasibility cert residual */
        scs_float resUnbdd; /**< \brief unbounded cert residual */
        scs_float relGap; /**< \brief relative duality gap */
        scs_float setupTime; /**< \brief time taken for setup phase (milliseconds) */
        scs_float solveTime; /**< \brief time taken for solve phase (milliseconds) */
        scs_float *RESTRICT progress_relgap; /**< \brief relative gap history */
        scs_float *RESTRICT progress_respri; /**< \brief primal residual history */
        scs_float *RESTRICT progress_resdual; /**< \brief dual residual history */
        scs_float *RESTRICT progress_pcost; /**< \brief scaled primal cost history */
        scs_float *RESTRICT progress_dcost; /**< \brief sclaed dual cost history */
        scs_float *RESTRICT progress_norm_fpr; /**< \brief FPR history */
        scs_float *RESTRICT progress_time; /**< \brief Timestamp of iteration */
        scs_int *RESTRICT progress_iter; /**< \brief iterations when residulas are recorded */
        scs_int *RESTRICT progress_mode; /**< \brief Mode of SuperSCS at each iteration */
        scs_int *RESTRICT progress_ls; /**< \brief Number of line search iterations */
        long allocated_memory; /**< \brief Memory, in bytes, that was allocated to run the algorithm */
    };

    /**
     *  \brief Normalization variables 
     */
    struct scs_scaling {
        scs_float *RESTRICT D, *RESTRICT E; /* for normalization */
        scs_float meanNormRowA, meanNormColA;
    };

    /**
     * Creates a new empty solution structure which is to be used 
     * to retrieve the solution \f$(x^\star, y^\star, s^\star)\f$. 
     * 
     * This function does not initialize of allocate memory for \c x, \c s
     * or \c y (but it sets the respective pointers to ::SCS_NULL).
     * 
     * @return Initialized #ScsSolution structure.
     */
    ScsSolution * scs_init_sol(void);

    /**
     * Creates a new empty #ScsInfo structure which is then provided to #scs to get 
     * information about the status of the algorithm (e.g., the duality gap, 
     * the solution status, etc).
     * 
     * @return Initialized #ScsInfo structure.
     */
    ScsInfo * scs_init_info(void);


    /**
     * Creates a new \c #ScsData structure without allocating memory for \f$A\f$, 
     * \f$b\f$ and \f$c\f$ and its sets all settings to their default values, that 
     * is
     * 
     *  1. alpha = 0.5
     *  2. c0 = 0.999
     *  3. c1 = ...
     * 
     * @return #ScsData object
     * 
     * @see ::scs_set_default_settings
     */
    ScsData * scs_init_data(void);

    /** 
     * scs calls \c scs_init, \c scs_solve, and \c scs_finish 
     * 
     * @param d
     * @param k
     * @param sol
     * @param info
     * 
     * @return status code
     * 
     * \remark It is very important that <code>info</code> is created using 
     * ::scs_init_info.
     */
    scs_int scs(
            const ScsData *RESTRICT d,
            const ScsCone *RESTRICT k,
            ScsSolution *RESTRICT sol,
            ScsInfo *RESTRICT info);

    /**
     * Returns the version of SCS
     * 
     * @return 
     */
    const char *scs_version(void);

    /**
     * \brief Converts milliseconds to a <code>00:00:00.0</code> time format
     * 
     * @param time given elapsed time in milliseconds
     * @param hours hours
     * @param minutes minutes
     * @param secs seconds
     * @param sec_rest remaining time in seconds (positive and smaller than \c 1)
     */
    void scs_millis_to_time(scs_float time,
            scs_int * hours,
            scs_int * minutes,
            scs_int * secs,
            scs_float * sec_rest);


    /**
     * Parses a YAML file and constructs/initialises the corresponding #ScsData and #ScsCone
     * objects.
     * 
     * Example of use:
     * 
     * ~~~~~
     * ScsData * data;
     * ScsCone * cone;
     * const char * filepath = "matlab/scs-yaml/example.yml";
     * int status = scs_from_YAML(filepath, &data, &cone);
     * if (status != 0) { 
     *  // handle failure
     * }
     * // use `data` and `cone` ...
     * // at the end don't forget to call `scs_free_data`
     * scs_free_data(data, cone);
     * ~~~~~
     * 
     * @param filepath Absolute or relative path to YAML file
     * @param data pointer-to-pointer to a #ScsData object. This function will 
     * initialise `data` using the YAML file.
     * @param cone pointer-to-pointer to a #ScsCone object. This function will 
     * initialise `cone` using the YAML file.
     * @return status code; returns \c 0 if parsing has succeeded; a positive
     * error code otherwise. 
     * 
     * \sa #scs_to_YAML
     * \sa \ref page_save_load "Saving and loading problems" (detailed documentation)
     */
    scs_int scs_from_YAML(const char * filepath,
            ScsData ** data,
            ScsCone ** cone);

    /**
     * 
     * @param filepath relative or absolute path to a file which this function 
     * will create. 
     * 
     * The caller must have the necessary permissions to create the
     * file, otherwise the method returns the error code \c 101.
     * 
     * @param metadata problem metadata which can be created using #scs_init_conic_problem_metadata
     * @param data pointer to exisint non-null #ScsData object
     * @param cone pointer to exisint non-null #ScsCone object
     * @return this function returns \c 0 on success and a positive status code
     * otherwise.
     * 
     * \sa #scs_from_YAML
     * \sa ScsConicProblemMetadata
     * \sa \ref page_save_load "Saving and loading problems" (detailed documentation)
     */
    scs_int scs_to_YAML(
            const char * RESTRICT filepath,
            ScsConicProblemMetadata * metadata,
            const ScsData * RESTRICT data,
            const ScsCone * RESTRICT cone);

#ifdef __cplusplus
}
#endif
#endif
