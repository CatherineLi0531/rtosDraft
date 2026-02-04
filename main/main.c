#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN 2

void light_on(void *pvParameters)
{

    while (1)
    {
        gpio_set_level(LED_PIN, 1);                    
        vTaskDelay(2000 / portTICK_PERIOD_MS);                           

        printf("\n");
    }
}

void light_off(void *pvParameters)
{

    while (1)
    {
        gpio_set_level(LED_PIN, 0);                    
        vTaskDelay(1000 / portTICK_PERIOD_MS);                           

        printf("\n");
    }
}

// ----- app_main: Entry point in ESP-IDF -----
void app_main(void)
{
    printf("Starting FreeRTOS tasks...\n");

    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    xTaskCreate(light_on, "on", 2048, NULL, 1, NULL);
    xTaskCreate(light_off, "off", 2048, NULL, 1, NULL);
    
}

