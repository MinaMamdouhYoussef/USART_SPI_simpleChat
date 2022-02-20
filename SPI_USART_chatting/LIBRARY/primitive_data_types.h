#ifndef __PRIMITIVE__DATA__TYPES__
#define __PRIMITIVE__DATA__TYPES__

typedef char sint8_t                          ;
typedef unsigned char uint8_t                 ;


typedef short sint16_t 						   ;
typedef unsigned short uint16_t			       ;
typedef long sint32_t        				   ;
typedef unsigned long uint32_t          	   ;
typedef long long sint64_t          		   ;
typedef unsigned long long uint64_t            ;

typedef float float32_t                		   ;
typedef double float64_t               		   ;
typedef long double float128_t                 ;


typedef sint8_t* ptos8int_t 				   ;
typedef uint8_t* ptou8int_t 				   ;
typedef sint16_t* ptosshort_t  		           ;
//typedef uint16_t* ptoushort_t  	  		       ;
typedef sint32_t* ptoslong_t    			       ;
typedef uint32_t* ptoulong_t  		           ;
typedef sint64_t* ptoslonglong_t  	    	       ;
typedef uint64_t* ptoulonglong_t  			       ;
typedef float32_t* ptofloat_t           	   ;
typedef float64_t* ptodouble64_t                ;
typedef float128_t* ptolongdouble_t              ;

#define NULL_POINTER   (void*)0
#define NULL_CHAR 	   '\0'
#endif
