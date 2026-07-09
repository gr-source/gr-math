#ifndef DEFAULT_H
#define DEFAULT_H

#define MATH_USE_SIMD

#if defined(MATH_USE_SIMD)
#define ALIGN32 __attribute__((aligned(32)))
#define ALIGN16 __attribute__((aligned(16)))
#define ALIGN8  __attribute__((aligned(8)))
#else
#define ALIGN32
#define ALIGN16
#define ALIGN8
#endif

#endif // !DEFAULT_H
