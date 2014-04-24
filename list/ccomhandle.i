#line 1 "..\\src\\12UARTHandle\\CComHandle.c"












 
#line 1 "f:\\Keil\\ARM\\RV31\\Inc\\string.h"
 
 
 
 




 








 











#line 37 "f:\\Keil\\ARM\\RV31\\Inc\\string.h"


  
  typedef unsigned int size_t;








extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 184 "f:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 200 "f:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 223 "f:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 238 "f:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 261 "f:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 493 "f:\\Keil\\ARM\\RV31\\Inc\\string.h"



 
#line 16 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"




 





 












 







 






#line 47 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"

#line 61 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"

   




 















 
#line 92 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"











 





extern __softfp unsigned __ARM_dcmp4(double  , double  );
extern __softfp unsigned __ARM_fcmp4(float  , float  );
    




 

extern __declspec(__nothrow) __softfp int __ARM_fpclassifyf(float  );
extern __declspec(__nothrow) __softfp int __ARM_fpclassify(double  );
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isfinitef(float __x)
{
    return (((*(unsigned *)&(__x)) >> 23) & 0xff) != 0xff;
}
__inline __declspec(__nothrow) __softfp int __ARM_isfinite(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff) != 0x7ff;
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isinff(float __x)
{
    return ((*(unsigned *)&(__x)) << 1) == 0xff000000;
}
__inline __declspec(__nothrow) __softfp int __ARM_isinf(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) << 1) == 0xffe00000) && ((*(unsigned *)&(__x)) == 0);
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_islessgreaterf(float __x, float __y)
{
    unsigned __f = __ARM_fcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
__inline __declspec(__nothrow) __softfp int __ARM_islessgreater(double __x, double __y)
{
    unsigned __f = __ARM_dcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
    


 

__inline __declspec(__nothrow) __softfp int __ARM_isnanf(float __x)
{
    return (0x7f800000 - ((*(unsigned *)&(__x)) & 0x7fffffff)) >> 31;
}
__inline __declspec(__nothrow) __softfp int __ARM_isnan(double __x)
{
    unsigned __xf = (*(1 + (unsigned *)&(__x))) | (((*(unsigned *)&(__x)) == 0) ? 0 : 1);
    return (0x7ff00000 - (__xf & 0x7fffffff)) >> 31;
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isnormalf(float __x)
{
    unsigned __xe = ((*(unsigned *)&(__x)) >> 23) & 0xff;
    return (__xe != 0xff) && (__xe != 0);
}
__inline __declspec(__nothrow) __softfp int __ARM_isnormal(double __x)
{
    unsigned __xe = ((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff;
    return (__xe != 0x7ff) && (__xe != 0);
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_signbitf(float __x)
{
    return (*(unsigned *)&(__x)) >> 31;
}
__inline __declspec(__nothrow) __softfp int __ARM_signbit(double __x)
{
    return (*(1 + (unsigned *)&(__x))) >> 31;
}
     
     








#line 210 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"



   
  typedef float float_t;
  typedef double double_t;







extern const int math_errhandling;



extern __declspec(__nothrow) double acos(double  );
    
    
    
extern __declspec(__nothrow) double asin(double  );
    
    
    
    

extern __declspec(__nothrow) __pure double atan(double  );
    
    

extern __declspec(__nothrow) double atan2(double  , double  );
    
    
    
    

extern __declspec(__nothrow) double cos(double  );
    
    
    
    
extern __declspec(__nothrow) double sin(double  );
    
    
    
    

extern void __use_accurate_range_reduction(void);
    
    

extern __declspec(__nothrow) double tan(double  );
    
    
    
    

extern __declspec(__nothrow) double cosh(double  );
    
    
    
    
extern __declspec(__nothrow) double sinh(double  );
    
    
    
    
    

extern __declspec(__nothrow) __pure double tanh(double  );
    
    

extern __declspec(__nothrow) double exp(double  );
    
    
    
    
    

extern __declspec(__nothrow) double frexp(double  , int *  ) __attribute__((__nonnull__(2)));
    
    
    
    
    
    

extern __declspec(__nothrow) double ldexp(double  , int  );
    
    
    
    
extern __declspec(__nothrow) double log(double  );
    
    
    
    
    
extern __declspec(__nothrow) double log10(double  );
    
    
    
extern __declspec(__nothrow) double modf(double  , double *  ) __attribute__((__nonnull__(2)));
    
    
    
    

extern __declspec(__nothrow) double pow(double  , double  );
    
    
    
    
    
    
extern __declspec(__nothrow) double sqrt(double  );
    
    
    




    __inline double _sqrt(double __x) { return sqrt(__x); }




    __inline float _sqrtf(float __x) { return (float)sqrt(__x); }

    



 

extern __declspec(__nothrow) __pure double ceil(double  );
    
    
extern __declspec(__nothrow) __pure double fabs(double  );
    
    

extern __declspec(__nothrow) __pure double floor(double  );
    
    

extern __declspec(__nothrow) double fmod(double  , double  );
    
    
    
    
    

    









 



extern __declspec(__nothrow) double acosh(double  );
    

 
extern __declspec(__nothrow) double asinh(double  );
    

 
extern __declspec(__nothrow) double atanh(double  );
    

 
extern __declspec(__nothrow) double cbrt(double  );
    

 
__inline __declspec(__nothrow) __pure double copysign(double __x, double __y)
    

 
{
    (*(1 + (unsigned *)&(__x))) = ((*(1 + (unsigned *)&(__x))) & 0x7fffffff) | ((*(1 + (unsigned *)&(__y))) & 0x80000000);
    return __x;
}
__inline __declspec(__nothrow) __pure float copysignf(float __x, float __y)
    

 
{
    (*(unsigned *)&(__x)) = ((*(unsigned *)&(__x)) & 0x7fffffff) | ((*(unsigned *)&(__y)) & 0x80000000);
    return __x;
}
extern __declspec(__nothrow) double erf(double  );
    

 
extern __declspec(__nothrow) double erfc(double  );
    

 
extern __declspec(__nothrow) double expm1(double  );
    

 



    

 






#line 444 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"


extern __declspec(__nothrow) double hypot(double  , double  );
    




 
extern __declspec(__nothrow) int ilogb(double  );
    

 
extern __declspec(__nothrow) int ilogbf(float  );
    

 
extern __declspec(__nothrow) int ilogbl(long double  );
    

 







    

 





    



 





    



 





    

 





    



 





    



 





    



 





    

 





    

 





    


 

extern __declspec(__nothrow) double lgamma (double  );
    


 
extern __declspec(__nothrow) double log1p(double  );
    

 
extern __declspec(__nothrow) double logb(double  );
    

 
extern __declspec(__nothrow) float logbf(float  );
    

 
extern __declspec(__nothrow) long double logbl(long double  );
    

 
extern __declspec(__nothrow) double nextafter(double  , double  );
    


 
extern __declspec(__nothrow) float nextafterf(float  , float  );
    


 
extern __declspec(__nothrow) long double nextafterl(long double  , long double  );
    


 
extern __declspec(__nothrow) double nexttoward(double  , long double  );
    


 
extern __declspec(__nothrow) float nexttowardf(float  , long double  );
    


 
extern __declspec(__nothrow) long double nexttowardl(long double  , long double  );
    


 
extern __declspec(__nothrow) double remainder(double  , double  );
    

 
extern __declspec(__nothrow) __pure double rint(double  );
    

 
extern __declspec(__nothrow) double scalbln(double  , long int  );
    

 
extern __declspec(__nothrow) float scalblnf(float  , long int  );
    

 
extern __declspec(__nothrow) long double scalblnl(long double  , long int  );
    

 
extern __declspec(__nothrow) double scalbn(double  , int  );
    

 
extern __declspec(__nothrow) float scalbnf(float  , int  );
    

 
extern __declspec(__nothrow) long double scalbnl(long double  , int  );
    

 




    

 



 
extern __declspec(__nothrow) __pure float _fabsf(float);  
__inline __declspec(__nothrow) __pure float fabsf(float __f) { return _fabsf(__f); }
extern __declspec(__nothrow) float sinf(float  );
extern __declspec(__nothrow) float cosf(float  );
extern __declspec(__nothrow) float tanf(float  );
extern __declspec(__nothrow) float acosf(float  );
extern __declspec(__nothrow) float asinf(float  );
extern __declspec(__nothrow) float atanf(float  );
extern __declspec(__nothrow) float atan2f(float  , float  );
extern __declspec(__nothrow) float sinhf(float  );
extern __declspec(__nothrow) float coshf(float  );
extern __declspec(__nothrow) float tanhf(float  );
extern __declspec(__nothrow) float expf(float  );
extern __declspec(__nothrow) float logf(float  );
extern __declspec(__nothrow) float log10f(float  );
extern __declspec(__nothrow) float powf(float  , float  );
extern __declspec(__nothrow) float sqrtf(float  );
extern __declspec(__nothrow) float ldexpf(float  , int  );
extern __declspec(__nothrow) float frexpf(float  , int *  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) __pure float ceilf(float  );
extern __declspec(__nothrow) __pure float floorf(float  );
extern __declspec(__nothrow) float fmodf(float  , float  );
extern __declspec(__nothrow) float modff(float  , float *  ) __attribute__((__nonnull__(2)));

 
 













 
__declspec(__nothrow) long double acosl(long double );
__declspec(__nothrow) long double asinl(long double );
__declspec(__nothrow) long double atanl(long double );
__declspec(__nothrow) long double atan2l(long double , long double );
__declspec(__nothrow) long double ceill(long double );
__declspec(__nothrow) long double cosl(long double );
__declspec(__nothrow) long double coshl(long double );
__declspec(__nothrow) long double expl(long double );
__declspec(__nothrow) long double fabsl(long double );
__declspec(__nothrow) long double floorl(long double );
__declspec(__nothrow) long double fmodl(long double , long double );
__declspec(__nothrow) long double frexpl(long double , int* ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double ldexpl(long double , int );
__declspec(__nothrow) long double logl(long double );
__declspec(__nothrow) long double log10l(long double );
__declspec(__nothrow) long double modfl(long double  , long double *  ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double powl(long double , long double );
__declspec(__nothrow) long double sinl(long double );
__declspec(__nothrow) long double sinhl(long double );
__declspec(__nothrow) long double sqrtl(long double );
__declspec(__nothrow) long double tanl(long double );
__declspec(__nothrow) long double tanhl(long double );





 
extern __declspec(__nothrow) float acoshf(float  );
__declspec(__nothrow) long double acoshl(long double );
extern __declspec(__nothrow) float asinhf(float  );
__declspec(__nothrow) long double asinhl(long double );
extern __declspec(__nothrow) float atanhf(float  );
__declspec(__nothrow) long double atanhl(long double );
__declspec(__nothrow) long double copysignl(long double , long double );
extern __declspec(__nothrow) float cbrtf(float  );
__declspec(__nothrow) long double cbrtl(long double );
extern __declspec(__nothrow) float erff(float  );
__declspec(__nothrow) long double erfl(long double );
extern __declspec(__nothrow) float erfcf(float  );
__declspec(__nothrow) long double erfcl(long double );
extern __declspec(__nothrow) float expm1f(float  );
__declspec(__nothrow) long double expm1l(long double );
extern __declspec(__nothrow) float log1pf(float  );
__declspec(__nothrow) long double log1pl(long double );
extern __declspec(__nothrow) float hypotf(float  , float  );
__declspec(__nothrow) long double hypotl(long double , long double );
extern __declspec(__nothrow) float lgammaf(float  );
__declspec(__nothrow) long double lgammal(long double );
extern __declspec(__nothrow) float remainderf(float  , float  );
__declspec(__nothrow) long double remainderl(long double , long double );
extern __declspec(__nothrow) float rintf(float  );
__declspec(__nothrow) long double rintl(long double );



#line 824 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"





#line 979 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"











#line 1181 "f:\\Keil\\ARM\\RV31\\Inc\\math.h"



 
#line 17 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "f:\\Keil\\ARM\\RV31\\Inc\\time.h"
 
 
 
 









 





 












#line 40 "f:\\Keil\\ARM\\RV31\\Inc\\time.h"


  
  typedef unsigned int size_t;








    
 
#line 64 "f:\\Keil\\ARM\\RV31\\Inc\\time.h"





typedef unsigned int clock_t;     
typedef unsigned int time_t;      

#pragma push
#pragma anon_unions

struct tm {
    int tm_sec;   
 
    int tm_min;    
    int tm_hour;   
    int tm_mday;   
    int tm_mon;    
    int tm_year;   
    int tm_wday;   
    int tm_yday;   
    int tm_isdst;  
    union {        
        struct {
            int __extra_1, __extra_2;
        };
        struct {
            long __extra_1_long, __extra_2_long;
        };
        struct {
            char *__extra_1_cptr, *__extra_2_cptr;
        };
        struct {
            void *__extra_1_vptr, *__extra_2_vptr;
        };
    };
};

#pragma pop

   



 

extern __declspec(__nothrow) clock_t clock(void);
   





 
extern __declspec(__nothrow) double difftime(time_t  , time_t  );
   


 
extern __declspec(__nothrow) time_t mktime(struct tm *  ) __attribute__((__nonnull__(1)));
   













 
extern __declspec(__nothrow) time_t time(time_t *  );
   






 

extern __declspec(__nothrow) char *asctime(const struct tm *  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) char *_asctime_r(const struct tm *  ,
                                char * __restrict  ) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) char *asctime_r(const struct tm *  ,
                               char * __restrict  ) __attribute__((__nonnull__(1,2)));

   



 
extern __declspec(__nothrow) char *ctime(const time_t *  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) struct tm *gmtime(const time_t *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) struct tm *localtime(const time_t *  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) struct tm *_localtime_r(const time_t * __restrict  ,
                                       struct tm * __restrict  ) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) struct tm *localtime_r(const time_t * __restrict  ,
                                      struct tm * __restrict  ) __attribute__((__nonnull__(1,2)));

   



 
extern __declspec(__nothrow) size_t strftime(char * __restrict  , size_t  ,
                       const char * __restrict  ,
                       const struct tm * __restrict  ) __attribute__((__nonnull__(1,3,4)));
   











































 











#line 271 "f:\\Keil\\ARM\\RV31\\Inc\\time.h"



 
#line 18 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"
 
 
 




 
 



 












  


 








#line 45 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"


  
  typedef unsigned int size_t;










    



    typedef unsigned short wchar_t;  
#line 74 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { __int64 quot, rem; } lldiv_t;
    


#line 95 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"
   



 

   




 
#line 114 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) __int64 atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) __int64 strtoll(const char * __restrict  ,
                               char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned __int64 strtoull(const char * __restrict  ,
                                         char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
#line 414 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
#line 502 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

#line 531 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"

extern __declspec(__nothrow) __pure int abs(int  );
   



 

extern __declspec(__nothrow) __pure div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __pure long int labs(long int  );
   



 




extern __declspec(__nothrow) __pure ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __pure __int64 llabs(__int64  );
   



 




extern __declspec(__nothrow) __pure lldiv_t lldiv(__int64  , __int64  );
   











 
#line 612 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"



 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __pure __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __pure __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 



 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











#line 866 "f:\\Keil\\ARM\\RV31\\Inc\\stdlib.h"


 
#line 19 "..\\src\\12UARTHandle\\CComHandle.c"

#line 1 "..\\src\\APP\\include.h"












 




#line 1 "..\\inc\\LPC17xx.h"








 
 
 
 
#line 20 "..\\inc\\LPC17xx.h"






 



 

 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn           = -14,       
  MemoryManagement_IRQn         = -12,       
  BusFault_IRQn                 = -11,       
  UsageFault_IRQn               = -10,       
  SVCall_IRQn                   = -5,        
  DebugMonitor_IRQn             = -4,        
  PendSV_IRQn                   = -2,        
  SysTick_IRQn                  = -1,        

 
  WDT_IRQn                      = 0,         
  TIMER0_IRQn                   = 1,         
  TIMER1_IRQn                   = 2,         
  TIMER2_IRQn                   = 3,         
  TIMER3_IRQn                   = 4,         
  UART0_IRQn                    = 5,         
  UART1_IRQn                    = 6,         
  UART2_IRQn                    = 7,         
  UART3_IRQn                    = 8,         
  PWM1_IRQn                     = 9,         
  I2C0_IRQn                     = 10,        
  I2C1_IRQn                     = 11,        
  I2C2_IRQn                     = 12,        
  SPI_IRQn                      = 13,        
  SSP0_IRQn                     = 14,        
  SSP1_IRQn                     = 15,        
  PLL0_IRQn                     = 16,        
  RTC_IRQn                      = 17,        
  EINT0_IRQn                    = 18,        
  EINT1_IRQn                    = 19,        
  EINT2_IRQn                    = 20,        
  EINT3_IRQn                    = 21,        
  ADC_IRQn                      = 22,        
  BOD_IRQn                      = 23,        
  USB_IRQn                      = 24,        
  CAN_IRQn                      = 25,        
  DMA_IRQn                      = 26,        
  I2S_IRQn                      = 27,        
  ENET_IRQn                     = 28,        
  RIT_IRQn                      = 29,        
  MCPWM_IRQn                    = 30,        
  QEI_IRQn                      = 31,        
  PLL1_IRQn                     = 32,        
  USBActivity_IRQn              = 33,        
  CANActivity_IRQn              = 34         
} IRQn_Type;




 

 





#line 1 "..\\inc\\core_cm3.h"



















 




















































 

 
 
 
 
 
 
 
 


#line 1 "f:\\Keil\\ARM\\RV31\\Inc\\stdint.h"
 
 





 









#line 25 "f:\\Keil\\ARM\\RV31\\Inc\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 196 "f:\\Keil\\ARM\\RV31\\Inc\\stdint.h"

     







     










     











#line 260 "f:\\Keil\\ARM\\RV31\\Inc\\stdint.h"



 


#line 86 "..\\inc\\core_cm3.h"

















 

#line 112 "..\\inc\\core_cm3.h"





 


 





 






 
typedef struct
{
  volatile uint32_t ISER[8];                       
       uint32_t RESERVED0[24];
  volatile uint32_t ICER[8];                       
       uint32_t RSERVED1[24];
  volatile uint32_t ISPR[8];                       
       uint32_t RESERVED2[24];
  volatile uint32_t ICPR[8];                       
       uint32_t RESERVED3[24];
  volatile uint32_t IABR[8];                       
       uint32_t RESERVED4[56];
  volatile uint8_t  IP[240];                       
       uint32_t RESERVED5[644];
  volatile  uint32_t STIR;                          
}  NVIC_Type;


 
typedef struct
{
  volatile const  uint32_t CPUID;                         
  volatile uint32_t ICSR;                          
  volatile uint32_t VTOR;                          
  volatile uint32_t AIRCR;                         
  volatile uint32_t SCR;                           
  volatile uint32_t CCR;                           
  volatile uint8_t  SHP[12];                       
  volatile uint32_t SHCSR;                         
  volatile uint32_t CFSR;                          
  volatile uint32_t HFSR;                          
  volatile uint32_t DFSR;                          
  volatile uint32_t MMFAR;                         
  volatile uint32_t BFAR;                          
  volatile uint32_t AFSR;                          
  volatile const  uint32_t PFR[2];                        
  volatile const  uint32_t DFR;                           
  volatile const  uint32_t ADR;                           
  volatile const  uint32_t MMFR[4];                       
  volatile const  uint32_t ISAR[5];                       
} SCB_Type;


 
typedef struct
{
  volatile uint32_t CTRL;                          
  volatile uint32_t LOAD;                          
  volatile uint32_t VAL;                           
  volatile const  uint32_t CALIB;                         
} SysTick_Type;


 
typedef struct
{
  volatile  union  
  {
    volatile  uint8_t    u8;                        
    volatile  uint16_t   u16;                       
    volatile  uint32_t   u32;                       
  }  PORT [32];                                
       uint32_t RESERVED0[864];
  volatile uint32_t TER;                           
       uint32_t RESERVED1[15];
  volatile uint32_t TPR;                           
       uint32_t RESERVED2[15];
  volatile uint32_t TCR;                           
       uint32_t RESERVED3[29];
  volatile uint32_t IWR;                           
  volatile uint32_t IRR;                           
  volatile uint32_t IMCR;                          
       uint32_t RESERVED4[43];
  volatile uint32_t LAR;                           
  volatile uint32_t LSR;                           
       uint32_t RESERVED5[6];
  volatile const  uint32_t PID4;                          
  volatile const  uint32_t PID5;
  volatile const  uint32_t PID6;
  volatile const  uint32_t PID7;
  volatile const  uint32_t PID0;
  volatile const  uint32_t PID1;
  volatile const  uint32_t PID2;
  volatile const  uint32_t PID3;
  volatile const  uint32_t CID0;
  volatile const  uint32_t CID1;
  volatile const  uint32_t CID2;
  volatile const  uint32_t CID3;
} ITM_Type;


 
typedef struct
{
       uint32_t RESERVED0;
  volatile const  uint32_t ICTR;                          



       uint32_t RESERVED1;

} InterruptType_Type;


 

typedef struct
{
  volatile const  uint32_t TYPE;                          
  volatile uint32_t CTRL;                          
  volatile uint32_t RNR;                           
  volatile uint32_t RBAR;                          
  volatile uint32_t RASR;                          
  volatile uint32_t RBAR_A1;                       
  volatile uint32_t RASR_A1;                       
  volatile uint32_t RBAR_A2;                       
  volatile uint32_t RASR_A2;                       
  volatile uint32_t RBAR_A3;                       
  volatile uint32_t RASR_A3;                       
} MPU_Type;



 
typedef struct
{
  volatile uint32_t DHCSR;                         
  volatile  uint32_t DCRSR;                         
  volatile uint32_t DCRDR;                         
  volatile uint32_t DEMCR;                         
} CoreDebug_Type;


 
#line 274 "..\\inc\\core_cm3.h"

#line 281 "..\\inc\\core_cm3.h"










 






#line 311 "..\\inc\\core_cm3.h"


 


 




#line 336 "..\\inc\\core_cm3.h"


 
 
 
 









 
extern uint32_t __get_PSP(void);









 
extern void __set_PSP(uint32_t topOfProcStack);









 
extern uint32_t __get_MSP(void);











 
extern void __set_MSP(uint32_t topOfMainStack);








 
extern uint32_t __REV16(uint16_t value);








 
extern int32_t __REVSH(int16_t value);


#line 504 "..\\inc\\core_cm3.h"









 









 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}








 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0x1ff);
}









 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}








 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}








 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}








 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & 1);
}








 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}








 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}





