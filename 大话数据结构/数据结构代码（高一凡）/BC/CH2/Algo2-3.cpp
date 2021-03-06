 // algo2-3.cpp 实现算法2.7的程序
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h"
 #include"bo2-1.cpp"
 #include"func2-3.cpp" // 包括equal()、comp()、print()、print2()和print1()函数
 void MergeList(SqList La,SqList Lb,SqList &Lc) // 算法2.7
 { // 已知顺序线性表La和Lb的元素按值非递减排列。
   // 归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列
   ElemType *pa,*pa_last,*pb,*pb_last,*pc;
   pa=La.elem;
   pb=Lb.elem;
   Lc.listsize=Lc.length=La.length+Lb.length; // 不用InitList()创建空表Lc
   pc=Lc.elem=(ElemType *)malloc(Lc.listsize*sizeof(ElemType));
   if(!Lc.elem) // 存储分配失败
     exit(OVERFLOW);
   pa_last=La.elem+La.length-1;
   pb_last=Lb.elem+Lb.length-1;
   while(pa<=pa_last&&pb<=pb_last) // 表La和表Lb均非空
   { // 归并
     if(*pa<=*pb)
       *pc++=*pa++; // 将pa所指单元的值赋给pc所指单元后，pa和pc分别+1(指向下一个单元)
     else
       *pc++=*pb++; // 将pb所指单元的值赋给pc所指单元后，pa和pc分别+1(指向下一个单元)
   } // 以下两个while循环只会有一个被执行
   while(pa<=pa_last) // 表La非空且表Lb空
     *pc++=*pa++; // 插入La的剩余元素
   while(pb<=pb_last) // 表Lb非空且表La空
     *pc++=*pb++; // 插入Lb的剩余元素
 }

 void main()
 {
   SqList La,Lb,Lc;
   int j;
   InitList(La); // 创建空表La
   for(j=1;j<=5;j++) // 在表La中插入5个元素，依次为1、2、3、4、5
     ListInsert(La,j,j);
   printf("La= "); // 输出表La的内容
   ListTraverse(La,print1);
   InitList(Lb); // 创建空表Lb
   for(j=1;j<=5;j++) // 在表Lb中插入5个元素，依次为2、4、6、8、10
     ListInsert(Lb,j,2*j);
   printf("Lb= "); // 输出表Lb的内容
   ListTraverse(Lb,print1); // 由按非递减排列的表La、Lb得到按非递减排列的表Lc
   MergeList(La,Lb,Lc);
   printf("Lc= "); // 输出表Lc的内容
   ListTraverse(Lc,print1);
 }
