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

#include "TouchFlexSensor.h"

#include "GlobalVars.h"

#ifdef SOC_TOUCH_SENSOR_SUPPORTED

namespace SlimeVR::Sensors {
void TouchFlexSensor::motionSetup() {
	lastValue = touchRead(pin);
	working = true;
	hasNewData = true;
	m_tpsCounter.reset();
	m_dataCounter.reset();
}

void TouchFlexSensor::motionLoop() {
	uint32_t now = millis();
	if (now - lastMeasureTime >= measureIntervalMs) {
		float currentValue = touchRead(pin);
		lastValue += smoothingFactor * (currentValue - lastValue);
		hasNewData = true;
		hadData = true;
		lastMeasureTime = now;
		m_tpsCounter.update();
	}
}

void TouchFlexSensor::sendData() {
	if (hasNewDataToSend()) {
		networkConnection.sendFlexData(sensorId, lastValue);
		m_dataCounter.update();
		hasNewData = false;
		lastSendTime = millis();
	}
}

bool TouchFlexSensor::hasNewDataToSend() {
	uint32_t now = millis();
	return hasNewData && (now - lastSendTime >= sendIntervalMs);
}

}  // namespace SlimeVR::Sensors
#endif  // SOC_TOUCH_SENSOR_SUPPORTED
