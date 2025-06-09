## Overview
이 프로젝트는 동기화 3대 문제 중 하나인 "Dinning Philosopher"를 해결하는 소스코드들을을 포함하고 있습니다.

## Implemantation
- Request all resources: 코드가 시작하는 부분에서 한번에 모든 자원을 요청하고 모든 자원을 할당 받아서 시작합니다. 이 방법을 통해 점유대기를 없앱니다. 

- Resource Ordering: 자원을 항상 오름차순으로 할당합니다. 이 방법을 통해 순환 대기를 방지하여 데드락 발생을 막습니다.

## Evaluation
테스트를 통해 해당 방법들이 효과적으로 데드락을 방지하는 것을 확인했습니다.

## Conclusion
DeadLock은 발생확률이 낮지만 Handling 비용이 높으니 비용과 처리 측면에서 적절한 타협점을 찾아야 한다는 것을 느꼈습니다.