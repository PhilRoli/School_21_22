# State Diagramm

```mermaid
graph TD;
    ERROR-->IDLE;
    IDLE-->STATE2;
    IDLE-->STATE1;
    STATE1-->ERROR;
    STATE2-->ERROR;
    STATE2-->IDLE;
    STATE1-->IDLE;
```