#line 1046 "..\\inc\\core_cm3.h"



 













 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  
  reg_value  = ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR;                                                     
  reg_value &= ~((0xFFFFU << 16) | (0x0F << 8));                               
  reg_value  = ((reg_value | (0x5FA << 16) | (PriorityGroupTmp << 8)));   
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR = reg_value;
}









 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR >> 8) & 0x07);                                           
}









 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}









 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000) + 0x0100))->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}













 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 5)) & 0xff); }  
  else {
    ((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)] = ((priority << (8 - 5)) & 0xff);    }         
}















 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 5)));  }  
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)]           >> (8 - 5)));  }  
}
















 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 5) ? 5 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 5) < 7) ? 0 : PriorityGroupTmp - 7 + 5;
 
  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}

















 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 5) ? 5 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 5) < 7) ? 0 : PriorityGroupTmp - 7 + 5;
  
  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}



 



 














 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > ((1<<24) -1))  return (1);                                              

  ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  =  (ticks & ((1<<24) -1)) - 1;                                       
  NVIC_SetPriority (SysTick_IRQn, (1<<5) - 1);                             
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   =  (0x00);                                                               
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL = (1 << 2) | (1<<0) | (1<<1);  
  return (0);                                                                             
}







 








 
static __inline void NVIC_SystemReset(void)
{
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR  = ((0x5FA << 16) | (((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (0x700)) | (1<<2));  
  __dsb(0);                                                                                            
  while(1);                                                                             
}


 











 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (ch == '\n') ITM_SendChar('\r');
  
  if ((((CoreDebug_Type *) (0xE000EDF0))->DEMCR & (1 << 24))  &&
      (((ITM_Type *) (0xE0000000))->TCR & 1)                  &&
      (((ITM_Type *) (0xE0000000))->TER & (1UL << 0))  ) 
  {
    while (((ITM_Type *) (0xE0000000))->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000))->PORT[0].u8 = (uint8_t) ch;
  }  
  return (ch);
}







 
#line 95 "..\\inc\\LPC17xx.h"
#line 1 "..\\inc\\system_LPC17xx.h"




















 










#line 1 "..\\inc\\LPC17xx.h"
#line 33 "..\\inc\\system_LPC17xx.h"

extern uint32_t SystemFrequency;     










 
extern void SystemInit (void);










 
extern void SystemClockUpdate (void);





#line 96 "..\\inc\\LPC17xx.h"


 
 
 


#pragma anon_unions



 
#line 120 "..\\inc\\LPC17xx.h"

#line 136 "..\\inc\\LPC17xx.h"


 

