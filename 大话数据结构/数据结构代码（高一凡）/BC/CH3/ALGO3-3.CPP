 // algo3-3.cpp ���ţ�()��[]��{}��ƥ��ļ���
 typedef char SElemType;
 #include"c1.h"
 #include"c3-1.h"
 #include"bo3-1.cpp"

 void check()
 { // �������������һ���ַ��������������Ƿ����
   SqStack s;
   SElemType ch[80],*p,e;
   InitStack(s); // ��ʼ��ջ
   printf("����������ţ�()��[]��{}���ı���ʽ\n");
   gets(ch);
   p=ch; // pָ���ַ��������ַ�
   while(*p) // û����β
     switch(*p)
     {
       case '(':
       case '[':
       case '{':Push(s,*p++); // ��������ջ����p++
                break;
       case ')':
       case ']':
       case '}':if(!StackEmpty(s)) // ջ����
                {
                  Pop(s,e); // ����ջ��Ԫ��
                  if(!(e=='('&&*p==')'||e=='['&&*p==']'||e=='{'&&*p=='}'))
                  { // ����3��ƥ�����֮������
                    printf("�������Ų����\n");
                    exit(ERROR);
                  }
                }
                else // ջ��
                {
                  printf("ȱ��������\n");
                  exit(ERROR);
                }
       default: p++; // �����ַ���������ָ�������
     }
   if(StackEmpty(s)) // �ַ�������ʱջ��
     printf("����ƥ��\n");
   else
     printf("ȱ��������\n");
 }

 void main()
 {
   check();
 }
