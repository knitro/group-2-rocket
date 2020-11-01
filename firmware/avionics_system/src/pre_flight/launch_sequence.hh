#ifndef _LAUNCH_SEQUENCE_
#define _LAUNCH_SEQUENCE_

/*Includes*/
#include <stdint.h>

/*Header Content*/
namespace launch_sequence_ns {

  uint8_t perform_launch_tests();

  uint8_t init_start_time();

  uint8_t countdown_tick();

}

#endif /* _LAUNCH_SEQUENCE_ */