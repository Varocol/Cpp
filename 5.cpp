#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Stu //�ṹ��
{
	int num;
	char name[20];
	char sex[20];
	int age;
	float score[3];
	struct Stu *next;
} stu[100];

//////////////////////////////////////////

int link()
{
	int t;
	FILE *fp = NULL;
	fp = fopen("student.txt", "ab+");
	fseek(fp, 0, SEEK_END);
	t = ftell(fp);
	fclose(fp);
	return t;
}

void save(struct Stu *head) //���浽�ļ�
{
	struct Stu *p = NULL;
	int eof = EOF;
	p = head;
	FILE *fp;
	if ((fp = fopen("student.txt", "ab+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
	}
	else
	{
		printf("����ɹ�\n");
	}
	while (p != NULL)
	{
		fwrite(p, sizeof(struct Stu), 1, fp);
		p = p->next;
	}
	fwrite(&eof,sizeof(eof),1,fp); //�ļ���Ҫ����ļ���β����https://blog.csdn.net/weixin_30821731/article/details/95099549
	fclose(fp);
}

struct Stu *read() //��ȡ
{
	int t;
	struct Stu *head, *p, *p0;
	head = NULL;
	FILE *fp;
	if ((fp = fopen("student.txt", "rb+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		return head;
	}
	t = link();
	if (t == 0)
	{
		return head;
	}
	//����һ���������
	p0 = (struct Stu *)malloc(sizeof(struct Stu));
	fread(p0, sizeof(struct Stu), 1, fp);
	head = p = p0;
	while (p0->next != NULL)
	{
		p0 = (struct Stu *)malloc(sizeof(struct Stu));
		p->next = p0;
		p = p0;
	}
	p->next = NULL;
	p = NULL; //���p��p->next
	fclose(fp);
	return head;
}

////////////////////////////////////////////////////////

void list() //����Ŀ¼
{
	printf("\t\t\t\t\t****************��ӭʹ�ñ�ϵͳ*****************\n");
	printf("\t\t\t\t\t*****************1.¼��************************\n");
	printf("\t\t\t\t\t*****************2.���************************\n");
	printf("\t\t\t\t\t*****************3.�޸�************************\n");
	printf("\t\t\t\t\t*****************4.ɾ��************************\n");
	printf("\t\t\t\t\t*****************5.��ʾ************************\n");
	printf("\t\t\t\t\t*****************6.��ȡ************************\n");
	printf("\t\t\t\t\t*****************7.�˳�************************\n");
}

struct Stu *create() //����
{

	struct Stu *head = NULL, *p = NULL, *p0 = NULL; //�ṹ��ָ�����
	p0 = (struct Stu *)malloc(sizeof(struct Stu));	//ǿ��ת��+�����ڴ�
	p = head = p0;
	int num;//��������ѧ��
	boolean flag = false;
	printf("������ѧ����ѧ��(0 ֹͣ����):");
	scanf("%d", &num);
	while (num != 0) //�������룬���ж�ѧ���Ƿ�Ϊ0
	{
		flag =true;
		p0->num = num;
		printf("������ѧ��������:");
		scanf("%s", p0->name);
		printf("������ѧ�����Ա�:");
		scanf("%s", p0->sex);
		printf("������ѧ��������:");
		scanf("%d", &(p0->age));
		printf("������ѧ�������ĳɼ�:");
		scanf("%f", &(p0->score[0]));
		printf("������ѧ������ѧ�ɼ�:");
		scanf("%f", &(p0->score[1]));
		printf("������ѧ����C���Գɼ�:");
		scanf("%f", &(p0->score[2]));
		printf("\n");
		printf("������ѧ����ѧ��(0 ֹͣ����):");
		scanf("%d", &num);
		if (num)//���ѧ��Ϊ0�Ͳ������ַ
		{
			p0 = (struct Stu *)malloc(sizeof(struct Stu));
			p->next = p0;
			p = p0;
		}
	}
	p->next = NULL;
	if (flag)//���û��д�����ݾͲ�����
	{
		save(head);
	}
	return head;
}

struct Stu *add(struct Stu *head) //����
{

	struct Stu *p = NULL, *p0 = NULL;
	p = head;
	printf("\n������Ҫ���ӵ�ѧ����Ϣ\n\n");
	if (head == NULL)
	{
		p0 = (struct Stu *)malloc(sizeof(struct Stu));
		printf("������ѧ����ѧ��:");
		scanf("%d", &p0->num);
		printf("������ѧ��������:");
		scanf("%s", p0->name);
		printf("������ѧ�����Ա�:");
		scanf("%s", p0->sex);
		printf("������ѧ��������:");
		scanf("%d", &p0->age);
		printf("������ѧ�������ĳɼ�:");
		scanf("%f", &p0->score[0]);
		printf("������ѧ������ѧ�ɼ�:");
		scanf("%f", &p0->score[1]);
		printf("������ѧ����C���Գɼ�:");
		scanf("%f", &p0->score[2]);
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p0 = (struct Stu *)malloc(sizeof(struct Stu));
		printf("������ѧ����ѧ��:");
		scanf("%d", &p0->num);
		printf("������ѧ��������:");
		scanf("%s", p0->name);
		printf("������ѧ�����Ա�:");
		scanf("%s", p0->sex);
		printf("������ѧ��������:");
		scanf("%d", &p0->age);
		printf("������ѧ�������ĳɼ�:");
		scanf("%f", &p0->score[0]);
		printf("������ѧ������ѧ�ɼ�:");
		scanf("%f", &p0->score[1]);
		printf("������ѧ����C���Գɼ�:");
		scanf("%f", &p0->score[2]);
		p->next = p0;
		p = p0;
		p->next = NULL;
	}
	save(head);
	return head;
}

struct Stu *change(struct Stu *head) //�޸�
{

	int n;
	struct Stu *p = NULL;
	p = head;
	printf("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d", &n);

    if(head == NULL){
		printf("û�е������ݣ�\n");
		return head;
	}

	while (p->num != n)
	{
		p = p->next;
	}

	printf("������Ҫ�������޸�Ϊ:");
	scanf("%s", p->name);
	printf("������Ҫ���Ա��޸�Ϊ:");
	scanf("%s", p->sex);
	printf("������Ҫ�������޸�Ϊ:");
	scanf("%d", &p->age);
	printf("������Ҫ�����ĳɼ��޸�Ϊ:");
	scanf("%f", &p->score[0]);
	printf("������Ҫ����ѧ�ɼ��޸�Ϊ:");
	scanf("%f", &p->score[1]);
	printf("������Ҫ��C���Գɼ��޸�Ϊ:");
	scanf("%f", &p->score[2]);

	save(head);
	return head;
}

struct Stu *delet(struct Stu *head) //����ɾ��
{

	char na[20];
	struct Stu *p = NULL, *p0 = NULL;
	p0 = p = head;
	printf("������ɾ��ѧ��������");
	scanf("%s", na);
	if(head == NULL){
		printf("û��ѧ����Ϣ\n");
		return head;
	}
	if (strcmp(p->name, na) == 0)
	{
		head = p->next;
	}
	else
	{
		while (p != NULL)
		{

			if (strcmp(p->name, na) == 0)
			{
				p0->next = p0->next->next;
			}
			p0 = p;
			p = p->next;
		}
	}
	save(head);
	return head;
}

void show(struct Stu *head) //���
{

	struct Stu *p0 = NULL;
	p0 = head;
	if (head == NULL)
	{
		printf("\t\t��Ϣ�ڴ�Ϊ��\n\n\n");
	}

	while (p0 != NULL)
	{
		printf("ѧ����ѧ��:");
		printf("%d", p0->num);
		printf("\nѧ��������:");
		printf("%s", p0->name);
		printf("\nѧ�����Ա�:");
		printf("%s", p0->sex);
		printf("\nѧ��������:");
		printf("%d", p0->age);
		printf("\nѧ�������ĳɼ�:");
		printf("%.2f", p0->score[0]);
		printf("\nѧ������ѧ�ɼ�:");
		printf("%.2f", p0->score[1]);
		printf("\nѧ����C���Գɼ�:");
		printf("%.2f", p0->score[2]);
		printf("\n\n\n\n\n");
		p0 = p0->next;
	}
}

int main() ////������
{

	int n;
	struct Stu *head = NULL;
	while (1) //ͨ��Ŀ¼�������...
	{
		list();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			head = create(); //¼��
			break;
		case 2:
			head = add(head); //���
			break;
		case 3:
			head = change(head); //�޸�
			break;
		case 4:
			head = delet(head); //ɾ��
			break;
		case 5:
			show(head); //��ʾ
			break;
		case 6: //��ȡ
			head = read();
			break;
		case 7: //�˳�
			return 0;
			break;
		}
	}
	return 0;
}