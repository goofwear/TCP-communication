# TCP-communication

> 간단한 TCP 통신 프로그램입니다.

이 프로젝트는 TCP-IP를 이용하여 다른 컴퓨터와 통신할 수 있는 프로젝트입니다. 입문자라도 쉽게 이해하고 사용할 수 있도록 기초적인 네트워크 프로그래밍만 사용했습니다. 프로그래밍 학습에 유용하게 써주면 좋겠습니다.

## 프로젝트 소개

- 동기
  - 네트워크 프로그래밍을 공부하는 사람들에게 도움이 되고자 만들었습니다.
- 목적
  - 학습에 필요한 예제로 사용한다.
- 주요 기능
  - 클라이언트에서 메시지를 보내면 서버에서 그대로 돌려보내준다. (Echo 서버)

## Build Status

shield.io에서 뱃지를 선택하여 패키지, Release, 코드 커버리지, 다운로드 수, 버전 등을 명시한다.

## 설치 방법

1. Release 뱃지를 클릭하여 릴리즈 페이지로 이동한다.
2. 가장 최신 버전을 다운로드한다. (Latest Release)
3. 추가적인 설치과정은 없고 실행파일을 더블클릭만 하면된다.

## 사용 예시

실제로 프로젝트를 사용하는 모습을 GIF나 동영상으로 만들어 보여준다. 사용자가 결과물을 사용하는 방법을 순서대로 설명한다.

## 기능

- 공통
  - 네트워크 프로그램이 동작하는 상태를 자세히 출력한다.
- 서버
  - 클라이언트가 보낸 메시지를 그대로 되돌려 보내준다.
- 클라이언트
  - 서버와 송수신할 수 있다.

## API, 프레임워크

- WinAPI, WinSock2


## 개발 환경

- S/W 개발 환경
  - Visual Studio 2017 Community (15.9.5)
  - Windows 10 SDK (10.0.17763.0)
  - C Language (x64 Build)
- 개발 환경 설정
  - 리포지토리를 클론, 포크하거나 압축파일로 코드를 다운로드하세요.
  - Visual Studio 2017로 솔루션 파일(.sln)을 여세요.
  - 프로젝트 속성에서 Windows SDK 버전을 자신의 컴퓨터에 설치된 버전으로 맞추세요. (10.0.17763.0 권장)
  - 코딩 시작~!

## 변경 로그

- 1.0.0
  - 첫 릴리즈

## 개발자 정보와 크레딧

- 개발자
  - Lulin Pollux - [GitHub 프로필](https://github.com/Lulin-Pollux), [kistssy+dev@gmail.com](mailto:kistssy+dev@gmail.com)
- 크레딧
  - 참고 교재: [TCP/IP 윈도우 소켓 프로그래밍](http://book.interpark.com/product/BookDisplay.do?_method=detail&sc.shopNo=0000400000&sc.prdNo=212916162&sc.saNo=003002001&bid1=search&bid2=product&bid3=title&bid4=001) (김선우 저, 한빛아카데미)

## 기여 방법

1. [이 프로젝트](https://github.com/Lulin-Pollux/TCP-communication)를 포크합니다.
2. GitHub Desktop에서 새 브랜치를 만드세요.
3. 수정사항을 커밋하세요.
4. 새 브랜치에 푸시하세요.
5. 풀리퀘스트를 보내주세요.

## 라이센스

MIT License © Lulin Pollux

`LICENSE`에서 자세한 정보를 확인할 수 있습니다.