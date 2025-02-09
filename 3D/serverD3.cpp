#pragma comment(lib,"ws2_32")
#include <winsock2.h>
#include <stdio.h>
int main(int argc, char *argv[]){
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2),&wsa);
	
	SOCKET s;
	s= socket(AF_INET,SOCK_STREAM,0);
	if(s==INVALID_SOCKET){
		printf("socket error!!\n");
		return -1;
	}
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345); // 꼭 해줘야 됨
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.10.145");//inet_addr("자기 ip");

	FILE * fp = fopen("C:\\output.txt","a");
	if(fp==NULL){
		printf("파일을 열 수 없습니다\n");
		return -2;
	}
	
	int errch;

	errch = bind(s,(sockaddr*)&addr,sizeof(addr));	//sockaddr과 socoaddr_in은 다르기 때문에 형변환을 해줌
	if(errch==SOCKET_ERROR){ //SOCKET_ERROR = -1
		printf("bind error!!!\n");
		return -1;
	}

	errch = listen(s,SOMAXCONN);
	if(errch == SOCKET_ERROR){
		printf("listen error!!\n");
			return -1;
	}
	SOCKADDR_IN clt_addr;
	SOCKET clt_s;
	int len = sizeof(clt_addr);

	clt_s = accept(s,(sockaddr*)&clt_addr,&len); //상대방의 정보가 저장됨
	if(clt_s == INVALID_SOCKET){
		printf("accept error!!!\n");
		return -1;
	}
	printf("접속한 ip : %s:%d\n",inet_ntoa(clt_addr.sin_addr),clt_addr.sin_port);

	char buf[1024];
	int size = recv(clt_s,buf,sizeof(buf),0);
	printf("수신 데이터 크기 : %d\n",size);
	printf("수신 데이터 : %s\n",buf);

	fprintf(fp,"\n수신 데이터 : %s\n수신 데이터 크기 : %d\n",buf,size);
	
	size = send(clt_s,buf,sizeof(buf),0);
	printf("\n송신 데이터 : %s\n송신 데이터 크기 : %d\n",buf,size);
	printf("%d : winsock successfully finished!!\n",s);
	
	closesocket(s);
	WSACleanup();
	return 0;
}