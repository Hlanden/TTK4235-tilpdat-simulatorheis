/**
 * @file
 * @brief Driver for the elevator hardware.
 *
 * Neatly wraps up Martin Korsgaard's spaghetti
 * from 2006 ;)
 *
 * Kolbjørn Austreng
 */
#ifndef HARDWARE_H
#define HARDWARE_H

#define SIMULATOR

#ifdef SIMULATOR

#include "driver/hardware_sim.h"

#endif //SIMULATOR
#ifndef SIMULATOR

#include "driver/hardware_sal.h"

#endif // !SIMULATOR

#endif // HARDWARE_H