#line 146 "..\\inc\\LPC17xx.h"

























 

























































































































































































 

 




 




				 
 





 



 
#line 387 "..\\inc\\LPC17xx.h"
    
 




 


 
 






 
#line 411 "..\\inc\\LPC17xx.h"










 
#line 440 "..\\inc\\LPC17xx.h"

 
#line 460 "..\\inc\\LPC17xx.h"

 
#line 480 "..\\inc\\LPC17xx.h"

 
#line 500 "..\\inc\\LPC17xx.h"


 
#line 525 "..\\inc\\LPC17xx.h"


 
#line 544 "..\\inc\\LPC17xx.h"

 
#line 565 "..\\inc\\LPC17xx.h"

 
#line 583 "..\\inc\\LPC17xx.h"

 
#line 602 "..\\inc\\LPC17xx.h"


 
#line 611 "..\\inc\\LPC17xx.h"

 
#line 624 "..\\inc\\LPC17xx.h"

 
#line 637 "..\\inc\\LPC17xx.h"


 
#line 657 "..\\inc\\LPC17xx.h"

 
#line 676 "..\\inc\\LPC17xx.h"

 
#line 695 "..\\inc\\LPC17xx.h"


 
#line 713 "..\\inc\\LPC17xx.h"


 







 
#line 756 "..\\inc\\LPC17xx.h"


 
#line 765 "..\\inc\\LPC17xx.h"


 
#line 782 "..\\inc\\LPC17xx.h"


 






 
#line 823 "..\\inc\\LPC17xx.h"


 


 




 
#line 847 "..\\inc\\LPC17xx.h"

 
#line 855 "..\\inc\\LPC17xx.h"


 

 
#line 872 "..\\inc\\LPC17xx.h"

 





 
#line 905 "..\\inc\\LPC17xx.h"

 
#line 932 "..\\inc\\LPC17xx.h"


 
#line 950 "..\\inc\\LPC17xx.h"

 






 






 






 






 






 






 






 







 





 

 



 






 






 




 



 






 
#line 1069 "..\\inc\\LPC17xx.h"


 
#line 1095 "..\\inc\\LPC17xx.h"


 

 









 
#line 1116 "..\\inc\\LPC17xx.h"

 



 


 


 
#line 1145 "..\\inc\\LPC17xx.h"

 
#line 1164 "..\\inc\\LPC17xx.h"

 






 










 
#line 1216 "..\\inc\\LPC17xx.h"

















 
typedef struct
{
  union {
  volatile const  uint8_t  RBR;
  volatile  uint8_t  THR;
  volatile uint8_t  DLL;
       uint32_t RESERVED0;
  };
  union {
  volatile uint8_t  DLM;
  volatile uint32_t IER;
  };
  union {
  volatile const  uint32_t IIR;
  volatile  uint8_t  FCR;
  };
  volatile uint8_t  LCR;
       uint8_t  RESERVED1[7];
  volatile const  uint8_t  LSR;
       uint8_t  RESERVED2[7];
  volatile uint8_t  SCR;
       uint8_t  RESERVED3[3];
  volatile uint32_t ACR;
  volatile uint8_t  ICR;
       uint8_t  RESERVED4[3];
  volatile uint8_t  FDR;
       uint8_t  RESERVED5[7];
  volatile uint8_t  TER;
       uint8_t  RESERVED6[39];
  volatile const  uint8_t  FIFOLVL;
} LPC_UART_TypeDef;

typedef struct
{
  union {
  volatile const  uint8_t  RBR;
  volatile  uint8_t  THR;
  volatile uint8_t  DLL;
       uint32_t RESERVED0;
  };
  union {
  volatile uint8_t  DLM;
  volatile uint32_t IER;
  };
  union {
  volatile const  uint32_t IIR;
  volatile  uint8_t  FCR;
  };
  volatile uint8_t  LCR;
       uint8_t  RESERVED1[7];
  volatile const  uint8_t  LSR;
       uint8_t  RESERVED2[7];
  volatile uint8_t  SCR;
       uint8_t  RESERVED3[3];
  volatile uint32_t ACR;
  volatile uint8_t  ICR;
       uint8_t  RESERVED4[3];
  volatile uint8_t  FDR;
       uint8_t  RESERVED5[7];
  volatile uint8_t  TER;
       uint8_t  RESERVED6[39];
  volatile const  uint8_t  FIFOLVL;
} LPC_UART0_TypeDef;

typedef struct
{
  union {
  volatile const  uint8_t  RBR;
  volatile  uint8_t  THR;
  volatile uint8_t  DLL;
       uint32_t RESERVED0;
  };
  union {
  volatile uint8_t  DLM;
  volatile uint32_t IER;
  };
  union {
  volatile const  uint32_t IIR;
  volatile  uint8_t  FCR;
  };
  volatile uint8_t  LCR;
       uint8_t  RESERVED1[3];
  volatile uint8_t  MCR;
       uint8_t  RESERVED2[3];
  volatile const  uint8_t  LSR;
       uint8_t  RESERVED3[3];
  volatile const  uint8_t  MSR;
       uint8_t  RESERVED4[3];
  volatile uint8_t  SCR;
       uint8_t  RESERVED5[3];
  volatile uint32_t ACR;
       uint32_t RESERVED6;
  volatile uint32_t FDR;
       uint32_t RESERVED7;
  volatile uint8_t  TER;
       uint8_t  RESERVED8[27];
  volatile uint8_t  RS485CTRL;
       uint8_t  RESERVED9[3];
  volatile uint8_t  ADRMATCH;
       uint8_t  RESERVED10[3];
  volatile uint8_t  RS485DLY;
       uint8_t  RESERVED11[3];
  volatile const  uint8_t  FIFOLVL;
} LPC_UART1_TypeDef;




#line 19 "..\\src\\APP\\include.h"
#line 1 "..\\src\\APP\\Config.h"












 




 


 


 













enum emTxResult{
	U_TxError = 1,
	U_TxSucc = 0,	
};
	
	
enum emErrorDef{
	U_Error = 1,
	U_Fault = 1,
	U_Usual = 0,	
	
};








 




 
typedef  unsigned  char  tBoolean;
typedef  unsigned char   uchar;                    
typedef  unsigned char   uint8;                    
typedef  signed   char   int8;                     
typedef  unsigned short  uint16;                   
typedef  signed   short  int16;                    
typedef  unsigned int    uint32;                   
typedef  signed   int    int32;                    
typedef  float           fp32;                     
typedef  double          fp64;                     	  
typedef  unsigned long   ulong;



 


#line 20 "..\\src\\APP\\include.h"
#line 1 "..\\src\\common\\buffer.h"
                                  























 



typedef struct{
unsigned char read;	
unsigned char  write;	
unsigned char  len;	
unsigned char *buffer;	
unsigned char  overflue;	
}TBuffer;
extern TBuffer	Uartbuf;
extern TBuffer	Wirelessbuf;
extern TBuffer* pUartbuf;
extern TBuffer* pWirelessbuf;




extern unsigned char  BufferInit(TBuffer* pbuf,unsigned char * pdata,unsigned short len);
extern unsigned char  BufferReset(TBuffer* pbuf);
extern unsigned char  BufferWrite(TBuffer* pbuf ,unsigned char * pdata ,unsigned short len);
extern unsigned char  BufferRead(TBuffer* pbuf ,unsigned char * pdata ,unsigned short len ,unsigned char offset);
extern unsigned char  BufferClear(TBuffer* pbuf ,unsigned short len);




 
#line 21 "..\\src\\APP\\include.h"
#line 1 "..\\src\\common\\CMaDefine.h"












 















#line 35 "..\\src\\common\\CMaDefine.h"




#line 22 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Hardware\\CSSP\\ssp.h"












 

#line 18 "..\\src\\Hardware\\CSSP\\ssp.h"




	
 






 






 





 





 





 





 



#line 71 "..\\src\\Hardware\\CSSP\\ssp.h"

 



#line 87 "..\\src\\Hardware\\CSSP\\ssp.h"



extern void  SSP1_Init(void);
extern uint8 SPI_FLASH_SendByte (uint8 tmp);
extern void SSPSend( uint32_t portnum, uint8_t *Buf, uint32_t Length );
extern void SSPReceive( uint32_t portnum, uint8_t *buf, uint32_t Length );
extern void M25P80_Section_Erase(uint32 addr);
extern void M25P80_Bulk_Erase(void);
extern void M25P80_Write_1Byte(uint32 addr , uint8 data);
extern void M25P80_Write_Bytes(uint32 addr , uint8* wr_buf_p , uint16 no);
extern uint8 M25P80_Read_1Byte(uint32 addr );
extern uint8 M25P80_ReadFast_1Byte(uint32 addr );
extern void M25P80_Read_Bytes(uint32 addr , uint8* re_buf_p , uint16 no);
void SSP1_Write_En(void);
void SSP1_Write_Dis(void);
void SSP1_Write_CMD(uint8 cmd,uint32 addr);
void SSP1_Write_1Byte(uint32 addr , uint8 data);
void MDelay(uint8 tmp);
void M25P80_WP_En(void);
void SSP1_Write_Bytes(uint32 addr , uint8 *data , uint16 no);
uint8 SSP1_Read_1Byte(uint32 addr );
void SSP1_Section_Erase(uint32 addr);
void SSP1_Bulk_Erase(void);
void SSP1_Read_Bytes(uint32 addr , uint8* data , uint16 no);
void SSP_Busy(void);



 

#line 25 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Hardware\\I2C\\i2c.h"















 
#line 18 "..\\src\\Hardware\\I2C\\i2c.h"




















extern void  I2C0_Init(uint32 ulFi2c);
void I2CIntEnd(void);
void I2CIntStart(void);
extern uint8 IRcvByte(uint8 sla, uint8 *dat);
extern uint8 ISendByte(uint8 sla, uint8 dat);
extern uint8 I2C_ReadNByte (uint8 sla, uint32 suba_type, uint32 suba, uint8 *s, uint32 num);
extern uint8 I2C_WriteNByte(uint8 sla, uint8 suba_type, uint32 suba, uint8 *s, uint32 num);

extern void i2c0_enable(void);
extern void i2c0_disable(void);
#line 28 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Board\\pcf8563.h"















 

#line 19 "..\\src\\Board\\pcf8563.h"





typedef struct _PCF8563_DATE{
   uint8	second;
   uint8	minute;
   uint8	hour;
   uint8	day;
   uint8	week;
   uint8	month;
   uint16	year;
}PCF8563_DATE;





 
#line 46 "..\\src\\Board\\pcf8563.h"


 




 
#line 60 "..\\src\\Board\\pcf8563.h"


 




 
#line 74 "..\\src\\Board\\pcf8563.h"


 







 



 uint8 PCF8563_Set(PCF8563_DATE *tp);
 uint8 PCF8563_Read(PCF8563_DATE *tp);
 uint8 PCF8563_SS(uint8 cmd);
 uint8 PCF8563_Set_TD(uint8 cmd, uint16 TD);
 uint16 PCF8563_Get_TD(uint8 cmd);
 uint8 PCF8563_Set_ClkOut(uint8 cmd);
 uint8 PCF8563_Set_Alarm(uint8 cmd, uint8 tm);
 uint8 PCF8563_Set_Timer(uint8 cmd, uint8 cnt);
 uint8 PCF8563_INT_State(uint8 cmd);
 void PCF8563_Init(void);

void getcurrent_date(PCF8563_DATE *date);




 
#line 30 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Hardware\\GPIO\\GPIOInit.h"












 

 


void GPIOinit(void);

#line 33 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\UART\\uart.h"


















 
#line 21 "..\\src\\Hardware\\UART\\uart.h"

















#line 46 "..\\src\\Hardware\\UART\\uart.h"





 




 

typedef struct note_info_t
{
    uint8 frame1;
    uint8 frame2;
    uint8 frame3;
    uint8 cmd1;
    uint8 cmd_rw;
    uint8 devtype;
    uint8 targetaddr;
    uint8 controllernum;
    uint8 datelen;
    uint8 loop;
    uint8 addr;
    uint8 hz[32];
    uint8 cs[2];
}note_info_t;


 















void ClrData3(void);

extern void NoteData_Init(void);
extern uint8 GetCom0Ann(uint8 row,uint8 cow);
extern uint8 GetAnnRow( uint8 comp);
extern void ClrCom1Data0(void);
extern void clr_tp(void);
extern uint8 GetCom1Data0(uint8 row);
void CSaveAnn(void);
void AnnCounterInit(void);
extern uint32 UARTInit( uint32 portNum, uint32 Baudrate );
extern void UartIntEnd(void);
extern void UartIntStart(void);
extern void UART0_IRQHandler( void );
extern void UART1_IRQHandler( void );
extern void UARTSend(uint32 portNum, uint8 *Ptr, uint32 Length);
extern uint32 uart1GetByte (void);
extern void uart1GetStr (uint32 *pucStr, uint32 ulNum);

