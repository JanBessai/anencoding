#ifndef __LUT_H__
#define __LUT_H__

#define LUTS()  \
  MK_LUT(int, ANNot, 256)

#ifndef __LUT_IMPL__
#define MK_LUT(T, F, N) \
  extern const T (*F##Table_##T) [N]
LUTS();
#undef MK_LUT
#endif


#endif

