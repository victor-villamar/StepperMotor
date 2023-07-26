# CHANGELOG

Todos los cambios notables en este proyecto seran documentados en este archivo.

El formato está basado en [Keep a Changelog](http://keepachangelog.com/), y este proyecto se adhiere a [Semantic Versioning](http://semver.org/).

## [0.0.0] - 2023/07/19

### Added
- Changelog
- StepperMotor.ino
- AccelSteper library
- Pines y variable de control del stepper motor.
- **initialCondition()**. Función para establecer las condiciones iniciales del stepper motor.
- **runstepper()**. Mueve el motor a una cierta velocidad cuando la flag allowed es true.

## [0.0.0] - 2023/07/21

### Added
- Variables globales de control
- **checkcommand()**. Función para detectar los comandos recibidos por el puerto Serial.
- **rotateRelative()**. Función para el movimiento relativo del motor desde la posicion actual.
- **rotateAbsolute()**. Función para el movimiento del motor a una posición absoluta.
-**Home()**. Función que mueve el stepper motor desde la posición actual hasta la posición establecida como home (0).
    
### Changed
- **runstepper()**. Se ha eliminado el movimiento por velocidad en esta función.
- **initialCondition()**. Se ha establecido la posición inicial como 0.

## [0.0.0] - 2023/07/26

### Added
- Carpetas Images y Datasheet
- Imagenes y documentos .pdf a dichas carpetas

### Changed
- README.md