static int Uart0SendByte(int buf, uint8 flag) ;

extern uint32 Uart1SendByte(uint32 buf) ;
extern void UART0_SendString (uint8 *s);
extern void UART1_SendString (uint8 *s);
uint8 GetAnnFlag(void);
void HandleNote(void);
void SaveAnnFun(void);
void puts__(char *s);
void lcd_printf(char *str,...);

void uart_all_disable(void);
void uart_all_enable(void);

void SetConvertdataAll(void);

void set_note_info(note_info_t *info);







void add_note_nums(void);
void add_note_size(void);
void check_note_nums(void);
void check_note_size(void);
void reset_note_buf(uint8 notenum);
void set_note_buf(uint8 notenum, uint8 note_size, uint8 val);
void print_note_buf(void);





 
 
 
 
 
 










 

#line 172 "..\\src\\Hardware\\UART\\uart.h"





 


 



 




 

 


 

 



 
 

 
 


 

 
 


 

 
 

 


 

 
 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 




 

 
 

 

 

 

 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 


 

 
 

 

 

 

 

 


 

 
 

 

 

 

 


 

 
 

 

 


 

 
 

 


 

 
 

 

 

 

 


 


 


 

 


 

 
 


 

 
 

 

 





 



 




 


 

 

 

 

 





typedef struct
{
    volatile uint32 tx_head;                 
    volatile uint32 tx_tail;                 
    volatile uint32 rx_head;                 
    volatile uint32 rx_tail;                 
    volatile uint8  tx[256];   
    volatile uint8  rx[256];   
} UART_RING_BUFFER_T;
















typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;





















 
typedef struct{
    unsigned short len;									 
    unsigned short num;									 
    unsigned char senden;
    unsigned char datarray[0x100];			 
}TdUartSend;

typedef struct{
    unsigned char clrlen;								 
    unsigned char datarray[0x100];			 
}TdUartRcv;







 
#line 35 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\Extint\\extint.h"












 




void  Eint3_Init(void);
void  SetE1_flag(void);
void  ClrE1_flag(void);
uint8 GetE1_flag(void);
void  SetE3_flag(void);
void  ClrE3_flag(void);
uint8 GetE3_flag(void);
void  cExt3IntFlow(void);
void  cExt3IntRise(void);
void cExt3IntClrFlow(void);
void cExt3IntClrRise(void);
void Eint_Dis(void);
void Eint_En(void);
void Eint_DisAll_Exuart(void);
void Eint_EnAll_Exuart(void);


uint8_t GetSyncFlag(void);
void SyncTimeInit(void);



void SetStartSyncms(uint8_t order,uint32_t val);
void PrintP023TiggerInfo(void);







void vSetFallingCount(uint32_t count);

void vClrFallingCount(void);

void vSetRiseingCount(uint32_t count);

void vClrRiseingCount(void);

void extint1_disable(void);
void extint1_enable(void);

void extint3_enable(void);
void extint3_disable(void);



#line 37 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\PWM.h"












 










#line 31 "..\\src\\Hardware\\PWM.h"





#line 57 "..\\src\\Hardware\\PWM.h"

#line 69 "..\\src\\Hardware\\PWM.h"

#line 77 "..\\src\\Hardware\\PWM.h"

void PWM1_IRQHandler (void) ;
void PWM_Init(void);
void PWM1_Set(uint32 cycle, uint32 offset );
void PWM1_Start( void );
void PWM1_Stop( void );


void pwm1_enable(void);
void pwm1_disable(void);


uint8 get_PWM1_Started(void);
void set_PWM1_Started(void);
void clr_PWM1_Started(void);



#line 39 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Board\\lcd.h"












 
#line 15 "..\\src\\Board\\lcd.h"

 








#line 31 "..\\src\\Board\\lcd.h"






void DelayMs(uint32 Time);    
void DATAout(uint8 j);
void CheckState(void);   
void SendCommandToLCD(uint8 com);  
void SetLine(uint8 page);	 
  
void SetStartLine(uint8 startline);
 
void SetColumn(uint8 column);
  
void SetOnOff(uint8 onoff);
 
void WriteByte(uint8 dat);
 
void SelectScreen(uint8 screen);
  
void ClearScreen(uint8  screen);
void Clear16Screen(uint8  screen);
 
void delay(uint8  z);
 
void delay_long (uint32 ulTime);
 
void InitLCD(void );
 
void Display(uint8  ss,uint8  page,uint8  column,uint32  number);
void DisplayBlack(uint8  ss,uint8  page,uint8  column,uint32  number);
void Display12by12(uint8  ss,uint8  page,uint8  column,uint8  number);

void Display1(uint8  ss,uint8  page,uint8  column,uint8  number);	

void Displaynumber(uint8  ss,uint8  page,uint8  column,uint8  number);	
void IOint(void);

void DisplaynumberBlack(uint8  ss,uint8 page,uint8  column,uint8  number);
void WriteBlackByte(uint8 dat);
void WriteBlue(uint8 screen,uint8 line,uint8 col,uint8 row);

void DisplayJBHZK(uint8  ss,uint8  page,uint8  column,uint16 xHZcode);
void DisplayJBHZKBlack(uint8  ss,uint8  page,uint8  column,uint16 xHZcode);

#line 42 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\Timer\\CTime.h"











 





#line 19 "..\\src\\Hardware\\Timer\\CTime.h"
 







 
 
 

  

 
 
  
 
 
 	

 
 
 
extern  void     SetHeartTick(uint32 tmp);
extern  void AddHeartTick(void);
extern  uint32   GetHeartTick(void);
extern  void     Init_CTime0(void);  
extern  void     Init_CTime1(void);
extern  void     init_timer (uint8 timer_num, uint32 TimerInterval); 
extern  void     SetTimeTickCounter(uint8 tmp);
extern  uint8    GetTimeTickCounter(void);
extern  void     AddSpeakerTick(void);
extern  void     SetSpeakerTick(uint16 tmp);
extern  uint16   GetSpeakerTick(void);
extern  void     TIMER0_IRQHandler (void);  
extern  void     TIMER1_IRQHandler (void);
extern  void     enable_timer( uint8 timer_num );
extern  void     disable_timer( uint8 timer_num );
extern  void     reset_timer( uint8 timer_num );
extern  void     CLedShow(void);
extern  void     CSpeakerPWM(void);
extern  void     OnLCD(void);
extern  void vAddLedFlag(void);
extern  void vClrLedFlag(void);
extern  uint32 vGetLedFlag(void);
extern  void OffLcd(void);
extern  void vAddScreenMask(void);
extern  uint32 vGetScreenMask(void);

void timern_disable(uint8 timern);
void timern_enable(uint8 timern);
  
 
 

#line 87 "..\\src\\Hardware\\Timer\\CTime.h"


#line 44 "..\\src\\APP\\include.h"

#line 1 "..\\src\\common\\CSpeaker.h"












 




void Breeze_Controll(int Breeze_time,int Stoptime_add);

#line 46 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Board\\CRelay.h"












 


void Relay_Init(void);
void Fire_Relay_On(void);
void Fire_Relay_Off(void);
void Fault_Relay_On(void);
void Fault_Relay_Off(void);


#line 48 "..\\src\\APP\\include.h"

#line 1 "..\\src\\common\\CIntStEnd.h"












 

void EndInt(void);
void StartInt(void);

#line 50 "..\\src\\APP\\include.h"


#line 1 "..\\src\\common\\CGrapParam.h"












 

#line 16 "..\\src\\common\\CGrapParam.h"



#line 71 "..\\src\\common\\CGrapParam.h"

void SetBaseAddr(uint8 row,uint8 tmp);
void AddBaseAddr(uint8 row);
void SubBaseAddr(uint8 row);
uint8 GetBaseAddr(uint8 row);

void set_BaseAddr_default(void);

void AddLocalParaSel(void);
void SetLocalParaSel(uint8 tmp);
uint8 GetLocalParaSel(void);


void Set_department(uint8 row,uint8 tmp);

void Add_department(uint8 row);
void Sub_department(uint8 row);
uint8 Get_zone_bit(uint8 row);

void Add_department_sel(void);
void Set_department_sel(uint8 tmp);
uint8 Get_zone_bit_sel(void);
void check_localaddr(void);







void SetComRegFlag(void);
uint8 GetComRegFlag(void);
void ClrComRegFlag(void);

void AddCompRegParaSel(void);
void SetCompRegParaSel(uint8 tmp);
uint8 GetCompRegParaSel(void);

void SetCompRegDep(uint16 tmp);
void AddCompRegDep(void);
void SubCompRegDep(void);
uint16 GetCompRegDep(void);

void SetCompRegAddr(uint8 tmp);
void AddCompRegAddr(void);
void SubCompRegAddr(void);
uint8 GetCompRegAddr(void);

void SetCompRegNum(uint16 tmp);
void AddCompRegNum(void);
void SubCompRegNum(void);
uint16 GetCompRegNum(void);

void AddCompSetDep(void);
void SubCompSetDep(void);
uint16 GetCompSetDep(void);
void SetCompSetDep(uint16 tmp);

void AddCompSetNum(void);
void SubCompSetNum(void);
uint16 GetCompSetNum(void);
void SetCompSetNum(uint16 tmp);

void SetComSetSelSet(uint8 tmp);
void AddComSetSelSet(void);
void SubComSetSelSet(void);
uint8 GetComSetSelSet(void);

void AddComSet_seltab(void);
void SubComSet_seltab(void);
uint8 GetComSet_seltab(void);
void SetComSet_seltab(uint8 tmp);

void SetYear(uint16 tmp);
void AddYear(void);
void SubYear(void);
uint16 GetYear(void);

void SetMonth(uint16 tmp);
void AddMonth(void);
void SubMonth(void);
uint16 GetMonth(void);

void AddDay(void);
void SubDay(void);
uint16 GetDay(void);
void SetDay(uint16 tmp);

void SetHour(uint16 tmp);
void AddHour(void);
void SubHour(void);
uint16 GetHour(void);

void SetMintue(uint16 tmp);
void AddMintue(void);
void SubMintue(void);
uint16 GetMintue(void);

void SetSecond(uint16 tmp);
void AddSecond(void);
void SubSecond(void);
uint16 GetSecond(void);

void SetSelTime(uint8 tmp);
void AddSelTime(void);
uint8 GetSelTime(void);

void SetAnnDep(uint16 tmp);
void AddAnnDep(void);
void SubAnnDep(void);
uint16 GetAnnDep(void);

void SetAnnCompNum(uint16 tmp);
void AddAnnCompNum(void);
void SubAnnCompNum(void);
uint16 GetAnnCompNum(void);

void SetAnnSel(uint8 tmp);
void AddAnnSel(void);
uint8 GetAnnSel(void);

void AddSysCheckDep(void);
void SubSysCheckDep(void);
void SetSysCheckDep(uint8 tmp);
uint8 GetSysCheckDep(void);

void AddStatusDep(void);
void SubStatusDep(void);
void SetStatusDep(uint8 tmp);
uint8 GetStatusDep(void);

void AddStatusComp(void);
void SubStatusComp(void);
void SetStatusComp(uint8 tmp);
uint8 GetStatusComp(void);

void AddStatusFlag(void);
void SetStatusFlag(uint8 tmp);
uint8 GetStatusFlag(void);


void AddIntenDep(void);
void SubIntenDep(void);
void SetIntenDep(uint8 tmp);
uint8 GetIntenDep(void);

void AddIntenComp(void);
void SubIntenComp(void);
void SetIntenComp(uint8 tmp);
uint8 GetIntenComp(void);

void AddIntenFlag(void);
void SetIntenFlag(uint8 tmp);
uint8 GetIntenFlag(void);



#line 53 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\Delay.h"












 






void SysTick_Handler(void);   

void delay1(void);
void Delay1Ms(uint32 t);




 


#line 55 "..\\src\\APP\\include.h"


#line 1 "..\\src\\MenuCtrl\\runfunction.h"












 

#line 1 "..\\src\\common\\CFlashParam.h"












 

#line 16 "..\\src\\common\\CFlashParam.h"




#line 1 "..\\src\\Board\\pcf8563.h"















 

#line 19 "..\\src\\Board\\pcf8563.h"
#line 101 "..\\src\\Board\\pcf8563.h"



 
#line 21 "..\\src\\common\\CFlashParam.h"
#line 1 "..\\src\\common\\CMaDefine.h"












 















#line 35 "..\\src\\common\\CMaDefine.h"




