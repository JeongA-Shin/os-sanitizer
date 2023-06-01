# Sanitizer-Enabled Kernel Compilation Project
이 프로젝트는 Ubuntu와 FreeBSD 운영 체제의 여러 버전들에 KASAN(Kernel Address Sanitizer)과 KCSAN(Kernel Concurrency Sanitizer)를 적용하여 컴파일하는 데 초점을 맞춘다.  
즉, 해당 프로젝트의 최종 목표는 메모리 버그와 동시성 문제를 감지하여 커널의 보안과 신뢰성을 향상시키는 것이다.

## sanitizer란?
Sanitizer는 소프트웨어의 다양한 유형의 버그와 보안 취약성을 탐지하고 방지하기 위해 설계된 강력한 툴이다.   
해당 프로젝트에서 우리는 Sanitizer 중 구글이 제공하는 두 가지를 사용하여 컴파일한다.  

### ✨KASAN (Kernel Address Sanitizer)
KASAN은 리눅스 커널을 위한 동적 런타임 메모리 오류 탐지기이다.   
범위 밖 메모리 액세스를 포함한 다양한 메모리 관련 버그를 탐지한다.  
### ✨KCSAN (Kernel Concurrency Sanitizer)
KCSAN은 리눅스 커널을 위한 동적 데이터 레이스 탐지기이다.  
커널 코드의 동시 실행에서 발생하는 잠재적인 데이터 경합 조건을 식별한다.  

