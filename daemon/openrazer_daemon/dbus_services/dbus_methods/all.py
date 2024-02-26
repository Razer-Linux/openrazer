# SPDX-License-Identifier: GPL-2.0-or-later

"""
DBus methods available for all devices.
"""
import os
from openrazer_daemon.dbus_services import endpoint

# Keyboard layout IDs
# There are more than listed here, but others are not known yet.
layoutids = {"01": "en_US",
             "02": "el_GR",
             "03": "de_DE",
             "04": "fr_FR",
             "05": "ru_RU",
             "06": "en_GB",
             "07": "Nordic",
             "0A": "tr_TR",
             "0C": "ja_JP",
             "0F": "de_CH",
             "10": "es_ES",
             "11": "it_IT",
             "12": "pt_PT",
             "81": "en_US_mac"}


@endpoint('razer.device.misc', 'getDriverVersion', out_sig='s')
def version(self):
    """
    Get the devices driver version

    :return: Get driver version string like 1.0.7
    :rtype: str
    """
    self.logger.debug("DBus call version")

    # Caching
    if 'driver_version' in self.method_args:
        return self.method_args['driver_version']

    driver_path = self.get_driver_path('version')

    driver_version = '0.0.0'

    if os.path.exists(driver_path):
        # Check it exists, as people might not have reloaded driver
        with open(driver_path, 'r') as driver_file:
            driver_version = driver_file.read().strip()

    self.method_args['driver_version'] = driver_version
    return driver_version


@endpoint('razer.device.misc', 'getFirmware', out_sig='s')
def get_firmware(self):
    """
    Get the devices firmware version

    :return: Get firmware string like v1.1
    :rtype: str
    """
    self.logger.debug("DBus call get_firmware")

    driver_path = self.get_driver_path('firmware_version')

    with open(driver_path, 'r') as driver_file:
        return driver_file.read().strip()


@endpoint('razer.device.misc', 'getDeviceName', out_sig='s')
def get_device_name(self):
    """
    Get the device's descriptive string

    :return: Device string like 'BlackWidow Ultimate 2013'
    :rtype: str
    """
    self.logger.debug("DBus call get_device_name")

    driver_path = self.get_driver_path('device_type')

    with open(driver_path, 'r') as driver_file:
        return driver_file.read().strip()


@endpoint('razer.device.misc', 'getKeyboardLayout', out_sig='s')
def get_keyboard_layout(self):
    """
    Get the device's keyboard layout

    :return: String like 'en_US', 'de_DE', 'en_GB' or 'unknown'
    :rtype: str
    """
    self.logger.debug("DBus call get_keyboard_layout")

    driver_path = self.get_driver_path('kbd_layout')

    with open(driver_path, 'r') as driver_file:
        try:
            return layoutids[driver_file.read().strip()]
        except KeyError:
            return "unknown"


# Functions to define a hardware class
@endpoint('razer.device.misc', 'getDeviceType', out_sig='s')
def get_device_type_keyboard(self):
    """
    Get the device's type

    :return: 'keyboard'
    :rtype: str
    """
    self.logger.debug("DBus call get_device_type")
    return 'keyboard'


@endpoint('razer.device.misc', 'getDeviceType', out_sig='s')
def get_device_type_mouse(self):
    """
    Get the device's type

    :return:'mouse'
    :rtype: str
    """
    self.logger.debug("DBus call get_device_type")
    return 'mouse'


@endpoint('razer.device.misc', 'getDeviceType', out_sig='s')
def get_device_type_mousemat(self):
    """
    Get the device's type

    :return:'mousemat'
    :rtype: str
    """
    self.logger.debug("DBus call get_device_type")
    return 'mousemat'


@endpoint('razer.device.misc', 'getDeviceType', out_sig='s')
def get_device_type_core(self):
    """
    Get the device's type

    :return:'core'
    :rtype: str
    """
    self.logger.debug("DBus call get_device_type")
    return 'core'


@endpoint('razer.device.misc', 'getDeviceType', out_sig='s')
def get_device_type_keypad(self):
    """
    Get the device's type

    :return:'keypad'
    :rtype: str
    """
    self.logger.debug("DBus call get_device_type")
    return 'keypad'


@endpoint('razer.device.misc', 'getDeviceType', out_sig='s')
def get_device_type_headset(self):
    """
    Get the device's type

    :return:'headset'
    :rtype: str
    """
    self.logger.debug("DBus call get_device_type")
    return 'headset'