#line 22 "..\\src\\common\\CFlashParam.h"
#line 1 "..\\src\\Hardware\\UART\\uart.h"


















 
#line 21 "..\\src\\Hardware\\UART\\uart.h"

#line 580 "..\\src\\Hardware\\UART\\uart.h"


 
#line 23 "..\\src\\common\\CFlashParam.h"









#line 40 "..\\src\\common\\CFlashParam.h"


#line 54 "..\\src\\common\\CFlashParam.h"







#line 86 "..\\src\\common\\CFlashParam.h"


 
 
 
 
 

#line 103 "..\\src\\common\\CFlashParam.h"





 
 
 
 
 







typedef	union FlashInfoDef
{
    
    uint8    row;  
    uint8 	 type;	
    uint8	   setup;	
    uint8    alarmtype;
    
    
    uint16  year;
    uint8   month;
    uint8   day;
    uint8   hour;
    uint8   minute;
    uint8   second;
    
    uint8    signal;
    uint8    compann;
}tFlashinfoDef,*PFlashinfoDef;






 
 
 
 
 

typedef void (void_fnc_t) (void);
typedef struct Flash_Record{
    uint32 addr;
    uint8 (*buf)[(1)];
    uint8 (*bigbuf)[(8)];
    uint8 (*alarmbuf)[(18)];
    uint8 (*nodebuf)[(2)]; 
    uint8 (*histbuf)[(17)]; 
    uint32 llen;
    uint32 rlen;
    void_fnc_t *initfun;
    void_fnc_t *savefun;
}Flash_Record;



 
 
 
 
 






 
 
 
 
 








typedef struct alarminfo{
    uint8 inzone;
    uint8 part;
    uint8 ciraddr;
    uint8 alarmsum;
    uint8 type;
    uint8 alarmed;
    PCF8563_DATE dateyear;
    uint8 firstalarm;
    uint8 attr;
    uint8 vAnnRow;
    uint8 reserve;
}alarminfo;

 
 
 
 
 
typedef struct history_st{
    uint8 order;
    uint8 inzone;
    uint8 part;
    uint8 circleaddr;
    uint8 vAnnRow;
    uint8 attr;
    uint8 opstype;
    uint8 devtype;
    uint8 lastnum;
    PCF8563_DATE dateyear;
}history_st;



typedef struct
{
    uint32 firesum;
    uint32 faultsum;
    uint32 battlowsum;
}tSum;

 
 
 
 
 






typedef struct compent{
    uint8 inzone;
    uint8 part;
    uint8 ciraddr;
    uint8 psn0;
    uint8 psn1;
    uint8 psn2;
    uint8 psn3;
    uint8 devtype;
}compent;







 
void SetHistFlag(uint8 tmp);
uint8 GetHistFlag(void);

uint8 gethistory_isfirealarm(uint32 row);

uint8 gethistory_isbatlow(uint32 row);

uint8 gethistory_isfault(uint32 row);
void AddPageConter(void);
void SetPageConter(uint8 tmp);
uint8 GetPageConter(void);
void AddHistConter(void);
uint16 GetHistConter(void);
void SetHistConter(uint16 tmp);

void setHistFullFlag(uint8 flag);
uint8 getHistFullFlag(void);

uint8 getHistFull(void);
static void init_record(Flash_Record * flash_record);
static void save_record(Flash_Record * flash_record);

static void set_array(Flash_Record * flash_record,uint32 row,uint32 col,uint8 tmp);

static uint8 get_array(Flash_Record * flash_record,uint32 row,uint32 col);
void init_basic_info(void);
void set_basic_info(uint32 row,uint8 tmp);
uint8 get_basic_info(uint32 row);

void save_basic_info(void);

void set_basic_nums(uint8 compnums);

void add_basic_nums(void);

void sub_basic_nums(void);
void set_basic_localaddr(uint8 localaddr);
void set_basic_zones(uint8 departallnums);
uint32 get_basic_localaddr(void);
uint32 get_basic_zones(void);
uint32 get_basic_nums(void);
void init_comp_info(void);
void save_comp_info(void);

static void set_comp_info(uint32 row,uint32 col,uint8 tmp);

static uint8 get_comp_info(uint32 row,uint32 col);

void set_comp_inzone(uint8 item,uint8 inzone);

void set_comp_partnumber(uint8 item,uint8 partnumber);
void set_comp_ciraddr(uint8 item,uint8 ciraddr);
void set_comp_psn0(uint8 item,uint8 psn0);
void set_comp_psn1(uint8 item,uint8 psn1);
void set_comp_psn2(uint8 item,uint8 psn2);
void set_comp_psn3(uint8 item,uint8 psn3);
void set_comp_devtype(uint8 item,uint8 devtype);

void set_comp_all(uint8 item,compent *compinfo);

void clr_comp_all(uint8 item);

void clr_comp_loop_all(void);

void set_comp_all_and_save(uint8 item,compent *compinfo);

uint8 get_comp_inzone(uint8 item);
uint8 get_comp_partnumber(uint8 item);
uint8 get_comp_ciraddr(uint8 item);

uint8 judge_same_ciraddr(uint8 row,uint8 ciraddr);
uint8 get_comp_psn0(uint8 item);
uint8 get_comp_psn1(uint8 item);
uint8 get_comp_psn2(uint8 item);
uint8 get_comp_psn3(uint8 item);
uint8 get_comp_devtype(uint8 item);

void get_comp_all(uint8 item, compent *compinfo);
void init_mask_info(void) ;
void save_mask_info(void) ;
void set_mask_info(uint32 row,uint8 tmp);
uint8 get_mask_info(uint32 row) ;

void init_alarm_info(void);

void save_alarm_info(void) ;
static void set_alarm(uint32 row,uint32 col, uint8 tmp);
static uint8 get_alarm_info(uint32 row,uint32 col) ;

uint8 get_alarm_attr(uint32 row);
uint8 get_alarm_alarmed(uint32 row);

uint8 judge_alarm_firealarmed(uint32 row);

uint8 judge_alarm_faultalarmed(uint32 row);
uint8 get_alarm_firstalarm(uint32 row);

void set_alarm_inzone(uint32 item, uint8 tmp);
void set_alarm_part(uint32 item, uint8 tmp);
void set_alarm_ciraddr(uint32 item, uint8 tmp);
void set_alarm_alarmsum(uint32 item, uint8 tmp);
void set_alarm_type(uint32 item, uint8 tmp);
void set_alarm_alarmed(uint32 item, uint8 tmp);
void set_alarm_firstalarm(uint32 item, uint8 tmp);
void set_alarm_allinfo(uint32 item,alarminfo *info);

void clr_alarm_allinfo(void);
void set_alarm_allinfo_andsave(uint32 item,alarminfo *info);
uint8 get_alarm_part(uint32 item);
uint8 get_alarm_ciraddr(uint32 item);
uint8 get_alarm_type(uint32 item);
void get_alarm_allinfo(uint32 item, alarminfo *info);

void set_alarm_first(alarminfo *info);

void get_alarm_first(alarminfo *info);

uint8 get_alarm_firstflag(void);

uint8 get_alarm_first_part(void);

uint8 get_firealarm_nums(void);
void clr_firealarm(void);

uint8 get_alarm_item_bypart(uint8 part);

uint8 get_faultalarm_nums(void);

uint8 judge_alarm_first(void);
void init_node_info(void) ;
void save_node_info(void);

void set_node_info(uint32 row,uint32 col,uint8 tmp);

uint8 get_node_info(uint32 row,uint32 col);

int8 get_node_row( uint8 comp);
void save_node_and_nodenums(void) ;

void init_nodenums_info(void) ;

void save_nodenums_info(void);
void set_nodenums(uint8 tmp);
uint8 get_nodenums(void);
void add_nodenums(void);
void init_hist_info(void) ;
void save_hist_info(void) ;

static uint8 get_hist_info(uint32 row,uint8 col) ;
void set_hist_info(uint32 row,uint8 col,uint8 tmp) ;
void clr_hist_info(void)  ;
uint8 get_hist_order(uint32 row) ;
uint8 get_hist_inzone(uint32 row) ;
uint8 get_hist_part(uint32 row) ;
uint8 get_hist_circleaddr(uint32 row) ;
uint8 get_hist_vAnnRow(uint32 row) ;
uint8 get_hist_attr(uint32 row) ;
uint8 get_hist_opstype(uint32 row) ;
uint8 get_hist_devtype(uint32 row) ;
uint8 get_hist_lastnum(uint32 row) ;

void get_hist_datetime(uint32 row,PCF8563_DATE* dateyear) ;

void get_hist_allinfo(uint32 row, history_st* info);

void set_hist_allinfo(uint32 row, history_st* info);

void save_hist_all(void);

uint8 judge_histnums_full(void);

void set_histnum_full(void);

void init_histnums_info(void) ;
void save_histnums_info(void) ;

static void set_histnum_info(uint32 row,uint8 tmp);

static uint8 get_histnum_info(uint32 row);

void init_hist_and_histnums(void);
void init_histsufix_info(void);

void init_flash_all(void);

uint8 CheckDepComp(uint8 dep,uint8 comp);

int16 GetNum(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3);
void CAddCirCounter(void);
void CSetCirCounter(uint8 tmp);
uint8 CGetCirCounter(void);
int8 GetRow(uint8 t1,uint8 t2);

uint8 JudgeAlarmType(void);
uint8 JudgeCompAlarmType(uint8 row);
void SetDatatoFlash(uint8 row,uint8 col,uint8 tmp);
uint8 GetDatatoFlash(uint8 row,uint8 col);

uint8 GetDatatoFlashType(uint8 row);
uint8 GetDatatoFlashAlarmType(uint8 row);
void SetFlashData(uint8 id,uint8 tmp);
void SetDepCompSum(uint16 temp,uint8 tmp);
uint8 GetDepCompSum(uint16 tmp);

uint8 ReadFlashPsn(uint8 row,uint8 col);
void SetCom0Ann(uint8 row,uint8 cow,uint8 tmp);

void set_node_all_info(uint32 row,note_info_t *info);






 


#line 16 "..\\src\\MenuCtrl\\runfunction.h"



























void DisplayKeyMenu(void);
void Systemp_Task(void);
void SendHeart(void);

void CS0Setup(uint8 tmp);
void inqury_state__byuart0(void);


void show_head_menu(void);
void set_history_alarm_pos(uint16 pos);

void set_menu_alarm_info(alarminfo alarm_info);


void clr_alarm_loop_show(void);
void set_alarm_loop_show(void);
uint8 get_alarm_loop_show(void);

#line 58 "..\\src\\APP\\include.h"

#line 1 "..\\src\\APP\\publicparam.h"












 

#line 1 "..\\src\\APP\\include.h"












 

#line 115 "..\\src\\APP\\include.h"

#line 18 "..\\src\\APP\\publicparam.h"






 

#line 60 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Menu\\startmenu.h"












 





void Start_Menu12by12(void);
void Start_Menu(void);




 




#line 62 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\mainmenu.h"












 





void Main_Menu(uint8 tmp);
void menu_complete(void);
void menu_press_return_toreturn(void);
void menu_Speaker_Open_Close(uint8 tmp);
void menu_waiting(void);



 
#line 63 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\setmenu.h"












 



void Set_Menu(uint8 tmp);
void CSaveInfo(void);

#line 64 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\checkmenu.h"












 



void Check_Menu(uint8 tmp);

#line 65 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\testmenu.h"












 


void Test_Menu(uint8 tmp);
#line 66 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\batteryLow.h"












 



void Battery_Low(uint8 depart,uint8 compent,uint16 sum,uint8 type,PCF8563_DATE timed);

#line 67 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\breakdown.h"












 


void Breakdown(uint8 attr,uint8 compent,uint16 sum,uint8 type,PCF8563_DATE* timed);


#line 68 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CLocalSet.h"












 



uint16 HZ_SHOW(uint8* hz,uint8 num);

void Local_Menu(uint8 local_addr0,uint8 local_addr1,uint8 local_addr2,uint8 depart0,uint8 depart1,uint8 depart2,uint8 selflag,uint8 sureFlag);

#line 69 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CCompReg.h"












 




#line 25 "..\\src\\Menu\\CCompReg.h"


void CompReg_menu(uint16 department,uint16 tmp,uint8 regf,uint8 tm2,uint8 rflag,uint8 sureflag);
void menu_compaddr(uint8 line);
void menu_compstatus(void);
void menu_comptype(void);
#line 70 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CCompSet.h"












 





void CompSet_Menu(uint16 temp,uint16 tmp,uint8 tm,uint8 sflag,uint8 sureflag);
void GNSelect(uint8 tm);
void GNSelectBlack(uint8 tm);
#line 71 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CDateMod.h"












 



