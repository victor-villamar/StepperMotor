# StepperMotor with DM860A driver

<!-- TABLA DE CONTENIDOS -->
<details>
    <summary><h2>Tabla de contenidos</h2></summary>
    <ol>
        <li>
            <a href="#sobre-el-proyecto">Sobre el proyecto</a>
                <ul>
                    <li><a href="#contenido">Contenido</a></li>
                </ul>
                <ul>
                    <li><a href="#comandos">Comandos</a></li>
                </ul>
                 <ul>
                    <li><a href="#hardware">Hardware</a></li>
                </ul>
        </li>
        <li>
            <a href="#conexiones">Conexiones</a>
        </li>
        <li>
            <a href="#versiones">Versiones</a>
        </li> 
        <li>
            <a href="#instalación">Instalación</a>
        </li>
        <li>
            <a href="#como-se-usa">Cómo se usa</a>
        </li>
    </ol>
</details>

<!-- SOBRE EL PROYECTO -->
## Sobre el proyecto

Este proyecto se centra en el control del movimiento de un stepper motor y el driver DM860A.

El control del stepper motor se realiza mediante una serie de comandos introducidos mediante consola o enviados mediante el puerto Serial en el caso de conectar un ordenador.

Para el movimiento del stepper se emplean funciones de la libreria [Accelstepper.h](http://www.airspayce.com/mikem/arduino/AccelStepper/) de arduino.

<!-- CONTENIDO -->
### Contenido

Este proyecto esta estructurado en una serie de directorios que se describirán a continuación:

* **Datasheet**  $\rightarrow$ Directorio que continene los datasheet de los componentes empleados (stepper motor y driver).
* **Images**  $\rightarrow$ Directorio que contiene las imagenes utilizadas en el README.
* **StepperMotor**  $\rightarrow$ Directorio que contiene el programa y las librerias empleadas. 

<!-- COMANDOS -->
### Comandos
 
 Para que el programa realice sus diferentes funciones es necesario mandar una serie de comandos por el puerto **Serial**.


|Comando|Función|
|:-----:|:-----:|
|p|Rota el stepper motor hacia una posición relativa positiva|
|n|Rota el stepper motor hacia una posición relativa negativa|
|R|Rota el stepper motor hacia una posición absoluta positiva|
|r|Rota el stepper motor hacia una posición absoluta negativa|
|s|Detiene el movimiento del stepper motor|
|a|Establece una aceleración al stepper motor|
|l|Informa la posición actual en pasos|
|h|Regresa el stepper motor a su posicion de incio (0)|
|u|Actualiza la posicion de incio (0)|

<!-- HARDWARE -->
### Hardware

El hardware necesario para poder utilizar este proyecto son los siguientes:

* [Arduino Mega 2056](https://docs.arduino.cc/hardware/mega-2560)
* [Stepper motor](https://www.omc-stepperonline.com/download/17HS15-1504S-X1.pdf)
* Driver [DM860A](https://cnc-tehnologi.ru/files/DM860A.pdf)
* Fuente de alimentacion regulable entre 12-24V.

Además es necesario configurar los switches del driver para que funcione en el modo que requerimos. En este proyecto se configura de la siguiente manera:

![Microsteps](https://raw.githubusercontent.com/victor-villamar/StepperMotor/master/Images/Microsteps_resolution.jpg)

![Dinamyc_current](https://raw.githubusercontent.com/victor-villamar/StepperMotor/master/Images/Dinamyc_current_setting.jpg)

<!-- CONEXIONES -->
## Conexiones

![schematic](https://raw.githubusercontent.com/victor-villamar/StepperMotor/master/Images/schematic.jpg)

<!-- VERSIONES -->
## Versiones

* [1.0.0] $\rightarrow$ Versión operativa que permite el control del stepper motor mediante comandos introducidos por el puerto **Serial**.


<!-- INSTALACION -->
## Instalación

1. Clona este repositorio.

    ```terminal
     git clone https://github.com/victor-villamar/StepperMotor.git
   ```
2. Ejecuta el programa en tu ordenador.

    ```terminal
   Tu localización de la carpeta GitHub\StepperMotor\StepperMotor\StepperMotor.ino
    ```
3. Instalar las libreria [Accelstepper.h](http://www.airspayce.com/mikem/arduino/AccelStepper/)

4. Realizar las conexiones ilustradas y la configuracion del driver.
5. Carga el programa en la placa.

<!-- COMO SE USA -->
## Cómo se usa

La interacción del usuario con el programa una vez cargado en la placa es la siguiente:

* Mediante la consola Serial introducimos los comandos.
* Se le puede establecer un home al principio o posteriomente.
* Se le puede establecer una aceleración nueva o utilizar la que está establecida por defecto.
* Mover el motor de manera relativa o absoluta.
* Mostrar la posición en la que se encuentra (en pasos).
* Actualizar el home o realizar un regreso a home.




