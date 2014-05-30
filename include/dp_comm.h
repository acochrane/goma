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
 
#ifndef DP_COMM_H
#define DP_COMM_H

#ifdef EXTERN
#undef EXTERN
#endif

#ifdef _DP_COMM_C
#define EXTERN /* do nothing */
#endif

#ifndef _DP_COMM_C
#define EXTERN extern
#endif

EXTERN void exchange_dof
PROTO((Comm_Ex *,		/* cx - ptr to communications exchange info */
       Dpi *,			/* dpi - distributed processing info */
       double *));		/* x - local processor dof-based vector */


EXTERN void exchange_node
PROTO((Comm_Ex *cx,		/* cx - ptr to communications exchange info */
       Dpi *d,			/* dpi - distributed processing info */
       double *a));		/* x - local processor node-based vector */

#endif /* _DP_COMM_H */
