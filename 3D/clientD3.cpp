#pragma comment(lib,"ws2_32")
#include <winsock2.h>
#include <stdio.h>
//#include <stdlib.h>
int main(int argc, char *argv[]){
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2),&wsa);
	SOCKET s;
	s= socket(AF_INET,SOCK_STREAM,0);
	if(s==INVALID_SOCKET){
		printf("socket error!!\n");
		return -1;
	}
	if(argc!=3){
		printf("인자값 형식이 잘못되었습니다\n명령어 ip port\n");
		return -3;
	}

	FILE * fp = fopen("C:\\input.txt","r");
	if(fp==NULL){
		printf("파일을 열 수 없습니다\n");
		return -2;
	}


	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2])); // htons() 꼭 해줘야 됨
	addr.sin_addr.S_un.S_addr = inet_addr(argv[1]);//inet_addr("서버 ip");
	
	int errch;
	errch = connect(s, (sockaddr*)&addr,sizeof(addr));//서버를 찾아가는 함수
	if(errch == SOCKET_ERROR){
		printf("connect error!!!!\n");
		return -1;
	}
	
	char buf[1024];

	fscanf(fp,"%s",&buf);

	//printf("송신 데이터 입력 : ");
	//gets(buf);
	
	int size = send(s,buf,sizeof(buf),0);
	printf("송신 데이터 : %s\n",buf);
	printf("송신 데이터 크기 : %d\n",size);

	size = recv(s,buf,sizeof(buf),0);
	printf("\n수신한 데이터 크기 : %d\n수신한 데이터 : %s\n",size,buf);
	closesocket(s);
	WSACleanup();
	return 0;
}