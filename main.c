#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"

int main(void)
{
    cy_rslt_t result;

    result = cybsp_init() ;
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    __enable_irq();
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
    cyhal_gpio_init (CYBSP_USER_LED , CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG , 1);

        for (;;)
        {
        	cyhal_gpio_write(CYBSP_USER_LED, 0);
        	cyhal_system_delay_ms(250);
        	printf("LED ENCENDIDO\r\n\n");
        	cyhal_gpio_write(CYBSP_USER_LED, 1);
        	cyhal_system_delay_ms(250);
        	printf("LED APAGADO\r\n\n");
        }
}