void DateMod_Menu(uint16 year,uint8 month,uint8 day,uint8 hour,uint8 minute,uint8 second,uint8 tflag,uint8 sureflag);


#line 72 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CAnnotate.h"












 



void Annotate_Menu(uint8 dep,uint8 comp,uint8 aflag);

#line 73 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CSysCheck.h"












 




void SysCheck_Menu(uint16 t1,uint8 t2,uint8 t3,uint8 t4);

#line 74 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CCompStat.h"












 




void CompStat_Menu(uint8 t1,uint8 t2,uint8 type,uint8 t4,uint8 t5,uint8 sflag);
#line 75 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CHistoryList.h"












 





 
#line 27 "..\\src\\Menu\\CHistoryList.h"





void History_Menu(uint8 num1,uint8 address,uint8 type,uint8 alarmType,uint8 part,PCF8563_DATE* TimeAndDate);
void menu_nohistory(void);
void menu_history_over(void);



#line 76 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CCompInten.h"












 



void CompInten_Menu(uint8 inzone,uint8 compent,uint8 type,int8 inten);
void CSetIntenFlag(uint8 tmp);
uint8 CGetIntenFlag(void);




#line 77 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CTestSelf.h"












 



void TestSelf_Menu(void);


#line 78 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\alarmenu.h"












 




void Alarm_Menu(uint8 fisrtpart,uint8 otherpart,uint8 cirAddr,uint16 alarmsum,uint8 type,PCF8563_DATE *timed);


#line 79 "..\\src\\APP\\include.h"


#line 1 "..\\src\\common\\CTimerTask.h"












 





#line 20 "..\\src\\common\\CTimerTask.h"







 







 
 
 









 
















 






 


 







 
 

 

 
extern void InitTmrTickTask(void); 


extern tBoolean GetTickTaskStatus(uint8 taskID); 			
extern tBoolean GetTickTaskStaNoClr(uint8 taskID);
extern tBoolean SetTmrTickTask(uint8 taskID, uint32 SetMSec);
extern tBoolean KillTickTask(uint8 taskID);

extern void ClearTickTaskTmr(uint8 taskID);  
extern void SetTickTaskSign(uint8 taskID); 			
extern void ClrTickTaskSign(uint8 taskID);
extern tBoolean JudgeTickTaskUsing(uint8 taskID); 			

 





#line 82 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Board\\CLED.h"












 



void Led_Init(void);
void Led_ALL_On(void);
void Led_Off(void);

void Led_Run_Init(void);
void Led_Run_On(void);
void Led_Run_Off(void);

void Led_Silence_Init(void);
void Led_Silence_On(void);
void Led_Silence_Off(void);

void Led_Wireless_Init(void);
void Led_Wireless_On(void);
void Led_Wireless_Off(void);


void Led_Fault_Init(void);
void Led_Fault_On(void);
void Led_Fault_Off(void);


void Led_Fire_Init(void);
void Led_Fire_On(void);
void Led_Fire_Off(void);

#line 85 "..\\src\\APP\\include.h"

#line 1 "..\\src\\13CirCon\\CAddressCount.h"












 


void AddCirCounter(void);
uint32 GetCirCounter(void);

void Clr_Alarm(void);






void SetAlarm_Circuit_Flag(uint8 tmp);


void SetSync(void);
uint8 GetSync(void);
void ClrSync(void);


uint32 SyncFlagCounter(void);
void ClrCirCounter(void);
void addxialasignal(void);
uint8 getxialasignal(void);
void add_weixialasignal(void);

void clr_weixialasignal(void);
void clr_xialasignal(void);
#line 87 "..\\src\\APP\\include.h"

#line 1 "..\\src\\common\\CFlash_ADDR_Def.h"







#line 17 "..\\src\\common\\CFlash_ADDR_Def.h"



#line 89 "..\\src\\APP\\include.h"






















 
 
 


#line 21 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\12UARTHandle\\CComHandle.h"












 

#line 16 "..\\src\\12UARTHandle\\CComHandle.h"











#line 36 "..\\src\\12UARTHandle\\CComHandle.h"







#line 49 "..\\src\\12UARTHandle\\CComHandle.h"





















 

#line 79 "..\\src\\12UARTHandle\\CComHandle.h"










#line 97 "..\\src\\12UARTHandle\\CComHandle.h"



uint8 Convertdata[6] ={0};
uint8 UartRxbuf[9];
uint8 UartTxbuf[9];
uint8 Rxdata[9];
uint8 UartClrflag;	
uint8 UartClrLen;	
uint8 DefAddrEn;	
uint8 UartSendLen;	
uint8 *pTxbuf;		
uint8 MasterAddr;
uint8 Flag195=0;
uint8 FirstAlarm_Flag=0;

uint8 AlarmSum[3]={0};

uint8 CheckInfoFlag[3]={0};



uint8 com1Count=0;

uint8  reset_fault_flag=0;
uint8  reset_batt_flag=0;
uint8  Address_Counter=0;

uint8 vdisplay_alarm[5]={0};
PCF8563_DATE    valarmtime;
uint8 vDispaly_alarm_flag=0;
PCF8563_DATE alarm_date;

void SetFirstAlarm_Flag(uint8 tmp);

void SetDisplay_alarm_flag(uint8 tmp);
uint8 GetDisplay_alarm_flag(void);
void Setdisplay_alarm(uint8 row,uint8 tmp);
uint8 Getdisplay_alarm(uint8 row);
PCF8563_DATE Getalarmtime(void);
void AddHeartFaultFlag(void);


void SetSum(uint8 row,uint8 tmp);
uint8 GetSum(uint8 row);





void SetConvertdata(uint8 col,uint8 tmp);

void UartBindSend(uint8 cmd,uint8 len);
uint8 wireless_data_check(void);
void HandleInfo_Uart1(void);
void set_firealarm_ciraddr(uint8 cir_addr);

void set_faultalarm_ciraddr(uint8 cir_addr);

void set_normalalarm_ciraddr(uint8 cir_addr);

uint8 CompareAddr(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3, int16 *com_num);

void check_lp_running(void);



uint8 check_psn_all0xff(void);





 


#line 22 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\12UARTHandle\\CComPara.h"












 

#line 16 "..\\src\\12UARTHandle\\CComPara.h"




#pragma pack(1)	
typedef struct{
	uint8 	header;	
	uint8	  cmd;   
	uint32  addr; 
	uint8   attr;
	uint8   detail;
	uint8	cs;	
}TdUartMsg,*PdUartMsg;
typedef struct{
	uint8 	header;	
	uint8	  cmd;   
	uint8 	addr[4]; 
	uint8   attr;
	uint8   detail;
	uint8	cs;	
}TdUartMsgDetail,*PdUartMsgDetail;
#pragma pack()
typedef union{
	TdUartMsg	UartMsg;
	TdUartMsgDetail	UartMsgDetail;
	uint8	UartMsgArray[sizeof(TdUartMsg)];
}TdUartMsgUnion,*PdUartMsgUnion;







#line 77 "..\\src\\12UARTHandle\\CComPara.h"

uint8 GetHeart(uint8 row);
void ReadHeart(void);
void data_from_data0(void);

void ClrComData(uint8 row);

PdUartMsgUnion GetComData(uint8 row);
uint8 get_dataCount(void);
void AddBattLowSum(void);
uint32 GetBattLowSum(void);

void AddBrokenSum(void);
uint32 GetBrokenSum(void);



void MergeData(void);
void Com0DataUnzip(void);
void Com0Handle(void);

void SetHeartFaultFlag(void);
void ClrHeartFaultFlag(void);
uint8 GetHeartFaultFlag(void);

void SetAlarmFlag(uint8 row,uint8 tmp);
uint8 GetAlarmFlag(uint8 row);


uint8 GetFirstAlarm_Addr(uint8 row);




void AddAlarmInfoFlag(void);
void SubAlarmInfoFlag(void);
void SetAlarmInfoFlag(uint8 tmp);
uint8 GetAlarmInfoFlag(void);


void SetReleaseFlag(uint8 tmp);
uint8 GetReleaseFlag(void);

void SetFlag_195(uint8 tmp);
uint8 GetFlag_195(void);

void SetCirAddrCurrent(uint8 tmp);
uint8 GetCirAddrCurrent(void);
void CompareCirAddr(void);
void Init_CirAddrInfo(void);
void ClrCirAlarmData(void);


void CirAlarmDataInit(void);

void SetFlagLed(uint8 tmp);
uint8 GetFlagLed(void);








 


#line 23 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\common\\CFlashParam.h"












 

#line 16 "..\\src\\common\\CFlashParam.h"

#line 473 "..\\src\\common\\CFlashParam.h"


 


#line 24 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\12UARTHandle\\CComAnn.h"












 



#line 25 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\MenuCtrl\\CKeyCounter.h"












 






#line 27 "..\\src\\MenuCtrl\\CKeyCounter.h"

void SetCounter1(uint8 tmp);
void AddCounter1(void);
void SubCounter1(void);
uint8 GetCounter1(void);

void SetCounter2(uint8 tmp);
void AddCounter2(void);
void SubCounter2(void);
uint8 GetCounter2(void);


void SetCounter3(uint8 tmp);
void AddCounter3(void);
void SubCounter3(void);
uint8 GetCounter3(void);



void SetGrapCount(uint8 tmp);
void AddGrapCount(void);
void SubGrapCount(void);
void ClrGrapCount(void);
uint8 GetGrapCount(void);

void AddMenuFlag(void);
void SubMenuFlag(void);
uint8 GetMenuFlag(void);
void SetMenuFlag(uint8 tmp);

void SetPasswordFlag(uint8 tmp);
uint8 GetPasswordFlag(void);
#line 26 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\common\\CSendToFlash.h"































#line 27 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\14Sand195\\CSendTo195.h"












 



void SaveData195(uint8 col,uint8 tmp);
uint8 GetData195(uint8 col);
void Query_ByUart0(uint8 data3,uint8 data9,uint8 ciraddr);

#line 28 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\MenuCtrl\\CTaskSure.h"












 




















#line 42 "..\\src\\MenuCtrl\\CTaskSure.h"



























void SetZjFlag(uint8 tmp);
uint8 GetZjFlag(void);
void Set_Note_Flag(void);
void Clr_Note_Flag(void);
uint8 Get_Note_Flag(void);




void CLevel1_Sure(uint8 tmp);
void setup_Sure(uint8 tmp);
void query_Sure(uint8 tmp);
void test_Sure(uint8 tmp);
void CLevel24_Sure(uint8 tmp);
void CLevel27_Sure(void);
void CLevel3_Sure(uint8 tmp);
void menu_press_ok_complete(uint8 line);
void menu_setup_done(void);
void menu_press_ok_save(void);
void SetSpeaker_ON(void);
void SetSpeaker_OFF(void);
uint8 GetSpeaker_Flag(void);
void menu_ops_done(void);

uint16 local_addr_value(void);

void query_compstatus_ok(void);
void menu_compset(void);
void menu_comp_masked(void);
void menu_comp_started(void);
void menu_opsing(void);


void set_enter_flag(void);
uint8 get_enter_falg(void);
void clr_enter_flag(void);
void menu_deling(void);
void menu_comp_noreg(void);


void set_entry_localaddr_flag(void);
uint8 get_entry_localaddr_flag(void);
void clr_entry_localaddr_flag(void);
void reset_ok(void);
#line 29 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\common\\CMaDefine.h"












 















#line 35 "..\\src\\common\\CMaDefine.h"




#line 30 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\Board\\CLED.h"












 



void Led_Init(void);
void Led_ALL_On(void);
void Led_Off(void);

void Led_Run_Init(void);
void Led_Run_On(void);
void Led_Run_Off(void);

void Led_Silence_Init(void);
void Led_Silence_On(void);
void Led_Silence_Off(void);

void Led_Wireless_Init(void);
void Led_Wireless_On(void);
void Led_Wireless_Off(void);


void Led_Fault_Init(void);
void Led_Fault_On(void);
void Led_Fault_Off(void);


void Led_Fire_Init(void);
void Led_Fire_On(void);
void Led_Fire_Off(void);

#line 31 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\common\\CGetCompSum.h"





















#line 32 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\13CirCon\\CAddressCount.h"












 


void AddCirCounter(void);
uint32 GetCirCounter(void);

void Clr_Alarm(void);






void SetAlarm_Circuit_Flag(uint8 tmp);


void SetSync(void);
uint8 GetSync(void);
void ClrSync(void);


uint32 SyncFlagCounter(void);
void ClrCirCounter(void);
void addxialasignal(void);
uint8 getxialasignal(void);
void add_weixialasignal(void);

