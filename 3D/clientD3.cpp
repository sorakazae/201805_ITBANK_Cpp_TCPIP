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
		printf("���ڰ� ������ �߸��Ǿ����ϴ�\n��ɾ� ip port\n");
		return -3;
	}

	FILE * fp = fopen("C:\\input.txt","r");
	if(fp==NULL){
		printf("������ �� �� �����ϴ�\n");
		return -2;
	}


	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2])); // htons() �� ����� ��
	addr.sin_addr.S_un.S_addr = inet_addr(argv[1]);//inet_addr("���� ip");
	
	int errch;
	errch = connect(s, (sockaddr*)&addr,sizeof(addr));//������ ã�ư��� �Լ�
	if(errch == SOCKET_ERROR){
		printf("connect error!!!!\n");
		return -1;
	}
	
	char buf[1024];

	fscanf(fp,"%s",&buf);

	//printf("�۽� ������ �Է� : ");
	//gets(buf);
	
	int size = send(s,buf,sizeof(buf),0);
	printf("�۽� ������ : %s\n",buf);
	printf("�۽� ������ ũ�� : %d\n",size);

	size = recv(s,buf,sizeof(buf),0);
	printf("\n������ ������ ũ�� : %d\n������ ������ : %s\n",size,buf);
	closesocket(s);
	WSACleanup();
	return 0;
}