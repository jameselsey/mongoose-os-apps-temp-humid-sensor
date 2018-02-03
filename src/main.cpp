#include <mgos.h>
#include <Adafruit_BME280.h>

#define SENSOR_ADDR 0x76

static Adafruit_BME280 *s_bme = nullptr;

// Couldn't get bme280 example app to work due to arduino compat
// here's a modified version 
// Credit to nliviu from MOS Forums for help with this 
// https://forum.mongoose-os.com/discussion/1977/cant-get-bme280-example-app-to-work#latest

void readTimerCB(void *arg)
{    
    printf("Temperature: %.2f *C\n", s_bme->readTemperature());
    // Humidity will only work on BME280, not BMP280
    printf("Humidity: %.2f %%RH\n", s_bme->readHumidity());
    printf("Pressure: %.2f kPa\n\n", s_bme->readPressure() / 1000.0);
    (void) arg;
}

enum mgos_app_init_result mgos_app_init(void)
{
    s_bme = new Adafruit_BME280();

    // Initialize sensor
    if (!s_bme->begin(SENSOR_ADDR)) {
        printf("Can't find a sensor\n");
        return MGOS_APP_INIT_ERROR;
    }

    mgos_set_timer(2000, 1, readTimerCB, NULL);

    return MGOS_APP_INIT_SUCCESS;
}