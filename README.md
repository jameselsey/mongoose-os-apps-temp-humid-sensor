mongoose-os-apps-temp-humid-sensor
===============

Simple app to read temperature (and humidity when I get BME280s) and report to AWS IoT.

Set the I2C pins in mos.yml and ensure deviceId is correct in main.cpp (should probably externalise that too)
