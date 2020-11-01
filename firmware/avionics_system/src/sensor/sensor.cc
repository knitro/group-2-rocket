#include <cstring>
#include "sensor.hh"

template <typename T>
void sensor_ns::circular_buffer<T>::addValue(T newVal) {
    for (int i = sizeof(data) / sizeof(T); i >= 0; i--) {
        if (i - 1 >= 0) {
            data[i] = data[i-1];
        }
    }
    data[0] = newVal;
}

template <typename T>
T* sensor_ns::circular_buffer<T>::getBuffer() {
    return data;
}

template <typename T>
int sensor_ns::circular_buffer<T>::getCapacity() {
    return SENSOR_BUFFER_LEN;
}

