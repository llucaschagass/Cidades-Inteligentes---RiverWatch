# RiverWatch - Monitoramento de Altura de Rio

## Descrição:

O RiverWatch é um projeto que utiliza um sensor de distância ultrassônico conectado a um ESP32 para monitorar a altura de um rio em tempo real. Com base na altura medida, o sistema emite alertas para indicar possíveis riscos de transbordamento, ajudando na prevenção de enchentes e na segurança das comunidades ribeirinhas.

Este é um projeto do Cidades Inteligentes, programa de extensão do Centro Universitário UNA campus Betim.

## Componentes:

- ESP32
- Sensor de distância ultrassônico (HC-SR04)
- Módulo Wi-Fi (integrado ao ESP32)
- Conexão à internet (Wi-Fi)
- Arduino Uno (opcional, para integração com servidor web)
- Placa de circuito impresso (PCB)
- Bateria ou fonte de alimentação externa (para operação autônoma)

## Funcionamento:

O ESP32 é responsável por medir a distância entre o sensor ultrassônico e a superfície da água do rio. Com base nessa medida, o sistema avalia se há riscos de transbordamento:

- Distância <= 5 cm: O sistema emite o alerta "Atenção, o rio alagou! Evite passar perto dele."
- 5 cm < Distância <= 20 cm: O sistema emite o alerta "Alerta, possibilidade de alagamento no rio."
- Distância > 20 cm: O sistema emite a mensagem "Tudo normal no rio."

## Montagem:

1. Conecte o sensor de distância ultrassônico ao ESP32 conforme o esquema de pinagem especificado no código.
2. Configure o ESP32 para se conectar a uma rede Wi-Fi disponível.
3. Instale o ESP32 em uma localização adequada, com vista para o rio a ser monitorado.

## Integração com Servidor Web:

- O sistema pode ser integrado a um servidor web para exibir os dados de altura do rio em tempo real.
- Para isso, é necessário configurar o Arduino Uno (ou outro microcontrolador) para enviar os dados recebidos do ESP32 para o servidor web.

## Licença:

Este projeto é disponibilizado sob a licença [MIT](https://opensource.org/licenses/MIT).