void clr_weixialasignal(void);
void clr_xialasignal(void);
#line 33 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"











 





#line 19 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"
#line 1 "..\\src\\CLoopCtrl\\CLpInfoDef.h"











 





#line 19 "..\\src\\CLoopCtrl\\CLpInfoDef.h"
 







 
 
 







 









 
 
 
 
 
 
 


extern  void   Init_CLpInfoDef(void);

 

 

 
 
 

#line 74 "..\\src\\CLoopCtrl\\CLpInfoDef.h"







#line 20 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"







 
 
 




 









 
 
 


typedef union type_tLpScanFlag{	   

   uint32   Word;
     uint16   UByte[4>>1];
     uint8    Byte[4];
   struct
     {
        uint32 bSys:1;	            
                                        
            uint32 bAddr:8;	            

            uint32 bComm:2;	            
            uint32 bState:1;            
            uint32 bRec0:4;             


            uint32 bAnsFlag:1;          
            uint32 bAnsStar:1;          
            uint32 bAnsStep:4;          
            uint32 bAnsTId:3;           
            uint32 bReset:1;            
    }Bit;
}tLpScanFlag;
 
 
 


extern  void   Init_CLpScanCtrl(void);

extern  void   NewNode_CLpScanCtrl(void);

extern  void   ClrComm_CLpScanCtrl(void);
extern  void   SetComm_CLpScanCtrl(uint8 vComm);
extern  uint8  GetComm_CLpScanCtrl(void);

extern  void   ClrAddr_CLpScanCtrl(void);
extern  void   IncAddr_CLpScanCtrl(void);
extern  void   SetAddr_CLpScanCtrl(uint8 vAddr);
extern  uint8  GetAddr_CLpScanCtrl(void);

extern  void    ClrSys_CLpScanCtrl(void);
extern  void    SetSys_CLpScanCtrl(void);
extern  uint8   GetSys_CLpScanCtrl(void);

extern  void    ClrState_CLpScanCtrl(void);
extern  void    SetState_CLpScanCtrl(void);
extern  uint8   GetState_CLpScanCtrl(void);

extern  void    ClrAnsFlag_CLpScanCtrl(void);
extern  void    SetAnsFlag_CLpScanCtrl(void);
extern  uint8   GetAnsFlag_CLpScanCtrl(void);

extern  void    ClrAnsStar_CLpScanCtrl(void);
extern  void    SetAnsStar_CLpScanCtrl(void);
extern  uint8   GetAnsStar_CLpScanCtrl(void);

extern  void    ClrAnsStep_CLpScanCtrl(void);
extern  void    SetAnsStep_CLpScanCtrl(void);
extern  uint8   GetAnsStep_CLpScanCtrl(void);

extern  void    ClrAnsTId_CLpScanCtrl(void);
extern  void    SetAnsTId_CLpScanCtrl(void);
extern  uint8   GetAnsTId_CLpScanCtrl(void);
extern  void    DecAnsTId_CLpScanCtrl(void);



extern  void  SetReset_CLpScanCtrl(void);
extern  uint8 GetReset_CLpScanCtrl(void);
extern  void  ClrReset_CLpScanCtrl(void);

 
 
 

#line 133 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"







#line 34 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\componentinfo\\componentinfo.h"


















































































#line 35 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\componentinfo\\store_addr.h"
#line 4 "..\\src\\componentinfo\\store_addr.h"














extern void init_store(void);



















extern uint32 get_store_comp_state(uint8 item);

extern uint32 get_comp_ciraddr_zp(uint8 inzone,uint8 partnumber);

extern uint32 get_storepos(void);



extern void clr_store_comp_info(uint8 item);

extern uint8 judge_store_new(uint8 item);


extern void add_store_comp_nums(void);

extern void sub_store_comp_nums(void);
#line 36 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\CNodeInfo\\CNodeInfo.h"











 





#line 19 "..\\src\\CNodeInfo\\CNodeInfo.h"
#line 20 "..\\src\\CNodeInfo\\CNodeInfo.h"







 
 
 













 
 
 


typedef union type_tNodeInfo{	   

    uint32   Word;
    uint16   UByte[4>>1];
    uint8    Byte[4];
    struct
    {
        uint32 bReset:1;
        uint32 bCkCyc:4;	       
        uint32 bResetCyc:2;	     
        uint32 bComm:2;	         
        
        uint32 bFault:1;	           
        uint32 bFaultCyc:3;	         
        uint32 bReg:1;	         
        uint32 bState:2;	       
        uint32 bAlarm:1;	       

    }Bit;
}tNodeInfo;
 
 
 


extern  void  Init_CNodeInfo(void);

extern  void    SetState_CNodeInfo(uint8 vAddr,uint8 vType);
extern  uint8   GetState_CNodeInfo(uint8 vAddr);
extern  void    ClrState_CNodeInfo(uint8 vAddr);

extern  void    ClrReset_CNodeInfo(uint8 vAddr);
extern  void    SetReset_CNodeInfo(uint8 vAddr);
extern  uint8   GetReset_CNodeInfo(uint8 vAddr);

extern  void    ClrReg_CNodeInfo(uint8 vAddr);
extern  void    SetReg_CNodeInfo(uint8 vAddr);
extern  uint8   GetReg_CNodeInfo(uint8 vAddr);

extern  void    ClrAlarm_CNodeInfo(uint8 vAddr);
extern  void    SetAlarm_CNodeInfo(uint8 vAddr);
extern  uint8   GetAlarm_CNodeInfo(uint8 vAddr);

extern  void    ClrMax_CNodeInfo(void);
extern  void    SetMax_CNodeInfo(uint8 vAddr);
extern  uint8   GetMax_CNodeInfo(void);


extern  void    SetComm_CNodeInfo(uint8 vAddr,uint8 vType);
extern  uint8   GetComm_CNodeInfo(uint8 vAddr);
extern  void    ClrComm_CNodeInfo(uint8 vAddr);


extern  void    SetCkCyc_CNodeInfo(uint8 vAddr);
extern  uint8   GetCkCyc_CNodeInfo(uint8 vAddr);
extern  void    ClrCkCyc_CNodeInfo(uint8 vAddr);



 
 
 

#line 119 "..\\src\\CNodeInfo\\CNodeInfo.h"







#line 37 "..\\src\\12UARTHandle\\CComHandle.c"
#line 1 "..\\src\\common\\CGrapParam.h"












 

#line 16 "..\\src\\common\\CGrapParam.h"
#line 226 "..\\src\\common\\CGrapParam.h"


#line 38 "..\\src\\12UARTHandle\\CComHandle.c"











extern PCF8563_DATE    timedate;
PdUartMsgUnion pdUartSend;

PdUartMsgUnion pdUartRcv;
tFlashinfoDef  FlashInfo;


history_st  histinfo;

compent  compreg;

void AddHeartFaultFlag(void);





void SetFirstAlarm_Flag(uint8 tmp)
{
    FirstAlarm_Flag=tmp;
}
void SetDisplay_alarm_flag(uint8 tmp)
{
    vDispaly_alarm_flag=tmp;
}
uint8 GetDisplay_alarm_flag(void)
{
    return vDispaly_alarm_flag;
}
void Setdisplay_alarm(uint8 row,uint8 tmp)
{
    vdisplay_alarm[row]=tmp;
}
uint8 Getdisplay_alarm(uint8 row)
{
    return 	vdisplay_alarm[row];
}
PCF8563_DATE Getalarmtime(void)
{
    return valarmtime;
}

void SetSum(uint8 row,uint8 tmp)
{
    AlarmSum[row]=tmp;
}
uint8 GetSum(uint8 row)
{
    return AlarmSum[row];
}
void SetConvertdata(uint8 col,uint8 tmp)
{
    Convertdata[col]=tmp;
}





void check_lp_running(void)
{
    while(GetSys_CLpScanCtrl());
}

 

void UartBindSend(uint8 cmd,uint8 len)
{
    uint8 num;
    uint8 dat =0;

    pdUartSend = (PdUartMsgUnion)UartTxbuf;
    pdUartSend->UartMsg .header = 0x82;
    pdUartSend->UartMsg .cmd = cmd;

    if(9 == len){
        memcpy(pdUartSend->UartMsgDetail .addr, Convertdata, 6);  
        for(num = 0; num < 7; num++)					
            dat += pdUartSend->UartMsgArray[num+1];
        pdUartSend->UartMsg .cs = dat;

        UartSendLen = 9;
        pTxbuf = pdUartSend->UartMsgArray;
    }else{

    }

    UARTSend(1,pdUartSend->UartMsgArray,len);
}
 









uint8 wireless_data_check(void)
{
    uint8 num;
    uint8 dat = 0;

    if(pdUartRcv->UartMsg .header != 0x82)
    {

        UartClrflag = 0xA5;
        UartClrLen = 0x01;
        return 0x00;
    }
    if(pdUartRcv->UartMsg .cmd == 0x38)
    {
        return 0x01;
    }

    for(num = 1; num < 9-1; num++)				
        dat += pdUartRcv->UartMsgArray[num];
    dat = (dat&0xff);
    if(dat == pdUartRcv->UartMsg .cs)			
    {
        UartClrflag = 0xA5;
        UartClrLen = 9;
        return 0x01;
    }

    UartClrflag = 0xA5;
    UartClrLen = 0x01;
    return 0x00;
}
 

uint8 find_zone_comp(uint8 inzone,uint8 partnumber)
{
    uint8 i;

    for(i=(1);i<=50;i++)
        if((get_comp_partnumber(i) == partnumber)&&
                ((0xff) !=get_comp_partnumber(i)))
        {

            return 1;
        }
    return 0;
}

void printf_zone_comp_info(void)
{
    uint8 i;
    for(i=(1);i<=50;i++)
        lcd_printf("->info::%d:inzone:%d,partnumber:%d\n",i,get_comp_inzone(i),get_comp_partnumber(i));

}

void autoadd_compreg(void)
{
    AddCompRegNum();
    if(GetCompRegNum() >50)
        SetCompRegNum((1));
}


 
void comp_reg_deal(void)
{
    uint16 ciraddr,partnumber,total_nums;
    int16 com_num=-1;

    memset(&compreg,0,sizeof(compent));

    memset(&histinfo,0,sizeof(history_st));


    OnLCD();
    lcd_printf("GetComRegFlag:%d\n",GetComRegFlag());


    total_nums=get_basic_nums();
    ciraddr=get_basic_localaddr();
    partnumber=GetCompRegNum();

    lcd_printf("===comp regging info......\n");
    lcd_printf("total_nums:%d\n",total_nums);
    lcd_printf("partnumber:%d\n",partnumber);
    lcd_printf("ciraddr:%d\n",ciraddr);


    getcurrent_date(&histinfo.dateyear);

    


    EndInt(); 


    
    if(find_zone_comp(0,partnumber))
    {

        CompReg_menu(0,partnumber,2,GetCompRegAddr(),GetCompRegParaSel(),0);
        goto END;

    }
    else if(CompareAddr(pdUartRcv->UartMsgDetail .addr[3],pdUartRcv->UartMsgDetail .addr[2],pdUartRcv->UartMsgDetail .addr[1],pdUartRcv->UartMsgDetail .addr[0],&com_num)==0)
    {

        CompReg_menu(0,partnumber,3,GetCompRegAddr(),GetCompRegParaSel(),0);

        goto END;


    }
    else if(0x2 == CompareAddr(pdUartRcv->UartMsgDetail .addr[3],pdUartRcv->UartMsgDetail .addr[2],pdUartRcv->UartMsgDetail .addr[1],pdUartRcv->UartMsgDetail .addr[0],&com_num))
    {

        CompReg_menu(0,partnumber,7,GetCompRegAddr(),GetCompRegParaSel(),0);

        goto END;

    }
    else
    {
        if(total_nums > 50){
            

            CompReg_menu(0,partnumber,5,GetCompRegAddr(),GetCompRegParaSel(),0);
            goto END;

        }
        if(ciraddr > 200)
        {
            CompReg_menu(0,partnumber,4,GetCompRegAddr(),GetCompRegParaSel(),0);


            goto END;

        }






        
        CompReg_menu(0,partnumber,6,GetCompRegAddr(),GetCompRegParaSel(),0);

        

        compreg.inzone = histinfo.inzone = 0;
        compreg.part   = histinfo.part   =partnumber;
        compreg.ciraddr =histinfo.circleaddr = ciraddr;
        compreg.psn0    = pdUartRcv->UartMsgDetail .addr[3];
        compreg.psn1    = pdUartRcv->UartMsgDetail .addr[2];
        compreg.psn2    = pdUartRcv->UartMsgDetail .addr[1];
        compreg.psn3    = pdUartRcv->UartMsgDetail .addr[0];
        compreg.devtype =histinfo.devtype = pdUartRcv->UartMsgDetail .attr;




        histinfo.attr    = (0x00);
        histinfo.opstype = (0xff);
        histinfo.order = GetHistConter();
        histinfo.lastnum   = (0xff);
        histinfo.vAnnRow = (0xff);

        lcd_printf("-->>save hist:\n");
        lcd_printf("year:%d\n",histinfo.dateyear.year);
        lcd_printf("month:%d\n",histinfo.dateyear.month);
        lcd_printf("day:%d\n",histinfo.dateyear.day);
        lcd_printf("hour:%d\n",histinfo.dateyear.hour);
        lcd_printf("minute:%d\n",histinfo.dateyear.minute);
        lcd_printf("second:%d\n",histinfo.dateyear.second);

        
        set_comp_all(partnumber,&compreg);
        set_mask_info(partnumber,(0x00));
        set_hist_allinfo(GetHistConter(),&histinfo);


        
        SetReg_CNodeInfo(ciraddr);
        

        save_comp_info();
        save_mask_info();
        save_hist_all();

        lcd_printf("->>save reg info save to flash\n");

        autoadd_compreg();
        CompReg_menu(0,GetCompRegNum(),1,GetCompRegAddr(),GetCompRegParaSel(),0);
    }


END:
    StartInt();
    Eint_EnAll_Exuart();




}

 
void inquiry_signal_strength(void)
{
    int16 com_num=-1;
    int8 ret;
    lcd_printf("===>>>signal strength test\n");
    OnLCD();
    ret=CompareAddr(pdUartRcv->UartMsgDetail .addr[3],pdUartRcv->UartMsgDetail .addr[2],pdUartRcv->UartMsgDetail .addr[1],pdUartRcv->UartMsgDetail .addr[0],&com_num);
    if(!ret&&com_num>=0)
    {
        lcd_printf("comp num:%d\n",com_num);

        CompInten_Menu(get_comp_inzone(com_num),
                       get_comp_partnumber(com_num),
                       pdUartRcv->UartMsgDetail .attr,
                       pdUartRcv->UartMsgDetail .detail);
    }else{
        CompInten_Menu(0,0,(0xff),0);
    }
}
uint8 is_0xff(uint8 psn)
{
    return ((0xff) == psn);
}


