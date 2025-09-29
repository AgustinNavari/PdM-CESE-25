Práctica 5 – PdM

Se implementan las siguientes funciones:

bool_t uartInit();
void uartSendString(uint8_t * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);

A modo de prueba se implementa un "eco" en donde el microcontrolador devuelve un mensaje recibido de hasta 128 bytes.
Por ejemplo:

Si se envia: Hola Mundo <CR>

El microcontrolador responde: Hola Mundo <CR> 

Se utiliza la USART 2.

Para poder probar el codigo utilice la aplicacion "Docklight" en windows. Conectando la placa Nucleo con el USB y seleccionando el puerto COM correspondiente se pueden enviar los mensajes y "escuhar" el eco.

Al iniciar el programa se envia la configuracion de la UART. Para verlo en la terminal es necesario resetear el micro con el boton de reset.

![Ejemplo de funcionamiento](img/Docklight.jpeg)

