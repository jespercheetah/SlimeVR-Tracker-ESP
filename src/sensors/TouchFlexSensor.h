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

#include "sensor.h"

#ifdef ESP32
#include <soc/soc_caps.h>
#endif  // ESP32

#ifdef SOC_TOUCH_SENSOR_SUPPORTED

#ifndef DEFAULT_TOUCH_SMOOTHING_FACTOR
#define DEFAULT_TOUCH_SMOOTHING_FACTOR 0.3f
#endif

namespace SlimeVR::Sensors {
class TouchFlexSensor : public Sensor {
public:
	TouchFlexSensor(
		uint8_t id,
		uint8_t pin,
		float smoothingFactor = DEFAULT_TOUCH_SMOOTHING_FACTOR
	)
		: Sensor(
			  "TouchFlexSensor",
			  SensorTypeID::ADC_RESISTANCE,
			  id,
			  EmptyRegisterInterface::instance,
			  0.0f,
			  &EmptySensorInterface::instance
		  )
		, pin(pin)
		, smoothingFactor(smoothingFactor) {}

	void motionSetup() override final;
	void motionLoop() override final;
	void sendData() override final;
	bool hasNewDataToSend() override final;

	SensorStatus getSensorState() override final { return SensorStatus::SENSOR_OK; }

	SensorDataType getDataType() override final {
		return SensorDataType::SENSOR_DATATYPE_FLEX_RESISTANCE;
	}

private:
	uint8_t pin;
	float smoothingFactor;

	static constexpr uint32_t measureIntervalMs = 10;
	// Initialize to ensure immediate measurement on first loop
	uint32_t lastMeasureTime = -measureIntervalMs;
	float lastValue = 0.0f;

	static constexpr uint32_t sendIntervalMs = 50;
	// Initialize to ensure immediate send on first loop
	uint32_t lastSendTime = -sendIntervalMs;

	bool hasNewData = false;
};
}  // namespace SlimeVR::Sensors

#endif  // SOC_TOUCH_SENSOR_SUPPORTED
