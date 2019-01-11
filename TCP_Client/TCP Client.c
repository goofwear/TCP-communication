﻿#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "ws2_32")
#include <WinSock2.h>
#include <stdio.h>
#define SERVERIP "127.12.34.56"


//오류 메시지를 출력하고 프로그램을 종료하는 함수
void err_quit(char *msg)
{
	//에러 코드로부터 오류 메시지를 만든다.
	LPSTR msgBuf;
	FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
		WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&msgBuf, 0, NULL);

	//오류 메시지를 알림창으로 띄운다.
	MessageBox(NULL, msgBuf, msg, MB_ICONERROR);

	//버퍼 메모리 반환
	LocalFree(msgBuf);

	//프로그램 종료
	exit(1);
}

//오류 메시지를 출력하는 함수
void err_display(char *msg)
{
	//에러 코드로부터 오류 메시지를 만든다.
	LPSTR msgBuf;
	FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
		WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&msgBuf, 0, NULL);

	//오류 메시지를 콘솔창에 출력한다.
	printf("[%s] %s\n", msg, msgBuf);

	//버퍼 메모리 반환
	LocalFree(msgBuf);
}

int main()
{
	int retval;

	//윈속을 초기화한다.
	WSADATA wsa;
	retval = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (retval != 0)
	{
		printf("WSAStartup() 오류: %d", retval);
		return 1;
	}

	//통신용 소켓을 생성한다.
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
		err_quit("socket()");

	//서버에 연결한다.
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(50000);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
		err_quit("connect()");
	
	//서버에 연결했음을 알린다.
	printf("\n[TCP 클라이언트] 서버 연결: %s:%d \n\n",
		inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port));

	//통신에 사용할 변수를 선언한다.
	char buffer[512] = { '\0' };

	while (1)
	{
		//송신할 데이터를 입력한다.
		printf("Send: ");
		gets_s(buffer, sizeof(buffer));
		if (strcmp(buffer, "/exit") == 0)
			break;

		//데이터를 송신한다.
		retval = send(sock, buffer, (int)strlen(buffer) + 1, 0);
		if (retval == SOCKET_ERROR)
		{
			err_display("send()");
			break;
		}

		//데이터를 수신한다.
		retval = recv(sock, buffer, retval, MSG_WAITALL);
		if (retval == SOCKET_ERROR)
		{
			err_display("recv()");
			break;
		}

		//수신한 데이터를 출력한다.
		printf("Recv: %s\n", buffer);
	}

	//통신용 소켓을 닫는다.
	retval = closesocket(sock);
	if (retval != 0)
		err_display("closesocket()");

	//윈속을 종료한다.
	retval = WSACleanup();
	if (retval != 0)
		err_display("WSACleanup()");

	printf("프로그램을 종료합니다. \n");
	system("pause");
	return 0;
}