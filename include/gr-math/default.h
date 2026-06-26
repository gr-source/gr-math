#ifndef DEFAULT_H
#define DEFAULT_H

#if defined(MATH_USE_SIMD)
#define ALIGN __attribute__((aligned(16)))
#else
#define ALIGN32
#define ALIGN16
#define ALIGN8
#endif

#endif // !DEFAULT_H
