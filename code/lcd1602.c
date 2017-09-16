#include<string>
#include<common.h>

sbit rs=P3^2;
sbit rw=P3^3;
sbit en=P3^6;



/*命令函数*/
void lcd_cmd(uchar x)
{
  rs=0;
  rw=0;
  P1=x;
  //delay(5);
  en=1;
  delay(5);
  en=0;
}

/*数据函数*/
void lcd_data(uchar y)
{
  rs=1;
  rw=0;
  P1=y;
  //delay(5);
  en=1;
  delay(5);
  en=0;
}

/*初始化*/
void lcd_init()
{
  lcd_cmd(0x38);//1602显示，8数据口
  lcd_cmd(0x0e);
  
  lcd_cmd(0x01);//清屏
  lcd_cmd(0x06);
  lcd_cmd(0x02);
}

/**/
void main()
{
  char a[]="date:2017.04.04";
  char *p;
  p=a;
  lcd_init();
  lcd_cmd(0x80);
  while(*p!='\0')
  lcd_data(*p++);
  
}

