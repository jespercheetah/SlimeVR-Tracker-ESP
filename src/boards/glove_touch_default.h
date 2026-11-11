/*
	SlimeVR Code is placed under the MIT license
	Copyright (c) 2026 Jesper Cheetah & SlimeVR contributors

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/

#pragma once

#ifndef GLOVE_SIDE
#define GLOVE_SIDE GLOVE_LEFT
#endif

#ifndef TOUCH_PIN_LITTLE
#define TOUCH_PIN_LITTLE T9
#endif
#ifndef TOUCH_PIN_RING
#define TOUCH_PIN_RING T8
#endif
#ifndef TOUCH_PIN_MIDDLE
#define TOUCH_PIN_MIDDLE T7
#endif
#ifndef TOUCH_PIN_INDEX
#define TOUCH_PIN_INDEX T6
#endif
#ifndef TOUCH_PIN_THUMB
#define TOUCH_PIN_THUMB T0
#endif

#define MAX_SENSORS_COUNT 5

#define SENSOR_DESC_LIST                                        \
	SCALAR_SENSOR_DESC_ENTRY(TouchFlexSensor, TOUCH_PIN_LITTLE) \
	SCALAR_SENSOR_DESC_ENTRY(TouchFlexSensor, TOUCH_PIN_RING)   \
	SCALAR_SENSOR_DESC_ENTRY(TouchFlexSensor, TOUCH_PIN_MIDDLE) \
	SCALAR_SENSOR_DESC_ENTRY(TouchFlexSensor, TOUCH_PIN_INDEX)  \
	SCALAR_SENSOR_DESC_ENTRY(TouchFlexSensor, TOUCH_PIN_THUMB)

#if GLOVE_SIDE == GLOVE_LEFT

#define TRACKER_TYPE TrackerType::TRACKER_TYPE_SVR_GLOVE_LEFT
#define SENSOR_INFO_LIST                                                \
	SENSOR_INFO_ENTRY(0, SensorPosition::POSITION_LEFT_LITTLE_PROXIMAL) \
	SENSOR_INFO_ENTRY(1, SensorPosition::POSITION_LEFT_RING_PROXIMAL)   \
	SENSOR_INFO_ENTRY(2, SensorPosition::POSITION_LEFT_MIDDLE_PROXIMAL) \
	SENSOR_INFO_ENTRY(3, SensorPosition::POSITION_LEFT_INDEX_PROXIMAL)  \
	SENSOR_INFO_ENTRY(4, SensorPosition::POSITION_LEFT_THUMB_PROXIMAL)

#elif GLOVE_SIDE == GLOVE_RIGHT

#define TRACKER_TYPE TrackerType::TRACKER_TYPE_SVR_GLOVE_RIGHT
#define SENSOR_INFO_LIST                                                 \
	SENSOR_INFO_ENTRY(0, SensorPosition::POSITION_RIGHT_LITTLE_PROXIMAL) \
	SENSOR_INFO_ENTRY(1, SensorPosition::POSITION_RIGHT_RING_PROXIMAL)   \
	SENSOR_INFO_ENTRY(2, SensorPosition::POSITION_RIGHT_MIDDLE_PROXIMAL) \
	SENSOR_INFO_ENTRY(3, SensorPosition::POSITION_RIGHT_INDEX_PROXIMAL)  \
	SENSOR_INFO_ENTRY(4, SensorPosition::POSITION_RIGHT_THUMB_PROXIMAL)

#else
#error "Invalid glove side"
#endif  // GLOVE_SIDE
