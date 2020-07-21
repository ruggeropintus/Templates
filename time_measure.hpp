#if 0
{
#include <chrono>
  std::chrono::system_clock sysClock;
  std::chrono::system_clock::time_point ckBegin, ckEnd;
  std::chrono::system_clock::time_point globalCkBegin, globalCkEnd;

  globalCkBegin = sysClock.now();
  ckBegin = sysClock.now();
  ckEnd = sysClock.now();
  std::cerr << "STEP 1 - initialize data - elapsed time - "
            << std::chrono::duration_cast<std::chrono::seconds>(ckEnd - ckBegin)
                   .count()
            << " secs" << std::endl;
  globalCkEnd = sysClock.now();
  std::cerr << "TOTAL elapsed time - "
            << std::chrono::duration_cast<std::chrono::seconds>(globalCkEnd -
                                                                globalCkBegin)
                   .count()
            << " secs" << std::endl;
}
#endif