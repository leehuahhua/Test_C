#include <stdio.h>
double  fun(  int  n )
{
	double a;
	double s=0;
	for(a=1;a<=n;a++)
	{
		s+=1/(a*(a+1));
	}
	 
	return s;
}
main()   /* 主函数 */
{  void NONO ();
   printf("%f\n", fun(10));
   NONO();
   getchar();
}
void NONO ()
{/* 本函数用于打开文件，输入数据，调用函数，输出数据，关闭文件。 */
  FILE *fp, *wf ;
  int i, n ;
  double s ;

  fp = fopen("..\\..\\in.dat","r") ;
  wf = fopen("..\\..\\out.dat","w") ;
  for(i = 0 ; i < 10 ; i++) {
    fscanf(fp, "%d", &n) ;
    s = fun(n) ;
    fprintf(wf, "%f\n", s) ;
  }
  fclose(fp) ;
  fclose(wf) ;
}
