## Overview
이 프로젝트는 운영체제 3대 문제 중 하나인 "Producer Consumer Problem"의 Infinite Buffer와 Bounded Buffer를 해결하는 소스코드를 포함하고 있습니다.

## Implemantation
- Infinite Buffer: 소비자는 sem_wait(&fill)를 통해 buffer가 0이면 wait하며, 생산자가 생산을 마치면 sem_post(&fill)을 통해 깨워줍니다.

- Bounded Buffer: 윗 상황에 생산자에 대한 제약도 추가합니다. 생산자는 sem_wait(&empty)를 통해 버퍼의 크기가 MAX이면 wait하며 소비자가 소비를 하면 sem_post(&empty)로 깨워줍니다.

## Evaluation
테스트를 통하여 Infinite문제에선 buffer가 0미만으로 내려가지 않는 것을 확인했고 Bounded 문제에선 buffer가 0 ~ 30인 것을 확인했습니다.

## Conclusion
성능 향상을 위해 자원을 공유하는 일이 많기 때문에 생산자 소비자 문제를 해결할 줄 아는 것이 중요하겠다는 걸 느꼈습니다.