uint8 check_psn_all0xff(void)
{
    if(is_0xff(pdUartRcv->UartMsgDetail . addr[3])
            &&is_0xff(pdUartRcv->UartMsgDetail . addr[2])
            &&is_0xff(pdUartRcv->UartMsgDetail . addr[1])
            &&is_0xff(pdUartRcv->UartMsgDetail . addr[0]))
        return (1);
    else
        return (0);
}

 
uint8 is_my_psn(int16* com_num)
{
    *com_num=-1;
    if(0 == CompareAddr(pdUartRcv->UartMsgDetail . addr[3],pdUartRcv->UartMsgDetail . addr[2],pdUartRcv->UartMsgDetail . addr[1],pdUartRcv->UartMsgDetail . addr[0],com_num))
        return (1);
    else
        return (0);

}
void led_relay_deal(void)
{
    Fire_Relay_On();
    Led_Fire_On();
    Led_Silence_Off();

}


void set_firealarm_ciraddr(uint8 cir_addr)
{
    SetAlarm_CNodeInfo(cir_addr);  
    SetState_CNodeInfo(cir_addr,2); 

}

void set_faultalarm_ciraddr(uint8 cir_addr)
{
    SetAlarm_CNodeInfo(cir_addr);
    SetState_CNodeInfo(cir_addr,1);
}

void set_normalalarm_ciraddr(uint8 cir_addr)
{

    lcd_printf("normal ciraddr:%d\n",cir_addr);
    ClrAlarm_CNodeInfo(cir_addr);
    SetState_CNodeInfo(cir_addr,0);
}





 
void menu_firealarm_face(alarminfo* alarm1_info)
{
    memset(&histinfo,0,sizeof(history_st));

    histinfo.part = alarm1_info->part;
    histinfo.circleaddr = alarm1_info->ciraddr;
    histinfo.attr       = alarm1_info->attr;
    histinfo.devtype    = alarm1_info->type;
    histinfo.dateyear   = alarm1_info->dateyear;
    histinfo.vAnnRow    = alarm1_info->vAnnRow;

    lcd_printf("=====>>alarm1_info\n");
    lcd_printf("part: %d\n",alarm1_info->part);
    lcd_printf("ciraddr: %d\n",alarm1_info->ciraddr);
    lcd_printf("attr: %d\n",alarm1_info->attr);
    lcd_printf("devtype: %d\n",alarm1_info->type);
    lcd_printf("vAnnRow: %d\n",alarm1_info->vAnnRow);



    
    led_relay_deal();

    

    
    set_firealarm_ciraddr(alarm1_info->ciraddr);
    
    SetMenuFlag((1));
    SetDisplay_alarm_flag((1));

    set_menu_alarm_info(*alarm1_info);
    
    
    
    
    
    
    SetReleaseFlag(1);
    
    set_hist_allinfo(GetHistConter(),&histinfo);
    save_hist_all();
    
    
    
    
    
    
    
    
    

    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
}




















































































void menu_fault_deal(alarminfo* alarm_info)
{

    memset(&histinfo,0,sizeof(history_st));

    histinfo.part = alarm_info->part;
    histinfo.circleaddr = alarm_info->ciraddr;
    histinfo.attr       = alarm_info->attr;
    histinfo.devtype    = alarm_info->type;
    histinfo.dateyear   = alarm_info->dateyear;
    histinfo.vAnnRow    = alarm_info->vAnnRow;

    lcd_printf("=====>>fault alarm_info\n");
    lcd_printf("part: %d\n",alarm_info->part);
    lcd_printf("ciraddr: %d\n",alarm_info->ciraddr);
    lcd_printf("attr: %d\n",alarm_info->attr);
    lcd_printf("devtype: %d\n",alarm_info->type);
    lcd_printf("vAnnRow: %d\n",alarm_info->vAnnRow);

    Led_Fault_On();
    Fault_Relay_On();


    if(GetAlarmFlag(0) !=1)
        SetAlarmFlag(0,3);
    if(GetReleaseFlag()==0)
    {
        set_faultalarm_ciraddr(alarm_info->ciraddr);
        SetReleaseFlag(4);
        
        SetMenuFlag((0x03));
        SetDisplay_alarm_flag((3));
        
        set_menu_alarm_info(*alarm_info);

        
        
        
        

    }

    set_hist_allinfo(GetHistConter(),&histinfo);
    save_hist_all();


}
const uint8 fault_restore_cfg[2]={0x0b,0x01};

void normal_deal(uint8 num,uint8 cir_addr)
{
    lcd_printf("normal,ciraddr:%d\n",cir_addr);
    set_normalalarm_ciraddr(cir_addr);
    if(Flag195)
    {
        Query_ByUart0(fault_restore_cfg[0],fault_restore_cfg[1],cir_addr);
    }
    Flag195 = 0;
    if(reset_fault_flag)
    {
        reset_fault_flag=0;
        Led_Fault_Off();
        Fault_Relay_Off();
        
        if(GetDatatoFlash(num,(3)) == (0x32))
        {
            SetDatatoFlash(num,(3),0);
            
        }
        SetMenuFlag((0));
    }
    if(reset_batt_flag)
    {
        reset_batt_flag=0;
        Led_Fault_Off();
        Fault_Relay_Off();
        if(GetDatatoFlash(num,(3)) == (0x31))
        {
            SetDatatoFlash(num,(3),0);
            
        }
        SetMenuFlag((0));
    }
}

alarminfo  alarm_info;

 
void HandleInfo_Uart1(void)
{
    uint8 rcvcmd;

    uint8 cir_addr=0;

    int16 num;
    
    
    pdUartRcv = GetComData(com1Count);

    if(wireless_data_check() == 0x01)
    {

        ClrCom1Data0();

        rcvcmd = pdUartRcv->UartMsg .cmd;

        switch(rcvcmd)
        {
        case	0x30:		
        case	0x31:		
        case	0x32:		
        case	0x33:		
        case	0x34:		
        case	0x35:		
        case	0x36:		
            break;
        case	0x38:		
            ClrHeartFaultFlag();
            lcd_printf("CMD_139W\n");
            break;
        case	0x39:		
            clr_tp();
            break;
        case	0x40:		

            lcd_printf("-->>CMD_ALARM!!!\n");
            if(check_psn_all0xff())
            {
                lcd_printf("psn all 0xff\n");
                break;
            }
            if(is_my_psn(&num))
            {
                if(num < 0)
                    return;
                OnLCD();
                SetFlagLed(1);
                UartBindSend(0x40,9);


                
                if(get_mask_info(num) == (0x01))
                {
                    lcd_printf("num is masked:%d\n",num);

                    break;
                }
                else
                {
                    
    
                    lcd_printf("num:%d\n",num);
                    alarm_info.part = num;
                    alarm_info.ciraddr = get_comp_ciraddr(num);
                    alarm_info.type    = get_comp_devtype(num);
                    alarm_info.attr    = pdUartRcv->UartMsg .attr ;
                    alarm_info.alarmed = (0x02);
                    alarm_info.vAnnRow = GetAnnRow(num);
                    PCF8563_Read(&alarm_info.dateyear);

                    lcd_printf("alarm ciraddr:%d\n",alarm_info.ciraddr);
                    if((0x33) == alarm_info.attr)
                    {
                        
                        if((!judge_alarm_first())&&JudgeAlarmType())
                        {
                            lcd_printf("--->>>first alarm\n");
                            set_alarm_allinfo_andsave(num,&alarm_info);
                            set_alarm_first(&alarm_info);
                            
                            menu_firealarm_face(&alarm_info);
                        }else{
                            
                            if(judge_alarm_firealarmed(num))
                            {
                                
                                break;
                            }
                            lcd_printf("num:%d haved fire alarmed first\n",num);
                            set_alarm_allinfo_andsave(num,&alarm_info);
                            menu_firealarm_face(&alarm_info);
                        }
                    }
                    else if(((0x32) == alarm_info.attr)||
                            ((0x31) == alarm_info.attr))
                    {
                        if(judge_alarm_faultalarmed(num))
                        {
                            lcd_printf("num:%d haved fault alarmed\n",num);
                            break;
                        }
                        lcd_printf("num:%d haved fault alarmed\n",num);
                        set_alarm_allinfo_andsave(num,&alarm_info);
                        menu_fault_deal(&alarm_info);
                    }
                    Led_Silence_Off();
                    if((0x30) == pdUartRcv->UartMsg .attr)
                    {
                        lcd_printf("normal state\n");
                        normal_deal(num,cir_addr);
                    }
                }
            }else{
                
                
                
                
                
                break;
            }

            SetFlagLed(0);
            break;
        case	0x41:		
            lcd_printf("CMD_COMREG\n");

            if(CGetIntenFlag())
            {
                inquiry_signal_strength();
            }
            else if(GetComRegFlag())
            {
                ClrComRegFlag();

                comp_reg_deal();

            }else{
                OnLCD();
            }
            SetFlagLed(0);
            break;
        case	0x42:		
            if(pdUartRcv->UartMsg .attr == 0x30)
            {

            }
            else if(pdUartRcv->UartMsg .attr == 0x31)
            {

            }
            else if(pdUartRcv->UartMsg .attr == 0x32)
            {

            }
            else if(pdUartRcv->UartMsg .attr == 0x33)
            {

            }
            break;
        case	0x51:		
            break;
        default:
            break;
        }
        memset(pdUartRcv->UartMsgArray, 0 , 9);

    }else{

    }

     




    
    ClrComData(com1Count);
    com1Count++;
    if(com1Count== 20)
        com1Count=0;

    if(UartClrflag == 0xA5)
    {
        
        UartClrLen = 0x00;
        UartClrflag = 0x00;
    }
}































































































 
uint8 CompareAddr(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3,int16 *com_num)
{
    uint8 j;
    uint8 Regflag=1;
    if((0xff == psn0)&&
            (0xff == psn1)&&
            (0xff == psn2)&&
            (0xff == psn3))
    {
        return 0x2;
    }

    for(j= (1);j<= 50;j++)
    {
        if((get_comp_psn0(j)==psn0)&&
                (get_comp_psn1(j)==psn1)&&
                (get_comp_psn2(j)==psn2)&&
                (get_comp_psn3(j)==psn3))
        {

            if(com_num){
                *com_num=j;
                Regflag=0;
            }
            break;
        }
    }
    return Regflag;
}



