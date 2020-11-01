#ifndef _TRANSMIT_DATA_
#define _TRANSMIT_DATA_

// /*Includes*/
#include <stdint.h>
#include <RadioLib.h>

/*Header Content*/
namespace transmit_data_ns {

    uint8_t setup();

    uint8_t transmit(String toSend);

}

#endif /* _TRANSMIT_DATA_ */