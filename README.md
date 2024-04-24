# Sistema de Gestión Hotelera

Este es un sistema de gestión hotelera desarrollado en C++ como parte de un proceso educativo y  de aprendizaje. Permite ingresar datos de clientes, habitaciones, realizar facturación y realizar búsquedas.

## Funcionalidades

El sistema proporciona las siguientes funcionalidades:

- **Ingresar Datos de Cliente**: Permite registrar los datos de un nuevo cliente, incluyendo cédula, nombre, apellido, procedencia y teléfono.
  
- **Ingresar Consumo del Cliente**: Permite ingresar el consumo adicional realizado por un cliente durante su estancia en el hotel.

- **Imprimir Facturas**: Permite imprimir las facturas generadas para cada cliente, mostrando detalles como el número de factura, nombre del cliente, habitación ocupada, tipo de habitación, valor de la habitación por día, número de días de estancia, consumo adicional y valor total.

- **Búsqueda por Habitación**: Permite buscar información de un cliente y su factura asociada a una habitación específica.

- **Búsqueda por Clientes**: Permite buscar información de un cliente por su apellido.

- **Mostrar Lista de Clientes**: Muestra la lista de todos los clientes registrados en el sistema.

## Estructura del Código

El código está dividido en tres listas enlazadas:

- **Lista A (Clientes)**: Almacena la información de los clientes, incluyendo su cédula, nombre, apellido, procedencia y teléfono.

- **Lista B (Habitaciones)**: Almacena la información de las habitaciones, incluyendo el número de habitación, número de piso, tipo de habitación y valor por día.

- **Lista C (Facturación)**: Almacena la información de la facturación de cada cliente, incluyendo el número de factura, número de días de estancia, valor total y consumo adicional.

## Requisitos del Sistema

Para compilar y ejecutar este código, se requiere un compilador de C++ que admita las bibliotecas estándar utilizadas y el sistema operativo debe ser compatible con las funciones de la biblioteca `conio.h`.

## Uso del Sistema

Al ejecutar el programa, se presenta un menú con las opciones disponibles. Selecciona la opción deseada utilizando las letras indicadas y sigue las instrucciones proporcionadas en pantalla.

