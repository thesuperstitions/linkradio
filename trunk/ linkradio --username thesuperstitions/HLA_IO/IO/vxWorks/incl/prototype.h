#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#ifndef P
#if defined(__STDC__) || defined(__STDCPP__) || defined(USE_PROTOTYPES)
#define P(x)    x
#else /* __STDC__ __STDCPP__ USE_PROTOTYPES */
#define P(x)    ()
#endif /* USE_PROTOTYPES */
#endif /* P */

#endif  /*  PROTOTYPE_H */
