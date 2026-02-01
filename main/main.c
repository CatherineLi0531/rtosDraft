#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED1 GPIO_NUM_2
#define LED2 GPIO_NUM_4

// ----- Task 1: Blink LED1 every 500 ms -----
void blink_task_1(void *pvParameters)
{
    /*gpio_reset_pin(LED1);
    gpio_set_direction(LED1, GPIO_MODE_OUTPUT);*/

    while (1)
    {
        /*gpio_set_level(LED1, 1);                     // Turn LED ON
        vTaskDelay(pdMS_TO_TICKS(500));              // Wait 500 ms
        gpio_set_level(LED1, 0);                     // Turn LED OFF
        vTaskDelay(pdMS_TO_TICKS(500)); */             // Wait 500 ms

        printf("\n");
    }
}

// ----- Task 2: Blink LED2 every 200 ms -----
void print(void *pvParameters)
{
    /*gpio_reset_pin(LED2);
    gpio_set_direction(LED2, GPIO_MODE_OUTPUT);*/

    while (1)
    {
        /*gpio_set_level(LED2, 1);                     // Turn LED ON
        vTaskDelay(pdMS_TO_TICKS(200));              // Wait 200 ms
        gpio_set_level(LED2, 0);                     // Turn LED OFF
        vTaskDelay(pdMS_TO_TICKS(200));              // Wait 200 ms*/

        printf("*");
    }
}

// ----- app_main: Entry point in ESP-IDF -----
void app_main(void)
{
    printf("Starting FreeRTOS tasks...\n");

    // Create both tasks
    xTaskCreate(blink_task_1, "Blink1", 2048, NULL, 1, NULL);
    //xTaskCreate(blink_task_2, "Blink2", 2048, NULL, 1, NULL);
}