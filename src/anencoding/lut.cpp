#define __LUT_IMPL__
#include "lut.h"

template <class T, T ... args>
struct TemplateLut {
  static const T table[sizeof ... (args)];
};

template <class T, T ... args>
const T TemplateLut<T, args...>::table[sizeof ... (args)] = { args ... };

template <unsigned int N, class T, template<unsigned int, class> class F, T ... args>
struct TemplateLutBuilder {
  typedef typename TemplateLutBuilder<N-1, T, F, F<N, T>::value, args...>::result result;
};

template <class T, template<unsigned int, class> class F, T ... args>
struct TemplateLutBuilder<0, T, F, args...> {
  typedef TemplateLut<T, args...> result;
};

template <unsigned int N, class T, template<unsigned int, class> class F>
struct GenerateLut {
  typedef typename TemplateLutBuilder<N, T, F>::result result;
};

template <unsigned int A>
struct ANNot {
  template <unsigned int N, class T>
  struct LutFun {
    enum { value = (T)( ~((N ))) };
  };
};

const unsigned int A = 127;

#define MK_LUT(T, F, N) \
  const T (*F##Table_##T)[N] = &GenerateLut<N, T, F<A>::LutFun>::result::table
LUTS();
#undef MK_LUT


