/************************************************************************ *
* Goma - Multiphysics finite element software                             *
* Sandia National Laboratories                                            *
*                                                                         *
* Copyright (c) 2014 Sandia Corporation.                                  *
*                                                                         *
* Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,  *
* the U.S. Government retains certain rights in this software.            *
*                                                                         *
* This software is distributed under the GNU General Public License.      *
\************************************************************************/
 

#ifndef _MM_FILL_RS_H
#define _MM_FILL_RS_H

#ifdef EXTERN
#undef EXTERN
#endif

#ifdef _MM_FILL_RS_C
#define EXTERN /* do nothing */
#endif

#ifndef _MM_FILL_RS_C
#define EXTERN extern
#endif

EXTERN int assemble_real_solid	/* mm_fill_rs.c                              */
PROTO((	double ,		/* time - present time value                 */
	double ,		/* tt                                        */
	double ));		/* dt                                        */

EXTERN int solid_stress_tensor	/* mm_fill_rs.c                              */
PROTO((dbl [DIM][DIM],		/* TT                                        */
       dbl [DIM][DIM][DIM][MDE], /* dTT_dx                                   */
       dbl [DIM][DIM][DIM][MDE], /* dTT_drs                                  */
       dbl [DIM][DIM][MDE],	/* dTT_dp                                    */
       dbl [DIM][DIM][MAX_CONC][MDE], /* dTT_dc                              */
       dbl [DIM][DIM][MDE],      /* dTT_dp_liq                            */
       dbl [DIM][DIM][MDE],      /* dTT_dp_gas                            */
       dbl [DIM][DIM][MDE],      /* dTT_dporosity                            */
       dbl [DIM][DIM][MDE],  /* dTT_dT                            */
       dbl [DIM][DIM][MDE],     /* dTT_dmax_strain                           */
       dbl ,			/* mu                                        */
       dbl ));			/* lambda                                    */

EXTERN int belly_flop_rs
PROTO((dbl ));			/* mu - elastic modulus (plane stress case)  */

EXTERN int get_convection_velocity_rs
PROTO((double [DIM],		/* vconv - Calculated convection velocity    */
       double [DIM],		/* vconv_old - Calcd convect velo, prev time */
       CONVECTION_VELOCITY_DEPENDENCE_STRUCT *,
       double ,			/* dt                                        */
       double ));		/* tt                                        */

EXTERN void f_kinematic_displacement_bc
PROTO((double [DIM],		/* func                                      */
       double [DIM][MAX_VARIABLE_TYPES + MAX_CONC][MDE], /* d_func           */
       const int,   		/* i_mat                                     */
       const int,  		/* ss_id                                     */
       const double *,          /* user parameters                           */
       const int ));		/* length of user parameters                 */

EXTERN void f_kinematic_displacement_rs_bc
PROTO((double [DIM],		/* func                                      */
       double [DIM][MAX_VARIABLE_TYPES + MAX_CONC][MDE], /* d_func           */
       int    ,
       const int ,
       double xi[DIM],
       const Exo_DB *exo  ));		/* i_mat                                     */
#endif /* _MM_FILL_RS_H */
