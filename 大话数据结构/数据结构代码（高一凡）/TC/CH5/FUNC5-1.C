 /* func5-1.c 广义表的书写形式串为SString类型，包括算法5.8。bo5-5.c和bo5-6.c调用 */
 #include"c4-1.h" /* 定义SString类型 */
 #include"bo4-1.c" /* SString类型的基本操作 */
 void sever(SString str,SString hstr) /* 算法5.8改。SString是数组，不需引用类型 */
 { /* 将非空串str分割成两部分：hstr为第一个','之前的子串，str为之后的子串 */
   int n,k,i; /* k记尚未配对的左括号个数 */
   SString ch,c1,c2,c3;
   n=StrLength(str); /* n为串str的长度 */
   StrAssign(c1,","); /* c1=',' */
   StrAssign(c2,"("); /* c2='(' */
   StrAssign(c3,")"); /* c3=')' */
   SubString(ch,str,1,1); /* ch为串str的第1个字符 */
   for(i=1,k=0;i<=n&&StrCompare(ch,c1)||k!=0;++i) /* i小于串长且ch不是',' */
   { /* 搜索最外层的第一个逗号 */
     SubString(ch,str,i,1); /* ch为串str的第i个字符 */
     if(!StrCompare(ch,c2)) /* ch='(' */
       ++k; /* 左括号个数+1 */
     else if(!StrCompare(ch,c3)) /* ch=')' */
       --k; /* 左括号个数-1 */
   }
   if(i<=n) /* 串str中存在','，它是第i-1个字符 */
   {
     SubString(hstr,str,1,i-2); /* hstr返回串str','前的字符 */
     SubString(str,str,i,n-i+1); /* str返回串str','后的字符 */
   }
   else /* 串str中不存在',' */
   {
     StrCopy(hstr,str); /* 串hstr就是串str */
     ClearString(str); /* ','后面是空串 */
   }
 }
