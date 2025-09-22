Práctica 4.2 – PdM

Implementación de una máquina de estados finita para anti-rebote por software y un módulo API_debounce reutilizable. Se integra con API_delay (retardos no bloqueantes) y un ejemplo que cambia la frecuencia de parpadeo del LED al presionar el botón de la placa.

Estructura del proyecto
```
/Core
  /Inc
    main.h
  /Src
    main.c
/drivers
  /API
    /inc
      API_delay.h
      API_debounce.h
    /src
      API_delay.c
      API_debounce.c
README.md
```
