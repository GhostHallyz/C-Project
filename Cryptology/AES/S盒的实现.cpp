#include<bits/stdc++.h>
 
using namespace std;

#define N 16
unsigned char S_BOX[256]={0}; //���ڴ洢S�� 
//unsigned char S[16][16]={0};
//unsigned char S_1[16][16]={0};
//ʵ��S�к��� 
void gen_labs(void)
{
	unsigned char pow_tab[256];
	unsigned char log_tab[256];
	unsigned char mid_tab[256];
	unsigned char sbx_tab[256]; 
	unsigned char b[8]={0xf1,0xe3,0xc7,0x8f,0x1f,0x3e,0x7c,0xf8};
	int i,j,k,p;
	//��0-255�Ŀ����� 
	for(i=0,p=1;i<256;i++)
	{
		pow_tab[i]=p;
		log_tab[p]=i;
		p=p^(p<<1)^(p&0x80?0x11b:0);
	}
	//��0-255�Ŀ�������洢��mid_tab�� 
	for(i=0;i<256;i++)
	{
		mid_tab[i]=(i?pow_tab[255-log_tab[i]]:0); 
	}
	
	for(i=0;i<256;i++)
	{
		int t=0,m=0,mid=0,tab=0;
		for(j=0;j<8;j++)
		{
			m=mid=(b[j]&mid_tab[i]);
			for(k=0;k<8;k++)
			{
				int n=(mid>>1);
				if(m!=(n<<1))
				{
					t++;
				}
				mid=n;
				m=mid;
			}
			if(t%2>0)
			{
				int temp=1;
				for(k=0;k<j;k++)
				{
					temp=temp<<1;
				}
				tab +=temp;
			}
			t=0;
		} 
		sbx_tab[i]=tab^0x63;//ʵ�ֹ�ʽ�е�+0x63 
	}  
	
	//�����洢��ӡ�����Ϣ 
	memcpy(S_BOX,sbx_tab,256);
	printf("************����Լ�����ʽ�Ŀ�����************\n"); 
	for(i=1;i<=256;i++)
	{
		printf("%.2X ",mid_tab[i-1]);
		if(i%16==0)
			printf("\n");
	} 
	printf("\n\n");
	printf("******************S-BOX*****************\n");
	//int t=0;
	for(i=1;i<=256;i++)
    {
	 	printf("%.2X ",S_BOX[i-1]);
	 	//S[t][(i-1)%16]=S_BOX[i-1];
	 	if(i%16==0)
	 	{
	 	//	t++;
	 		printf("\n");
		}
	}
} 

int main()
{
	gen_labs();
	system("pause");
	//while(1); 
}