@endpoint('razer.device.misc', 'getDeviceType', out_sig='s')
def get_device_type_accessory(self):
    """
    Get the device's type

    :return:'accessory'
    :rtype: str
    """
    self.logger.debug("DBus call get_device_type")
    return 'accessory'


@endpoint('razer.device.misc', 'hasMatrix', out_sig='b')
def has_matrix(self):
    """
    If the device has an LED matrix
    """
    self.logger.debug("DBus call has_matrix")

    return self.HAS_MATRIX


@endpoint('razer.device.misc', 'getMatrixDimensions', out_sig='ai')
def get_matrix_dims(self):
    """
    If the device has an LED matrix
    """
    self.logger.debug("DBus call has_matrix")

    if not self.HAS_MATRIX:
        raise RuntimeError("Device does not have matrix capabilities")
    if self.HAS_MATRIX and self.MATRIX_DIMS is None:
        raise RuntimeError("HAS_MATRIX is set but no MATRIX_DIMS set!")

    return list(self.MATRIX_DIMS)


@endpoint('razer.device.misc', 'setFanSpeed', in_sig='i')
def set_fan_speed(self, fan_speed):
    """
     set fan speed
     :param fan_speed: speed in RPMs if 0 - auto mode
    """

    self.logger.debug("DBus call set_fan_speed")

    if fan_speed > 5300:
        fan_speed = 5300
    elif fan_speed != 0 and fan_speed < 3500:
        fan_speed = 3500

    driver_path = self.get_driver_path('fan_speed')

    with open(driver_path, 'w') as driver_file:
        driver_file.write(str(fan_speed))


@endpoint('razer.device.misc', 'getFanSpeed', out_sig='i')
def get_fan_speed(self):
    """
     get fan speed
     :return fan_speed: speed in RPMs
    """

    self.logger.debug("DBus call get_fan_speed")

    driver_path = self.get_driver_path('fan_speed')

    with open(driver_path, 'r') as driver_file:
        return int(driver_file.read().strip())


@endpoint('razer.device.misc', 'setPowerMode', in_sig='s')
def set_power_mode(self, power_mode):
    """
     set power mode as string
    """

    self.logger.debug("DBus call set_power_mode")

    driver_path = self.get_driver_path('power_mode')

    with open(driver_path, 'w') as driver_file:
        driver_file.write(str(power_mode))


@endpoint('razer.device.misc', 'getPowerMode', out_sig='s')
def get_power_mode(self):
    """
     get power mode
    """

    self.logger.debug("DBus call get_power_mode")

    driver_path = self.get_driver_path('power_mode')

    with open(driver_path, 'r') as driver_file:
        return driver_file.read().strip()


@endpoint('razer.device.misc', 'setCPUBoost', in_sig='s')
def set_cpu_boost(self, boost):
    """
     set CPU boost
    """

    self.logger.debug("DBus call set_cpu_boost")

    driver_path = self.get_driver_path('cpu_boost')

    with open(driver_path, 'w') as driver_file:
        driver_file.write(boost)


@endpoint('razer.device.misc', 'getCPUBoost', out_sig='s')
def get_cpu_boost(self):
    """
     get CPU boost
    """

    self.logger.debug("DBus call get_cpu_boost")

    driver_path = self.get_driver_path('cpu_boost')

    with open(driver_path, 'r') as driver_file:
        return driver_file.read().strip()


@endpoint('razer.device.misc', 'setGPUBoost', in_sig='s')
def set_gpu_boost(self, boost):
    """
     set GPU boost
    """

    self.logger.debug("DBus call set_gpu_boost")

    driver_path = self.get_driver_path('gpu_boost')

    with open(driver_path, 'w') as driver_file:
        driver_file.write(boost)


@endpoint('razer.device.misc', 'getGPUBoost', out_sig='s')
def get_gpu_boost(self):
    """
     get GPU boost
    """

    self.logger.debug("DBus call get_gpu_boost")

    driver_path = self.get_driver_path('cpu_boost')

    with open(driver_path, 'r') as driver_file:
        return driver_file.read().strip()


@endpoint('razer.device.misc', 'setBHO', in_sig='d')
def set_bho(self, threshold):
    """
     set battery health optimizer
    """

    self.logger.debug("DBus call set_bho")

    driver_path = self.get_driver_path('bho')

    with open(driver_path, 'w') as driver_file:
        driver_file.write(str(threshold))


@endpoint('razer.device.misc', 'getBHO', out_sig='d')
def get_bho(self):
    """
     get battery health optimizer
    """

    self.logger.debug("DBus call get_bho")

    driver_path = self.get_driver_path('bho')
    with open(driver_path, 'w') as driver_file:
        return int(driver_file.read().strip())
