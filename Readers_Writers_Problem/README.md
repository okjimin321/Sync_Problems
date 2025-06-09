## Overview
이 프로젝트는 운영체제 3대 문제 중 하나인 
"Readers Writers Problem"을 
해결하는 2가지 소스코드를 포함하고 있습니다.

## Implementation
- Readers_Preference: 첫 reader가 Lock을 잡으면 마지막 reader가 Lock을 풀 때까지 reader가 공유자원을 독점합니다.
- Writer_Preference: writer가 들어오면 reader가 더 들어오는 것을 막아 writer에게 우선권을 줍니다.

## Evaluation
 간단한 테스트를 통해 각 선호가 적절이 작동하는 것을 확인했습니다.

## Conclusion
조건 동기화로 특정 process에게 선호를 주는 실습을 통해 시스템을 효율적으로 사용하기 위해 동기화가 중요하다는 것을 경험했습니다. 