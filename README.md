# Operating Systems Synchronization Problems

## Overview

이 프로젝트는 **운영체제의 대표적인 동기화 문제 3가지**를 해결하는 데 초점을 맞추고 있습니다.

- **Dining Philosophers Problem**  
- **Producer-Consumer Problem (Infinite & Bounded Buffer)**
- **Readers-Writers Problem (Readers Preference & Writers Preference)**

각 문제는 동기화(synchronization)와 데드락(deadlock) 방지 기법을 적용하여 해결되었으며, 실제 테스트를 통해 구현의 안정성을 검증하였습니다.

---

## Implementation Details

### 1. Dining Philosophers Problem

- **Request All Resources**  
  코드 시작 시 모든 자원을 한 번에 요청 및 할당받아 실행함으로써 *점유 대기 조건*을 제거하여 데드락을 방지합니다.
  
- **Resource Ordering**  
  자원은 항상 **오름차순으로 요청**하도록 하여 *순환 대기*를 막고 데드락을 방지합니다.

---

### 2. Producer-Consumer Problem

- **Infinite Buffer**  
  - 소비자는 `sem_wait(&fill)`을 통해 buffer가 비어있을 때 대기합니다.  
  - 생산자는 생산을 마친 뒤 `sem_post(&fill)`로 소비자를 깨웁니다.

- **Bounded Buffer**  
  - 위와 동일하되, **생산자도 `sem_wait(&empty)`로 버퍼 크기가 초과되면 대기**합니다.  
  - 소비자가 소비를 마치면 `sem_post(&empty)`로 생산자를 깨웁니다.

---

### 3. Readers-Writers Problem

- **Readers Preference**  
  - 첫 번째 Reader가 Lock을 잡으면, 마지막 Reader가 Lock을 풀 때까지 Reader가 공유 자원을 독점합니다.

- **Writers Preference**  
  - Writer가 접근하면 이후 Reader의 접근을 차단하여 Writer에게 우선권을 부여합니다.

---

## Evaluation

- **Dining Philosophers**: 데드락 없이 자원 사용이 순차적으로 잘 이뤄짐을 확인했습니다.
- **Producer-Consumer**:  
  - Infinite 버퍼에서는 buffer가 음수로 내려가지 않음을 확인  
  - Bounded 버퍼에서는 buffer가 `0 ~ MAX` 범위 내에서 안정적으로 유지됨을 확인했습니다.
- **Readers-Writers**: 각 선호 정책에 따라 동작 순서가 적절히 적용됨을 테스트로 검증했습니다.

---


