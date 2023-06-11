# Sanitizer-Enabled Kernel Compilation Project
이 프로젝트는 Ubuntu와 FreeBSD 운영 체제의 여러 버전들에 KASAN(Kernel Address Sanitizer)과 KCSAN(Kernel Concurrency Sanitizer)를 적용하여 컴파일하는 데 초점을 맞춘다.  
즉, 해당 프로젝트의 최종 목표는 메모리 버그와 동시성 문제를 감지하여 커널의 보안과 신뢰성을 향상시키는 것이다.

## sanitizer란?
Sanitizer는 소프트웨어의 다양한 유형의 버그와 보안 취약성을 탐지하고 방지하기 위해 설계된 강력한 툴이다.   
해당 프로젝트에서 우리는 Sanitizer 중 구글이 제공하는 두 가지를 사용하여 컴파일한다.  

### ✨KASAN (Kernel Address Sanitizer)
* KASAN은 리눅스 커널을 위한 동적 런타임 메모리 오류 탐지기이다.   
* 범위 밖 메모리 액세스를 포함한 다양한 메모리 관련 버그를 탐지한다.  
### ✨KCSAN (Kernel Concurrency Sanitizer)
* KCSAN은 리눅스 커널을 위한 동적 데이터 레이스 탐지기이다.  
* 커널 코드의 동시 실행에서 발생하는 잠재적인 데이터 경합 조건을 식별한다.  

프로젝트 중 KASAN 및 KCSAN에 대한 내용은 Google에서 제공하는 <a href="https://github.com/google/sanitizers">공식 문서</a> 를 참조하였다.

## Config 파일과 커널 컴파일
* Config 파일은 커널의 구성 옵션을 설정하는 파일
* Config 파일을 통해 컴파일하고자 하는 커널의 기능과 옵션을 지정함
* 우분투의 경우 make menuconfig 커맨드를 통해 config 파일을 새롭게 설정한다
* freeBSD의 경우 make buildkernel KERNCONF="해당 CONFIG 파일명"을 통해 컴파일한다.

## 우분투 버전별 KASAN 적용 결과
* 우분투 버전별로 KASAN을 적용하여 컴파일 한 후 bzImage 크기를 비교한 결과이다.    
   
|우분투 버전|3.x|4.x|5.x|
|:------:|:---:|:---:|:---:|
|적용 전|8M|9.6M|11M|
|적용 후|옵션 없음|15M|에러가 감지되어 중단됨|

## freeBSD 컴파일 시 KASAN 적용 결과
* KASAN 옵션은 freeBSD에서 커널 버전 13.1부터 적용되기 시작하였다.
* 메인 라인을 위주로 비교하는 것을 목표로 하였는데, 현재 (2023.6월 기준) freeBSD는 13.2가 최신인 상태이다
* 따라서 아래의 비교 결과는 커널 버전 13.1에서만 KASAN을 적용하여 컴파일 하기 전과 후의 커널 이미지 크기를 비교한 것이다.

## 우분투 버전별 KCSAN 적용 결과
* 우분투 버전별로 KCSAN을 적용하여 컴파일 한 후 bzImage 크기를 비교한 결과이다.

## freeBSD 컴파일 시 KCSAN 적용 결과
* KCSAN 옵션은 freeBSD에서 커널 버전 13.1부터 적용되기 시작하였다.
* 메인 라인을 위주로 비교하는 것을 목표로 하였는데, 현재 (2023.6월 기준) freeBSD는 13.2가 최신인 상태이다
* 따라서 아래의 비교 결과는 커널 버전 13.1에서만 KCSAN을 적용하여 컴파일 하기 전과 후의 커널 이미지 크기를 비교한 것이다.

## 결론
Sanitizer를 적용하면 메모리 관련 버그와 데이터 레이스를 포함한 커널의 여러 버그들을 탐지하고 진단할 수 있다. 즉, 테스트 단계에서 Sanitizer를 통해 커널의 메모리 안정성과 동시성 오류를 효과적으로 검출하고 차단하여 이러한 버그로 인해 발생하는 시스템 충돌 및 보안 취약성의 위험을 줄인다.

## 추후 과제
1. 한 종류가 아닌, 다양한 종류의 Sanitizer가 적용된 커널에 대해 버그 사항을 찾아보고 취약점을 찾아봐야 한다.
2. 커널에 대하여 직접 버그 사항을 만들고 테스트하여 분석함으로서 sanitizer의 효용성에 대한 연구를 진행한다.
